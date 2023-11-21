// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSoldierR.generated.h"

/**
 *
 */
class AProjectileBase;


UCLASS()
class DIESELPUNK_API USkillSoldierR : public UPlayerSkill
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "MYDP")
	float EDamage = 50;
	
	bool IsE = false;
	bool InCooldownE = false;
	
	UPROPERTY(EditAnywhere, Category = "MYDP")
	float ECooldownTime = 5.f;

	UPROPERTY(EditAnywhere, Category = "MYDP")
	UParticleSystem *PinPointHitEffect;
	
	UPROPERTY(EditDefaultsOnly, Category = "MYDP")
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY()
	AProjectileBase *Projectile;
	
public:
	// 생성자
	USkillSoldierR();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;
	
	void AfterLogic();

};
