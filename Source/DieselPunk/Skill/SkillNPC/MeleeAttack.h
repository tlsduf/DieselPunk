// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "MeleeAttack.generated.h"

/**
 *
 */
class AApplyRadialDamage;
class ACharacterNPC;

UCLASS()
class DIESELPUNK_API UMeleeAttack : public USkillBase
{
	GENERATED_BODY()

	// 소유한 액터의 위치와 캡슐이 스윕을 시작하는 위치 사이의 거리
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float AttackStartPoint = 50.f;

	// 스윕이 시작하는 위치와 스윕이 끝나는 위치 사이의 거리
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float AttackRange = 150.f;

	// 캡슐의 반지름
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float AttackRadius = 50.f;

public:
	UMeleeAttack();
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	virtual void AbilityShot(AActor* InTarget = nullptr) override;
};
