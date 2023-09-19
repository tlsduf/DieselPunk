// Copyright GuardiansW. All Rights Reserved.
//
// 충돌 관련 편의 함수 모음

#pragma once

class UWorld;

namespace UtilCollision
{
	// 전방으로 캡슐스윕을 해 히트정보를 받아온다
	void CapsuleSweepMulti(TArray<FHitResult>& OutHitResults, const FVector& InStartLocation, const FVector& InEndLocation, const float& InCapsuleRadius, EProjectileOwnerType inProjectileOwnerType, bool InDebugOnOff);

	// 전방으로 라인트레이스를 해 히트정보를 받아온다
	FHitResult LineTraceForward(APawn *OwnerPawn, float InAttackRange, bool InDebugOnOff);

	// 커서 아래 위치 히트를 반환
	FHitResult GetUnderCursor();

	// inStartLocation 으로부터 z방향의 트레이스 히트를 반환한다. inUpDown = 1 > Z  / inUpDown = -1 > -Z
	FHitResult GetZTrace(FVector inStartLocation, int8 inUpDown);
}