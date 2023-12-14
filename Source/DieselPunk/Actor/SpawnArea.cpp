// Fill out your copyright notice in the Description page of Project Settings.


#include "../Actor/SpawnArea.h"
#include "../Manager/DatatableManager.h"
#include "../Data/MonsterSpawnerDataTable.h"
#include "../Data/CharacterDataTable.h"
#include "../Character/CharacterNPC.h"
#include "../Manager/ObjectManager.h"

#include <Components/SplineComponent.h>
#include <DrawDebugHelpers.h>


// =============================================================
// 생성자
// =============================================================
ASpawnArea::ASpawnArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SetRootComponent(SplineComponent);
	SplineComponent->SetClosedLoop(true);
	SplineComponent->PrimaryComponentTick.bCanEverTick = false;
}

// =============================================================
// BeginPlay
// =============================================================
void ASpawnArea::BeginPlay()
{
	Super::BeginPlay();

	if(ObjectId == -1)
		FObjectManager::GetInstance()->AddActor(this);
	
	// Set PolygonPoints on Spline
	PolygonPoints.Empty();
	PolygonPoints.Reserve(SplineComponent->GetNumberOfSplinePoints());
	for(int i = 0; i < SplineComponent->GetNumberOfSplinePoints(); ++i)
		PolygonPoints.Add(SplineComponent->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::World));

	// 스플라인 디버그라인
	for(int i = 0; i < SplineComponent->GetNumberOfSplinePoints(); ++i)
	{
		if(i == SplineComponent->GetNumberOfSplinePoints() - 1)
			DrawDebugLine( GetWorld(),SplineComponent->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::World),SplineComponent->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::World),FColor::Red, true);
		else
			DrawDebugLine( GetWorld(),SplineComponent->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::World),SplineComponent->GetLocationAtSplinePoint(i + 1, ESplineCoordinateSpace::World),FColor::Red, true);
	}
}

// =============================================================
// Called change info in editor
// =============================================================
void ASpawnArea::OnConstruction(const FTransform& InTransform)
{
	Super::OnConstruction(InTransform);

	// Set All Spline Point Type "Linear"
	for(int i = 0; i < SplineComponent->GetNumberOfSplinePoints(); ++i)
		SplineComponent->SetSplinePointType(i, ESplinePointType::Linear, true);
}

// =============================================================
// Called every frame
// =============================================================
void ASpawnArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Spawn Monster by Calling SetSpawnerName();
	if(bDoSpawn)
		SpawnMonster(DeltaTime);
}

// =============================================================
// SpawnerName에 해당하는 데이터테이블의 정보를 읽어 세팅하고, 스폰을 시작합니다.
// =============================================================
void ASpawnArea::SetSpawnerName(FString InSpawnerName)
{
	//몬스터 스폰정보 등록
	const FMonsterSpawnerDataTable* monsterSpawnerDataTable = FDataTableManager::GetInstance()->GetData<FMonsterSpawnerDataTable>(EDataTableType::MonsterSpawner, InSpawnerName);
	if(monsterSpawnerDataTable == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("몬스터 스포너: %s의 변수 SpawnerName: %s에 해당하는 데이터가 없습니다. SpawnerName 데이터 테이블에 맞게 설정해주세요"), *GetName(), *InSpawnerName)
		return;
	}
	
	for(const FMonsterSpawnInfo& spawnInfo : monsterSpawnerDataTable->MonsterSpawnerInfo)
	{
		//info 정보 획득
		FSpawnInfo1 info;
		info.MonsterName = spawnInfo.MonsterName;
		info.DelayTime = spawnInfo.DelayTime;

		//BP경로 획득
		const FCharacterDataTable* characterDataTable = FDataTableManager::GetInstance()->GetData<FCharacterDataTable>(EDataTableType::Character, spawnInfo.MonsterName);
		if(characterDataTable == nullptr)
		{
			LOG_SCREEN(FColor::Red, TEXT("스포너: %s의 DT_SpawnerDataTable에 설정된 MonsterName: %s에 해당하는 데이터를 DT_Character에서 찾을 수 없습니다."), *InSpawnerName, *spawnInfo.MonsterName)
			continue;
		}
		info.BpPath = UtilPath::GetCharacterBlueprintPath(*characterDataTable->BluePrintPath);

		//정보 추가
		SpawnInfo.Add(info);
	}

	//스폰 지연시간에 따라 정렬
	SpawnInfo.Sort([](const FSpawnInfo1& lhs, const FSpawnInfo1& rhs)
	{
		return lhs.DelayTime < rhs.DelayTime; 
	});

	// SpawnerDeltaTime 초기화, 스폰 활성화
	SpawnerDeltaTime = 0.f;
	bDoSpawn = true;
}

