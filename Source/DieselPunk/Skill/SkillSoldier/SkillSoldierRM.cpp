// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierRM.h"
#include "../../Actor\ProjectileBase.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Handler/CoolTimeHandler.h"

#include <GameFramework/PlayerController.h>
#include <Components/SkeletalMeshComponent.h>
#include <TimerManager.h>

USkillSoldierRM::USkillSoldierRM() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierRM::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierRM::SkillTriggered()
{
	Super::SkillTriggered();
	
	auto ownerPawn = Cast<ACharacterPC>(OwnerCharacter);
	
	// 쿨타임 감소
	float CoolDown = 0.2 * ownerPawn->PCSkillManager.SoldierMouseRMUpgradeType[ESoldierMouseRMUpgradeType::CoolDown];
	// 쿨타임!!!!!!!!!!!!!!!!!!
	CoolTimeHandler->SetCoolTime(CoolTime - CoolDown);
	ownerPawn->SkillActivating[EAbilityType::MouseRM] = true;
	GetWorld()->GetTimerManager().SetTimer(
	PlaySkillTHandle, [this]()
	{ Cast<ACharacterPC>(GetOwner())->SkillActivating[EAbilityType::MouseRM] = false; },
	SkillPlayTime, false);
	
	FVector lineTraceLocation;
	FRotator lineTraceRotation;
	OwnerController->GetPlayerViewPoint(lineTraceLocation, lineTraceRotation);
	FVector end = lineTraceLocation + lineTraceRotation.Vector() * 10000;
	FVector shotLocation = ownerPawn->GetMesh()->GetSocketLocation("Muzzle_01");
	FRotator shotRotation = (end - shotLocation).Rotation();
	
	// projectile spawn
	if(ProjectileClass)
	{
		FTransform SpawnTransform( shotRotation, shotLocation);
		Projectile = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, SpawnTransform, GetOwner());
		
		Projectile->Damage += 10 * ownerPawn->PCSkillManager.SoldierMouseRMUpgradeType[ESoldierMouseRMUpgradeType::DamageUp];
		
		Projectile->FinishSpawning(SpawnTransform);
	}
}
