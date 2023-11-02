// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "EnemyAIController.generated.h"


UCLASS()
class DIESELPUNK_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	static const FName TargetKey;		//블랙보드에 등록된 변수를 지칭합니다.
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree *AIBehavior;

	UPROPERTY(EditAnywhere)
	float SpawnTime = 1.0f;

	FTimerHandle SpawnAnimTHandle;
	
	bool GPlaySpawnAnim = false;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool IsDead() const;
	bool PlaySpawnAnim();
	void SetTruePlaySpawnAnim();

	//Ai를 실행합니다.
	void RunAi(APawn* InPawn, bool InForced = false);
	
};
