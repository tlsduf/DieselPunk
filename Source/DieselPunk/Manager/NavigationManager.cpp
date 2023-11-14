// Fill out your copyright notice in the Description page of Project Settings.

#include "NavigationManager.h"
#include "ObjectManager.h"
#include "FstreamManager.h"
#include "../Character/CharacterPC.h"
#include "../Actor/FloorStaticMeshActor.h"

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
		for(int i = 0; i < loadData.Num(); i += 3)
		{
			uint8 value = loadData[i + 2];
			NavNode.FindOrAdd(loadData[i]).FindOrAdd(loadData[i + 1]) = static_cast<ENavNodeState>(value);
		}
	}
}

void FNavigationManager::Release()
{
	for(TPair<int32, TMap<int32, ENavNodeState>>& pair : NavNode)
		pair.Value.Empty();
	NavNode.Empty();
}

//네비 노드 추가
void FNavigationManager::AddNavNode(int32 InX, int32 InY, ENavNodeState InNavNodeState)
{
	ENavNodeState navNodeState = NavNode.FindOrAdd(InX).FindOrAdd(InY);
	navNodeState = (navNodeState < InNavNodeState) ? InNavNodeState : navNodeState;
}

//네비 노드 생성
void FNavigationManager::BuildNavNode(TWeakObjectPtr<AFloorStaticMeshActor> InFloorStaticMeshActor,
                                      TArray<FDpBox> InBoxes)
{
	if(!NavNode.IsEmpty())
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

		for(int32 x = minGridX; x < maxGridX; ++x)
		{
			for(int32 y = minGridY; y < maxGridY; ++y)
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
				FObjectManager::GetInstance()->GetWorld()->OverlapMultiByChannel(hitResult, location, FQuat::Identity, ECC_WorldStatic,
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

				//FloorStaticMeshActor 외의 충돌여부에 따라 NavNodeState 설정
				if(hitResult.Num() > 1)
					AddNavNode(x, y, ENavNodeState::BlockedByNonBreakable);
				else
					AddNavNode(x, y, ENavNodeState::Passable);
			}
		}
	}

	//파일 출력을 위한 데이터 정리
	TArray<int32> outArray;
	for(const TPair<int32, TMap<int32, ENavNodeState>>& nodes : NavNode)
	{
		for(const TPair<int32, ENavNodeState>& node : nodes.Value)
		{
			outArray.Add(nodes.Key);
			outArray.Add(node.Key);
			outArray.Add(static_cast<int32>(node.Value));
		}
	}
	
	//노드 파일출력
	FString fileName = FObjectManager::GetInstance()->GetWorld()->GetMapName();
	fileName = TEXT("NavNode_") + fileName + TEXT(".bin");
	bool IsWriting = FFstreamManager::WriteDataBinaryByInteger(fileName, outArray);
}
