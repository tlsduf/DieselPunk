// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimInstance.h"
#include "DPAnimInstance.generated.h"


class ACharacterBase;

constexpr int LeanIntensityScaling = 7.0f;

UCLASS()
class DIESELPUNK_API UDPAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	// 빙의 된 플레이어 캐릭터
	TWeakObjectPtr<ACharacterBase> Character;
	
	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	bool IsInAir = false;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	FVector Velocity = FVector::ZeroVector;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	FRotator ActorRotation = FRotator::ZeroRotator;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	FRotator BaseAimRotation = FRotator::ZeroRotator;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	FRotator DeltaRotation = FRotator::ZeroRotator;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	FRotator CharacterDirectionRotation = FRotator::ZeroRotator;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	float Speed = 0;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	float HorizontalSpeed = 0;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	float YawDelta = 0;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Movement", Meta = (AllowPrivateAccess = true))
	bool IsAccelerating = false;
	

	UPROPERTY(BlueprintReadOnly, Category = "MYDP_State", Meta = (AllowPrivateAccess = true))
	bool InCombat = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "MYDP_State", Meta = (AllowPrivateAccess = true))
	bool IsDead = false;

	FRotator RotationLastTick = FRotator();
	
	UPROPERTY(BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	bool OnRail = false;
	
	// 터렛 공격 애니메이션 노드 조건
	UPROPERTY(BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	EAbilityType UseSkillType = EAbilityType::None;

	UPROPERTY(BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	float AnimSpeed = 1.f;

	FTimerHandle AttackTHandle;
	
public:
	// 생성자
	UDPAnimInstance();
	// 비긴플레이
	virtual void NativeBeginPlay() override;
	// 틱마다 호출되는 함수, 스피드를 계산한다.
	virtual void NativeUpdateAnimation(float InDeltaSeconds) override;

	// 캐릭터 회전에 따른 기울기를 계산합니다.
	float CalYawDelta(float InDeltaSeconds);
	
public:
	/////////////////////////////////////////////////////////////////////
	// Getter, Setter //
	void SetOnRail(const bool inBool) { OnRail = inBool; }
	
	void AttackSign(EAbilityType InUseSkillType);
	EAbilityType GetAttackSign(){return UseSkillType;}
	void AttackEndSign();
};
