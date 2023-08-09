// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include <CoreMinimal.h>
#include "SkillSoldierQ.generated.h"

/**
 *
 */
class AProjectileGranade;

UCLASS()
class DIESELPUNK_API USkillSoldierQ : public UPlayerSkill
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileGranade> ProjectileGranadeClass;

	UPROPERTY()
	AProjectileGranade *ProjectileGranade;

	FTimerHandle ZoomTHandle;
public:
	// 생성자
	USkillSoldierQ();

	void Shot();

protected:
	virtual void BeginPlay() override;

	
public:
	virtual void SkillTriggered() override;


};
