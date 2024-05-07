// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "HitscanFire.generated.h"


class AHitscanBase;


UCLASS()
class DIESELPUNK_API UHitscanFire : public USkillBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float AttackRange = 10000;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Util")
	bool DebugOnOff = true;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	UParticleSystem *HitParticles;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	FEffectTransform HitEffectFTransform = FEffectTransform();

public:
	UHitscanFire();
	
protected:
	virtual void BeginPlay() override;
	
public:
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	virtual void AbilityShot(AActor* InTarget = nullptr) override;
};
