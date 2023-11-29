// Fill out your copyright notice in the Description page of Project Settings.

#include "NavigationManager.h"
#include "ObjectManager.h"
#include "FstreamManager.h"
#include "../Character/CharacterPC.h"
#include "../Actor/FloorStaticMeshActor.h"

#include <DrawDebugHelpers.h>

Singleton_Defintion(FNavigationManager)

FNavigationManager::FNavigationManager()
{
	
}

FNavigationManager::~FNavigationManager()
{
	
}

void FNavigationManager::Initialize()
{
	FString fileName = TEXT("NavNode_UEDPIE_0_TestLevel_DefenceGame.bin");
	TArray<int32> loadData;
	if(FFstreamManager::ReadDataBinaryByInteger<int32>(fileName, loadData))
	{
		for(int i = 0; i < loadData.Num(); i += (3 + Character_MaxHalfGrid))
		{
			uint8 value = loadData[i + 2];
			FDpNavNode& node = NavMap.FindOrAdd(loadData[i]).FindOrAdd(loadData[i + 1]);
			node.X = loadData[i];
			node.Y = loadData[i + 1];
			node.NavNodeState = static_cast<ENavNodeState>(loadData[i + 2]);
			node.IsGoNodeState.SetNum(Character_MaxHalfGrid);
			for(int j = 0; j < Character_MaxHalfGrid; ++j)
				node.IsGoNodeState[j] = static_cast<ENavNodeState>(loadData[i + 3 + j]);
		}
	}
}

void FNavigationManager::Release()
{
	for(TPair<int32, TMap<int32, FDpNavNode>>& pair : NavMap)
		pair.Value.Empty();
	NavMap.Empty();
}

//네비 노드 추가
void FNavigationManager::AddNavNode(int32 InX, int32 InY, FDpNavNode InNavNode)
{
	FDpNavNode& navNode = NavMap.FindOrAdd(InX).FindOrAdd(InY);
	navNode.X = InNavNode.X;
	navNode.Y = InNavNode.Y;
	if(navNode.IsGoNodeState.Num() != Character_MaxHalfGrid)
		navNode.IsGoNodeState.SetNum(Character_MaxHalfGrid);
	if(navNode.NavNodeState < InNavNode.NavNodeState)
		navNode.NavNodeState = InNavNode.NavNodeState;
}

//리스트 안에 존재 여부 반환
bool FNavigationManager::IsInList(int32 InX, int32 InY, const TArray<TPair<int32, int32>>& InList)
{
	const TPair<int32, int32>* find = InList.FindByPredicate([&InX, &InY](const TPair<int32, int32>& elem)
	{
		return elem.Key == InX && elem.Value == InY;
	});

	return find != nullptr;
}

