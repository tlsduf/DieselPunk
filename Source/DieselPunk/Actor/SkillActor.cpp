// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillActor.h"
#include "../Character/CharacterBase.h"

#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Kismet/GameplayStatics.h>


// =============================================================
// 생성자
// =============================================================
ASkillActor::ASkillActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

// =============================================================
// BeginPlay
// =============================================================
void ASkillActor::BeginPlay()
{
	Super::BeginPlay();

	if(GetOwner() != nullptr)
	{
		OwnerCharacter = Cast<ACharacterBase>(GetOwner());
		OwnerController = OwnerCharacter->GetController();
	}
}

// =============================================================
// Tick
// =============================================================
void ASkillActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASkillActor::InitTransformOffset()
{
	AddActorLocalTransform(OffsetTransform);
}
