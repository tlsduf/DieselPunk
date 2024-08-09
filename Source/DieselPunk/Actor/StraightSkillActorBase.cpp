// Fill out your copyright notice in the Description page of Project Settings.

#include "StraightSkillActorBase.h"
#include "../Character/CharacterBase.h"

#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Kismet/GameplayStatics.h>

#include "Weapon.h"
#include "DieselPunk/Data/ProjectileSkillActorDataTable.h"
#include "DieselPunk/Manager/DatatableManager.h"
#include "DieselPunk/Manager/ObjectManager.h"


// =============================================================
// 생성자
// =============================================================
AStraightSkillActorBase::AStraightSkillActorBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

// =============================================================
// BeginPlay
// =============================================================
void AStraightSkillActorBase::BeginPlay()
{
	Super::BeginPlay();

	//데이터 테이블 조회
	const FProjectileSkillActorDataTable* data =
		FDataTableManager::GetInstance()->GetData<FProjectileSkillActorDataTable>(EDataTableType::ProjectileSkillActor, ProjectileSkillActorName.ToString());
	if(!data)
		return;

	Piercing = data->StraightSkillActorData.Piercing;
	Speed = data->StraightSkillActorData.Speed;

	ProjectileMovementComponent->InitialSpeed = Speed;
	ProjectileMovementComponent->MaxSpeed = Speed;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0;
	ProjectileMovementComponent->Velocity = GetActorForwardVector() * Speed;
}

// =============================================================
// Tick
// =============================================================
void AStraightSkillActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStraightSkillActorBase::_OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor,
	UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult)
{
	Super::_OnHit(InHitComp, InOtherActor, InOtherComp, InNormalImpulse, InHitResult);

	// Effect
	FEffectTransform hitEffectFTransform;
	hitEffectFTransform.Location = HitEffectTransform.Location + GetActorLocation();
	hitEffectFTransform.Rotation = HitEffectTransform.Rotation + GetActorRotation();
	hitEffectFTransform.Scale = HitEffectTransform.Scale;

	if (N_HitEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitEffectFTransform);
	if (HitEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitEffectFTransform);
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());

	// 데미지 전달
	if (OwnerCharacter.IsValid() && InOtherActor && InOtherActor != this && InOtherActor != GetOwner())
	{
		if(Cast<AWeapon>(GetOwner()) == nullptr || InOtherActor != Cast<AWeapon>(GetOwner())->GetOwnerPlayer())
		{
			if(RadialAttackInfos.IsEmpty())
				UGameplayStatics::ApplyDamage(InOtherActor, Damage, OwnerController.Get(), this, nullptr);
			else
				ApplyRadialDamage();

			if(--Piercing < 0)
				FObjectManager::GetInstance()->DestroyActor(this);
		}
	}
}

void AStraightSkillActorBase::_BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor,
	UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult& InSweepResult)
{
	Super::_BeginOverlapEvent(InOverlappedComponent, InOtherActor, InOtherComp, InOtherBodyIndex, InbFromSweep,
	                          InSweepResult);

	// Effect
	FEffectTransform hitEffectFTransform;
	hitEffectFTransform.Location = HitEffectTransform.Location + GetActorLocation();
	hitEffectFTransform.Rotation = HitEffectTransform.Rotation + GetActorRotation();
	hitEffectFTransform.Scale = HitEffectTransform.Scale;

	if (N_HitEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitEffectFTransform);
	if (HitEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitEffectFTransform);
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());

	// 데미지 전달
	if (OwnerCharacter.IsValid() && InOtherActor && InOtherActor != this && InOtherActor != GetOwner())
	{
		if(Cast<AWeapon>(GetOwner()) == nullptr || InOtherActor != Cast<AWeapon>(GetOwner())->GetOwnerPlayer())
		{
			if(RadialAttackInfos.IsEmpty())
				UGameplayStatics::ApplyDamage(InOtherActor, Damage, OwnerController.Get(), this, nullptr);
			else
				ApplyRadialDamage();

			if(--Piercing < 0)
				FObjectManager::GetInstance()->DestroyActor(this);
		}
	}
}
