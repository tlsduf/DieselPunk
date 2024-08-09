// Fill out your copyright notice in the Description page of Project Settings.

#include "ParabolaSkillActorBase.h"
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
AParabolaSkillActorBase::AParabolaSkillActorBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

// =============================================================
// BeginPlay
// =============================================================
void AParabolaSkillActorBase::BeginPlay()
{
	Super::BeginPlay();

	//데이터 테이블 조회
	const FProjectileSkillActorDataTable* data =
		FDataTableManager::GetInstance()->GetData<FProjectileSkillActorDataTable>(EDataTableType::ProjectileSkillActor, ProjectileSkillActorName.ToString());

	if(!data)
		return;

	Speed = data->ParabolaSkillActorData.Speed;
	MinFlightTime = data->ParabolaSkillActorData.MinFlightTime;
	ParabolaArrivalTimeCoefficient = data->ParabolaSkillActorData.ParabolaArrivalTimeCoefficient;

	DistanceAtGoal = FVector::Distance(GoalLocation, StartLocation);

	FlightTime = MinFlightTime + ParabolaArrivalTimeCoefficient *
		(DistanceAtGoal - OwnerCharacter->GetStat(ECharacterStatType::AtkMinRange)) / OwnerCharacter->GetStat(ECharacterStatType::ShellFall);

	FallTime = FlightTime * 0.5f;
	
	Direction = ((GoalLocation - StartLocation) / 3 + FVector(0.0, 0.0, Speed));
	Direction.Normalize();

	SetActorRotation(Direction.Rotation());

	AscentSpeed = Speed;

	ProjectileMovementComponent->Deactivate();
}

// =============================================================
// Tick
// =============================================================
void AParabolaSkillActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(DeltaFlightTime >= FlightTime - FallTime && !IsFalling)
	{
		Direction = FVector(0.0, 0.0, -1.0);
		SetActorRotation(Direction.Rotation());
		SetActorLocation(GoalLocation - Direction * Speed * FallTime);
		IsFalling = true;
	}
	
	DeltaFlightTime += DeltaTime;
	OldLocation = GetActorLocation();
	if(IsFalling)
	{
		FallSpeed += Speed * DeltaTime * 2.f;
		AddActorWorldOffset(Direction * FallSpeed * DeltaTime);
	}
	else
	{
		AscentSpeed -= Speed * DeltaTime / ((FlightTime - FallTime) * 2.f);
		AddActorWorldOffset(Direction * Speed * DeltaTime);
	}

	FCollisionQueryParams param;
	if(OwnerCharacter.IsValid())
		param.AddIgnoredActor(OwnerCharacter.Get());
	FHitResult result;
	if(GetWorld()->LineTraceSingleByChannel(result, OldLocation, GetActorLocation(), ECC_WorldStatic, param))
	{
		if(IsValid(result.GetActor()))
			SetActorLocation(result.Location);
	}
}

void AParabolaSkillActorBase::_OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor,
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
		}
	}
	FObjectManager::GetInstance()->DestroyActor(this);
}

void AParabolaSkillActorBase::_BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor,
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
		}
	}
	FObjectManager::GetInstance()->DestroyActor(this);
}