//네비 노드 생성
void FNavigationManager::BuildNavMap(TWeakObjectPtr<AFloorStaticMeshActor> InFloorStaticMeshActor,
                                      TArray<FDpBox> InBoxes)
{
	if(!NavMap.IsEmpty())
	{
		BuildNavMapLocation();
		BuildNavGraph();
		return;
	}
	UWorld* world = FObjectManager::GetInstance()->GetWorld();
	if(world == nullptr)
		return;

	//노드 생성
	for(const FDpBox& box : InBoxes)
	{
		FVector minLoc = box.Location - box.Extend;
		FVector maxLoc = box.Location + box.Extend;

		int32 minGridX = static_cast<int32>(minLoc.X) / GridSize - 1;
		int32 maxGridX = static_cast<int32>(maxLoc.X) / GridSize + 1;
		int32 minGridY = static_cast<int32>(minLoc.Y) / GridSize - 1;
		int32 maxGridY = static_cast<int32>(maxLoc.Y) / GridSize + 1;


		for(int32 x = minGridX; x <= maxGridX; ++x)
		{
			for(int32 y = minGridY; y <= maxGridY; ++y)
			{
				//충돌 초기화
				TArray<FOverlapResult> hitResult;
				FVector location;
				location.X = (x * GridSize) + (GridSize * 0.5);
				location.Y = (y * GridSize) + (GridSize * 0.5);
				location.Z = box.Location.Z;
				FVector boxHalfExtend;
				boxHalfExtend.X = GridSize * 0.5;
				boxHalfExtend.Y = GridSize * 0.5;
				boxHalfExtend.Z = box.Extend.Z * 2;

				//플레이어 충돌범위 제외
				FCollisionQueryParams params;
				params.AddIgnoredActor(FObjectManager::GetInstance()->GetPlayer());

				//충돌 검사
				world->OverlapMultiByChannel(hitResult, location, FQuat::Identity, ECC_WorldStatic,
					FCollisionShape::MakeBox(boxHalfExtend), params);

				//노드 생성
				FOverlapResult* find = hitResult.FindByPredicate([&InFloorStaticMeshActor](const FOverlapResult& overlapResult)
				{
					if(InFloorStaticMeshActor.IsValid())
						return overlapResult.GetActor() == Cast<AActor>(InFloorStaticMeshActor.Get());
					return false;
				});

				//FloorStaticMeshActor와 충돌하지 않는다면 continue
				if(find == nullptr)
					continue;
				
				FDpNavNode navNode;
				navNode.X = x;
				navNode.Y = y;
				//FloorStaticMeshActor 외의 충돌여부에 따라 NavNodeState 설정
				if(hitResult.Num() > 1)
				{
					navNode.NavNodeState = ENavNodeState::BlockedByNonBreakable;
					AddNavNode(x, y, navNode);
					
				}
				else
				{
					navNode.NavNodeState = ENavNodeState::Passable;
					AddNavNode(x, y, navNode);
				}
			}
		}
	}

	//못지나 가는 노드가 주위에 있는 지 세팅
	for(TPair<int32, TMap<int32, FDpNavNode>>& nodes : NavMap)
	{
		for(TPair<int32, FDpNavNode>& node : nodes.Value)
		{
			if(node.Value.NavNodeState == ENavNodeState::BlockedByNonBreakable)
			{
				//못지나 가는 노드를 생성 시 주위 노드에 알림
				for(int i = 0; i < Character_MaxHalfGrid; ++i)
				{
					for(int j = -i; j <= i; ++j)
					{
						for(int k = -i; k <= i; ++k)
						{
							if(!IsInCircle(0, 0, i, j, k))
								continue;
							FDpNavNode& otherNavNode = NavMap.FindOrAdd(node.Value.X + j).FindOrAdd(node.Value.Y + k);
							if(otherNavNode.IsGoNodeState.Num() != Character_MaxHalfGrid)
								otherNavNode.IsGoNodeState.SetNum(Character_MaxHalfGrid);
							otherNavNode.IsGoNodeState[i] = ENavNodeState::BlockedByNonBreakable;
						}
					}
				}
			}
		}
	}

	//파일 출력을 위한 데이터 정리
	TArray<int32> outArray;
	for(const TPair<int32, TMap<int32, FDpNavNode>>& nodes : NavMap)
	{
		for(const TPair<int32, FDpNavNode>& node : nodes.Value)
		{
			outArray.Add(node.Value.X);
			outArray.Add(node.Value.Y);
			outArray.Add(static_cast<int32>(node.Value.NavNodeState));
			for(int i = 0; i < Character_MaxHalfGrid; ++i)
				outArray.Add(static_cast<int32>(node.Value.IsGoNodeState[i]));
		}
	}
	
	//노드 파일출력
	FString fileName = world->GetMapName();
	fileName = TEXT("NavNode_") + fileName + TEXT(".bin");
	bool IsWriting = FFstreamManager::WriteDataBinaryByInteger(fileName, outArray);

	BuildNavMapLocation();
	BuildNavGraph();
}

//네비 노드 Location 설정
void FNavigationManager::BuildNavMapLocation()
{
	UWorld* world = FObjectManager::GetInstance()->GetWorld();
	if(world == nullptr)
		return;
	
	//X, Y값으로 Location을 빌드합니다.
	for(TPair<int32, TMap<int32, FDpNavNode>>& nodes : NavMap)
	{
		for(TPair<int32, FDpNavNode>& node : nodes.Value)
		{
			FHitResult hit;
			FVector location;
			location.X = static_cast<double>(node.Value.X * GridSize + GridSize * 0.5);
			location.Y = static_cast<double>(node.Value.Y * GridSize + GridSize * 0.5);
			location.Z = 0.0;
			FVector start = location, end = location;

			start.Z = 99999.0;
			end.Z = -99999.0;
			
			if(world->LineTraceSingleByChannel(hit,	start, end, ECollisionChannel::ECC_GameTraceChannel9))
				node.Value.Location = hit.Location;
		}
	}
}

