// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileAttack.h"
#include "..\../Actor\ProjectileBase.h"
#include "..\..\Character\CharacterNPC.h"

#include <GameFramework/PlayerController.h>
#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>


UProjectileAttack::UProjectileAttack() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void UProjectileAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UProjectileAttack::SkillTriggered()
{
	Super::SkillTriggered();

	auto ownerPawn = Cast<ACharacterNPC>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;

	//const FRotator shotRotation = ownerPawn->GetActorForwardVector().Rotation();
	ShotRotation = ownerController->GetControlRotation();
	
	// projectile spawn
	if(ProjectileBaseClass)
	{
		ShotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
		FTransform SpawnTransform = FTransform( ShotRotation, ShotLocation);
		ProjectileBase = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileBaseClass, SpawnTransform, GetOwner());
		ProjectileBase->FinishSpawning(SpawnTransform);
	}
}
