// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "ProjectileAttack.generated.h"

/**
 *
 */
class AProjectileBase;


UCLASS()
class DIESELPUNK_API UProjectileAttack : public USkillBase
{
	GENERATED_BODY()

public:
	// 생성자
	UProjectileAttack();

protected:
	virtual void BeginPlay() override;

public:
	virtual void AbilityStart() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "MYDP")
	TSubclassOf<AProjectileBase> ProjectileBaseClass;

	UPROPERTY()
	AProjectileBase *ProjectileBase;
};
