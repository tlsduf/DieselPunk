// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierR.h"
#include "../SkillActor/ProjectileGranade.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"

#include <GameFramework/PlayerController.h>
#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>


USkillSoldierR::USkillSoldierR() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierR::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierR::SkillTriggered()
{
	Super::SkillTriggered();

	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;

	

	// 라인트레이스로 최종경로설정
	FVector lineTraceLocation;
	FRotator lineTraceRotation;
	ownerController->GetPlayerViewPoint(lineTraceLocation, lineTraceRotation);
	
	FVector end = lineTraceLocation + lineTraceRotation.Vector() * 10000;
	FHitResult hit;

	bool HasHit = GetWorld()->LineTraceSingleByChannel(hit, lineTraceLocation, end, ECollisionChannel::ECC_GameTraceChannel1);
	FVector shotLocation = ownerPawn->GetMesh()->GetSocketLocation("hand_lShotSocket");
	FVector ThisZeroVector = HasHit ? hit.Location - shotLocation : end - shotLocation;
	FRotator shotRotation = ThisZeroVector.Rotation();

	// projectile spawn
	if(ProjectileGranadeClass)
	{
		FActorSpawnParameters param = FActorSpawnParameters();
		param.Owner = GetOwner();
		ProjectileGranade = GetWorld()->SpawnActor<AProjectileGranade>(ProjectileGranadeClass, shotLocation, shotRotation, param);
	}
	

	//애니메이션 재생?
	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance());
	if (!animInst)
		return;

	animInst->PlayMontage(EAbilityType::SkillR, ESoldierSkillMontageType::AroundAttack1);
}