// =============================================================
// 스포너가 소환한 몬스터가 다 파괴되었는지를 반환합니다.
// =============================================================
bool ASpawnArea::IsWaveCleared()
{
	return SpawnMonsterId.IsEmpty();
}

// =============================================================
// SpawnInfo에 담긴 정보대로 몬스터를 스폰합니다.
// =============================================================
void ASpawnArea::SpawnMonster(float InDeltaTime)
{
	SpawnerDeltaTime += InDeltaTime;

	//생성한 몬스터 중 Destroy된 액터 삭제
	for(TArray<int32>::TIterator iterId{SpawnMonsterId.CreateIterator()}; iterId; ++iterId)
	{
		if(FObjectManager::GetInstance()->FindActor(*iterId) == nullptr)
			iterId.RemoveCurrent();
	}

	//생성할 몬스터가 남아있다면
	if(!SpawnInfo.IsEmpty())
	{
		//SpawnInfo의 첫 원소 획득
		TArray<FSpawnInfo1>::TIterator iterSpawnInfo{ SpawnInfo.CreateIterator() };

		//스폰될 시간보다 스포너의 시간이 오래됐다면
		if(iterSpawnInfo->DelayTime <= SpawnerDeltaTime)
		{
			//UClass 생성
			UClass* classInfo = LoadClass<ACharacterNPC>(NULL, *iterSpawnInfo->BpPath);

			//스폰 파라미터 설정
			FSpawnParam spawnParam;
			spawnParam.Location = GetActorLocation();
			spawnParam.Rotation = GetActorRotation();
			spawnParam.CallBackSpawn = nullptr;

			//몬스터 생성
			int32 id = FObjectManager::GetInstance()->CreateActor<ACharacterNPC>(classInfo, spawnParam);

			//몬스터 생성 검증
			if(!FObjectManager::IsValidId(id))
				LOG_SCREEN(FColor::Red, TEXT("스포너: %s에서 몬스터를 생성하지 못했습니다."), *SpawnerName)
			else
				SpawnMonsterId.Add(id);

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
// 스플라인 영역 안의 랜덤 위치값을 RandomLocation 에 담습니다.
// =============================================================
void ASpawnArea::GetRandomLocation()
{
	double minX = MAX_dbl, minY = MAX_dbl, maxX = MIN_dbl, maxY = MIN_dbl, maxZ = MIN_dbl;
	for(const FVector& point : PolygonPoints)
	{
		minX = minX > point.X ? point.X : minX;
		minY = minY > point.Y ? point.Y : minY;
		maxX = maxX < point.X ? point.X : maxX;
		maxY = maxY < point.Y ? point.Y : maxY;
		maxZ = maxZ < point.Z ? point.Z : maxZ;
	}
	
	for(double x = minX; x < maxX; x += DistanceDifference)
	{
		for(double y = minY; y < maxY; y += DistanceDifference)
		{
			if(!IsInPolygon(x, y))
				continue;
			FVector location = MakeRandomLocation(FVector(x, y, PolygonPoints[0].Z), DistanceDifference);
			if(!IsInPolygon(location.X, location.Y))
				continue;
			location.Z = UtilCollision::GetZTrace(location, -1).Location.Z;
			RandomLocation.Add(location);
		}
	}
}

// =============================================================
// 스플라인 내부에 점이 위치하는지 확인합니다. // Point in polygon algorithm
// =============================================================
bool ASpawnArea::IsInPolygon(double InX, double InY)
{
	int cn = 0;
	for(int i = 0; i < PolygonPoints.Num(); ++i)
	{
		int j = (i + 1) % PolygonPoints.Num();
		if((PolygonPoints[i].Y > InY) != (PolygonPoints[j].Y > InY))
		{
			double vt = (PolygonPoints[j].X - PolygonPoints[i].X) * (InY - PolygonPoints[i].Y)
						/ (PolygonPoints[j].Y - PolygonPoints[i].Y)
						+ PolygonPoints[i].X;
			if(InX < vt)
				++cn;
		}
	}

	return cn % 2 != 0;
}

// =============================================================
// 거리가 InRange인 랜덤 위치값을 반환합니다.
// =============================================================
FVector ASpawnArea::MakeRandomLocation(const FVector& InLocation, double InRange)
{
	double x = FMath::RandRange(-1.0, 1.0);
	double y = FMath::RandRange(-1.0, 1.0);

	FVector direction = FVector(x, y, 0.0);

	return InLocation + (direction.Normalize() * InRange);
}