// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimInstance.h"
#include "SoldierAnimInstance.generated.h"

enum class EAroundSkillMontageType : uint8;

UCLASS()
class DIESELPUNK_API USoldierAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
private:
	// 캐릭터가 사용할 애님 몽타주 Shift
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UAnimMontage> ShiftMontage;
	
	// 캐릭터가 사용할 애님 몽타주 SkillQ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UAnimMontage> SkillQMontage;
	
	// 캐릭터가 사용할 애님 몽타주 SkillE
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UAnimMontage> SkillEMontage;

	// 캐릭터가 사용할 애님 몽타주 SkillR
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UAnimMontage> SkillRMontage;

	// HandL 본 회전 블렌딩 알파
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	bool GunRecoilBool = 0;

public:
	// 생성자
	USoldierAnimInstance();
	// 틱마다 호출되는 함수, 스피드를 계산한다.
	virtual void NativeUpdateAnimation(float InDeltaSeconds) override;
	// AbilityType에 따른 몽타주를 반환합니다. None입력시 기본 몽타주 반환
	UAnimMontage* GetMontageByAbilityType(EAbilityType InAbilityType);
	// 몽타주를 재생하고 DurationTime을 반환합니다.
	float PlayMontage(EAbilityType InAbilityType, ESoldierSkillMontageType InSectionType, float InPlayRate = 1.f);
	// 몽타주 재생을 정지합니다.
	void StopMontage(EAbilityType InAbilityType, float InBlendOutTime);
	// 몽타주 재생을 일시 정지합니다.
	void PauseMontage(EAbilityType InAbilityType);
	// 몽타주를 다시 재생합니다.
	void ResumeMontage(EAbilityType InAbilityType);
	// 임시 반동 애니메이션
	void GunRecoil();
	
private:
	// SkillQ 전용 애님노티파이 입니다. 
	UFUNCTION()
	void AnimNotify_NotifySkillQ() const;
};

UENUM()
enum class ESoldierSkillMontageType : uint8
{
	Attack,				// 공격
	Max
};