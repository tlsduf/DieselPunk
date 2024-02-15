// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilCollision.h"

#include <CollisionShape.h>
#include <DrawDebugHelpers.h>
#include <GameFramework/PlayerController.h>
#include <Kismet/GameplayStatics.h>




// =============================================================
/**
	 *시작점->끝점까지 구로 스윕 트레이스를 합니다.
	 * @param OutHitResults : Sweep 결과 를 담아주는 배열입니다.
	 * @param inStartLocation : 트레이스의 시작점입니다. (시작 구의 정 가운데)
	 * @param inEndLocation : 트레이스의 끝점 입니다. (끝 구의 정 가운데)
	 * @param inCapsuleRadius : Sweep할 구의 반지름입니다.
	 * @param inDebugOnOff : 디버그캡슐의 Draw를 결정하는 bool변수입니다.
	 */
// =============================================================
void UtilCollision::CapsuleSweepMulti(UWorld* inWorld, TArray<FHitResult>& OutHitResults, const FVector& inStartLocation, const FVector& inEndLocation, const float& inCapsuleRadius, ECausorType inCausorType, bool inDebugOnOff)
{
	FCollisionQueryParams params;
	inWorld->SweepMultiByChannel(
		OutHitResults,
		inStartLocation,
		inEndLocation,
		FQuat::Identity,
		(inCausorType == ECausorType::Player) ? ECollisionChannel::ECC_GameTraceChannel7 : ECollisionChannel::ECC_GameTraceChannel8,
		FCollisionShape::MakeSphere(inCapsuleRadius),
		params);
	
	// 디버그 캡슐을 그린다. Red - hit 실패/ Green - hit 성공
	if (inDebugOnOff)
	{
		FVector traceVec = inEndLocation - inStartLocation;
		FVector center = inStartLocation + traceVec * 0.5f;
		float halfHeight = traceVec.Size() * 0.5f + inCapsuleRadius;
		FQuat capsuleRot = FRotationMatrix::MakeFromZ(traceVec).ToQuat();
		FColor drawColor = !OutHitResults.IsEmpty() ? FColor::Green : FColor::Red;
		float debugLifeTime = 5.0f;

		DrawDebugCapsule(inWorld,
						 center,
						 halfHeight,
						 inCapsuleRadius,
						 capsuleRot,
						 drawColor,
						 false,
						 debugLifeTime);
	}
}


// =============================================================
/**
	 *액터기준 전방으로 라인트레이스를 해 히트정보를 받아온다 LineTraceSingleByChannel
	 * @param inOwner : 트레이스하는 액터
	 * @param inAttackRange : 트레이스 거리
	 * @param inDebugOnOff : 드로우 디버그 On/Off
	 */
// =============================================================
FHitResult UtilCollision::LineTraceForward(UWorld* inWorld, AActor *inOwner, float inAttackRange, bool inDebugOnOff)
{
	FHitResult hit;
	if (inOwner == nullptr)
		return hit;

	FVector startLocation = inOwner->GetActorLocation();
	FRotator startRotation = inOwner->GetActorRotation();
	//if(AController *OwnerController = Cast<ACharacterBase>(inOwner)->GetController())
	//	OwnerController->GetPlayerViewPoint(startLocation, startRotation);
	FVector endLocation = startLocation + startRotation.Vector() * inAttackRange;
	
	FCollisionQueryParams params;
	params.AddIgnoredActor(inOwner);

	bool hasHit = inWorld->LineTraceSingleByChannel(
		hit,
		startLocation,
		endLocation,
		ECollisionChannel::ECC_GameTraceChannel1,
		params);

	AActor *hitActor = hit.GetActor();

	// 디버그 캡슐을 그린다. Red - hit 실패/ Green - hit 성공
	if (inDebugOnOff)
	{
		FVector traceVec = startRotation.Vector() * inAttackRange;
		FVector center = startLocation + traceVec * 0.5f;
		float halfHeight = inAttackRange * 0.5f;
		FQuat capsuleRot = FRotationMatrix::MakeFromZ(traceVec).ToQuat();
		FColor drawColor = (hitActor != nullptr && hitActor != inOwner) ? FColor::Green : FColor::Red;
		float debugLifeTime = 5.0f;

		DrawDebugCapsule(inWorld,
						 center,
						 halfHeight,
						 1,
						 capsuleRot,
						 drawColor,
						 false,
						 debugLifeTime);
	}
	
	return hit;
}

// =============================================================
// 커서 아래 위치 히트를 반환
// =============================================================
FHitResult UtilCollision::GetUnderCursor(UWorld* inWorld)
{
	FHitResult hit;
	APlayerController *ownerController = UGameplayStatics::GetPlayerController(inWorld, 0);
	if (ownerController)
	{
		ownerController->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false,
			hit);
		return hit;
	}
	return hit;
}

// =============================================================
// inStartLocation 으로부터 z방향의 트레이스 히트를 반환한다. inUpDown : 1 => Z  / inUpDown : -1 => -Z
// =============================================================
FHitResult UtilCollision::GetZTrace(UWorld* inWorld, FVector inStartLocation, int8 inUpDown)
{
	FHitResult hit;
	FCollisionQueryParams params;
	inWorld->LineTraceSingleByChannel(
	hit,
	inStartLocation,
	FVector(inStartLocation.X, inStartLocation.Y,inStartLocation.Z + (1000 * inUpDown)),
	ECollisionChannel::ECC_WorldStatic,
	params);

	return hit;
}

// 화면 중앙 지점으로부터 바라보는 방향 히트를 반환
bool UtilCollision::GetViewMiddle(UWorld* InWorld, APlayerController* InController, FHitResult& OutHitResult, int32 InRange, TArray<const AActor*> InIgnoreActor)
{
	FHitResult hit;

	//뷰 사이즈 획득
	int32 viewX, viewY;
	InController->GetViewportSize(viewX, viewY);

	viewX /= 2;
	viewY /= 2;

	FRotator cameraRotation = InController->PlayerCameraManager->GetCameraRotation();
	FVector cameraDirection = cameraRotation.Vector().GetSafeNormal();

	//스크린 스페이스 위치와 카메라 디렉션을 바탕으로 트레이싱 Start, End 획득
	FVector traceStartLocation, traceEndLocation;
	InController->DeprojectScreenPositionToWorld(viewX, viewY, traceStartLocation, cameraDirection);
	traceEndLocation = traceStartLocation + InRange * cameraDirection;

	//플레이어 충돌범위 제외
	FCollisionQueryParams params;
	for(const AActor* ignore : InIgnoreActor)
		params.AddIgnoredActor(ignore);

	//라인 충돌
	bool hasHit = InWorld->LineTraceSingleByChannel(
		hit,
		traceStartLocation,
		traceEndLocation,
		ECollisionChannel::ECC_WorldStatic,
		params);

	OutHitResult = hit;

	return hasHit;
}
