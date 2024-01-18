// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSelectInstallation.generated.h"

/**
 *
 */

class ACharacterNPC;

UCLASS()
class DIESELPUNK_API USkillSelectInstallation : public UPlayerSkill
{
	GENERATED_BODY()
protected:
	// 생성자
	USkillSelectInstallation();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	virtual void SkillTriggered() override;
};
