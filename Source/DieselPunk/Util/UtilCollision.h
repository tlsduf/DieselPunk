// 충돌 관련 편의 함수 모음

#pragma once

// =========================================
/* 범용적으로 사용할 트레이스 함수들입니다.
 * DieselPunk\Config\DefaultEngine.ini 에 추가된 트레이스 채널이 명시되어 있습니다.
 *
 * 현재 추가된 트레이스 채널 (변경될 때 마다 최신화 요함)
 * 
 * - ObjectChannels
 * ECC_GameTraceChannel1 = "Player"
 * ECC_GameTraceChannel2 = "Projectile_Player"
 * ECC_GameTraceChannel3 = "Enemy"
 * ECC_GameTraceChannel4 = "Projectile_Enemy"
 * ECC_GameTraceChannel5 = "traceChannel5"
 * 
 * - TraceChannels
 * ECC_GameTraceChannel6 = "TempTrace"
 * ECC_GameTraceChannel7 = "PlayerChannel"
 * ECC_GameTraceChannel8 = "EnemyChannel"
 * ECC_GameTraceChannel9 = "Floor"
*/
// =========================================

class UWorld;

namespace UtilCollision
{
	// 전방으로 캡슐스윕을 해 히트정보를 받아온다
	void CapsuleSweepMulti(TArray<FHitResult>& OutHitResults, const FVector& inStartLocation, const FVector& inEndLocation, const float& inCapsuleRadius, EProjectileOwnerType inProjectileOwnerType, bool inDebugOnOff);

	// 전방으로 라인트레이스를 해 히트정보를 받아온다
	FHitResult LineTraceForward(AActor *inOwner, float inAttackRange, bool inDebugOnOff);

	// 커서 아래 위치 히트를 반환
	FHitResult GetUnderCursor();

	// inStartLocation 으로부터 z방향의 트레이스 히트를 반환한다. inUpDown = 1 > Z  / inUpDown = -1 > -Z
	FHitResult GetZTrace(FVector inStartLocation, int8 inUpDown);
}