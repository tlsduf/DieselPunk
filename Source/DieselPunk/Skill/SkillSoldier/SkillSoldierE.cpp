// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierE.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Skill/SkillSoldier/SkillSoldierLM.h"

#include <GameFramework/PlayerController.h>
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

	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;

	//트리거 이벤트
	USkillSoldierLM *SoldierLM = nullptr;
	if(ownerPawn->Skills[0])
		SoldierLM = Cast<USkillSoldierLM>(ownerPawn->Skills[0]);
	
	if(SoldierLM != nullptr)
	{
		SoldierLM->EBuffOn = true;
		SoldierLM->Magazine = 20;
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

	animInst->PlayMontage(EAbilityType::SkillE, ESoldierSkillMontageType::AroundAttack1);
}
