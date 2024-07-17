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
 *  2. EStraightOwnerType		: 소유자Type // Player , Enemy
 *		소유자Type에 따라 투사체 캡슐콜리전 및 캡슐스윕 의 TraceChannel Set
*/ 
// =========================================


#include "ProjectileSkillActorBase.h"
#include "../Util/SplineConstructor.h"
#include "StraightSkillActorBase.generated.h"

class UCapsuleComponent;
class UProjectileMovementComponent;

UCLASS()
class DIESELPUNK_API AStraightSkillActorBase : public AProjectileSkillActorBase
{
	GENERATED_BODY()

protected:
	// =================================================================================================
	// 데이터 테이블에게 받아오는 변수
	// =================================================================================================

	//테이블 이름
	int32 Piercing = 0;

	//속도
	double Speed = 5000.0;
	
public:
	// Sets default values for this actor's properties
	AStraightSkillActorBase();

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
};
