// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierQ.h"
#include "../../Actor\ProjectileBase.h"
#include "../../Character/CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Handler/CoolTimeHandler.h"

#include <GameFramework/PlayerController.h>
#include <Components/SkeletalMeshComponent.h>

USkillSoldierQ::USkillSoldierQ() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierQ::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierQ::SkillTriggered()
{
	Super::SkillTriggered();
	
	// 쿨타임 && 스킬플레이타임
	CoolTimeHandler->SetCoolTime(CoolTime);
	OwnerCharacterPC->SkillActivating[EAbilityType::SkillQ] = true;
	TWeakObjectPtr<USkillSoldierQ> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(PlaySkillTHandle, [thisPtr]()
	{
		if(thisPtr.IsValid())
			thisPtr->OwnerCharacterPC->SkillActivating[EAbilityType::SkillQ] = false;
	},SkillPlayTime, false);
	
	//애니메이션 재생
	if(	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(OwnerCharacterPC->GetMesh()->GetAnimInstance()))
		animInst->PlayMontage(EAbilityType::SkillQ, ESoldierSkillMontageType::Attack);
}

// 몽타주에서 실행합니다.
void USkillSoldierQ::Shot()
{
	FVector shotLocation = OwnerCharacterPC->GetMesh()->GetSocketLocation("Grenade_socket");
	const FRotator shotRotation = OwnerController->GetControlRotation();
	FRotator spawnPitch = FRotator(0, 0, 0);
	
	if (30 <= shotRotation.Pitch && shotRotation.Pitch <= 90)
		spawnPitch.Pitch = 60;
	else
		spawnPitch.Pitch = shotRotation.Pitch + 30;
	
	// projectile spawn
	if(ProjectileClass)
	{
		// 투사체1
		FTransform spawnTransform = FTransform( FRotator(spawnPitch.Pitch, shotRotation.Yaw, 0), shotLocation);
		AProjectileBase *Projectile = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
		Projectile->Damage = Damage;
		Projectile->FinishSpawning(spawnTransform);
	}
}
