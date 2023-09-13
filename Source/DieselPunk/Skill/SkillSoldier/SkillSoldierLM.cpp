// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierLM.h"
#include "../../Actor\SoldierProjectile.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Handler/CoolTimeHandler.h"

#include <Kismet/GameplayStatics.h>
#include <InputTriggers.h>
#include <Components/SkeletalMeshComponent.h>

USkillSoldierLM::USkillSoldierLM() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierLM::BeginPlay()
{
	Super::BeginPlay();

	TempCoolTime = CoolTime;
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

	// 쿨타임!!!!!!!!!!!!!!!!!!!!!!
	CoolTimeHandler->SetCoolTime(CoolTime);
	
	// 라인트레이스로 최종경로설정
	FVector lineTraceLocation;
	FRotator lineTraceRotation;
	ownerController->GetPlayerViewPoint(lineTraceLocation, lineTraceRotation);
	
	FVector end = lineTraceLocation + lineTraceRotation.Vector() * 10000;
	//FHitResult hit;
	//bool Hit = GetWorld()->LineTraceSingleByChannel(hit, lineTraceLocation, end, ECollisionChannel::ECC_GameTraceChannel1);	//라인 트레이스 

	// Muzzle Location by BoneName
	FVector shotLocation =ownerPawn->GetMesh()->GetSocketLocation("Muzzle_01");
	//FRotator shotRotation = (Hit ? hit.Location - shotLocation : end - shotLocation).Rotation();	//트레이스 히트된 위치로 발사
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
	if(ProjectileClass && !EBuffOn)
	{
		//FString resourcePath = UtilPath::GetSkillPath( TEXT("SkillActor/BP_ProjectileBullet") );
		//ProjectileClass = LoadClass<ASoldierProjectile>( NULL, *resourcePath );
		FTransform SpawnTransform( shotRotation, shotLocation);
		Projectile = GetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());
		Projectile->FinishSpawning(SpawnTransform);
		
		
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
	if(ProjectileEBuffClass && EBuffOn)
	{
		FTransform SpawnTransform( shotRotation, shotLocation);
		Projectile = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileEBuffClass, SpawnTransform, GetOwner());
		Projectile->Stack = 3;
		Projectile->FinishSpawning(SpawnTransform);
		--Magazine;
		
		if (MuzzleParticlesSpecial)
			UGameplayStatics::SpawnEmitterAttached(
				MuzzleParticlesSpecial,
				ownerPawn->GetMesh(),
				TEXT("Muzzle_01"),
				FVector(ForceInit),
				FRotator::ZeroRotator,
				FVector(0.05));

		// 탄창 수 다 소진 시 버프 off
		if (Magazine == 0)
		{
			EBuffOn = false;
			CoolTime = TempCoolTime;
		}
	}
}
