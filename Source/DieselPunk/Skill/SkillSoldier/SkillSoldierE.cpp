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
	
	auto ownerPawn = Cast<ACharacterPC>(OwnerCharacter);

	// 쿨타임 감소
	float CoolDown = 0.5 * ownerPawn->PCSkillManager.SoldierSkillEUpgradeType[ESoldierSkillEUpgradeType::CoolDown];
	// 쿨타임!!!!!!!!!!!!!!!!!!
	CoolTimeHandler->SetCoolTime(CoolTime - CoolDown);
	
	//트리거 이벤트
	USkillSoldierLM *SoldierLM = nullptr;
	if(ownerPawn->Skills[EAbilityType::MouseLM])
		SoldierLM = Cast<USkillSoldierLM>(ownerPawn->Skills[EAbilityType::MouseLM]);
	
	if(SoldierLM != nullptr)
	{
		SoldierLM->EBuffOn = true;
		SoldierLM->Magazine = 5;
		SoldierLM->CoolTime = 0.2;
	}
	
	//이펙트 
	if (BuffEffect)
	{
		UGameplayStatics::SpawnEmitterAttached(
			BuffEffect,
			ownerPawn->GetMesh(),
			TEXT("pelvis"),
			FVector(ForceInit),
			FRotator::ZeroRotator,
			FVector(1));
	}
	
	//애니메이션 재생?
	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance());
	if (!animInst)
		return;

	animInst->PlayMontage(EAbilityType::SkillE, ESoldierSkillMontageType::Attack);
}