//그래프 생성
void FNavigationManager::BuildNavGraph()
{
	for(const TPair<int32, TMap<int32, FDpNavNode>>& nodes : NavMap)
	{
		for(const TPair<int32, FDpNavNode>& node : nodes.Value)
		{
			int x = nodes.Key;
			int y = node.Key;
			
			//상단
			if(NavMap.Find(x + 1) != nullptr && NavMap.Find(x + 1)->Find(y) != nullptr && NavMap[x + 1][y].NavNodeState == ENavNodeState::Passable)
				NavMap.FindOrAdd(x).FindOrAdd(y).Road.Add({x + 1, y});

			//우상단
			if(NavMap.Find(x + 1) != nullptr && NavMap.Find(x + 1)->Find(y + 1) != nullptr && NavMap[x + 1][y + 1].NavNodeState == ENavNodeState::Passable)
				NavMap.FindOrAdd(x).FindOrAdd(y).Road.Add({x + 1, y + 1});

			//우단
			if(NavMap.Find(x) != nullptr && NavMap.Find(x)->Find(y + 1) != nullptr && NavMap[x][y + 1].NavNodeState == ENavNodeState::Passable)
				NavMap.FindOrAdd(x).FindOrAdd(y).Road.Add({x, y + 1});

			//우하단
			if(NavMap.Find(x - 1) != nullptr && NavMap.Find(x - 1)->Find(y + 1) != nullptr && NavMap[x - 1][y + 1].NavNodeState == ENavNodeState::Passable)
				NavMap.FindOrAdd(x).FindOrAdd(y).Road.Add({x - 1, y + 1});

			//하단
			if(NavMap.Find(x - 1) != nullptr && NavMap.Find(x - 1)->Find(y) != nullptr && NavMap[x - 1][y].NavNodeState == ENavNodeState::Passable)
				NavMap.FindOrAdd(x).FindOrAdd(y).Road.Add({x - 1, y});

			//좌하단
			if(NavMap.Find(x - 1) != nullptr && NavMap.Find(x - 1)->Find(y - 1) != nullptr && NavMap[x - 1][y - 1].NavNodeState == ENavNodeState::Passable)
				NavMap.FindOrAdd(x).FindOrAdd(y).Road.Add({x - 1, y - 1});

			//좌단
			if(NavMap.Find(x) != nullptr && NavMap.Find(x)->Find(y - 1) != nullptr && NavMap[x][y - 1].NavNodeState == ENavNodeState::Passable)
				NavMap.FindOrAdd(x).FindOrAdd(y).Road.Add({x, y - 1});

			//좌상단
			if(NavMap.Find(x + 1) != nullptr && NavMap.Find(x + 1)->Find(y - 1) != nullptr && NavMap[x + 1][y - 1].NavNodeState == ENavNodeState::Passable)
				NavMap.FindOrAdd(x).FindOrAdd(y).Road.Add({x + 1, y - 1});
		}
	}
}

//최단 경로 찾기
bool FNavigationManager::_PathFinding(int32 InStartX, int32 InStartY, int32 InEndX, int32 InEndY, const int32 InCharacterGridSize)
{
	if(!OpenList.IsEmpty())
		OpenList.CreateIterator().RemoveCurrent();

	CloseList.Add({InStartX, InStartY});

	//인접 노드 조사
	for(const TPair<int32, int32>& idx : NavMap.Find(InStartX)->Find(InStartY)->Road)
	{
		//인접 노드가 목적지라면 검색 종료
		if(idx.Key == InEndX && idx.Value == InEndY)
		{
			NavMap[idx.Key][idx.Value].Parent = &NavMap[InStartX][InStartY];
			return true;
		}
		if(NavMap[idx.Key][idx.Value].IsGoNodeState[InCharacterGridSize - 1] == ENavNodeState::BlockedByNonBreakable)
			continue;

		//목적지 노드가 아니라면 OpenList에 보관
		if(!IsInList(idx.Key, idx.Value, OpenList) && !IsInList(idx.Key, idx.Value, CloseList))
		{
			NavMap[idx.Key][idx.Value].Parent = &NavMap[InStartX][InStartY];
			OpenList.Add({idx.Key, idx.Value});
		}
	}

	//찾을 수 있는 길이 없음
	if(OpenList.IsEmpty())
		return false;

	//휴리스틱 조사식으로 정렬
	double firstStartX = StartX;
	double firstStartY = StartY;
	
	OpenList.Sort([&firstStartX, &firstStartY, &InEndX, &InEndY](const TPair<int32, int32>& lhsIdx, const TPair<int32, int32>& rhsIdx)
	{
		double distStartCurrentLhs = DistanceIndex(firstStartX, firstStartY, lhsIdx.Key, lhsIdx.Value);
		double distCurrentEndLhs = DistanceIndex(lhsIdx.Key, lhsIdx.Value, InEndX, InEndY);

		double distStartCurrentRhs = DistanceIndex(firstStartX, firstStartY, rhsIdx.Key, rhsIdx.Value);
		double distCurrentEndRhs = DistanceIndex(rhsIdx.Key, rhsIdx.Value, InEndX, InEndY);

		return distStartCurrentLhs + distCurrentEndLhs <= distStartCurrentRhs + distCurrentEndRhs;
	});

	return _PathFinding(OpenList[0].Key, OpenList[0].Value, InEndX, InEndY, InCharacterGridSize);
}

