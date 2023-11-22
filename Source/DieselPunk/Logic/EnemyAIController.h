// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "EnemyAIController.generated.h"


UCLASS()
class DIESELPUNK_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

private:
	// 비헤비어 트리
	UPROPERTY(EditAnywhere)
	UBehaviorTree *AIBehavior;

	// SpawnTime 동안 Spawn 로직을 비헤비어 트리에서 실행
	UPROPERTY(EditAnywhere)
	float SpawnTime = 1.0f;

	FTimerHandle SpawnAnimTHandle;

public:
	bool bPlaySpawnAnim = true;			//BTService 에서 활용

	static const FName TargetKey;		//블랙보드에 등록된 변수를 지칭합니다.
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Ai를 실행합니다.
	void RunAi(APawn* InPawn, bool InForced = false);
};
