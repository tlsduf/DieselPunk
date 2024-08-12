// 충돌 관련 편의 함수 모음

#pragma once

// =========================================
/* 범용적으로 사용할 트레이스 함수와 기하학 계산 함수입니다.
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
 * ECC_GameTraceChannel6 = "CharacterMultiTrace"
 * ECC_GameTraceChannel7 = "PlayerChannel"
 * ECC_GameTraceChannel8 = "EnemyChannel"
 * ECC_GameTraceChannel9 = "Floor"
 *
 * 멀티 트레이스는 첫 블록이 감지될 때 까지의 오버랩 액터를 가져옵니다.
 * CharacterMultiTrace를 캐릭터 감지(MultiTrace)에 활용하기 위한방법 :
 * 기본 CharacterMultiTrace반응을 Overlap으로 설정해줍니다.(프로젝트 세팅-엔진-콜리전)
 * 모든 캐릭터의 CharacterMultiTrace반응을 Block으로 설정해줍니다.
 * ECC_GameTraceChannel6 로 MultiTrace를 하되, FCollisionQueryParams 의 IgnoredActor에 본인(필수)과 무시할 캐릭터들을 등록해줍니다.
 */
// =========================================

class UWorld;

namespace UtilCollision
{
	// 전방으로 캡슐스윕을 해 히트정보를 받아온다
	void CapsuleSweepMulti(UWorld* inWorld, TArray<FHitResult>& OutHitResults, const FVector& inStartLocation, const FVector& inEndLocation, const float& inCapsuleRadius, ECharacterType inCausorType, bool inDebugOnOff);

	// 전방으로 라인트레이스를 해 히트정보를 받아온다
	FHitResult LineTraceForward(UWorld* inWorld, AActor *inOwner, float inAttackRange, bool inDebugOnOff);

	// 커서 아래 위치 히트를 반환
	FHitResult GetUnderCursor(UWorld* inWorld);

	// inStartLocation 으로부터 z방향의 트레이스 히트를 반환한다. inUpDown = 1 > Z  / inUpDown = -1 > -Z
	FHitResult GetZTrace(UWorld* inWorld, FVector inStartLocation, int8 inUpDown);

	// 화면 중앙 지점으로부터 바라보는 방향 히트를 반환
	bool GetViewMiddle(UWorld* InWorld, APlayerController* InController, FHitResult& OutHitResult, int32 InRange = 99999, TArray<const AActor*> InIgnoreActor = TArray<const AActor*>());
}