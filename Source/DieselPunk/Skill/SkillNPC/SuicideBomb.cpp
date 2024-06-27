// Fill out your copyright notice in the Description page of Project Settings.

#include "SuicideBomb.h"
#include "..\..\Character\CharacterNPC.h"
#include "../../Animation/TurretAnimInstace.h"

#include <Kismet/GameplayStatics.h>
#include <Components/SkeletalMeshComponent.h>

#include "DrawDebugHelpers.h"
#include "DieselPunk/Component/StatControlComponent.h"


USuicideBomb::USuicideBomb() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USuicideBomb::BeginPlay()
{
	Super::BeginPlay();
}

void USuicideBomb::AbilityStart(AActor* InTarget)
{
	Super::AbilityStart(InTarget);
	
	auto ownerPawn = Cast<ACharacterBase>(OwnerCharacter);
	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance()))	
		animInst->AttackSign(EAbilityType::MouseLM);

	Super::AbilityShot(1.0, InTarget);
}

void USuicideBomb::AbilityShot(double InDamageCoefficient, AActor* InTarget)
{
	Super::AbilityShot(InDamageCoefficient, InTarget);

	auto ownerPawn = Cast<ACharacterBase>(OwnerCharacter);
	if(!ownerPawn)
		return;
	
	FCollisionQueryParams param;
	param.AddIgnoredActor(ownerPawn);
	TArray<FOverlapResult> overlapResults;
	if(GetWorld()->OverlapMultiByChannel(overlapResults, ownerPawn->GetActorLocation(), FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(Radius), param))
	{
		for(const FOverlapResult& result : overlapResults)
		{
			ACharacterBase* charBase = Cast<ACharacterBase>(result.GetActor());
			if(!charBase)
				continue;
			
			if(ownerPawn->GetCharacterType() == ECharacterType::Player || ownerPawn->GetCharacterType() == ECharacterType::Turret)
			{
				if(charBase->GetCharacterType() == ECharacterType::Monster)
					UGameplayStatics::ApplyDamage(charBase, Damage * InDamageCoefficient, OwnerController, ownerPawn, nullptr);
			}
			else if(ownerPawn->GetCharacterType() == ECharacterType::Monster)
			{
				if(charBase->GetCharacterType() == ECharacterType::Player
				|| charBase->GetCharacterType() == ECharacterType::Turret
				|| charBase->GetCharacterType() == ECharacterType::Installation)
					UGameplayStatics::ApplyDamage(charBase, Damage * InDamageCoefficient, OwnerController, ownerPawn, nullptr);
			}
		}
	}
	DrawDebugSphere(GetWorld(), ownerPawn->GetActorLocation(), Radius, 12, FColor::Red, false, 3, 0, 2);
	ownerPawn->GetStatControlComponent()->SetStat(ECharacterStatType::Hp, 0);
}
