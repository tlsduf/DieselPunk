// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierRM.h"
#include "../../Actor\ProjectileBase.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Handler/CoolTimeHandler.h"

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

void USkillSoldierRM::SkillTriggered()
{
	Super::SkillTriggered();

	AbilityStart();
}

void USkillSoldierRM::AbilityStart(AActor* InTarget)
{
	Super::AbilityStart(InTarget);
	
	// 쿨타임
	CoolTimeHandler->SetCoolTime(CoolTime);
	
	auto ownerPawn = Cast<ACharacterBase>(OwnerCharacter);
	if (auto pc = Cast<ACharacterPC>(ownerPawn))
		pc->StopJog();
	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance()))	
		animInst->AttackSign(EAbilityType::MouseRM);
}

void USkillSoldierRM::AbilityShot(double InDamageCoefficient, AActor* InTarget)
{
	Super::AbilityShot(InDamageCoefficient, InTarget);
	
	// 쿨타임 && 스킬플레이타임
	CoolTimeHandler->SetCoolTime(CoolTime);
	OwnerCharacterPC->SkillActivating[EAbilityType::MouseRM] = true;
	TWeakObjectPtr<USkillSoldierRM> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(PlaySkillTHandle, [thisPtr]()
	{
		if(thisPtr.IsValid())
			thisPtr->OwnerCharacterPC->SkillActivating[EAbilityType::MouseRM] = false;
	},SkillPlayTime, false);
	
	FVector lineTraceLocation;
	FRotator lineTraceRotation;
	OwnerController->GetPlayerViewPoint(lineTraceLocation, lineTraceRotation);
	
	FVector endLocation = lineTraceLocation + lineTraceRotation.Vector() * 10000;
	FVector shotLocation = OwnerCharacterPC->GetMesh()->GetSocketLocation("Muzzle_01");
	FRotator shotRotation = (endLocation - shotLocation).Rotation();
	
	// projectile spawn
	if(ProjectileClass)
	{
		FTransform spawnTransform( shotRotation, shotLocation);
		AProjectileBase *Projectile = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
		Projectile->SetDamage(Damage);
		Projectile->FinishSpawning(spawnTransform);
	}
}