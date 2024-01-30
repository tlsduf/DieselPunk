// Fill out your copyright notice in the Description page of Project Settings.


#include "../Actor/MonsterSpawner.h"
#include "../Manager/DatatableManager.h"
#include "../Data/WaveModuleDataTable.h"
#include "../Data/WaveSetDataTable.h"
#include "../Data/CharacterDataTable.h"
#include "../Character/CharacterNPC.h"
#include "../Manager/ObjectManager.h"
#include "../Actor/PathRouter.h"

#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <DrawDebugHelpers.h>



// =============================================================
// 생성자
// =============================================================
AMonsterSpawner::AMonsterSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRoot);
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(SceneRoot);
	BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxComponent->PrimaryComponentTick.bCanEverTick = false;

	// StaticMesh Set // 스태틱메쉬 설정
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SceneRoot);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->PrimaryComponentTick.bCanEverTick = false;
}

// =============================================================
// BeginPlay
// =============================================================
void AMonsterSpawner::BeginPlay()
{
	Super::BeginPlay();

	if(ObjectId == -1)
		FObjectManager::GetInstance()->AddActor(this);
	
	RegistPathRouter(PathRouterNodes);	// 스포너와 연결된 PathRouter를 모두 등록합니다.
	if(DebugOnOff)
	{
		if(!PathRouterNodes.IsEmpty())
		{
			DrawDebugLine(GetWorld(), GetActorLocation(), PathRouterNodes[1]->GetActorLocation(), FColor::Green, true, -1, 0, 5);
			for(int i = 1; i < PathRouterNodeNum; i++ )
			{
				DrawDebugLine(GetWorld(), PathRouterNodes[i]->GetActorLocation(), PathRouterNodes[i+1]->GetActorLocation(), FColor::Green, true, -1, 0, 5);
			}
		}
	}
	
	MakeRectangleBySplinePoints();			// 직사각형의 영역을 생성합니다.
	GetRandomLocation();					// RandomLocation을 세팅합니다
	// 랜덤위치를 Key로 하는 TMap PathMap을 세팅합니다.
	if(!RandomLocation.IsEmpty())
	{
		for(const FVector& location : RandomLocation)
		{
			TArray<FVector> goalLocArray;
			for(auto& pathRouter : PathRouterNodes)
			{
				goalLocArray.Add( pathRouter.Value->MakeGoalLocByProportion( SetProportion(location) ) );
			}
			PathMap.Add(location, goalLocArray);
		}
	}
}

// =============================================================
// Called change info in editor
// =============================================================
void AMonsterSpawner::OnConstruction(const FTransform& InTransform)
{
	Super::OnConstruction(InTransform);
}

// =============================================================
// Called every frame
// =============================================================
void AMonsterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Spawn Monster by Calling StartSpawn();
	if(bDoSpawn)
		SpawnMonster(DeltaTime);
}

// =============================================================
// SpawnerName에 해당하는 데이터테이블의 정보를 읽어 세팅하고, 스폰을 시작합니다.
// =============================================================
void AMonsterSpawner::StartSpawn(FString InWaveSetName)
{
	_SetWaveSet(InWaveSetName);

	// SpawnerDeltaTime 초기화, 스폰 활성화
	SpawnerDeltaTime = 0.f;
	bDoSpawn = true;
}

// =============================================================
//생성한 몬스터 중 Destroy된 액터 삭제
// =============================================================
void AMonsterSpawner::RemoveDeadNPCFromArray()
{
	for(TArray<int32>::TIterator iterId{SpawnedMonsterID.CreateIterator()}; iterId; ++iterId)
	{
		if(FObjectManager::GetInstance()->FindActor(*iterId) == nullptr)
			iterId.RemoveCurrent();
	}
}

// =============================================================
// InWaveSetName에 해당하는 데이터테이블의 정보를 읽어 SpawnInfo를 세팅합니다.
// =============================================================
void AMonsterSpawner::_SetWaveSet(FString InWaveSetName)
{
	const FWaveSetDataTable* WaveSetDataTable = FDataTableManager::GetInstance()->GetData<FWaveSetDataTable>(EDataTableType::WaveSet, InWaveSetName);
	if(WaveSetDataTable == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("|| 스포너 : %s || 스포너Num : %d || 해당 스포너의 WaveSetInfoID가 비었습니다. DT_StageWave에서 확인바람."), *GetName(), SpawnerNumber)
		return;
	}
	
	for(const FWaveInfo& waveInfo : WaveSetDataTable->WaveSetInfo)
	{
		_SetWaveModule(waveInfo.WaveModuleID, waveInfo.StartDelay);
	}
}

