// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterNPC.h"
#include "DieselPunk/Interface/ThrowableInterface.h"
#include "CharacterMonster.generated.h"

class UDPNavigationComponent;

// 경유지점 생성을 위한 가로 세로 비율
struct FProportion
{
	float Width = 0;
	float Length = 0;
};
// 경유지점 업데이트를 위한 선분의 시작, 끝 점
struct FRoutingLine
{
	FVector Start;
	FVector End;
	FRoutingLine() { Start = FVector::ZeroVector; End = FVector::ZeroVector; }
	FRoutingLine(FVector inStart, FVector inEnd) : Start(inStart), End(inEnd) {}
};

UCLASS()
class DIESELPUNK_API ACharacterMonster : public ACharacterNPC, public IThrowableInterface
{
	GENERATED_BODY()
	
	// TimerHandle
	FTimerHandle PathTHandle1;
	FTimerHandle PathTHandle2;
	FTimerHandle PathTHandle3;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "MYDP_Navi", meta = (AllowPrivateAccess = "true"))
	UDPNavigationComponent* DPNavigationComponent;

	FVector NowGoalLoc = FVector::ZeroVector;	// 처음으로 도달할 목표 위치 // 처음으로 도달할 경유지점 위치
	TMap<FVector, FRoutingLine> RoutingLines;	// GoalLoc를 업데이트 해주기 위한 선분과 경유지점 TMap입니다.

	int32 TargetedTurretID = -9997;				// 공격할 터렛 ID

	/////////////////////////////////////////////////////////////////////
	// for ThrowableInterface //
	UPROPERTY()
	TWeakObjectPtr<UBehaviorTree> CachedBehaviorTree = nullptr;

	float CachedMass = 100.f;

	bool IsThrowingActor = false;

	FTimerHandle DestroyTHandle;
protected:
	ACharacterMonster();
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
public:
	virtual void SetTarget() override;
	
	// '몬스터'의 Target을 설정합니다. // Tcik , 조건
	void UpdateEnemyTarget();
	
	// 조건이 맞다면 '몬스터'의 타겟을 플레이어로 설정합니다.
	bool bPlayerTargeting();
	
	// 몬스터와 목표의 거리에 따른 조건 설정 // BT 활용
	void SetInRange();

public:
	// Navigation
	// 몬스터의 RoutingLines TMap에 값을 추가합니다.
	void AddEnemyRoutingLines(FVector inGoalLoc, FVector inStart, FVector inEnd);
	// RoutingLines에서 GoalLoc(Key)들을 배열로 만들어 반환합니다.
	TArray<FVector> GetGoalLocArrayFromRoutingLines();
	// self와 선분사이의 거리를 반환합니다.
	float DistanceSegmentToSelf(FVector inStart, FVector inEnd);
	// '몬스터'의 GoalLoc를 갱신합니다. // GoalLoc는 경유지점입니다. // Tick , 조건
	void UpdateEnemyGoalLoc();

	
	// Curved Spline으로 된 경로를 생성합니다.
	// 몬스터 스폰완료시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
	void UpdateSplinePath();
	void _UpdateSplinePath();
	void __UpdateSplinePath();

	//Throwable Interface
	virtual void ThrowReady(TWeakObjectPtr<AActor> InThrowingOwner) override;
	virtual void ThrowExecute(TWeakObjectPtr<AActor> InThrowingOwner) override;
	virtual void ThrowComplete() override;

	// Ragdoll Test
	void StartRagdollAndDestroy();
};
