// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierLM.h"
#include "../SkillActor/ProjectileGranade.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"

#include <GameFramework/PlayerController.h>
#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>
#include <Kismet/GameplayStatics.h>

#include "Particles/ParticleSystem.h"


USkillSoldierLM::USkillSoldierLM() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierLM::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierLM::SkillTriggered()
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
	bool Hit = GetWorld()->LineTraceSingleByChannel(hit, lineTraceLocation, end, ECollisionChannel::ECC_GameTraceChannel1);

	// Muzzle Location by BoneName
	FVector shotLocation =ownerPawn->GetMesh()->GetSocketLocation("Muzzle_01");
	//FRotator shotRotation = (Hit ? hit.Location - shotLocation : end - shotLocation).Rotation();
	FRotator shotRotation = (end - shotLocation).Rotation();

	//===========================================
	// * MainAction 1 // 반동 애니메이션
	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance());
	if (!animInst)
		return;
	
	animInst->RotateGunRecoil();
	animInst->GunRecoil();

	//===========================================
	// * MainAction 2 // Projectile Spawn
	if(ProjectileGranadeClass && !EBuffOn)
	{
		FActorSpawnParameters param = FActorSpawnParameters();
		param.Owner = GetOwner();
		ProjectileGranade = GetWorld()->SpawnActor<AProjectileGranade>(ProjectileGranadeClass, shotLocation, shotRotation, param);
		
		if (MuzzleParticles)
			UGameplayStatics::SpawnEmitterAttached(
				MuzzleParticles,
				ownerPawn->GetMesh(),
				TEXT("Muzzle_01"),
				FVector(ForceInit),
				FRotator::ZeroRotator,
				FVector(0.1) );
	}
	// * or if EBuffOn is true
	if(ProjectileGranadeEBuffClass && EBuffOn)
	{
		FActorSpawnParameters param = FActorSpawnParameters();
		param.Owner = GetOwner();
		ProjectileGranade = GetWorld()->SpawnActor<AProjectileGranade>(ProjectileGranadeEBuffClass, shotLocation, shotRotation, param);
		--Magazine;
		if (Magazine == 0)
		{
			Magazine = 20;
			EBuffOn = false;
		}
		
		if (MuzzleParticlesSpecial)
			UGameplayStatics::SpawnEmitterAttached(
				MuzzleParticlesSpecial,
				ownerPawn->GetMesh(),
				TEXT("Muzzle_01"),
				FVector(ForceInit),
				FRotator::ZeroRotator,
				FVector(0.05));
	}


}