// =============================================================
// InWaveModuleName에 해당하는 데이터테이블의 정보를 읽어 SpawnInfo를 세팅하고, InAddStartDelay만큼 스폰시간을 더합니다.
// =============================================================
void AMonsterSpawner::_SetWaveModule(FString InWaveModuleName, float InAddStartDelay)
{
	const FWaveModuleDataTable* WaveModuleDataTable = FDataTableManager::GetInstance()->GetData<FWaveModuleDataTable>(EDataTableType::WaveModule, InWaveModuleName);
	if(WaveModuleDataTable == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("|| 스포너 : %s || 스포너Num : %d || 해당 스포너의 WaveModuleID가 비었습니다. DT_WaveSet에서 확인바람."), *GetName(), SpawnerNumber)
		return;
	}
	
	for(const FWaveModuleInfo& spawnInfo : WaveModuleDataTable->WaveModuleInfo)
	{
		//info 정보 획득
		FSpawnInfo info;
		info.MonsterName = spawnInfo.MonsterID;
		info.StartDelay = spawnInfo.StartDelay + InAddStartDelay;
		
		//BP경로 획득
		const FCharacterDataTable* characterDataTable = FDataTableManager::GetInstance()->GetData<FCharacterDataTable>(EDataTableType::Character, spawnInfo.MonsterID);
		if(characterDataTable == nullptr)
		{
			LOG_SCREEN(FColor::Red, TEXT("스포너: %s의 DT_WaveModuleDataTable에 설정된 MonsterID: %s에 해당하는 데이터를 DT_Character에서 찾을 수 없습니다."), *InWaveModuleName, *spawnInfo.MonsterID)
			continue;
		}
		info.BpPath = UtilPath::GetCharacterBlueprintPath(*characterDataTable->BluePrintPath);
		
		//정보 추가
		SpawnInfo.Add(info);
		if(spawnInfo.bDoRep)
		{
			for(int i = 0; i < (spawnInfo.Reps - 1); i++)
			{
				info.StartDelay += spawnInfo.Delay;
				SpawnInfo.Add(info);
			}
		}
	}
	
	//스폰 지연시간에 따라 정렬
	SpawnInfo.Sort([](const FSpawnInfo& lhs, const FSpawnInfo& rhs)
	{
		return lhs.StartDelay < rhs.StartDelay; 
	});
}

// =============================================================
// 스포너가 소환한 몬스터가 다 파괴되었는지를 반환합니다.
// =============================================================
bool AMonsterSpawner::IsWaveCleared()
{
	return SpawnedMonsterID.IsEmpty();
}

