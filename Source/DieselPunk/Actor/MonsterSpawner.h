// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <GameFramework/Actor.h>
#include "MonsterSpawner.generated.h"

struct FMonsterSpawnInfo;
struct FSpawnInfo
{
	FString MonsterName = TEXT("");	//스폰할 몬스터의 이름입니다. DT_Character와 행 이름이 동일해야합니다.
	float DelayTime = 0.f;			//지연시간입니다. 게임이 시작한 후 지연 시간만큼 흐른 뒤 해당 몬스터를 스폰합니다.
	FString BpPath = TEXT("");		//스폰할 몬스터의 Blueprint 경로입니다.
};

//몬스터가 스폰시킬 액터입니다.
UCLASS()
class DIESELPUNK_API AMonsterSpawner : public AActor
{
	GENERATED_BODY()

	//스포너 이름
	UPROPERTY(EditInstanceOnly)
	FString SpawnerName = TEXT("");

	//스폰 몬스터 정보
	TArray<FSpawnInfo> SpawnInfo;

	//누적 시간
	float SpawnerDeltaTime = 0.f;

	//스폰한 몬스터 IDs
	TArray<int32> SpawnMonsterId;
	
public:	
	// Sets default values for this actor's properties
	AMonsterSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
