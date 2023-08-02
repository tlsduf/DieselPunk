// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include <CoreMinimal.h>
#include "SkillGunnerLM.generated.h"

/**
 *
 */
class AProjectileGranade;
class UNiagaraSystem;

UCLASS()
class DIESELPUNK_API USkillGunnerLM : public UPlayerSkill
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileGranade> ProjectileGranadeClass;

	UPROPERTY()
	AProjectileGranade *ProjectileGranade;

	bool ToggleVar = true;
	
public:
	// 생성자
	USkillGunnerLM();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;

};
