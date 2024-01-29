// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSoldierQ.generated.h"

/**
 *
 */
class AProjectileBase;

UCLASS()
class DIESELPUNK_API USkillSoldierQ : public UPlayerSkill
{
	GENERATED_BODY()

private:
	FTimerHandle PlaySkillTHandle;
	
	UPROPERTY(EditDefaultsOnly, Category = "MYDP_Setting")
	TSubclassOf<AProjectileBase> ProjectileClass;

public:
	// 생성자
	USkillSoldierQ();

	// 몽타주에서 실행합니다.
	void Shot();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void SkillTriggered() override;


};
