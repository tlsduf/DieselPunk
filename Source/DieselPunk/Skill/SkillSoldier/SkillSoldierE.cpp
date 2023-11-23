// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierE.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Skill/SkillSoldier/SkillSoldierLM.h"
#include "../../Handler/CoolTimeHandler.h"

#include <Components/SkeletalMeshComponent.h>
#include <Kismet/GameplayStatics.h>

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
	
	// 쿨타임 감소
	float coolDown = 0.5 * OwnerCharacterPC->PCSkillManager.SoldierSkillEUpgradeType[ESoldierSkillEUpgradeType::CoolDown];
	// 쿨타임
	CoolTimeHandler->SetCoolTime(CoolTime - coolDown);
	
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
	{
		UGameplayStatics::SpawnEmitterAttached(
			BuffEffect,
			OwnerCharacterPC->GetMesh(),
			TEXT("pelvis"),
			FVector(ForceInit),
			FRotator::ZeroRotator,
			FVector(1));
	}
	
	//애니메이션 재생?
	if(USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(OwnerCharacterPC->GetMesh()->GetAnimInstance()))	
		animInst->PlayMontage(EAbilityType::SkillE, ESoldierSkillMontageType::Attack);
}
