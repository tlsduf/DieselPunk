// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeAttack.h"
#include "../../Util/UtilCollision.h"
#include "../../Character/CharacterNPC.h"
#include "../../Animation/MonsterAnimInstace.h"

#include <Kismet/GameplayStatics.h>
#include <Components/SkeletalMeshComponent.h>

UMeleeAttack::UMeleeAttack()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void UMeleeAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UMeleeAttack::AbilityStart()
{
	Super::AbilityStart();

	Attack();
}

float UMeleeAttack::PlayAnim()
{
	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	//애니메이션 재생?
	UMonsterAnimInstace* animInst = Cast<UMonsterAnimInstace>(ownerPawn->GetMesh()->GetAnimInstance());
	if (!animInst)
		return 0;
	
	return animInst->PlayMontage(EAbilityType::None, EMonsterSkillMontageType::Attack);
}

void UMeleeAttack::Attack()
{
	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	// 충돌 검사
	TArray<FHitResult> sweepResults;
	FVector startLocation = ownerPawn->GetActorLocation() + ownerPawn->GetActorForwardVector() * AttackStartPoint;
	FVector endLocation = startLocation + ownerPawn->GetActorForwardVector() * AttackRange;
	UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, EProjectileOwnerType::Enemy, DebugOnOff);

	// 데미지 결정
	float damage = Atk * AtkCoefficient;
	
	// 데미지 전달
	if(!sweepResults.IsEmpty())
	{
		AActor* hitActor;
		for (auto It = sweepResults.CreateIterator(); It; It++)
		{
			hitActor = It->GetActor();
			UGameplayStatics::ApplyDamage(hitActor, damage, OwnerController, ownerPawn, nullptr);
		}
	}
}
