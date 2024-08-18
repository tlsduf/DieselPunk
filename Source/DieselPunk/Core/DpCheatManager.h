// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CheatManager.h"
#include "DpCheatManager.generated.h"

/**
 * 개발 편리를 위한 치트매니저 입니다.
 */
UCLASS()
class DIESELPUNK_API UDpCheatManager : public UCheatManager
{
	GENERATED_BODY()

	//액터를 플레이어 앞에 스폰합니다.
	UFUNCTION(exec)
	void SpawnActor(const FString& InCharacterName);

	//오브젝트 ID의 액터를 삭제합니다.
	UFUNCTION(exec)
	void DestroyActor(int32 InObjectId);
	
	//MonsterSpawner 활성화합니다.
	UFUNCTION(exec)
	void StartSpawn(const FString& InCharacterName);

	//Player를 죽입니다.
	UFUNCTION(exec)
	void Kill_PC();
};

