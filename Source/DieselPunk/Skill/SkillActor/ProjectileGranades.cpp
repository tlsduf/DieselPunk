// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileGranades.h"

#include <Components/CapsuleComponent.h>


AProjectileGranade::AProjectileGranade()
{
}

void AProjectileGranade::BeginPlay()
{
	Super::BeginPlay();
	
	if(CollisionResponses == ECollisionResponsesType::OnHit && !bUseOneTick)
	{
		CapsuleComponent->OnComponentHit.AddDynamic(this, &AProjectileGranade::OnHit);
	}
	else if(CollisionResponses == ECollisionResponsesType::Overlap && !bUseOneTick)
	{
		CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectileGranade::BeginOverlapEvent);
	}
}

void AProjectileGranade::_OnHit(UPrimitiveComponent *HitComp, AActor *HitActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &HitResult)
{
	Super::_OnHit(HitComp, HitActor, OtherComp, NormalImpulse, HitResult);
}

void AProjectileGranade::_BeginOverlapEvent(class UPrimitiveComponent* InHitComp, class AActor* InOtherActor, class UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult & InSweepResult)
{
	Super::_BeginOverlapEvent(InHitComp, InOtherActor, InOtherComp, InOtherBodyIndex, InbFromSweep, InSweepResult);
}