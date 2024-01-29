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

void USkillSmall::AbilityStart(AActor* inTarget)
{
	Super::AbilityStart(inTarget);

	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	// 람다함수 캡쳐용 변수
	CaptureDamage = Damage;
	
	ShotRotation = OwnerController->GetControlRotation();
	
	// projectile spawn
	if(ProjectileBaseClass)
	{
		ShotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
		FTransform SpawnTransform = FTransform( ShotRotation, ShotLocation);
		AProjectileBase *ProjectileBase1 = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileBaseClass, SpawnTransform, GetOwner());
		ProjectileBase1->Damage = CaptureDamage;
		ProjectileBase1->FinishSpawning(SpawnTransform);

		ShotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket2");
		TWeakObjectPtr<USkillSmall> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(
		FireHandle2, [thisPtr](){
			if(thisPtr.IsValid())
			{
				FTransform SpawnTransform = FTransform( thisPtr->ShotRotation, thisPtr->ShotLocation);
				AProjectileBase *ProjectileBase2 = thisPtr->GetWorld()->SpawnActorDeferred<AProjectileBase>(thisPtr->ProjectileBaseClass, SpawnTransform, thisPtr->GetOwner());
				ProjectileBase2->Damage = thisPtr->CaptureDamage;
				ProjectileBase2->FinishSpawning(SpawnTransform);
			}
		},0.1f, false);

		ShotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket3");
		GetWorld()->GetTimerManager().SetTimer(
		FireHandle3, [thisPtr](){
			if(thisPtr.IsValid())
			{
				FTransform SpawnTransform = FTransform( thisPtr->ShotRotation, thisPtr->ShotLocation);
				AProjectileBase *ProjectileBase3 = thisPtr->GetWorld()->SpawnActorDeferred<AProjectileBase>(thisPtr->ProjectileBaseClass, SpawnTransform, thisPtr->GetOwner());
				ProjectileBase3->Damage = thisPtr->CaptureDamage;
				ProjectileBase3->FinishSpawning(SpawnTransform);
			}
		},0.2f, false);

		ShotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket4");
		GetWorld()->GetTimerManager().SetTimer(
		FireHandle4, [thisPtr](){
			if(thisPtr.IsValid())
			{
				FTransform SpawnTransform = FTransform( thisPtr->ShotRotation, thisPtr->ShotLocation);
				AProjectileBase *ProjectileBase4 = thisPtr->GetWorld()->SpawnActorDeferred<AProjectileBase>(thisPtr->ProjectileBaseClass, SpawnTransform, thisPtr->GetOwner());
				ProjectileBase4->Damage = thisPtr->CaptureDamage;
				ProjectileBase4->FinishSpawning(SpawnTransform);
			}
		},0.3f, false);
	}
}
