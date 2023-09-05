// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSoldierLM.generated.h"

class UInputTrigger;
class AProjectileBase;
class UNiagaraSystem;

UCLASS()
class DIESELPUNK_API USkillSoldierLM : public UPlayerSkill
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileBase> ProjectileEBuffClass;
	
	UPROPERTY()
	AProjectileBase *Projectile;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	UParticleSystem *MuzzleParticles;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	UParticleSystem *MuzzleParticlesSpecial;
public:

	bool EBuffOn = false;		//임시 구현 SkillE
	int8 Magazine = 20;			//임시 구현 SkillE 탄창 수
	
	// 생성자
	USkillSoldierLM();

	void UpdateSetting();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;

};
