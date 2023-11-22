// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "../PlayerSkill.h"
#include "SkillSoldierShift.generated.h"


UCLASS()
class DIESELPUNK_API USkillSoldierShift : public UPlayerSkill
{
	GENERATED_BODY()

public:
	// 생성자
	USkillSoldierShift();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;

private:
	FTimerHandle PlaySkillTHandle;
	
	bool IsDash = false;
	UPROPERTY(EditAnywhere, Category = "MYDP")
	float DashingTime = 0.1f;
	
	bool CanDash = true;

	UPROPERTY(EditAnywhere, Category = "MYDP")
	float DashDistance = 10000.f;

	UPROPERTY(EditAnywhere, Category = "MYDP")
	UParticleSystem *DashEffect;

	FTimerHandle DashTHandle;

	void StopDashing();
	void ResetDash();
};
