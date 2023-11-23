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
	UPROPERTY(EditDefaultsOnly, Category = "MYDP_Setting")
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "MYDP_Setting")
	TSubclassOf<AProjectileBase> ProjectileEBuffClass;
	
	UPROPERTY()
	AProjectileBase *Projectile;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	UParticleSystem *MuzzleParticles;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	UParticleSystem *MuzzleParticlesSpecial;
public:

	bool EBuffOn = false;		//SkillE 활성화상태
	int8 Magazine = 5;			//SkillE 탄창 수
	float TempCoolTime;			//E버프 쿨타임 롤백용 
	
	// 생성자
	USkillSoldierLM();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;
	
};
