// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerSkill.h"
#include "SkillSoldierRM.generated.h"

/**
 *
 */

class AProjectileBase;

UCLASS()
class DIESELPUNK_API USkillSoldierRM : public UPlayerSkill
{
	GENERATED_BODY()
private:
	FTimerHandle PlaySkillTHandle;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	TSubclassOf<AProjectileBase> ProjectileClass;
	
public:
	// 생성자
	USkillSoldierRM();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void SkillTriggered() override;

	// 스킬을 재생합니다. 보통 애니메이션 재생을 다룹니다.
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	// 스킬을 발동합니다. 보통 발사체 생성 및 데미지 처리를 다룹니다.
	virtual void AbilityShot(AActor* InTarget = nullptr) override;
	
private:
	bool IsZoom = false;

};
