// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileAttack.h"
#include "..\../Actor\ProjectileBase.h"
#include "..\..\Character\CharacterNPC.h"
#include "../../Util/SplineConstructor.h"

#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>
#include <DrawDebugHelpers.h>


UProjectileAttack::UProjectileAttack() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void UProjectileAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UProjectileAttack::AbilityStart(AActor* inTarget)
{
	Super::AbilityStart(inTarget);

	Fire(inTarget);
}

// 설정된 Transform으로 투사체를 생성합니다.
void UProjectileAttack::Fire(AActor* inTarget)
{
	if(inTarget == nullptr)
		return;
	
	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);
	
	// projectile spawn
	if(ProjectileBaseClass)
	{
		FVector shotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
		FRotator shotRotation = ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket");
		FTransform SpawnTransform = FTransform( shotRotation, shotLocation);
		
		AProjectileBase *ProjectileBase = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileBaseClass, SpawnTransform, GetOwner());
		ProjectileBase->Damage = Damage;
		FSplinePath splinePath;
		if(bHowitzer)
		{
			splinePath = MakeSplinePath(inTarget);
			ProjectileBase->SplinePath = splinePath;
			if(ownerPawn->DebugOnOff)
				DrawDebugSpline(splinePath);
			if(splinePath.IsValid())
				ProjectileBase->FinishSpawning(SpawnTransform);
			return;
		}
		ProjectileBase->FinishSpawning(SpawnTransform);
	}
}

// Target의 위치를 기반으로 곡사궤도를 생성하고, Projectile에 Spline정보를 줍니다.
FSplinePath UProjectileAttack::MakeSplinePath(AActor* inTarget)
{
	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);
	FVector shotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
	
	FSplinePath SplinePath;
	
	if(inTarget == nullptr)
		return SplinePath;
	
	SplinePath.ClearSplinePoints();
	SplinePath.AddSplinePoint(shotLocation, ESplineCoordinateSpace::World, ESplinePointType::Curve);
	FVector middlePoint = (shotLocation + inTarget->GetActorLocation()) / 2;
	float length = FVector::Dist(ownerPawn->GetActorLocation(), inTarget->GetActorLocation());
	FVector height  = FVector(0, 0, 0.3 * length);
	SplinePath.AddSplinePoint(middlePoint + height, ESplineCoordinateSpace::World, ESplinePointType::Curve);
	SplinePath.AddSplinePoint(inTarget->GetActorLocation(), ESplineCoordinateSpace::World, ESplinePointType::Curve);
	SplinePath.UpdateSpline();

	// Set clamp tangent
	FSplineCurves& path = SplinePath.Path;
	int32&& numPoints = path.Position.Points.Num();
	for (int32 pointIdx = 0; pointIdx < numPoints; ++pointIdx)
	{
		const FVector& currentPointLoc = path.Position.Points[pointIdx].OutVal;

		// clamp leave tangent
		const int32 nextPointIndex = pointIdx + 1;
		if (nextPointIndex < numPoints)
		{
			const FVector& nextPointLoc = path.Position.Points[nextPointIndex].OutVal;
			const float distToNext = FVector::Distance(nextPointLoc, currentPointLoc);
			path.Position.Points[pointIdx].LeaveTangent = path.Position.Points[pointIdx].LeaveTangent.GetClampedToMaxSize(distToNext);
		}
		
		// clamp arrive tangent
		const int32 prevPointIndex = pointIdx - 1;
		if (prevPointIndex >= 0)
		{
			const FVector& prevPointLoc = path.Position.Points[prevPointIndex].OutVal;
			const float distToPrev = FVector::Distance(prevPointLoc, currentPointLoc);
			path.Position.Points[pointIdx].ArriveTangent = path.Position.Points[pointIdx].ArriveTangent.GetClampedToMaxSize(distToPrev);
		}
		
		path.Position.Points[pointIdx].InterpMode = CIM_CurveUser;
	}
	SplinePath.UpdateSpline();

	return SplinePath;
}

// 경로 DrawDebug
void UProjectileAttack::DrawDebugSpline(FSplinePath inSpline)
{
	// Spline 경로
	double splineLength = inSpline.Path.GetSplineLength();
	double sectionLength = 1000.0 / 10;
	int value = static_cast<int>(splineLength / sectionLength);
	for(int i = 0 ; i < value; ++i)
	{
		FVector location = inSpline.GetLocationAtDistanceAlongSpline(i * sectionLength);
		FRotator rotation = inSpline.GetRotationAtDistanceAlongSpline(i * sectionLength);
		DrawDebugDirectionalArrow(GetWorld(),
			location - 10 * rotation.Vector(),
			location + 20 * rotation.Vector(),
			10, FColor::Red, false, 3, 0, 3);
	}
}

