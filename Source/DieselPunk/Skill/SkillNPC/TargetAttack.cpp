// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetAttack.h"
#include "..\..\Character\CharacterNPC.h"

#include <Kismet/GameplayStatics.h>
#include <Components/SkeletalMeshComponent.h>

UTargetAttack::UTargetAttack() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void UTargetAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UTargetAttack::AbilityStart()
{
	Super::AbilityStart();

	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);
}

void UTargetAttack::TargetAttack(AActor* inTarget)
{
	if(inTarget == nullptr)
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
	FEffectTransform hitET;
	hitET.Location = HitEffectFTransform.Location + inTarget->GetActorLocation();
	hitET.Rotation = HitEffectFTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
	hitET.Scale = HitEffectFTransform.Scale;
	if (N_HitEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitET);
	if (HitEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitET);

	
	// 데미지 결정
	float damage = Atk * AtkCoefficient;
	UGameplayStatics::ApplyDamage(inTarget, damage, OwnerController, ownerPawn, nullptr);
}
