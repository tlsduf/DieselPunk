// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include <CoreMinimal.h>
#include "SkillSoldierE.generated.h"

/**
 *
 */


UCLASS()
class DIESELPUNK_API USkillSoldierE : public UPlayerSkill
{
	GENERATED_BODY()

	FTimerHandle ZoomTHandle;
public:
	// 생성자
	USkillSoldierE();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SkillTriggered() override;

private:

};
