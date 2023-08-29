// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeAttack.h"
#include "../Util/UtilCollision.h"
#include "../Character/CharacterNPC.h"
#include "../Animation/MonsterAnimInstace.h"

#include <Kismet/GameplayStatics.h>
#include <GameFramework/PlayerController.h>
#include <Components/SkeletalMeshComponent.h>

void UMeleeAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UMeleeAttack::SkillTriggered()
{
	Super::SkillTriggered();

	_Attack();
}

float UMeleeAttack::Attack()
{
	auto *ownerPawn = Cast<ACharacterNPC>(GetOwner());
	if (ownerPawn == nullptr)
		return 0;

	//애니메이션 재생?
	UMonsterAnimInstace* animInst = Cast<UMonsterAnimInstace>(ownerPawn->GetMesh()->GetAnimInstance());
	if (!animInst)
		return 0;
	
	return animInst->PlayMontage(EAbilityType::None, EMonsterSkillMontageType::Attack);
}

void UMeleeAttack::_Attack()
{
	// 데미지 프레임워크를 위한 Instigator, Causer
	auto ownerPawn = Cast<ACharacterNPC>(GetOwner());
	if (ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if (ownerController == nullptr)
		return;

	// 충돌 검사
	TArray<FHitResult> sweepResults;
	FVector startLocation = ownerPawn->GetActorLocation() + ownerPawn->GetActorForwardVector() * AttackStartPoint;
	FVector endLocation = startLocation + ownerPawn->GetActorForwardVector() * AttackRange;
	UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, false, DebugOnOff);

	// 데미지 전달
	if(!sweepResults.IsEmpty())
	{
		AActor *hitActor;
		for (auto It = sweepResults.CreateIterator(); It; It++)
		{
			hitActor = It->GetActor();
			UGameplayStatics::ApplyDamage(hitActor, Damage, ownerController, ownerPawn, nullptr);
		}
	}
}
