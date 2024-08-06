// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAnimInstance.h"
#include "../Character/CharacterNPC.h"

#include <Animation/AnimMontage.h>

UMonsterAnimInstance::UMonsterAnimInstance(){}

// 틱마다 호출되는 함수
void UMonsterAnimInstance::NativeUpdateAnimation(float InDeltaSeconds)
{
	Super::NativeUpdateAnimation(InDeltaSeconds);

	AddRotation();
}

// AbilityType에 따른 몽타주를 반환합니다. None입력시 기본 몽타주 반환
UAnimMontage* UMonsterAnimInstance::GetMontageByAbilityType(EAbilityType InAbilityType)
{
	FSoftObjectPath path = MonsterMontage.ToSoftObjectPath();
	if(!path.IsValid())
		return nullptr;
	
	return LoadObject<UAnimMontage>(nullptr, *path.ToString());
}

// 몽타주를 재생합니다.
float UMonsterAnimInstance::PlayMontage(EAbilityType InAbilityType, EMonsterSkillMontageType InSectionType, float InPlayRate/* = 1.f*/)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if (!animMontage)
		return 0.f;
	
	FName sectionName = "Default";
	Montage_Play(animMontage, InPlayRate);
	Montage_JumpToSection(sectionName, animMontage);
	
	return animMontage->GetSectionLength(animMontage->GetSectionIndex(sectionName));
}

// 몽타주 재생을 정지합니다.
void UMonsterAnimInstance::StopMontage(EAbilityType InAbilityType, float InBlendOutTime)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Stop(InBlendOutTime, animMontage);
}

// 몽타주 재생을 일시 정지합니다.
void UMonsterAnimInstance::PauseMontage(EAbilityType InAbilityType)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Pause(animMontage);
}

// 몽타주를 다시 재생합니다.
void UMonsterAnimInstance::ResumeMontage(EAbilityType InAbilityType)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Resume(animMontage);
}

// 공중몹 프로펠러 회전
int16 UMonsterAnimInstance::AddRotation()
{
	Radian++;

	if(Radian == 360)
		Radian = 0;
	
	return Radian;
}
