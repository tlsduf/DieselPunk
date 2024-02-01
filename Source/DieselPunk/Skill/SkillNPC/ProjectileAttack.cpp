// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileAttack.h"
#include "..\../Actor\ProjectileBase.h"
#include "..\..\Character\CharacterNPC.h"
#include "../../Util/SplineConstructor.h"
#include "../../Animation/TurretAnimInstace.h"

#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>
#include <DrawDebugHelpers.h>

#include "Components/CapsuleComponent.h"


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

	//애니메이션 재생?
	if(UTurretAnimInstace* animInst = Cast<UTurretAnimInstace>(ownerPawn->GetMesh()->GetAnimInstance()))	
		animInst->AttackSign();
	
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
			//ProjectileBase->SplineLength = FVector::Dist(ownerPawn->GetActorLocation(), inTarget->GetActorLocation());
			if(ownerPawn->DebugOnOff)
				DrawDebugSpline(splinePath);
			if(splinePath.IsValid())
				ProjectileBase->FinishSpawning(SpawnTransform);
			return;
		}
		if(bDirectFireEffect)
		{
			splinePath = MakeSplinePathForDirectFire(inTarget);
			ProjectileBase->SplinePath = splinePath;
			//ProjectileBase->SplineLength = FVector::Dist(ownerPawn->GetActorLocation(), inTarget->GetActorLocation());
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

	auto monster = Cast<ACharacterNPC>(inTarget);
	float capsuleHalfHeight = monster->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	
	SplinePath.ClearSplinePoints();
	SplinePath.AddSplinePoint(shotLocation, ESplineCoordinateSpace::World, ESplinePointType::Curve);
	FVector middlePoint = (shotLocation + inTarget->GetActorLocation()) / 2;
	float distToTarget = FVector::Dist(ownerPawn->GetActorLocation(), inTarget->GetActorLocation());
	FVector height  = FVector(0, 0, 0.6 * distToTarget);
	SplinePath.AddSplinePoint(middlePoint + height, ESplineCoordinateSpace::World, ESplinePointType::Curve);
	SplinePath.AddSplinePoint(inTarget->GetActorLocation() + FVector(0, 0, -capsuleHalfHeight), ESplineCoordinateSpace::World, ESplinePointType::Curve);
	SplinePath.UpdateSpline();

	// Set clamp tangent
	FSplineCurves& path = SplinePath.Path;
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
	SplinePath.UpdateSpline();

	return SplinePath;
}

FSplinePath UProjectileAttack::MakeSplinePathForDirectFire(AActor* inTarget)
{
	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);
	FVector shotLocation = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
	
	FSplinePath SplinePath;
	
	if(inTarget == nullptr)
		return SplinePath;
	
	SplinePath.ClearSplinePoints();
	SplinePath.AddSplinePoint(shotLocation, ESplineCoordinateSpace::World, ESplinePointType::Linear);
	FVector middlePoint = (shotLocation + inTarget->GetActorLocation()) / 2;
	SplinePath.AddSplinePoint(middlePoint, ESplineCoordinateSpace::World, ESplinePointType::Linear);
	SplinePath.AddSplinePoint(inTarget->GetActorLocation(), ESplineCoordinateSpace::World, ESplinePointType::Linear);
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
	DrawDebugPoint(GetWorld(), inSpline.Path.Position.Points[0].OutVal, 5, FColor::Black, false, 3);
	DrawDebugPoint(GetWorld(), inSpline.Path.Position.Points[1].OutVal, 5, FColor::Black, false, 3);
	DrawDebugPoint(GetWorld(), inSpline.Path.Position.Points[2].OutVal, 5, FColor::Black, false, 3);
}

