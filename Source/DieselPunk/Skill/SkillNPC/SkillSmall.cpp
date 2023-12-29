// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSmall.h"
#include "..\../Actor\ProjectileBase.h"
#include "..\..\Character\CharacterNPC.h"

#include <GameFramework/PlayerController.h>
#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>


USkillSmall::USkillSmall() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSmall::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSmall::AbilityStart()
{
	Super::AbilityStart();

	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	// 데미지 결정
	CaptureDamage = Atk * AtkCoefficient;
	
	ShotRotation = OwnerController->GetControlRotation();
	
	// projectile spawn
	if(ProjectileBaseClass)
	{
		ShotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
		FTransform SpawnTransform = FTransform( ShotRotation, ShotLocation);
		ProjectileBase1 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileBaseClass, SpawnTransform, GetOwner());
		ProjectileBase1->Damage = CaptureDamage;
		ProjectileBase1->FinishSpawning(SpawnTransform);

		ShotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket2");
		TWeakObjectPtr<USkillSmall> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(
		FireHandle2, [thisPtr](){
			if(thisPtr.IsValid())
			{
				FTransform SpawnTransform = FTransform( thisPtr->ShotRotation, thisPtr->ShotLocation);
				thisPtr->ProjectileBase2 = thisPtr->GetWorld()->SpawnActorDeferred<AProjectileBase>(thisPtr->ProjectileBaseClass, SpawnTransform, thisPtr->GetOwner());
				thisPtr->ProjectileBase2->Damage = thisPtr->CaptureDamage;
				thisPtr->ProjectileBase2->FinishSpawning(SpawnTransform);
			}
		},0.1f, false);

		ShotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket3");
		GetWorld()->GetTimerManager().SetTimer(
		FireHandle3, [thisPtr](){
			if(thisPtr.IsValid())
			{
				FTransform SpawnTransform = FTransform( thisPtr->ShotRotation, thisPtr->ShotLocation);
				thisPtr->ProjectileBase3 = thisPtr->GetWorld()->SpawnActorDeferred<AProjectileBase>(thisPtr->ProjectileBaseClass, SpawnTransform, thisPtr->GetOwner());
				thisPtr->ProjectileBase3->Damage = thisPtr->CaptureDamage;
				thisPtr->ProjectileBase3->FinishSpawning(SpawnTransform);
			}
		},0.2f, false);

		ShotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket4");
		GetWorld()->GetTimerManager().SetTimer(
		FireHandle4, [thisPtr](){
			if(thisPtr.IsValid())
			{
				FTransform SpawnTransform = FTransform( thisPtr->ShotRotation, thisPtr->ShotLocation);
				thisPtr->ProjectileBase4 = thisPtr->GetWorld()->SpawnActorDeferred<AProjectileBase>(thisPtr->ProjectileBaseClass, SpawnTransform, thisPtr->GetOwner());
				thisPtr->ProjectileBase4->Damage = thisPtr->CaptureDamage;
				thisPtr->ProjectileBase4->FinishSpawning(SpawnTransform);
			}
		},0.3f, false);
	}
}
