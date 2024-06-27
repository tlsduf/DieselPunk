// Fill out your copyright notice in the Description page of Project Settings.

#include "HitscanFire.h"
#include "../../Character/CharacterNPC.h"
#include "DieselPunk/Animation/DPAnimInstance.h"

#include <Kismet/GameplayStatics.h>
#include <Components/SkeletalMeshComponent.h>


UHitscanFire::UHitscanFire()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void UHitscanFire::BeginPlay()
{
	Super::BeginPlay();
}

void UHitscanFire::AbilityStart(AActor* InTarget)
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

void UHitscanFire::AbilityShot(double InDamageCoefficient, AActor* InTarget)
{
	Super::AbilityShot(InDamageCoefficient, InTarget);

	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	// 충돌 검사
	FHitResult hit = UtilCollision::LineTraceForward(GetWorld(), ownerPawn, AttackRange, DebugOnOff);
	AActor *hitActor = hit.GetActor();

	// 데미지 결정
	float damage = CharacterStatAtk * AtkCoefficient;
	
	// 데미지 정보 전달
	if (hitActor != nullptr && hitActor != ownerPawn)
		UGameplayStatics::ApplyDamage(hitActor, damage * InDamageCoefficient, OwnerController, ownerPawn, nullptr);

	HitEffectFTransform.Location = hit.Location;
	if (HitParticles)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitParticles, HitEffectFTransform);
}
