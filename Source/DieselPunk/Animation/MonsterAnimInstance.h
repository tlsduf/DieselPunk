// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Animation/DPAnimInstance.h"
#include "MonsterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DIESELPUNK_API UMonsterAnimInstance : public UDPAnimInstance
{
	GENERATED_BODY()
	
private:
	// 캐릭터가 사용할 애님 몽타주 Shift
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UAnimMontage> MonsterMontage;

	// 공중몹 프로펠러 회전
	UPROPERTY(BlueprintReadOnly, Category = "MYDP", Meta = (AllowPrivateAccess = true))
	int Radian = 0;
	
public:
	// 생성자
	UMonsterAnimInstance();
	// 틱마다 호출되는 함수, 스피드를 계산한다.
	virtual void NativeUpdateAnimation(float InDeltaSeconds) override;
	// AbilityType에 따른 몽타주를 반환합니다. None입력시 기본 몽타주 반환
	UAnimMontage* GetMontageByAbilityType(EAbilityType InAbilityType);
	// 몽타주를 재생하고 DurationTime을 반환합니다.
	float PlayMontage(EAbilityType InAbilityType, EMonsterSkillMontageType InSectionType, float InPlayRate = 1.f);
	// 몽타주 재생을 정지합니다.
	void StopMontage(EAbilityType InAbilityType, float InBlendOutTime);
	// 몽타주 재생을 일시 정지합니다.
	void PauseMontage(EAbilityType InAbilityType);
	// 몽타주를 다시 재생합니다.
	void ResumeMontage(EAbilityType InAbilityType);

private:

	// 공중몹 프로펠러 회전
	int16 AddRotation();

};

UENUM()
enum class EMonsterSkillMontageType : uint8
{
	Attack,				// 공격
	Max
};