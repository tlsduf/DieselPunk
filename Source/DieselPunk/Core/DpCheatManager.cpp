// Fill out your copyright notice in the Description page of Project Settings.


#include "DpCheatManager.h"
#include "../Manager/ObjectManager.h"
#include "../Character/CharacterNPC.h"

//몬스터를 플레이어 앞에 스폰합니다.
void UDpCheatManager::SpawnMonster()
{
	FString resourcePath = TEXT("/Script/Engine.Blueprint'/Game/DieselPunk/Blueprints/Characters/BP_CharacterNPC_Small.BP_CharacterNPC_Small_C'");
	UClass* classInfo = LoadClass<ACharacterNPC>(NULL, *resourcePath);

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
