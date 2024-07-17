// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// =========================================
/*
 * 투사체 템플릿 클래스입니다.
 * 
 *  * 투사체는 생성 후 3가지 루트로 파괴에 이릅니다.
 *	1. 효과 즉시 발동 (bUseOneTick)
 *	2. 발사 후 OnHit or Overlap 이벤트
 *	3. 발사 후 n초 뒤 자동 파괴
 *
 *  * 투사체는 3지의 상태를 가집니다.
 *  1. ECollisionResponsesType	: 캡슐 콜리전 반응Type // OnHit , Overlap
 *		콜리전반응Type 에 따라 투사체 캡슐콜리전 Set
 *  2. EParabolaOwnerType		: 소유자Type // Player , Enemy
 *		소유자Type에 따라 투사체 캡슐콜리전 및 캡슐스윕 의 TraceChannel Set
*/ 
// =========================================


#include "ProjectileSkillActorBase.h"
#include "../Util/SplineConstructor.h"
#include "ParabolaSkillActorBase.generated.h"

class UCapsuleComponent;
class UProjectileMovementComponent;

UCLASS()
class DIESELPUNK_API AParabolaSkillActorBase : public AProjectileSkillActorBase
{
	GENERATED_BODY()

protected:
	// =================================================================================================
	// 데이터 테이블에게 받아오는 변수
	// =================================================================================================
	//투사체 속도
	float Speed = 5000.f;
	
	//최소 체공 시간
	float MinFlightTime = 1.f;

	//자주포 도달시간 계산식의 계수
	float ParabolaArrivalTimeCoefficient = 0.05f;

	// =================================================================================================
	// 스킬 액터에게 받아오는 변수
	// =================================================================================================
	//목표 위치
	FVector GoalLocation = FVector::ZeroVector;

	//포탄 진행 방향
	FVector Direction = FVector::ZeroVector;

	// =================================================================================================
	// 내부 사용 변수
	// =================================================================================================
	//낙하 속도
	float FallSpeed = 0.f;

	//상승 속도
	float AscentSpeed = 0.f;

	//시작 위치
	FVector StartLocation = FVector::ZeroVector;

	//총 체공 시간
	float FlightTime = 3.f;

	//낙하 시간
	float FallTime = 1.5f;

	//현재까지 체공 시간
	float DeltaFlightTime = 0.f;

	//현재 떨어지는 중인가?
	bool IsFalling = false;

	//이전 프레임 위치
	FVector OldLocation = FVector::ZeroVector;

	//시작지점부터 골까지의 거리
	float DistanceAtGoal = 0.f;
public:
	// Sets default values for this actor's properties
	AParabolaSkillActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void _OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult);
	
	virtual void _BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult);

public:
	FORCEINLINE void SetGoalLocation(FVector InGoalLocation){GoalLocation = InGoalLocation;}
	FORCEINLINE void SetDirection(FVector InDirection){Direction = InDirection;}
};
