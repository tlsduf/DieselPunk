// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSoldierQ.generated.h"

/**
 *
 */
class AProjectileBase;

UCLASS()
class DIESELPUNK_API USkillSoldierQ : public UPlayerSkill
{
	GENERATED_BODY()

private:
	FTimerHandle PlaySkillTHandle;
	
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY()
	AProjectileBase *Projectile1;

	UPROPERTY()
	AProjectileBase *Projectile2;

	UPROPERTY()
	AProjectileBase *Projectile3;
	
	UPROPERTY()
	AProjectileBase *Projectile4;
	
public:
	// 생성자
	USkillSoldierQ();

	void Shot();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void SkillTriggered() override;


};
