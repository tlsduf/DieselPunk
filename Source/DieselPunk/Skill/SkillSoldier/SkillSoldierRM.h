// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include <CoreMinimal.h>
#include "SkillSoldierRM.generated.h"

/**
 *
 */



UCLASS()
class DIESELPUNK_API USkillSoldierRM : public UPlayerSkill
{
	GENERATED_BODY()

public:
	// 생성자
	USkillSoldierRM();

protected:
	virtual void BeginPlay() override;
	//줌인
	void ZoomIn();
	//줌아웃
	void ZoomOut();
	
public:
	virtual void SkillStarted() override;
	virtual void SkillCompleted() override;

private:
	bool IsZoom = false;
};
