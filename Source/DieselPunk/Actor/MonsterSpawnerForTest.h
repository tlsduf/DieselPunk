// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterSpawnerForTest.generated.h"

class ACharacterNPC;

UCLASS()
class DIESELPUNK_API AMonsterSpawnerForTest : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditInstanceOnly)
	FString SpawnMonsterName = TEXT("");

	UPROPERTY(EditInstanceOnly)
	float Frequency = 2.f;
	
	TWeakObjectPtr<ACharacterNPC> Monster;

	float DeltaTime = 0.f;

	UClass* MonsterUClass = nullptr;
	
public:	
	// Sets default values for this actor's properties
	AMonsterSpawnerForTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;

};
