// Fill out your copyright notice in the Description page of Project Settings.

#include "HitscanFire.h"
#include "../../Character/CharacterNPC.h"
#include "../../Util/UtilCollision.h"

#include <Kismet/GameplayStatics.h>

UHitscanFire::UHitscanFire()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void UHitscanFire::BeginPlay()
{
	Super::BeginPlay();
}

void UHitscanFire::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHitscanFire::AbilityStart(AActor* inTarget)
{
	Super::AbilityStart(inTarget);

	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	// 충돌 검사
	FHitResult hit = UtilCollision::LineTraceForward(GetWorld(), ownerPawn, AttackRange, DebugOnOff);
	AActor *hitActor = hit.GetActor();

	// 데미지 결정
	float damage = CharacterStatAtk * AtkCoefficient;
	
	// 데미지 정보 전달
	if (hitActor != nullptr && hitActor != ownerPawn)
		UGameplayStatics::ApplyDamage(hitActor, damage, OwnerController, ownerPawn, nullptr);

	HitEffectFTransform.Location = hit.Location;
	if (HitParticles)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitParticles, HitEffectFTransform);
}
