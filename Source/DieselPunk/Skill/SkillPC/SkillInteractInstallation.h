// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillInteractInstallation.generated.h"

/**
 *
 */

class ACharacterHousing;

UCLASS()
class DIESELPUNK_API USkillInteractInstallation : public UPlayerSkill
{
	GENERATED_BODY()

	TWeakObjectPtr<ACharacterHousing> InteractiveInstallation;
	float Distance;
	bool IsValid;

	static constexpr float InteractiveRange = 2000.f;
protected:
	// 생성자
	USkillInteractInstallation();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void SkillStarted() override;
	virtual void SkillOngoing() override;
	virtual void SkillTriggered() override;
	virtual void SkillCanceled() override;

	bool CheckInteractive(FHitResult& InHitResult, int32 InRange, TArray<const AActor*> InIgnoreActor);
};
