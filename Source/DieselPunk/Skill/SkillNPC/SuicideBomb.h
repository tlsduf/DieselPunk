// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "SuicideBomb.generated.h"

/**
 *
 */

UCLASS()
class DIESELPUNK_API USuicideBomb : public USkillBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="MYDP_Collision")
	double Radius = 1000.0;
	
public:
	// 생성자
	USuicideBomb();

protected:
	virtual void BeginPlay() override;

public:
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	virtual void AbilityShot(double InDamageCoefficient, AActor* InTarget = nullptr) override;
};