//두 인덱스 사이 거리 측정
double FNavigationManager::DistanceIndex(double InAx, double InAy, double InBx, double InBy)
{
	return sqrt((InAx - InBx) * (InAx - InBx) + (InAy - InBy) * (InAy - InBy));
}

//경로 생성
TArray<FDpNavNode*> FNavigationManager::CreatePath(int32 InStartX, int32 InStartY, int32 InEndX, int32 InEndY)
{
	TArray<FDpNavNode*> outPath;
	outPath.Add(&NavMap[InEndX][InEndY]);

	FDpNavNode* parent = NavMap[InEndX][InEndY].Parent;

	while(true)
	{
		if(parent->X == InStartX && parent->Y == InStartY)
			break;

		outPath.Add(parent);
		parent = parent->Parent;
	}

	return outPath;
}

//포탑이 설치될 때 IsGoNodeState갱신
void FNavigationManager::SetBlockedByBreakableIsGoNodeState(int32 InX, int32 InY)
{
	for(int i = 0; i < Character_MaxHalfGrid; ++i)
	{
		for(int j = -i; j <= i; ++j)
		{
			for(int k = -i; k <= i; ++k)
			{
				if(!IsInCircle(0, 0, i, j, k))
					continue;
				
				if(NavMap.Find(InX) != nullptr && NavMap.Find(InX)->Find(InY) != nullptr)
				{
					if(NavMap.Find(InX)->Find(InY)->IsGoNodeState[i] == ENavNodeState::Passable)
						NavMap.Find(InX)->Find(InY)->IsGoNodeState[i] = ENavNodeState::BlockedByBreakable;
				}
			}			
		}
	}
}

bool FNavigationManager::IsInCircle(double InMiddleX, double InMiddleY, double InRadius, double InX, double InY)
{
	return DistanceIndex(InMiddleX, InMiddleY, InX, InY) <= InRadius;
}

void FNavigationManager::DrawDebugNavNode(int32 InX, int32 InY)
{
	UWorld* world = FObjectManager::GetInstance()->GetWorld();
	if(world == nullptr)
		return;
	
	if(NavMap.Find(InX) == nullptr || NavMap.Find(InX)->Find(InY) == nullptr)
		return;
	
	TArray<FVector> locations;
	locations.Reserve(4);
	locations.Add(NavMap[InX][InY].Location - FVector(GridSize * 0.5, -GridSize * 0.5, 0.0));
	locations.Add(NavMap[InX][InY].Location - FVector(GridSize * 0.5, GridSize * 0.5, 0.0));
	locations.Add(NavMap[InX][InY].Location - FVector(-GridSize * 0.5, GridSize * 0.5, 0.0));
	locations.Add(NavMap[InX][InY].Location - FVector(-GridSize * 0.5, -GridSize * 0.5, 0.0));

	for(int i = 0; i < locations.Num(); ++i)
	{
		FColor color = FColor::Green;
		if(NavMap[InX][InY].NavNodeState == ENavNodeState::Passable)
			color = FColor::Green;
		else if (NavMap[InX][InY].NavNodeState == ENavNodeState::BlockedByNonBreakable)
			color = FColor::Red;
		else if (NavMap[InX][InY].NavNodeState == ENavNodeState::BlockedByBreakable)
			color = FColor::Yellow;
					
		DrawDebugLine(world, locations[i], locations[(i + 1) % locations.Num()], color, true, -1, 0, 2);
	}
}

