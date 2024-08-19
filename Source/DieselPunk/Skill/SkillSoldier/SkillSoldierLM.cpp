// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierLM.h"
#include "../../Actor\ProjectileBase.h"
#include "../../Character/CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Handler/CoolTimeHandler.h"
#include "../../Skill/SkillSoldier/SkillSoldierR.h"
#include "../../Util/UtilCollision.h"

#include <Kismet/GameplayStatics.h>
#include <Components/SkeletalMeshComponent.h>


USkillSoldierLM::USkillSoldierLM() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierLM::BeginPlay()
{
	Super::BeginPlay();

	TempCoolTime = CoolTime;
}

void USkillSoldierLM::SkillTriggered()
{
	Super::SkillTriggered();

	AbilityStart();
}

void USkillSoldierLM::AbilityStart(AActor* InTarget)
{
	Super::AbilityStart(InTarget);
	
	// 쿨타임
	CoolTimeHandler->SetCoolTime(CoolTime);
	
	auto ownerPawn = Cast<ACharacterBase>(OwnerCharacter);
	if (auto pc = Cast<ACharacterPC>(ownerPawn))
		pc->StopJog();
	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance()))	
		animInst->AttackSign(EAbilityType::MouseLM);
}

void USkillSoldierLM::AbilityShot(double InDamageCoefficient, AActor* InTarget)
{
	Super::AbilityShot(InDamageCoefficient, InTarget);
	
	// 라인트레이스로 최종경로설정
	FVector lineTraceLocation;
	FRotator lineTraceRotation;
	OwnerController->GetPlayerViewPoint(lineTraceLocation, lineTraceRotation);
	
	FVector endLocation = lineTraceLocation + lineTraceRotation.Vector() * 10000;
	FHitResult hit;
	bool Hit = GetWorld()->LineTraceSingleByChannel(hit, lineTraceLocation, endLocation, ECC_DP_Player);	//라인 트레이스 

	// Muzzle Location by BoneName
	FVector shotLocation =OwnerCharacterPC->GetMesh()->GetSocketLocation("Muzzle_01");
	FRotator shotRotation = (Hit ? hit.Location - shotLocation : endLocation - shotLocation).Rotation();	//트레이스 히트된 위치로 발사
	//FRotator shotRotation = (endLocation - shotLocation).Rotation();	//고정된 위치로 발사

	
	//===========================================
	// * MainAction // Projectile Spawn
	if(ProjectileClass && !EBuffOn)
	{
		//FString resourcePath = UtilPath::GetSkillPath( TEXT("SkillActor/BP_ProjectileBullet") );
		//ProjectileClass = LoadClass<ASoldierProjectile>( NULL, *resourcePath );
		FTransform spawnTransform( shotRotation, shotLocation);
		AProjectileBase *Projectile = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
		Projectile->SetDamage(Damage);
		Projectile->FinishSpawning(spawnTransform);
	}
	// * or if EBuffOn is true
	if(ProjectileEBuffClass && EBuffOn)
	{
		FTransform spawnTransform( shotRotation, shotLocation);
		AProjectileBase *Projectile = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileEBuffClass, spawnTransform, GetOwner());
		Projectile->SetDamage(Damage * 1.5);
		Projectile->FinishSpawning(spawnTransform);
		--Magazine;

		// 탄창 수 다 소진 시 버프 off
		if (Magazine == 0)
		{
			EBuffOn = false;
			CoolTime = TempCoolTime;
		}
	}
}
