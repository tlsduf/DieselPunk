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

void UTargetAttack::AbilityStart(AActor* inTarget)
{
	Super::AbilityStart(inTarget);

	if(AtkCoefficient <= 0)
		return;
	
	if(inTarget == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("타겟정보 NULL"));
		return;
	}
	
	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	//애니메이션 재생?
	if(UTurretAnimInstace* animInst = Cast<UTurretAnimInstace>(ownerPawn->GetMesh()->GetAnimInstance()))	
		animInst->AttackSign();
	
	
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
	FEffectTransform hitET;
	hitET.Location = HitEffectFTransform.Location + inTarget->GetActorLocation();
	hitET.Rotation = HitEffectFTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
	hitET.Scale = HitEffectFTransform.Scale;
	if (N_HitEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitET);
	if (HitEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitET);

	
	UGameplayStatics::ApplyDamage(inTarget, Damage, OwnerController, ownerPawn, nullptr);
}
