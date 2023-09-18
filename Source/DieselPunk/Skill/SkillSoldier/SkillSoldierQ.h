// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSoldierQ.generated.h"

/**
 *
 */
class ASoldierProjectile;

UCLASS()
class DIESELPUNK_API USkillSoldierQ : public UPlayerSkill
{
	GENERATED_BODY()

private:
	FTimerHandle PlaySkillTHandle;
	
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<ASoldierProjectile> ProjectileClass;

	UPROPERTY()
	ASoldierProjectile *Projectile1;

	UPROPERTY()
	ASoldierProjectile *Projectile2;

	UPROPERTY()
	ASoldierProjectile *Projectile3;
	
	UPROPERTY()
	ASoldierProjectile *Projectile4;
	
public:
	// 생성자
	USkillSoldierQ();

	void Shot();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void SkillTriggered() override;


};
