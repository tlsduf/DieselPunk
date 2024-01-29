// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterHousing.h"
#include "CharacterTurret.generated.h"

class UHousingActorComponent;
class UMeshComponent;
class UMaterialInterface;
class UBoxComponent;

UCLASS()
class DIESELPUNK_API ACharacterTurret : public ACharacterHousing
{
	GENERATED_BODY()
	
public:
	ACharacterTurret();

	virtual void Tick(float DeltaTime) override;

	virtual void RunAi() override;

	// 터렛의 조건에 따라 타겟을 결정합니다.
	void SetTurretTarget();

	// inLocation이 유효 범위 안에 있으면 True 반환
	bool InValidArea(FVector inLocation);

protected:
	virtual void BeginPlay() override;
	
	// Called before destroying the object.
	virtual void BeginDestroy() override;
};
