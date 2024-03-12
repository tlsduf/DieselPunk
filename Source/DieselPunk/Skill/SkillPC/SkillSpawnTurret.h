// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSpawnTurret.generated.h"

/**
 *
 */

class ACharacterNPC;

UCLASS()
class DIESELPUNK_API USkillSpawnTurret : public UPlayerSkill
{
	GENERATED_BODY()

private:
	bool bTaskOn = false;
	bool ExpectedUnBind = false;

	//컨트롤하는 터렛 Id
	int32 ControlTurretId = -1;
	
protected:
	// 생성자
	USkillSpawnTurret();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void SkillStarted() override;
	
	virtual void SkillCompleted() override;
public:
	void SpawnCancel();

	bool IsExpectedUnBind(){return ExpectedUnBind;}
};
