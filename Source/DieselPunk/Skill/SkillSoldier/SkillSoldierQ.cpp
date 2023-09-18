// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierQ.h"
#include "../../Actor\SoldierProjectile.h"
#include "../../Character/CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Handler/CoolTimeHandler.h"

#include <GameFramework/PlayerController.h>
#include <Components/SkeletalMeshComponent.h>
#include <TimerManager.h>

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

	// 쿨타임 감소
	float CoolDown = 0.5 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::CoolDown];
	// 쿨타임!!!!!!!!!!!!!!!!!! && 스킬플레이타임
	CoolTimeHandler->SetCoolTime(CoolTime - CoolDown);
	ownerPawn->SkillActivating[EAbilityType::SkillQ] = true;
	DpGetWorld()->GetTimerManager().SetTimer(
	PlaySkillTHandle, [this]()
	{ Cast<ACharacterPC>(GetOwner())->SkillActivating[EAbilityType::SkillQ] = false; },
	SkillPlayTime, false);
	
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
		FTransform SpawnTransform;

		switch(ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::AddProjectile])
		{
		case 0 :
			// 투사체1
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw, 0), shotLocation);
			Projectile1 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile1->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile1->Stack = 10;
			Projectile1->FinishSpawning(SpawnTransform);
			break;
		case 1 :
			// 투사체1
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw - 10, 0), shotLocation);
			Projectile1 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile1->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile1->Stack = 10;
			Projectile1->FinishSpawning(SpawnTransform);

			// 투사체2
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw + 10, 0), shotLocation);
			Projectile2 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile2->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile2->Stack = 10;
			Projectile2->FinishSpawning(SpawnTransform);
			break;
		case 2 :
			// 투사체1
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw, 0), shotLocation);
			Projectile1 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile1->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile1->Stack = 10;
			Projectile1->FinishSpawning(SpawnTransform);

			// 투사체2
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw - 20, 0), shotLocation);
			Projectile2 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile2->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile2->Stack = 10;
			Projectile2->FinishSpawning(SpawnTransform);

			// 투사체3
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw + 20, 0), shotLocation);
			Projectile3 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile3->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile3->Stack = 10;
			Projectile3->FinishSpawning(SpawnTransform);
			break;
		default :
			// 투사체1
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw, 0), shotLocation);
			Projectile1 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile1->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile1->Stack = 10;
			Projectile1->FinishSpawning(SpawnTransform);

			// 투사체2
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw - 20, 0), shotLocation);
			Projectile2 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile2->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile2->Stack = 10;
			Projectile2->FinishSpawning(SpawnTransform);

			// 투사체3
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw + 20, 0), shotLocation);
			Projectile3 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile3->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile3->Stack = 10;
			Projectile3->FinishSpawning(SpawnTransform);

			// 투사체4
			SpawnTransform = FTransform( FRotator(spawnPitch.Pitch + 15, shotRotation.Yaw, 0), shotLocation);
			Projectile4 = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile4->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];

			Projectile4->Stack = 10;
			Projectile4->FinishSpawning(SpawnTransform);
			break;
		}
	}
}
