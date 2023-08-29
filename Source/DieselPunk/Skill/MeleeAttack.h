// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerSkill.h"
#include "MeleeAttack.generated.h"

/**
 *
 */
class AApplyRadialDamage;
class ACharacterNPC;

UCLASS()
class DIESELPUNK_API UMeleeAttack : public UPlayerSkill
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

private:

	// 소유한 액터의 위치와 캡슐이 스윕을 시작하는 위치 사이의 거리
	UPROPERTY(EditAnywhere, Category = Melee)
	float AttackStartPoint = 50.f;

	// 스윕이 시작하는 위치와 스윕이 끝나는 위치 사이의 거리
	UPROPERTY(EditAnywhere, Category = Melee)
	float AttackRange = 150.f;

	// 캡슐의 반지름
	UPROPERTY(EditAnywhere, Category = Melee)
	float AttackRadius = 50.f;

	UPROPERTY(EditAnywhere, Category = Melee)
	float Damage = 10.f;

	UPROPERTY(EditAnywhere, Category = Debug)
	bool DebugOnOff = true;

public:
	virtual void SkillTriggered() override;

	float Attack();
	
	void _Attack();
};