// =============================================================
// SpawnInfo에 담긴 정보대로 몬스터를 스폰합니다.
// =============================================================
void AMonsterSpawner::SpawnMonster(float InDeltaTime)
{
	SpawnerDeltaTime += InDeltaTime;

	//생성할 몬스터가 남아있다면
	if(!SpawnInfo.IsEmpty())
	{
		//SpawnInfo의 첫 원소 획득
		TArray<FSpawnInfo>::TIterator iterSpawnInfo{ SpawnInfo.CreateIterator() };

		//스폰될 시간보다 스포너의 시간이 오래됐다면
		if(iterSpawnInfo->StartDelay <= SpawnerDeltaTime)
		{
			//UClass 생성
			UClass* classInfo = LoadClass<ACharacterNPC>(NULL, *iterSpawnInfo->BpPath);
			
			//스폰 파라미터 설정
			FSpawnParam spawnParam;
			spawnParam.Location = RandomLocation[FMath::RandRange(0, RandomLocation.Num() - 1)];
			spawnParam.Rotation = GetActorRotation();
			spawnParam.CallBackSpawn = nullptr;

			//몬스터 생성
			int32 id = FObjectManager::GetInstance()->CreateActor<ACharacterNPC>(classInfo, spawnParam);

			//몬스터 생성 검증
			if(!FObjectManager::IsValidId(id))
				LOG_SCREEN(FColor::Red, TEXT("스포너: %d에서 몬스터를 생성하지 못했습니다."), SpawnerNumber)
			else
			{
				SpawnedMonsterID.Add(id);
				// 몬스터 투영값 계산 // 몬스터 목표배열 설정
				if(auto npc = Cast<ACharacterNPC>(FObjectManager::GetInstance()->FindActor(id)))
				{
					if(!PathRouterNodes.IsEmpty())
					{
						npc->AddEnemyRoutingLines(PathMap[spawnParam.Location][0], GetActorLocation(), PathRouterNodes[1]->GetActorLocation());
						for(int i = 1; i < PathRouterNodeNum; i++ )
						{
							npc->AddEnemyRoutingLines(PathMap[spawnParam.Location][i], PathRouterNodes[i]->GetActorLocation(), PathRouterNodes[i+1]->GetActorLocation());
						}
					}
					if(FObjectManager::GetInstance()->GetNexus() != nullptr)
						npc->AddEnemyRoutingLines(FObjectManager::GetInstance()->GetNexus()->GetActorLocation(), PathRouterNodes[PathRouterNodeNum]->GetActorLocation(), FObjectManager::GetInstance()->GetNexus()->GetActorLocation());
					npc->UpdateSplinePath();
				}
			}
		

			//생성한 몬스터 정보 삭제
			iterSpawnInfo.RemoveCurrent();
		}
	}
	else
	{
		// 모두 생성하였다면, 스폰 비활성화
		bDoSpawn = false;
	}
}

// =============================================================
// 연결된 PathRouter를 모두 번호를 부여하며 등록합니다.
// =============================================================
void AMonsterSpawner::RegistPathRouter(TMap<int32, TObjectPtr<APathRouter>>& inPathRouterNodes)
{
	if(NextPathRouter)
	{
		PathRouterNodeNum++;
		inPathRouterNodes.Add(PathRouterNodeNum, NextPathRouter);
		NextPathRouter->RegistPathRouter(inPathRouterNodes, PathRouterNodeNum);
	}
}

// =============================================================
// 스폰시 해당'몬스터'의 Proportion을 설정합니다.
// =============================================================
FVector2D AMonsterSpawner::SetProportion(FVector inLoc)
{
	// Get distance between (firstPoint-secondPoint)Line and ThirdPoint
	FVector firstPoint, secondPoint, thirdPoint;
	double a, b, c;
				
	firstPoint = RectanglePoints[0];
	secondPoint = RectanglePoints[3];
	thirdPoint = inLoc;
	a = firstPoint.Y - secondPoint.Y;
	b = secondPoint.X - firstPoint.X;
	c = firstPoint.X * secondPoint.Y - secondPoint.X * firstPoint.Y;
	float widthDist = abs((a * thirdPoint.X) + (b * thirdPoint.Y) + c) / sqrt((a * a) + (b * b));
	
	double X = widthDist / FVector::Dist(RectanglePoints[0], RectanglePoints[1]);

	firstPoint = RectanglePoints[0];
	secondPoint = RectanglePoints[1];
	thirdPoint = inLoc;
	a = firstPoint.Y - secondPoint.Y;
	b = secondPoint.X - firstPoint.X;
	c = firstPoint.X * secondPoint.Y - secondPoint.X * firstPoint.Y;
	float lengthDist = abs((a * thirdPoint.X) + (b * thirdPoint.Y) + c) / sqrt((a * a) + (b * b));
				
	double Y = lengthDist / FVector::Dist(RectanglePoints[0], RectanglePoints[3]);

	return FVector2D(X, Y); 
}

