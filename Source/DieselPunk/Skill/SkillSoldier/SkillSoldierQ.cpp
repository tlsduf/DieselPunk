// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierQ.h"
#include "..\SkillActor\ProjectileBase.h"
#include "../../Character/CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"

#include <GameFramework/PlayerController.h>
#include <Components/SkeletalMeshComponent.h>

USkillSoldierQ::USkillSoldierQ() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}



void USkillSoldierQ::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierQ::SkillTriggered()
{
	Super::SkillTriggered();

	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	
	//애니메이션 재생?
	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance());
	if (!animInst)
		return;

	animInst->PlayMontage(EAbilityType::SkillQ, ESoldierSkillMontageType::AroundAttack1);
}

void USkillSoldierQ::Shot()
{
	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;
	
	
	FVector shotLocation = ownerPawn->GetMesh()->GetSocketLocation("Granade_socket");
	const FRotator shotRotation = ownerController->GetControlRotation();
	FRotator spawnPitch = FRotator(0, 0, 0);
	if (30 <= shotRotation.Pitch && shotRotation.Pitch <= 90)
	{
		spawnPitch.Pitch = 60;
	}
	else
	{
		spawnPitch.Pitch = shotRotation.Pitch + 30;
	}
	// projectile spawn
	if(ProjectileClass)
	{
		FActorSpawnParameters param = FActorSpawnParameters();
		param.Owner = GetOwner();
		Projectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, shotLocation, FRotator(spawnPitch.Pitch, shotRotation.Yaw, 0), param);
	}
}