// Fill out your copyright notice in the Description page of Project Settings.


#include "DpCheatManager.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/DatatableManager.h"
#include "../Data/CharacterDataTable.h"
#include "../Character/CharacterNPC.h"
#include "../Actor/MonsterSpawner.h"
#include "DieselPunk/Character/CharacterHousing.h"

//액터를 플레이어 앞에 스폰합니다.
void UDpCheatManager::SpawnActor(const FString& InCharacterName)
{
	const FCharacterDataTable* dataTable = FDataTableManager::GetInstance()->GetData<FCharacterDataTable>(EDataTableType::Character, InCharacterName);

	if(!dataTable)
	{
		LOG_SCREEN(FColor::Red, TEXT("void UDpCheatManager::SpawnActor(const FString& InCharacterName)의 인자 InCharacterName: %s에 해당하는 데이터를 찾을 수 없습니다."), *InCharacterName)
		return;
	}
	
	UClass* classInfo = LoadClass<ACharacterNPC>(NULL, *UtilPath::GetCharacterBlueprintPath(*dataTable->BluePrintPath));

	if(!classInfo)
		return;

	FSpawnParam param;

	ACharacterPC* player = FObjectManager::GetInstance()->GetPlayer();
	
	param.Location = player->GetActorLocation() + player->GetActorForwardVector() * 1000.f;
	param.Rotation = FRotator(0.0, 0.0, 0.0);
	param.CallBackSpawn = nullptr;
	
	int32 objectId = FObjectManager::GetInstance()->CreateActor<ACharacterNPC>(classInfo, param);

	LOG_SCREEN(FColor::White, TEXT("몬스터가 생성되었습니다. ID : %d"), objectId);
}

//오브젝트 ID의 액터를 삭제합니다.
void UDpCheatManager::DestroyActor(int32 InObjectId)
{
	FObjectManager::GetInstance()->DestroyActor(InObjectId);
}

//SpawnArea를 활성화합니다.
void UDpCheatManager::StartSpawn(const FString& InCharacterName)
{
	int32 spawnerID = FObjectManager::GetInstance()->FindActorByPredicate([](AActor* InActor)
	{
		if(Cast<AMonsterSpawner>(InActor))
			return true;
		return false;
	});
	AMonsterSpawner* monsterSpawner = Cast<AMonsterSpawner>(FObjectManager::GetInstance()->FindActor(spawnerID));
	if(monsterSpawner)
		monsterSpawner->StartSpawn(InCharacterName);
}

//Player를 죽입니다.
void UDpCheatManager::Kill_PC()
{
	ACharacterPC* player = FObjectManager::GetInstance()->GetPlayer();
	player->ChangeStat(ECharacterStatType::Hp, -player->GetStat(ECharacterStatType::Hp));
}

// 모든 터렛의 Debug를 킴
void UDpCheatManager::DebugOn_Turret()
{
	TArray<int32> turretIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(turretIDs, [](AActor* InActor)
	{
		if(auto turret = Cast<ACharacterHousing>(InActor))
			if(turret->GetCharacterType() == ECharacterType::Turret || turret->GetStat(ECharacterStatType::Hp) > 0)
				return true;
		return false;
	});
	for(const int32& ID : turretIDs)
		Cast<ACharacterHousing>(FObjectManager::GetInstance()->FindActor(ID))->SetDebugOnOff(true);
}

// 모든 터렛의 Debug를 끔
void UDpCheatManager::DebugOff_Turret()
{
	TArray<int32> turretIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(turretIDs, [](AActor* InActor)
	{
		if(auto turret = Cast<ACharacterHousing>(InActor))
			if(turret->GetCharacterType() == ECharacterType::Turret || turret->GetStat(ECharacterStatType::Hp) > 0)
				return true;
		return false;
	});
	for(const int32& ID : turretIDs)
		Cast<ACharacterHousing>(FObjectManager::GetInstance()->FindActor(ID))->SetDebugOnOff(false);
}

// 모든 몬스터의 Debug를 킴
void UDpCheatManager::DebugOn_Monster()
{
	TArray<int32> monstersIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(monstersIDs, [](AActor* InActor)
	{
		if(auto npc = Cast<ACharacterNPC>(InActor))
			if(npc->GetCharacterType() == ECharacterType::Monster || npc->GetStat(ECharacterStatType::Hp) > 0)
				return true;
		return false;
	});
	for(const int32& ID : monstersIDs)
		Cast<ACharacterNPC>(FObjectManager::GetInstance()->FindActor(ID))->SetDebugOnOff(true);
}

// 모든 몬스터의 Debug를 끔
void UDpCheatManager::DebugOff_Monster()
{
	TArray<int32> monstersIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(monstersIDs, [](AActor* InActor)
	{
		if(auto npc = Cast<ACharacterNPC>(InActor))
			if(npc->GetCharacterType() == ECharacterType::Monster || npc->GetStat(ECharacterStatType::Hp) > 0)
				return true;
		return false;
	});
	for(const int32& ID : monstersIDs)
		Cast<ACharacterNPC>(FObjectManager::GetInstance()->FindActor(ID))->SetDebugOnOff(false);
}