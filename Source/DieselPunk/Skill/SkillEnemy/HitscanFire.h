// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "HitscanFire.generated.h"


class AHitscanBase;


UCLASS()
class DIESELPUNK_API UHitscanFire : public USkillBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
private:

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float AttackRange = 10000;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float Damage = 10.f;

	UPROPERTY(EditAnywhere, Category = "MYDP_Util")
	bool DebugOnOff = true;

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	UParticleSystem *HitParticles;

public:
	virtual void AbilityStart() override;
};
