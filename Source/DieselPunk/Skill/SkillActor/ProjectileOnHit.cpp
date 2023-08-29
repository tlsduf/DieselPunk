// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileOnHit.h"

#include <Components/CapsuleComponent.h>


AProjectileOnHit::AProjectileOnHit()
{
}

void AProjectileOnHit::BeginPlay()
{
	Super::BeginPlay();

	CapsuleComponent->OnComponentHit.AddDynamic(this, &AProjectileOnHit::OnHit);
	//CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectileGranade::BeginOverlapEvent);
}

void AProjectileOnHit::_OnHit(UPrimitiveComponent *HitComp, AActor *HitActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &HitResult)
{
	Super::_OnHit(HitComp, HitActor, OtherComp, NormalImpulse, HitResult);
}

void AProjectileOnHit::_BeginOverlapEvent(class UPrimitiveComponent* InHitComp, class AActor* InOtherActor, class UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult & InSweepResult)
{
	Super::_BeginOverlapEvent(InHitComp, InOtherActor, InOtherComp, InOtherBodyIndex, InbFromSweep, InSweepResult);
}