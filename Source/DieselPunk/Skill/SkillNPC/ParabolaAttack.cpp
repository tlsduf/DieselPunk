// Fill out your copyright notice in the Description page of Project Settings.

#include "ParabolaAttack.h"
#include "..\..\Character\CharacterNPC.h"
#include "../../Animation/TurretAnimInstace.h"
#include "../../Actor/ParabolaBase.h"

#include <Kismet/GameplayStatics.h>
#include <Components/SkeletalMeshComponent.h>
#include "../../Manager/ObjectManager.h"

#include "DrawDebugHelpers.h"


UParabolaAttack::UParabolaAttack() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void UParabolaAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UParabolaAttack::AbilityStart(AActor* InTarget)
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

void UParabolaAttack::AbilityShot(double InDamageCoefficient, AActor* InTarget)
{
	Super::AbilityShot(InDamageCoefficient, InTarget);

	if(InTarget == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("타겟정보 NULL"));
		return;
	}

	
	// parabola spawn
	if(ParabolaBaseClass)
	{
		FSpawnParam spawnParam;
		spawnParam.Location = OwnerCharacter->GetMesh()->GetSocketLocation("Grenade_socket");
		spawnParam.Rotation = OwnerCharacter->GetMesh()->GetSocketRotation("Grenade_socket");

		TWeakObjectPtr<ACharacterBase> ownerPtr = OwnerCharacter;
		FVector goalLoc = InTarget->GetActorLocation();
		spawnParam.CallBackSpawn = [ownerPtr, goalLoc](AActor* spawnActor)
		{
			if(!ownerPtr.IsValid())
				return;
			AParabolaBase* para = Cast<AParabolaBase>(spawnActor);
			para->SetOwnerPlayer(ownerPtr.Get());
			para->SetGoalLocation(goalLoc);
		};
		
		FObjectManager::GetInstance()->CreateActor<AParabolaBase>(ParabolaBaseClass, spawnParam);
	}
}
