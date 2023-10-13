// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "ProjectileAttack.generated.h"

/**
 *
 */
class AProjectileBase;


UCLASS()
class DIESELPUNK_API UProjectileAttack : public UPlayerSkill
{
	GENERATED_BODY()

public:
	// 생성자
	UProjectileAttack();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;

private:
	FVector ShotLocation;
	FRotator ShotRotation;
	
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileBase> ProjectileBaseClass;

	UPROPERTY()
	AProjectileBase *ProjectileBase;
};
