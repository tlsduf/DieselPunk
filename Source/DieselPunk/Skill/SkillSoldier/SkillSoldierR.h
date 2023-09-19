// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSoldierR.generated.h"

/**
 *
 */
class ASoldierProjectile;


UCLASS()
class DIESELPUNK_API USkillSoldierR : public UPlayerSkill
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	float EDamage = 50;
	
	bool IsE = false;
	bool InCooldownE = false;
	
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	float ECooldownTime = 5.f;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	UParticleSystem *PinPointHitEffect;
	
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<ASoldierProjectile> ProjectileClass;

	UPROPERTY()
	ASoldierProjectile *Projectile;
	
public:
	// 생성자
	USkillSoldierR();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;
	
	void AfterLogic();

};
