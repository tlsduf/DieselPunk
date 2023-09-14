// Fill out your copyright notice in the Description page of Project Settings.


#include "SoldierProjectile.h"
#include "../Character/CharacterNPC.h"
#include "../Util/UtilCollision.h"

#include <Kismet/GameplayStatics.h>

ASoldierProjectile::ASoldierProjectile()
{
}

void ASoldierProjectile::OneTickTask()
{
	Super::OneTickTask();

	auto ownerPawn = Cast<APawn>(DpGetPlayer());
	if(ownerPawn == nullptr)
		return;
	
	TArray<FHitResult> sweepResults;
	FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
	FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
	UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, ProjectileOwnerType, DebugOnOff);
	if(!sweepResults.IsEmpty())
	{
		for (auto It = sweepResults.CreateIterator(); It; It++)
		{
			auto enemy = Cast<ACharacterNPC>(Cast<APawn>(It->GetActor()));
			if(enemy != nullptr)
				if(isStackin)
					enemy->SoldierStack = enemy->SoldierStack + Stack;
		}
	}
}

void ASoldierProjectile::_OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult)
{
	Super::_OnHit(InHitComp, InOtherActor, InOtherComp, InNormalImpulse, InHitResult);

	
	auto ownerPawn = Cast<APawn>(DpGetPlayer());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;
	
	// 스택
	if (InOtherActor != nullptr && InOtherActor != ownerPawn)
	{
		if(DoRadialDamage)
		{
			TArray<FHitResult> sweepResults;
			FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
			FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
			UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, ProjectileOwnerType, DebugOnOff);
			if(!sweepResults.IsEmpty())
			{
				for (auto It = sweepResults.CreateIterator(); It; It++)
				{
					auto enemy = Cast<ACharacterNPC>(Cast<APawn>(It->GetActor()));
					if(enemy != nullptr)
						if(isStackin)
							enemy->SoldierStack = enemy->SoldierStack + Stack;
				}
			}
		}
		else
		{
			auto enemy = Cast<ACharacterNPC>(Cast<APawn>(InOtherActor));
			if(enemy != nullptr)
			{
				if(IsStackBoom)
				{
					UGameplayStatics::ApplyDamage(InOtherActor, (enemy->SoldierStack * StackDamage), ownerController, ownerPawn, nullptr);
					enemy->SoldierStack = 0;
				}
				if(isStackin)
					enemy->SoldierStack = enemy->SoldierStack + Stack;
			}
		}
	}
}

void ASoldierProjectile::_BeginOverlapEvent(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult& InSweepResult)
{
	Super::_BeginOverlapEvent(InHitComp, InOtherActor, InOtherComp, InOtherBodyIndex, InbFromSweep, InSweepResult);
	
	auto ownerPawn = Cast<APawn>(DpGetPlayer());
	if(ownerPawn == nullptr)
		return;
	
	// 스택
	if (InOtherActor != nullptr && InOtherActor != ownerPawn)
	{
		if(DoRadialDamage)
		{
			TArray<FHitResult> sweepResults;
			FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
			FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
			UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, ProjectileOwnerType, DebugOnOff);
			if(!sweepResults.IsEmpty())
			{
				for (auto It = sweepResults.CreateIterator(); It; It++)
				{
					auto enemy = Cast<ACharacterNPC>(Cast<APawn>(It->GetActor()));
					if(enemy != nullptr)
						if(isStackin)
							enemy->SoldierStack = enemy->SoldierStack + Stack;
				}
			}
		}
		else
		{
			auto enemy = Cast<ACharacterNPC>(Cast<APawn>(InOtherActor));
			if(enemy != nullptr)
				if(isStackin)
					enemy->SoldierStack = enemy->SoldierStack + Stack;
		}
	}
}
