// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "MokoshMeleeAttack.generated.h"

USTRUCT()
struct FRectangleRangeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FVector BoxExtend = FVector::ZeroVector;
};

USTRUCT()
struct FArcRangeInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, meta=(ClampMin = 0.f, ClampMax = 180.f))
	float Angle = 0.f;
};

/**
 *
 */

class UNiagaraSystem;

UCLASS()
class DIESELPUNK_API UMokoshMeleeAttack : public USkillBase
{
	GENERATED_BODY()

	//스킬 타격 범위
	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	ESearchAreaType	SkillHittingRange = ESearchAreaType::Rectangle;

	UPROPERTY(EditAnywhere, Category = "MYDP_Skill", meta=(EditCondition="SkillHittingRange == ESearchAreaType::Rectangle"))
	FRectangleRangeInfo RectangleRangeInfo;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Skill", meta=(EditCondition="SkillHittingRange == ESearchAreaType::Arc"))
	FArcRangeInfo ArcRangeInfo;

	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	bool RadialImpulse = false;

	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	float RadialImpulseStrength = 100.f;

	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	TArray<FName> Buffs;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	UNiagaraSystem *N_ShotEffect;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	UParticleSystem *ShotEffect;

	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	FEffectTransform ShotEffectTransform = FEffectTransform();
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	UNiagaraSystem *N_HitEffect;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	UParticleSystem *HitEffect;

	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	FEffectTransform HitEffectFTransform = FEffectTransform();
	
public:
	// 생성자
	UMokoshMeleeAttack();

protected:
	virtual void BeginPlay() override;

public:
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	virtual void AbilityShot(AActor* InTarget = nullptr) override;
};
