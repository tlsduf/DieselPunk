// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterSpawnerForTest.h"

#include "../Manager/DatatableManager.h"
#include "../Data/CharacterDataTable.h"
#include "../Manager/ObjectManager.h"
#include "../Character/CharacterNPC.h"

// Sets default values
AMonsterSpawnerForTest::AMonsterSpawnerForTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterSpawnerForTest::BeginPlay()
{
	Super::BeginPlay();
	const FCharacterDataTable* dataTable = FDataTableManager::GetInstance()->GetData<FCharacterDataTable>(EDataTableType::Character, SpawnMonsterName);
	if(!dataTable)
	{
		LOG_SCREEN(FColor::Red, TEXT("%s에 해당하는 데이터테이블 정보가 존재하지 않습니다."), *SpawnMonsterName)
		return;
	}
	MonsterUClass = LoadClass<ACharacterNPC>( NULL, *UtilPath::GetCharacterBlueprintPath(*dataTable->BluePrintPath));
}

// Called every frame
void AMonsterSpawnerForTest::Tick(float InDeltaTime)
{
	Super::Tick(InDeltaTime);
	if(!MonsterUClass)
		return;

	if(!Monster.IsValid())
	{
		DeltaTime += InDeltaTime;
		if(DeltaTime >= Frequency)
		{
			FSpawnParam spawnParam;
			spawnParam.Location = GetActorLocation();
			spawnParam.Rotation = GetActorRotation();
			spawnParam.CallBackSpawn = nullptr;
			
			int32 id = FObjectManager::GetInstance()->CreateActor<ACharacterNPC>(MonsterUClass, spawnParam);
			Monster = Cast<ACharacterNPC>(FObjectManager::GetInstance()->FindActor(id));
			DeltaTime = 0.f;
		}
	}
}

