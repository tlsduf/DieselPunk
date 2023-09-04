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
	// 생성자
	USkillSoldierR();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;

private:
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	float EDamage = 50;
	
	bool IsE = false;
	bool CanE = true;
	bool InCooldownE = false;
	
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	float ECooldownTime = 5.f;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	UParticleSystem *PinPointHitEffect;
	
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY()
	AProjectileBase *Projectile;

	FHitResult GetUnderCursorLocation();
};
