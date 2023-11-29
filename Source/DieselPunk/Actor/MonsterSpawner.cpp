// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterSpawner.h"
#include "../Manager/DatatableManager.h"
#include "../Data/MonsterSpawnerDataTable.h"
#include "../Data/CharacterDataTable.h"
#include "../Character/CharacterNPC.h"
#include "../Manager/ObjectManager.h"

// Sets default values
AMonsterSpawner::AMonsterSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterSpawner::BeginPlay()
{
	Super::BeginPlay();

	//몬스터 스폰정보 등록
	const FMonsterSpawnerDataTable* monsterSpawnerDataTable = FDataTableManager::GetInstance()->GetData<FMonsterSpawnerDataTable>(EDataTableType::MonsterSpawner, SpawnerName);
	if(monsterSpawnerDataTable == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("몬스터 스포너: %s의 변수 SpawnerName: %s에 해당하는 데이터가 없습니다. SpawnerName 데이터 테이블에 맞게 설정해주세요"), *GetName(), *SpawnerName)
		return;
	}
	
	for(const FMonsterSpawnInfo& spawnInfo : monsterSpawnerDataTable->MonsterSpawnerInfo)
	{
		//info 정보 획득
		FSpawnInfo info;
		info.MonsterName = spawnInfo.MonsterName;
		info.DelayTime = spawnInfo.DelayTime;

		//BP경로 획득
		const FCharacterDataTable* characterDataTable = FDataTableManager::GetInstance()->GetData<FCharacterDataTable>(EDataTableType::Character, spawnInfo.MonsterName);
		if(characterDataTable == nullptr)
		{
			LOG_SCREEN(FColor::Red, TEXT("스포너: %s의 DT_SpawnerDataTable에 설정된 MonsterName: %s에 해당하는 데이터를 DT_Character에서 찾을 수 없습니다."), *SpawnerName, *spawnInfo.MonsterName)
			continue;
		}
		info.BpPath = UtilPath::GetCharacterBlueprintPath(*characterDataTable->BluePrintPath);

		//정보 추가
		SpawnInfo.Add(info);
	}

	//스폰 지연시간에 따라 정렬
	SpawnInfo.Sort([](const FSpawnInfo& lhs, const FSpawnInfo& rhs)
	{
		return lhs.DelayTime < rhs.DelayTime; 
	});
}

// Called every frame
void AMonsterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpawnerDeltaTime += DeltaTime;

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
		TArray<FSpawnInfo>::TIterator iterSpawnInfo{ SpawnInfo.CreateIterator() };

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
}