// =============================================================
// 박스 컴포넌트를 기반으로 직사각형의 점을 PolygonPoints에 담습니다.
// =============================================================
void AMonsterSpawner::MakeRectangleBySplinePoints()
{
	FVector firstPoint, secondPoint, thirdPoint, fourthPoint;

	FVector scale = GetActorScale3D();
	double BoxScale = 150;
	firstPoint = BoxComponent->Bounds.Origin
	+ GetActorRotation().Vector().GetSafeNormal() * BoxScale * scale.X
	+ (GetActorRotation() + FRotator(0,-90,0)).Clamp().Vector().GetSafeNormal() * BoxScale * scale.Y;
	secondPoint = BoxComponent->Bounds.Origin
	+ GetActorRotation().Vector().GetSafeNormal() * BoxScale * scale.X
	+ (GetActorRotation() + FRotator(0,90,0)).Vector().GetSafeNormal() * BoxScale * scale.Y;
	thirdPoint = BoxComponent->Bounds.Origin
	- GetActorRotation().Vector().GetSafeNormal() * BoxScale * scale.X
	+ (GetActorRotation() + FRotator(0,90,0)).Vector().GetSafeNormal() * BoxScale * scale.Y;
	fourthPoint = BoxComponent->Bounds.Origin
	- GetActorRotation().Vector().GetSafeNormal() * BoxScale * scale.X
	+ (GetActorRotation() + FRotator(0,-90,0)).Vector().GetSafeNormal() * BoxScale * scale.Y;
	
	// Set RectanglePoints
	RectanglePoints.Empty();
	RectanglePoints.Add(firstPoint);
	RectanglePoints.Add(secondPoint);
	RectanglePoints.Add(thirdPoint);
	RectanglePoints.Add(fourthPoint);

	// Draw Debug
	if(DebugOnOff)
	{
		DrawDebugCylinder(GetWorld(), firstPoint, fourthPoint, 10, 4, FColor::Blue, true, -1, 0, 5);
		DrawDebugCylinder(GetWorld(), secondPoint, thirdPoint, 10, 4, FColor::Red, true, -1, 0, 5);
		DrawDebugLine(GetWorld(), firstPoint, (firstPoint + secondPoint)/2 + (GetActorRotation().Vector().GetSafeNormal() * 150), FColor::Green, true, -1, 0, 5);
		DrawDebugLine(GetWorld(), secondPoint, (firstPoint + secondPoint)/2 + (GetActorRotation().Vector().GetSafeNormal() * 150), FColor::Green, true, -1, 0, 5);
	
		for(int i = 0; i < RectanglePoints.Num(); ++i)
		{
			if(i == RectanglePoints.Num() - 1)
				DrawDebugLine( GetWorld(),RectanglePoints[i],RectanglePoints[0],FColor::Green, true, -1, 0, 5);
			else
				DrawDebugLine( GetWorld(),RectanglePoints[i],RectanglePoints[i + 1],FColor::Green, true, -1, 0, 5);
		}
	}
}

// =============================================================
// 사각 영역 안에 위치한 점을(점 사이의 거리 = DistanceDifference) RandomLocation 에 담습니다.
// =============================================================
void AMonsterSpawner::GetRandomLocation()
{
	double minX = 0, minY = 0, maxX = 0, maxY = 0;
	for(const FVector& polygonPoint : RectanglePoints)
	{
		minX = minX > polygonPoint.X ? polygonPoint.X : minX;
		minY = minY > polygonPoint.Y ? polygonPoint.Y : minY;
		maxX = maxX < polygonPoint.X ? polygonPoint.X : maxX;
		maxY = maxY < polygonPoint.Y ? polygonPoint.Y : maxY;
	}
	
	for(double x = minX; x < maxX; x += DistanceDifference)
	{
		for(double y = minY; y < maxY; y += DistanceDifference)
		{
			if(IsInPolygon(x, y))
			{
				FVector location = FVector(x, y, RectanglePoints[0].Z);
				location.Z = UtilCollision::GetZTrace(location, -1).Location.Z;
				RandomLocation.Add(location);
			}
		}
	}
}

// =============================================================
// 사각 내부에 점이 위치하는지 확인합니다. // Point in polygon algorithm
// =============================================================
bool AMonsterSpawner::IsInPolygon(double InX, double InY)
{
	int cn = 0;    // the  crossing number counter
	
	for (int i = 0; i < RectanglePoints.Num(); i++)
	{
		int j = (i + 1) % RectanglePoints.Num();
		if ((( RectanglePoints[i].Y <= InY ) && ( RectanglePoints[j].Y > InY )) || (( RectanglePoints[i].Y > InY ) && ( RectanglePoints[j].Y <=  InY )))
		{ 
			float vt = (float)(InY  - RectanglePoints[i].Y) / (RectanglePoints[j].Y - RectanglePoints[i].Y);
			if (InX <  RectanglePoints[i].X + vt * ( RectanglePoints[j].X - RectanglePoints[i].X )) 
				++cn;  
		}
	}
	return ( cn & 1 );    // 0 if even (out), and 1 if  odd (in)
}




