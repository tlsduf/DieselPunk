// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierQ.h"
#include "../../Actor\ProjectileBase.h"
#include "../../Character/CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Handler/CoolTimeHandler.h"

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
	
	// 쿨타임 감소
	float coolDown = 0.5 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::CoolDown];
	
	// 쿨타임 && 스킬플레이타임
	CoolTimeHandler->SetCoolTime(CoolTime - coolDown);
	OwnerCharacterPC->SkillActivating[EAbilityType::SkillQ] = true;
	TWeakObjectPtr<USkillSoldierQ> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(PlaySkillTHandle, [thisPtr]()
	{
		if(thisPtr.IsValid())
			thisPtr->OwnerCharacterPC->SkillActivating[EAbilityType::SkillQ] = false;
	},SkillPlayTime, false);
	
	//애니메이션 재생
	if(	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(OwnerCharacterPC->GetMesh()->GetAnimInstance()))
		animInst->PlayMontage(EAbilityType::SkillQ, ESoldierSkillMontageType::Attack);
}

// 몽타주에서 실행합니다.
void USkillSoldierQ::Shot()
{
	FVector shotLocation = OwnerCharacterPC->GetMesh()->GetSocketLocation("Grenade_socket");
	const FRotator shotRotation = OwnerController->GetControlRotation();
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
		FTransform spawnTransform;

		switch(OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::AddProjectile])
		{
		case 0 :
			// 투사체1
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw, 0), shotLocation);
			Projectile1 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile1->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile1->FinishSpawning(spawnTransform);
			break;
		case 1 :
			// 투사체1
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw - 10, 0), shotLocation);
			Projectile1 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile1->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile1->FinishSpawning(spawnTransform);

			// 투사체2
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw + 10, 0), shotLocation);
			Projectile2 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile2->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile2->FinishSpawning(spawnTransform);
			break;
		case 2 :
			// 투사체1
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw, 0), shotLocation);
			Projectile1 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile1->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile1->FinishSpawning(spawnTransform);

			// 투사체2
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw - 20, 0), shotLocation);
			Projectile2 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile2->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile2->FinishSpawning(spawnTransform);

			// 투사체3
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw + 20, 0), shotLocation);
			Projectile3 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile3->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile3->FinishSpawning(spawnTransform);
			break;
		default :
			// 투사체1
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw, 0), shotLocation);
			Projectile1 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile1->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile1->FinishSpawning(spawnTransform);

			// 투사체2
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw - 20, 0), shotLocation);
			Projectile2 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile2->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile2->FinishSpawning(spawnTransform);

			// 투사체3
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw + 20, 0), shotLocation);
			Projectile3 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile3->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile3->FinishSpawning(spawnTransform);

			// 투사체4
			spawnTransform = FTransform( FRotator(spawnPitch.Pitch + 15, shotRotation.Yaw, 0), shotLocation);
			Projectile4 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile4->Damage += 10 * OwnerCharacterPC->PCSkillManager.SoldierSkillQUpgradeType[ESoldierSkillQUpgradeType::DamageUp];
			Projectile4->FinishSpawning(spawnTransform);
			break;
		}
	}
}
