// Fill out your copyright notice in the Description page of Project Settings.

#include "ThrowingAttack.h"
#include "..\..\Character\CharacterNPC.h"
#include "../../Util/SplineConstructor.h"
#include "../../Animation/TurretAnimInstace.h"

#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>
#include <DrawDebugHelpers.h>

#include "Components/CapsuleComponent.h"
#include "DieselPunk/Manager/ObjectManager.h"
#include "GameFramework/MovementComponent.h"


UThrowingAttack::UThrowingAttack() : Super()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UThrowingAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for(TMap<int32, FThrowActorSplineInfo>::TIterator iter(ThrowActorInfos.CreateIterator()); iter; ++iter)
	{
		AActor* actor = FObjectManager::GetInstance()->FindActor(iter.Key());
		if(actor == nullptr)
			iter.RemoveCurrent();
		
		iter.Value().FlightDelta += DeltaTime;

		float value = iter.Value().FlightTime <= 0 ? 1.f : iter.Value().FlightDelta / iter.Value().FlightTime;

		float dist = iter.Value().SplinePath.GetSplineLength() * value;
		FVector newLocation = iter.Value().SplinePath.GetLocationAtDistanceAlongSpline(dist);


		if(UActorComponent* actorCompMovement = actor->GetComponentByClass(UMovementComponent::StaticClass()))
		{
			FVector oldLocation = actor->GetActorLocation();
			FVector movement = newLocation - oldLocation;
			movement.Normalize();
			UMovementComponent* movementComp = Cast<UMovementComponent>(actorCompMovement);
			movementComp->Velocity = movement * iter.Value().SplinePath.GetSplineLength() / iter.Value().FlightTime;

			if(UActorComponent* actorCompCapsule = actor->GetComponentByClass(UCapsuleComponent::StaticClass()))
			{
				UCapsuleComponent* capsuleComp = Cast<UCapsuleComponent>(actorCompCapsule);
				TArray<FOverlapResult> overlapResults;
				FCollisionQueryParams param;
				param.AddIgnoredActor(OwnerCharacter);
				if(GetWorld()->OverlapMultiByChannel(overlapResults,
													actor->GetActorLocation(),
													actor->GetActorQuat(),
													ECollisionChannel::ECC_WorldStatic,
													FCollisionShape::MakeCapsule(capsuleComp->GetScaledCapsuleRadius(), capsuleComp->GetScaledCapsuleHalfHeight()),
													param))
				{
					IThrowableInterface* throwInterface = Cast<IThrowableInterface>(actor);
					if(throwInterface)
						throwInterface->ThrowComplete();

					iter.RemoveCurrent();
				}
			}
		}
		else
		{
			if(!actor->SetActorLocation(newLocation, true))
			{
				IThrowableInterface* throwInterface = Cast<IThrowableInterface>(actor);
				if(throwInterface)
					throwInterface->ThrowComplete();

				iter.RemoveCurrent();
			}
		}

		if(iter.Value().FlightDelta >= iter.Value().FlightTime)
			iter.RemoveCurrent();
	}
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
		throwInterface->ThrowReady();
	throwActor->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("KeepRelativeTransform"));
	
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
	
	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);

	FThrowActorSplineInfo splineInfo;
	
	FVector startLocation = ownerPawn->GetMesh()->GetSocketLocation(TEXT("ThrowingSpawn"));
	FVector goalLocation = InTarget->GetActorLocation();
	splineInfo.FlightTime = FVector::Distance(startLocation, goalLocation) * MaxFlightTime / MaxRange;
	splineInfo.FlightDelta = 0.f;
	if(MakeSplinePath(InTarget, splineInfo.FlightTime, &splineInfo.SplinePath))
	{
		if(FObjectManager::GetInstance()->IsValidId(ThrowActorId))
			ThrowActorInfos.Add(ThrowActorId, splineInfo);
	}
}

bool UThrowingAttack::MakeSplinePath(AActor* InTarget, float InFlightTime, FSplinePath* OutSplinePath)
{
	if(InTarget == nullptr || OwnerCharacter == nullptr)
		return false;
	
	FVector shotLocation = OwnerCharacter->GetMesh()->GetSocketLocation("ThrowingSpawn");
	auto target = Cast<ACharacterBase>(InTarget);
	float capsuleHalfHeight = target->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	
	OutSplinePath->ClearSplinePoints();
	OutSplinePath->AddSplinePoint(shotLocation, ESplineCoordinateSpace::World, ESplinePointType::Curve);
	FVector middlePoint = (shotLocation + target->GetActorLocation()) / 2;
	middlePoint.Z += HeightCoefficient * InFlightTime / MaxFlightTime;
	float distToTarget = FVector::Dist(OwnerCharacter->GetActorLocation(), InTarget->GetActorLocation());
	OutSplinePath->AddSplinePoint(middlePoint, ESplineCoordinateSpace::World, ESplinePointType::Curve);
	OutSplinePath->AddSplinePoint(InTarget->GetActorLocation() + FVector(0, 0, -capsuleHalfHeight), ESplineCoordinateSpace::World, ESplinePointType::Curve);
	OutSplinePath->UpdateSpline();

	// Set clamp tangent
	FSplineCurves& path = OutSplinePath->Path;
	path.Position.Points[0].LeaveTangent = path.Position.Points[0].LeaveTangent.GetClampedToMaxSize(0);
	path.Position.Points[0].ArriveTangent = path.Position.Points[0].ArriveTangent.GetClampedToMaxSize(0);
	path.Position.Points[0].InterpMode = CIM_CurveUser;
	
	const float dist = 10 * distToTarget;
	path.Position.Points[1].LeaveTangent = path.Position.Points[1].LeaveTangent.GetClampedToMaxSize(dist);
	path.Position.Points[1].ArriveTangent = path.Position.Points[1].ArriveTangent.GetClampedToMaxSize(dist);
	path.Position.Points[1].InterpMode = CIM_CurveUser;
	
	path.Position.Points[2].LeaveTangent = path.Position.Points[2].LeaveTangent.GetClampedToMaxSize(0);
	path.Position.Points[2].ArriveTangent = path.Position.Points[2].ArriveTangent.GetClampedToMaxSize(0);
	path.Position.Points[2].InterpMode = CIM_CurveUser;
	OutSplinePath->UpdateSpline();

	return true;
}