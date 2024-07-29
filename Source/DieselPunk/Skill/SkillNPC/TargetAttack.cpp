// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetAttack.h"
#include "..\..\Character\CharacterNPC.h"
#include "../../Animation/TurretAnimInstace.h"

#include <Kismet/GameplayStatics.h>
#include <Components/SkeletalMeshComponent.h>

#include "DrawDebugHelpers.h"


UTargetAttack::UTargetAttack() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void UTargetAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UTargetAttack::AbilityStart(AActor* InTarget)
{
	Super::AbilityStart(InTarget);
	
	if(InTarget == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("타겟정보 NULL"));
		return;
	}
	
	auto ownerPawn = Cast<ACharacterBase>(OwnerCharacter);
	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance()))	
		animInst->AttackSign(EAbilityType::MouseLM);
}

void UTargetAttack::AbilityShot(double InDamageCoefficient, AActor* InTarget)
{
	Super::AbilityShot(InDamageCoefficient, InTarget);

	if(InTarget == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("타겟정보 NULL"));
		return;
	}

	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);
	
	// Shot Effect
	FEffectTransform shotET;
	shotET.Location = ShotEffectTransform.Location + ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
	shotET.Rotation = ShotEffectTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket");
	shotET.Scale = ShotEffectTransform.Scale;
	if (N_ShotEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_ShotEffect, shotET);
	if (ShotEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), ShotEffect, shotET);
	
	// Hit Effect
	TArray<FHitResult> results;
	if(ownerPawn->GetCharacterType() == ECharacterType::Player || ownerPawn->GetCharacterType() == ECharacterType::Turret)
	{
		GetWorld()->LineTraceMultiByChannel(results, ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket"), InTarget->GetActorLocation()
		, ECC_DP_PlayerChannel);
	}
	else if(ownerPawn->GetCharacterType() == ECharacterType::Monster)
	{
		GetWorld()->LineTraceMultiByChannel(results, ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket"), InTarget->GetActorLocation()
		, ECC_DP_EnemyChannel);
	}

	if(!results.IsEmpty())
	{
		for(const FHitResult& hitResult : results)
		{
			if(hitResult.GetActor() == InTarget)
			{
				FEffectTransform hitET;
				hitET.Location = HitEffectFTransform.Location + hitResult.Location;
				hitET.Rotation = HitEffectFTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
				hitET.Scale = HitEffectFTransform.Scale;
				if (N_HitEffect)
					UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitET);
				if (HitEffect)
					UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitET);
			}
		}
	}
	UGameplayStatics::ApplyDamage(InTarget, Damage * InDamageCoefficient, OwnerController, ownerPawn, nullptr);
}
