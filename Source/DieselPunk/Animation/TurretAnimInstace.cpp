// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretAnimInstace.h"
#include "../Character/CharacterNPC.h"

#include <Animation/AnimMontage.h>

#include "DieselPunk/Character/CharacterTurret.h"
#include "DieselPunk/Skill/SkillNPC/ParabolaAttack.h"

UTurretAnimInstace::UTurretAnimInstace(){}

// 틱마다 호출되는 함수
void UTurretAnimInstace::NativeUpdateAnimation(float InDeltaSeconds)
{
	Super::NativeUpdateAnimation(InDeltaSeconds);

	if(CurTarget.IsValid())
	{
		OwnerToTargetRot = (CurTarget->GetActorLocation() - GetOwningActor()->GetActorLocation()).Rotation() - GetOwningActor()->GetActorRotation();
		BarrelYaw = OwnerToTargetRot.Yaw;

		if(ACharacterTurret* turret = Cast<ACharacterTurret>(GetOwningActor()))
		{
			if(Cast<UParabolaAttack>(turret->GetNPCSkill()))
			{
				FVector direction = (CurTarget->GetActorLocation() - GetOwningActor()->GetActorLocation()) / 3 + FVector(0.0, 0.0, 10000.0);
				direction.Normalize();
				BarrelPitch = direction.Rotation().Pitch;
			}
			else
				BarrelPitch = OwnerToTargetRot.Pitch;
		}
		
		OwnerToTargetDist = FVector::Dist(CurTarget->GetActorLocation(), GetOwningActor()->GetActorLocation());
		float l =  FVector::Dist(FVector(CurTarget->GetActorLocation().X, CurTarget->GetActorLocation().Y, 0),
		FVector(GetOwningActor()->GetActorLocation().X, GetOwningActor()->GetActorLocation().Y, 0));
		float h = CurTarget->GetActorLocation().Z - GetOwningActor()->GetActorLocation().Z;
		UpDownDegree = atan(h / l) * 180 / PI;
	}
	
	ACharacterBase* owner = Cast<ACharacterBase>(TryGetPawnOwner());
	if(owner)
		TurretLevel = owner->GetStat(ECharacterStatType::Level);
}

// AbilityType에 따른 몽타주를 반환합니다. None입력시 기본 몽타주 반환
UAnimMontage* UTurretAnimInstace::GetMontageByAbilityType(EAbilityType InAbilityType)
{
	FSoftObjectPath path = MonsterMontage.ToSoftObjectPath();
	if(!path.IsValid())
		return nullptr;
	
	return LoadObject<UAnimMontage>(nullptr, *path.ToString());
}

// 몽타주를 재생합니다.
float UTurretAnimInstace::PlayMontage(EAbilityType InAbilityType, ETurretSkillMontageType InSectionType, float InPlayRate/* = 1.f*/)
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
void UTurretAnimInstace::StopMontage(EAbilityType InAbilityType, float InBlendOutTime)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Stop(InBlendOutTime, animMontage);
}

// 몽타주 재생을 일시 정지합니다.
void UTurretAnimInstace::PauseMontage(EAbilityType InAbilityType)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Pause(animMontage);
}

// 몽타주를 다시 재생합니다.
void UTurretAnimInstace::ResumeMontage(EAbilityType InAbilityType)
{
	UAnimMontage* animMontage = GetMontageByAbilityType(InAbilityType);
	if(!animMontage)
		return;
	Montage_Resume(animMontage);
}

// 현재 타겟을 설정합니다.
void UTurretAnimInstace::SetCurTarget(TWeakObjectPtr<ACharacterNPC> InCharacter)
{
	if(InCharacter.IsValid())
		CurTarget = InCharacter;
	else
		CurTarget = nullptr;
}
