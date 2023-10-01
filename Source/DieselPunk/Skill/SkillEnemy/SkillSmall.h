// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSmall.generated.h"

/**
 *
 */
class AProjectileBase;


UCLASS()
class DIESELPUNK_API USkillSmall : public UPlayerSkill
{
	GENERATED_BODY()

public:
	// 생성자
	USkillSmall();

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
	AProjectileBase *ProjectileBase1;
	UPROPERTY()
	AProjectileBase *ProjectileBase2;
	UPROPERTY()
	AProjectileBase *ProjectileBase3;
	UPROPERTY()
	AProjectileBase *ProjectileBase4;

	FTimerHandle FireHandle2;
	FTimerHandle FireHandle3;
	FTimerHandle FireHandle4;
};
