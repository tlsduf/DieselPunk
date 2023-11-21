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

void UProjectileAttack::AbilityStart()
{
	Super::AbilityStart();

	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);
	
	//const FRotator shotRotation = ownerPawn->GetActorForwardVector().Rotation();
	//FRotator shotRotation = ownerController->GetControlRotation();
	
	// projectile spawn
	if(ProjectileBaseClass)
	{
		FVector shotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
		FRotator shotRotation = ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket");
		FTransform SpawnTransform = FTransform( shotRotation, shotLocation);
		ProjectileBase = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileBaseClass, SpawnTransform, GetOwner());
		ProjectileBase->FinishSpawning(SpawnTransform);
	}
}
