// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include <CoreMinimal.h>
#include "SkillGunnerR.generated.h"

/**
 *
 */
class AProjectileBase;


UCLASS()
class DIESELPUNK_API USkillGunnerR : public UPlayerSkill
{
	GENERATED_BODY()

public:
	// 생성자
	USkillGunnerR();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileBase> ProjectileGranadeClass;

	UPROPERTY()
	AProjectileBase *ProjectileGranade;
};
