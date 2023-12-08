// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierE.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Skill/SkillSoldier/SkillSoldierLM.h"
#include "../../Handler/CoolTimeHandler.h"

#include <Components/SkeletalMeshComponent.h>


USkillSoldierE::USkillSoldierE() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierE::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierE::SkillTriggered()
{
	Super::SkillTriggered();
	
	// 쿨타임
	CoolTimeHandler->SetCoolTime(CoolTime);
	
	//트리거 이벤트
	if(OwnerCharacterPC->Skills[EAbilityType::MouseLM])
		if(USkillSoldierLM *soldierLM = Cast<USkillSoldierLM>(OwnerCharacterPC->Skills[EAbilityType::MouseLM]))
		{
			soldierLM->EBuffOn = true;
			soldierLM->Magazine = 5;
			soldierLM->CoolTime = 0.2;
		}

	//이펙트
	if (BuffEffect)
		UtilEffect::SpawnParticleEffectAttached(BuffEffect, OwnerCharacterPC->GetRootComponent());
	
	//애니메이션 재생?
	if(USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(OwnerCharacterPC->GetMesh()->GetAnimInstance()))	
		animInst->PlayMontage(EAbilityType::SkillE, ESoldierSkillMontageType::Attack);
}

