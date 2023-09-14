// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSoldierE.generated.h"

/**
 *
 */


UCLASS()
class DIESELPUNK_API USkillSoldierE : public UPlayerSkill
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	UParticleSystem *BuffEffect;
public:
	// 생성자
	USkillSoldierE();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;

private:
};
