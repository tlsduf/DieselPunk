// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SkillActor.generated.h"

class ACharacterBase;

UCLASS()
class DIESELPUNK_API ASkillActor : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	ACharacterBase* OwnerCharacter = nullptr;	// 소유자
	
	UPROPERTY()
	AController* OwnerController = nullptr;		// 소유 컨트롤러
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Location")
	FTransform OffsetTransform = FTransform::Identity;	// 초기 트랜스폼 오프셋
	
public:
	// Sets default values for this actor's properties
	ASkillActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// 설정한 OffsetTransform만큼 이동하여 초기 위치를 설정합니다.
	virtual void InitTransformOffset();
};
