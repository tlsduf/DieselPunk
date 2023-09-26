// Fill out your copyright notice in the Description page of Project Settings.

#include "DpAnimInstance.h"

#include "../Character/CharacterBase.h"
#include "../Util/UtilEnum.h"

#include <Animation/AnimMontage.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(DpAnimInstance)

// 생성자
UDpAnimInstance::UDpAnimInstance()
	: AnimMontage(nullptr), CharacterSpeed(0.f), RotateDamaged(0.0, 0.0, 0.0), Alpha(0.f), AlphaAnimator()
{
}

// 틱마다 호출되는 함수, 스피드를 계산한다.
void UDpAnimInstance::NativeUpdateAnimation(float InDeltaSeconds)
{
	Super::NativeUpdateAnimation(InDeltaSeconds);

	APawn* pawn = TryGetPawnOwner();
	if (IsValid(pawn))
		CharacterSpeed = pawn->GetVelocity().Size();

	AlphaAnimator.Update(InDeltaSeconds);
}

// 몽타주를 재생합니다.
float UDpAnimInstance::PlayMontage(EMontageSectionType InSectionType, float InPlayRate/* = 1.f*/)
{
	UAnimMontage* animMontage = LoadSoftObject<UAnimMontage>(AnimMontage);
	if (!animMontage)
		return 0.f;

	FName sectionName = FName(UtilEnum::EnumToString(InSectionType));
	Montage_Play(animMontage, InPlayRate);
	Montage_JumpToSection(sectionName, animMontage);
	
	return animMontage->GetSectionLength(animMontage->GetSectionIndex(sectionName));
}
// 몽타주 재생을 정지합니다.
void UDpAnimInstance::StopMontage(float InBlendOutTime)
{
	UAnimMontage* animMontage = LoadSoftObject<UAnimMontage>(AnimMontage);
	if(!animMontage)
		return;
	Montage_Stop(InBlendOutTime, animMontage);
}

// 몽타주 재생을 일시 정지합니다.
void UDpAnimInstance::PauseMontage()
{
	UAnimMontage* animMontage = LoadSoftObject<UAnimMontage>(AnimMontage);
	if(!animMontage)
		return;
	Montage_Pause(animMontage);
}

// 몽타주를 다시 재생합니다.
void UDpAnimInstance::ResumeMontage()
{
	UAnimMontage* animMontage = LoadSoftObject<UAnimMontage>(AnimMontage);
	if(!animMontage)
		return;
	Montage_Resume(animMontage);
}

// Spine 본의 Rotator를 회전합니다.
void UDpAnimInstance::RotateSpine(FRotator InRotate, float InDuration)
{
	RotateDamaged = InRotate;

	AnimatorParam param;
	param.AnimType = EAnimType::QuadraticEaseOut;
	param.StartValue = 1.f;
	param.EndValue = 0.f;
	param.DurationTime = InDuration;

	TWeakObjectPtr<UDpAnimInstance> thisPtr = this;
	param.DurationFunc = [thisPtr](float InCurValue)
	{
		if(thisPtr.IsValid())
			thisPtr->Alpha = InCurValue;
	};
	
	AlphaAnimator.Start(param);
}

// =============================================================
// Notify가 되면 Character Base에 EMontageSectionType을 넘겨줍니다.
// =============================================================
void UDpAnimInstance::AnimNotify_NotifyToCharacter() const
{
	if(ACharacterBase* owner = Cast<ACharacterBase>(TryGetPawnOwner()))
	{
		owner->NotifiedSectionName(STRING_TO_ENUM(EMontageSectionType, Montage_GetCurrentSection().ToString()));
	}
}