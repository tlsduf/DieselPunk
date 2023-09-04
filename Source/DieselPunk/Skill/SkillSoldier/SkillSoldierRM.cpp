// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierRM.h"
#include "../../Actor\ProjectileBase.h"
#include "..\..\Character\CharacterPC.h"

#include <GameFramework/PlayerController.h>
#include <Components/SkeletalMeshComponent.h>

USkillSoldierRM::USkillSoldierRM() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierRM::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierRM::SkillStarted()
{
	Super::SkillStarted();

	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;

	FVector lineTraceLocation;
	FRotator lineTraceRotation;
	ownerController->GetPlayerViewPoint(lineTraceLocation, lineTraceRotation);
	FVector end = lineTraceLocation + lineTraceRotation.Vector() * 10000;
	FVector shotLocation = ownerPawn->GetMesh()->GetSocketLocation("Muzzle_01");
	FRotator shotRotation = (end - shotLocation).Rotation();
	// projectile spawn
	if(ProjectileClass)
	{
		FActorSpawnParameters param = FActorSpawnParameters();
		param.Owner = GetOwner();
		Projectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, shotLocation, shotRotation, param);
	}
}
void USkillSoldierRM::SkillCompleted()
{
	Super::SkillCompleted();
	
}
