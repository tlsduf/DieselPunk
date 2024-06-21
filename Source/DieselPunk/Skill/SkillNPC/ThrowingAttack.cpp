// Fill out your copyright notice in the Description page of Project Settings.

#include "ThrowingAttack.h"
#include "..\..\Character\CharacterNPC.h"
#include "../../Util/SplineConstructor.h"
#include "../../Animation/TurretAnimInstace.h"

#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>
#include <DrawDebugHelpers.h>

#include "Components/CapsuleComponent.h"
#include "DieselPunk/Actor/ThrowableActor.h"
#include "DieselPunk/Manager/ObjectManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


UThrowingAttack::UThrowingAttack() : Super()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UThrowingAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UThrowingAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UThrowingAttack::AbilityStart(AActor* InTarget)
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

	FSpawnParam param;
	param.Location = FVector::ZeroVector;
	param.Rotation = FRotator::ZeroRotator;
	param.CallBackSpawn = nullptr;
	ThrowActorId = FObjectManager::GetInstance()->CreateActor<AActor>(ThrowingActorClass, param);
	AActor* throwActor = FObjectManager::GetInstance()->FindActor(ThrowActorId);
	IThrowableInterface* throwInterface = Cast<IThrowableInterface>(throwActor);
	if(throwInterface)
		throwInterface->ThrowReady(OwnerCharacter);
	AThrowableActor* throwableActor = Cast<AThrowableActor>(throwActor);
	if(throwableActor)
		throwableActor->SetDamage(Damage);
	throwActor->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("ThrowingActorSocket"));
	
	LOG_SCREEN(FColor::White, TEXT("를 사용합니다."))
}

// 설정된 Transform으로 투사체를 생성합니다.
void UThrowingAttack::AbilityShot(AActor* InTarget)
{
	if(InTarget == nullptr)
		return;

	if(MaxRange <= 0)
	{
		LOG_SCREEN(FColor::Red, TEXT("액터: %s의 ThrowingAttack: %s의 MaxRange가 0보다 작습니다."), *OwnerCharacter->GetName(), *GetName())
		return;
	}

	if(!FObjectManager::IsValidId(ThrowActorId))
		return;
	
	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	
	FVector startLocation = ownerPawn->GetMesh()->GetSocketLocation(TEXT("ThrowingActorSocket"));
	FVector goalLocation = InTarget->GetActorLocation();
	FVector outVelocity = FVector::ZeroVector;
	//if(UGameplayStatics::SuggestProjectileVelocity(this, outVelocity, startLocation, goalLocation, InitSpeed, HighArc, 0, GetWorld()->GetGravityZ(), ESuggestProjVelocityTraceOption::DoNotTrace))
	if(UGameplayStatics::SuggestProjectileVelocity_CustomArc(this, outVelocity, startLocation, goalLocation, GetWorld()->GetGravityZ(), ArcValue))
	{
		float flightTime = FVector::Distance(startLocation, goalLocation) * MaxFlightTime / MaxRange;
		FPredictProjectilePathParams predictParams(20.f, startLocation, outVelocity, flightTime);
		predictParams.DrawDebugTime = flightTime;
		predictParams.DrawDebugType = EDrawDebugTrace::Type::ForDuration;
		predictParams.OverrideGravityZ = GetWorld()->GetGravityZ();
		FPredictProjectilePathResult result;
		UGameplayStatics::PredictProjectilePath(this, predictParams, result);

		if(AActor* throwActor = FObjectManager::GetInstance()->FindActor(ThrowActorId))
		{
			throwActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			
			IThrowableInterface* throwInterface = Cast<IThrowableInterface>(throwActor);
			if(!throwInterface)
				return;

			throwInterface->ThrowExecute(OwnerCharacter);
				
			UActorComponent* actorComp = throwActor->GetComponentByClass(UMovementComponent::StaticClass());
			if(UCharacterMovementComponent* charMovementComp = Cast<UCharacterMovementComponent>(actorComp))
			{
				TWeakObjectPtr<UCharacterMovementComponent> moveCompPtr = charMovementComp;
				throwActor->GetWorldTimerManager().SetTimerForNextTick([moveCompPtr, outVelocity]()
				{
					if(moveCompPtr.IsValid())
						moveCompPtr->AddImpulse(outVelocity);
				});
			}
			else if(UProjectileMovementComponent* projMovementComp = Cast<UProjectileMovementComponent>(actorComp))
			{
				TWeakObjectPtr<UProjectileMovementComponent> moveCompPtr = projMovementComp;
				throwActor->GetWorldTimerManager().SetTimerForNextTick([moveCompPtr, outVelocity]()
				{
					if(moveCompPtr.IsValid())
						moveCompPtr->Velocity += outVelocity;
				});
			}
		}
	}
}