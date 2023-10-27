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

	bool bDrawSupport = false;
	
protected:
	// 생성자
	USkillSpawnTurret();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	virtual void SkillStarted() override;

private:
	// 스폰 위치를 시각적으로 보여줍니다. // 현재는 DrawDebug로 했습니다.
	// 나중에 이펙트로 치환하거나, 스폰할 액터의 메쉬정보를 받아와서 활용하면 될 것 같습니다.
	void DrawSupport();
};
