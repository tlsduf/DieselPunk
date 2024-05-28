// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "ParabolaAttack.generated.h"

/**
 *
 */

class AParabolaBase;

UCLASS()
class DIESELPUNK_API UParabolaAttack : public USkillBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting")
	TSubclassOf<AParabolaBase> ParabolaBaseClass;
	
public:
	// 생성자
	UParabolaAttack();

protected:
	virtual void BeginPlay() override;

public:
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	virtual void AbilityShot(AActor* InTarget = nullptr) override;
};