void FNavigationManager::DrawNonPassableNavNode(int32 InGridSize)
{
	if(InGridSize > Character_MaxHalfGrid || InGridSize < 0)
		return;
	
	UWorld* world = FObjectManager::GetInstance()->GetWorld();
	if(world == nullptr)
		return;
	
	for(const TPair<int32, TMap<int32, FDpNavNode>>& nodes : NavMap)
	{
		for(const TPair<int32, FDpNavNode>& node : nodes.Value)
		{
			TArray<FVector> locations;
			locations.Reserve(4);
			locations.Add(node.Value.Location - FVector(GridSize * 0.5, -GridSize * 0.5, 0.0));
			locations.Add(node.Value.Location - FVector(GridSize * 0.5, GridSize * 0.5, 0.0));
			locations.Add(node.Value.Location - FVector(-GridSize * 0.5, GridSize * 0.5, 0.0));
			locations.Add(node.Value.Location - FVector(-GridSize * 0.5, -GridSize * 0.5, 0.0));

			FColor color = FColor::Green;
			if(node.Value.IsGoNodeState[InGridSize - 1] == ENavNodeState::BlockedByNonBreakable)
				color = FColor::Red;
			else
				continue;
			for(int i = 0; i < locations.Num(); ++i)
				DrawDebugLine(world, locations[i], locations[(i + 1) % locations.Num()], color, true, -1, 0, 2);
		}
	}
}

//디버그용 네비 맵 Draw 
void FNavigationManager::DrawDebugNavMap()
{
	UWorld* world = FObjectManager::GetInstance()->GetWorld();
	if(world == nullptr)
		return;
	
	for(const TPair<int32, TMap<int32, FDpNavNode>>& nodes: NavMap)
	{
		for(const TPair<int32, FDpNavNode>& node : nodes.Value)
		{
			FVector firstLocation = node.Value.Location;
			TArray<FVector> locations;
			locations.Reserve(4);
			locations.Add(firstLocation - FVector(GridSize * 0.5, -GridSize * 0.5, 0.0));
			locations.Add(firstLocation - FVector(GridSize * 0.5, GridSize * 0.5, 0.0));
			locations.Add(firstLocation - FVector(-GridSize * 0.5, GridSize * 0.5, 0.0));
			locations.Add(firstLocation - FVector(-GridSize * 0.5, -GridSize * 0.5, 0.0));

			for(int i = 0; i < locations.Num(); ++i)
			{
				FColor color = FColor::Green;
				if(node.Value.NavNodeState == ENavNodeState::Passable)
					color = FColor::Green;
				else if (node.Value.NavNodeState == ENavNodeState::BlockedByNonBreakable)
					color = FColor::Red;
				else if (node.Value.NavNodeState == ENavNodeState::BlockedByBreakable)
					color = FColor::Yellow;
					
				DrawDebugLine(world, locations[i], locations[(i + 1) % locations.Num()], color, true, -1, 0, 2);
			}
		}
	}
}

//A-Star알고리즘을 통해 InStartLocation에서 InEndLocation까지의 최단거리 반환
TArray<FVector> FNavigationManager::PathFinding(const FVector& InStartLocation, const FVector& InEndLocation, const int32 InCharacterGridSize)
{
	TArray<FVector> outPath;
	
	if(InCharacterGridSize > Character_MaxHalfGrid || InCharacterGridSize < 0)
		return outPath;
	
	int32 startX = static_cast<int32>(InStartLocation.X) / GridSize;
	int32 startY = static_cast<int32>(InStartLocation.Y) / GridSize;
	int32 endX = static_cast<int32>(InEndLocation.X) / GridSize;
	int32 endY = static_cast<int32>(InEndLocation.Y) / GridSize;

	OpenList.Empty();
	CloseList.Empty();

	StartX = startX;
	StartY = startY;
	
	//이미 도착한 경우
	if(startX == endX && startY == endY)
		return outPath;

	//시작지점이 맵 외부이거나 갈 수 없는 노드일 경우
	if(NavMap.Find(startX) == nullptr || NavMap.Find(startX)->Find(startY) == nullptr || NavMap.Find(startX)->Find(startY)->NavNodeState != ENavNodeState::Passable)
		return outPath;

	//도착지점이 맵 외부이거나 갈 수 없는 노드일 경우 
	if(NavMap.Find(endX) == nullptr || NavMap.Find(endX)->Find(endY) == nullptr || NavMap.Find(endX)->Find(endY)->NavNodeState != ENavNodeState::Passable)
		return outPath;

	//길찾기 수행
	if(!_PathFinding(startX, startY, endX, endY, InCharacterGridSize))
		return outPath;

	//경로 생성
	TArray<FDpNavNode*> nodePath = CreatePath(StartX, StartY, endX, endY);
	Algo::Reverse(nodePath);
	for(const FDpNavNode* node : nodePath)
		outPath.Add(node->Location);

	return outPath;
}

