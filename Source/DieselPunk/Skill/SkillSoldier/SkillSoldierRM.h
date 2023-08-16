// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include <CoreMinimal.h>
#include "SkillSoldierRM.generated.h"

/**
 *
 */

class AProjectileGranade;

UCLASS()
class DIESELPUNK_API USkillSoldierRM : public UPlayerSkill
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly, Category = "MyCustomCategory")
	TSubclassOf<AProjectileGranade> ProjectileGranadeClass;

	UPROPERTY()
	AProjectileGranade *ProjectileGranade;
	
public:
	// 생성자
	USkillSoldierRM();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void SkillStarted() override;
	virtual void SkillCompleted() override;

private:
	bool IsZoom = false;
};
