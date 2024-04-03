// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Animation/DPAnimInstance.h"
#include "TurretAnimInstace.generated.h"

enum class ETurretSkillMontageType : uint8;
class ACharacterNPC;

UCLASS()
class DIESELPUNK_API UTurretAnimInstace : public UDPAnimInstance
{
	GENERATED_BODY()
	
private:
	// 캐릭터가 사용할 애님 몽타주 Shift
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UAnimMontage> MonsterMontage;

	// 터렛위치와 타겟위치 각도
	UPROPERTY(BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
	FRotator OwnerToTargetRot = FRotator::ZeroRotator;

	// 터렛위치와 타겟사이 거리
	UPROPERTY(BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
	float OwnerToTargetDist = 0;

	UPROPERTY()
	TWeakObjectPtr<ACharacterNPC> CurTarget = nullptr;

	// 터렛 공격 애니메이션 노드 조건
	UPROPERTY(BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
	bool bAttack = false;

	FTimerHandle AttackTHandle;
	
public:
	// 생성자
	UTurretAnimInstace();
	// 틱마다 호출되는 함수
	virtual void NativeUpdateAnimation(float InDeltaSeconds) override;
	// AbilityType에 따른 몽타주를 반환합니다. None입력시 기본 몽타주 반환
	UAnimMontage* GetMontageByAbilityType(EAbilityType InAbilityType);
	// 몽타주를 재생하고 DurationTime을 반환합니다.
	float PlayMontage(EAbilityType InAbilityType, ETurretSkillMontageType InSectionType, float InPlayRate = 1.f);
	// 몽타주 재생을 정지합니다.
	void StopMontage(EAbilityType InAbilityType, float InBlendOutTime);
	// 몽타주 재생을 일시 정지합니다.
	void PauseMontage(EAbilityType InAbilityType);
	// 몽타주를 다시 재생합니다.
	void ResumeMontage(EAbilityType InAbilityType);

	// 현재 타겟을 설정합니다.
	void SetCurTarget(TWeakObjectPtr<ACharacterNPC> InCharacter);

	// 터렛이 공격하면 신호를 줍니다.
	void AttackSign();
	
};

UENUM()
enum class ETurretSkillMontageType : uint8
{
	Attack,				// 공격
	Max
};