// Fill out your copyright notice in the Description page of Project Settings.


#include "SoldierAnimInstance.h"

#include "../Skill/SkillSoldier/SkillSoldierQ.h"
#include "../Character/CharacterPC.h"

#include <Animation/AnimMontage.h>


USoldierAnimInstance::USoldierAnimInstance()
	:ShiftMontage(nullptr), SkillQMontage(nullptr), SkillEMontage(nullptr), SkillRMontage(nullptr)
{
}
// 틱마다 호출되는 함수
void USoldierAnimInstance::NativeUpdateAnimation(float InDeltaSeconds)
{
	Super::NativeUpdateAnimation(InDeltaSeconds);

}

// AbilityType에 따른 몽타주를 반환합니다. None입력시 기본 몽타주 반환
UAnimMontage* USoldierAnimInstance::GetMontageByAbilityType(EAbilityType InAbilityType)
{
	switch ( InAbilityType )
	{
		case EAbilityType::MouseLM:			return nullptr;
		case EAbilityType::MouseRM:			return nullptr;
		case EAbilityType::Shift:
			{
				FSoftObjectPath path = ShiftMontage.ToSoftObjectPath();
				if(!path.IsValid())
					return nullptr;
				return LoadObject<UAnimMontage>(nullptr, *path.ToString());
			}
		case EAbilityType::SkillQ:			
			{
				FSoftObjectPath path = SkillQMontage.ToSoftObjectPath();
				if(!path.IsValid())
					return nullptr;
				return LoadObject<UAnimMontage>(nullptr, *path.ToString());
			}
		case EAbilityType::SkillE:			
			{
				FSoftObjectPath path = SkillEMontage.ToSoftObjectPath();
				if(!path.IsValid())
					return nullptr;
				return LoadObject<UAnimMontage>(nullptr, *path.ToString());
			}
		case EAbilityType::SkillR:			
			{
				FSoftObjectPath path = SkillRMontage.ToSoftObjectPath();
				if(!path.IsValid())
					return nullptr;
				return LoadObject<UAnimMontage>(nullptr, *path.ToString());
			}
		case EAbilityType::None:			return nullptr;
	}

	return nullptr;
}

// 몽타주를 재생합니다.
float USoldierAnimInstance::PlayMontage(EAbilityType InAbilityType, ESoldierSkillMontageType InSectionType, float InPlayRate/* = 1.f*/)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if (!animMontage)
		return 0.f;

	//TODO InSectionType 고쳐야됨 근데 Default로 읽어지긴하는듯?
	FName sectionName = "Default";
	Montage_Play(animMontage, InPlayRate);
	Montage_JumpToSection(sectionName, animMontage);
	
	return animMontage->GetSectionLength(animMontage->GetSectionIndex(sectionName));
}

// 몽타주 재생을 정지합니다.
void USoldierAnimInstance::StopMontage(EAbilityType InAbilityType, float InBlendOutTime)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Stop(InBlendOutTime, animMontage);
}

// 몽타주 재생을 일시 정지합니다.
void USoldierAnimInstance::PauseMontage(EAbilityType InAbilityType)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Pause(animMontage);
}

// 몽타주를 다시 재생합니다.
void USoldierAnimInstance::ResumeMontage(EAbilityType InAbilityType)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Resume(animMontage);
}

void USoldierAnimInstance::GunRecoil()
{
	GunRecoilBool = 1;
	TWeakObjectPtr<USoldierAnimInstance> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimerForNextTick([thisPtr]()
	{
		if(thisPtr.IsValid())
			thisPtr->GunRecoilBool = 0;
	});
}

void USoldierAnimInstance::AnimNotify_NotifySkillQ() const
{
	auto ownerPawn = Cast<ACharacterPC>(GetOwningActor());
	
	USkillSoldierQ *SoldierQ = nullptr;
	if(ownerPawn->Skills[EAbilityType::SkillQ])
		SoldierQ = Cast<USkillSoldierQ>(ownerPawn->Skills[EAbilityType::SkillQ]);
	
	if(SoldierQ != nullptr)
		SoldierQ->Shot();
}

