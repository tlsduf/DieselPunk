// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeAttack.h"
#include "../../Util/UtilCollision.h"
#include "../../Character/CharacterNPC.h"
#include "..\..\Animation\MonsterAnimInstance.h"

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

void UMeleeAttack::AbilityStart(AActor* InTarget)
{
	Super::AbilityStart(InTarget);
	
	if(InTarget == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("타겟정보 NULL"));
		return;
	}
	
	auto ownerPawn = Cast<ACharacterBase>(OwnerCharacter);
	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance()))	
		animInst->AttackSign(EAbilityType::MouseLM);
}

void UMeleeAttack::AbilityShot(double InDamageCoefficient, AActor* InTarget)
{
	Super::AbilityShot(InDamageCoefficient, InTarget);

	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	// 충돌 검사
	TArray<FHitResult> sweepResults;
	FVector startLocation = ownerPawn->GetActorLocation() + ownerPawn->GetActorForwardVector() * AttackStartPoint;
	FVector endLocation = startLocation + ownerPawn->GetActorForwardVector() * AttackRange;
	UtilCollision::CapsuleSweepMulti(GetWorld(), sweepResults, startLocation, endLocation, AttackRadius, ECausorType::Enemy, ownerPawn->GetDebugOnOff());
	
	// 데미지 전달
	if(!sweepResults.IsEmpty())
	{
		AActor* hitActor;
		for (auto It = sweepResults.CreateIterator(); It; It++)
		{
			hitActor = It->GetActor();
			UGameplayStatics::ApplyDamage(hitActor, Damage * InDamageCoefficient, OwnerController, ownerPawn, nullptr);
		}
	}
}