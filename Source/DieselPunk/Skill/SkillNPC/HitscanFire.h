// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "HitscanFire.generated.h"


class AHitscanBase;


UCLASS()
class DIESELPUNK_API UHitscanFire : public USkillBase
{
	GENERATED_BODY()

	UHitscanFire();
	
public:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
private:

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float AttackRange = 10000;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Util")
	bool DebugOnOff = true;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	UParticleSystem *HitParticles;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	FEffectTransform HitEffectFTransform = FEffectTransform();
	
public:
	virtual void AbilityStart() override;
};