//터렛 설치 가능한지 검색
bool FNavigationManager::IsPlacementTurret(FVector InLocation, int32 InGridSize)
{
	FVector outLocation = FVector::ZeroVector;

	TArray<int32> xIndex, yIndex;

	//GridSize가 홀수일때
	if(InGridSize & 1)
	{
		int32 startX = floor(InLocation.X / GridSize) - InGridSize / 2;
		int32 startY = floor(InLocation.Y / GridSize) - InGridSize / 2;

		for(int i = 0; i < InGridSize; ++i)
		{
			xIndex.Add(startX + i);
			yIndex.Add(startY + i);
		}
	}
	//GridSize가 짝수일때
	else
	{
		int32 startX = static_cast<int32>(round(InLocation.X / GridSize)) - InGridSize / 2;
		int32 startY = static_cast<int32>(round(InLocation.Y / GridSize)) - InGridSize / 2;

		for(int i = 0; i < InGridSize; ++i)
		{
			xIndex.Add(startX + i);
			yIndex.Add(startY + i);
		}
	}

	//설치가 가능한지 검사
	for(int32 x : xIndex)
	{
		for(int32 y : yIndex)
		{
			if(NavMap.Find(x) == nullptr || NavMap.Find(x)->Find(y) == nullptr || NavMap.Find(x)->Find(y)->NavNodeState != ENavNodeState::Passable)
				return false;
		}
	}
	return true;
}

//터렛 설치
bool FNavigationManager::PlacementTurret(FVector& InOutLocation, int32 InGridSize, TArray<TPair<int32, int32>>& OutIndex)
{
	FVector outLocation = FVector::ZeroVector;

	TArray<int32> xIndex, yIndex;

	//GridSize가 홀수일때
	if(InGridSize & 1)
	{
		int32 startX = floor(InOutLocation.X / GridSize) - InGridSize / 2;
		int32 startY = floor(InOutLocation.Y / GridSize) - InGridSize / 2;

		for(int i = 0; i < InGridSize; ++i)
		{
			xIndex.Add(startX + i);
			yIndex.Add(startY + i);
		}
	}
	//GridSize가 짝수일때
	else
	{
		int32 startX = static_cast<int32>(round(InOutLocation.X / GridSize)) - InGridSize / 2;
		int32 startY = static_cast<int32>(round(InOutLocation.Y / GridSize)) - InGridSize / 2;

		for(int i = 0; i < InGridSize; ++i)
		{
			xIndex.Add(startX + i);
			yIndex.Add(startY + i);
		}
	}

	//설치가 가능한지 검사
	for(int32 x : xIndex)
	{
		for(int32 y : yIndex)
		{
			if(NavMap.Find(x) == nullptr || NavMap.Find(x)->Find(y) == nullptr || NavMap.Find(x)->Find(y)->NavNodeState != ENavNodeState::Passable)
				return false;

			outLocation += NavMap[x][y].Location;
		}
	}

	//최종 위치계산
	outLocation /= xIndex.Num() * yIndex.Num();
	InOutLocation = outLocation;
	
	//설치한 곳에 ENavNodeState를 BlockedByBreakable로 변경
	for(int32 x : xIndex)
		for(int32 y : yIndex)
		{
			NavMap[x][y].NavNodeState = ENavNodeState::BlockedByBreakable;
			OutIndex.Add({x, y});
			//SetBlockedByBreakableIsGoNodeState(x, y);
			DrawDebugNavNode(x, y);
		}

	return true;
}

void FNavigationManager::RestoreNavNodeByDestructedTurret(const TArray<TPair<int32, int32>>& InIndex)
{
	for(const TPair<int32, int32>& idx : InIndex)
	{
		if(NavMap.Find(idx.Key) == nullptr || NavMap.Find(idx.Key)->Find(idx.Value) == nullptr)
		{
			LOG_SCREEN(FColor::Red, TEXT("FNavigationManager::RestoreNavNodeByDestructedTurret() Error! Node is not found. Check InIndex"))
			continue;
		}
		NavMap[idx.Key][idx.Value].NavNodeState = ENavNodeState::Passable;
	}
}
