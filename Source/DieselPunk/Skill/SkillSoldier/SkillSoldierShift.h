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
	virtual void SkillCompleted() override;

private:
	bool IsDash = false;				// 대쉬중이면 true
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float DashingTime = 0.1f;			// 해당 시간 동안 대쉬유지
	
	bool CanDash = true;				// 대쉬 가능한 상태인가

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float DashDistance = 10000.f;		// 대쉬 거리

	FTimerHandle PlaySkillTHandle;
	FTimerHandle DashTHandle;

	void StartDash();
	void StopDashing();
	void ResetDash();
};
