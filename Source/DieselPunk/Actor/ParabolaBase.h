// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// =========================================
/*
 * 포물선 운동을 하는 자주포 포탄 클래스입니다.
*/ 
// =========================================


#include "SkillActor.h"
#include "../Util/SplineConstructor.h"
#include "ParabolaBase.generated.h"

UCLASS()
class DIESELPUNK_API AParabolaBase : public ASkillActor
{
	GENERATED_BODY()

protected:
	// =================================================================================================
	// 기본 구성요소
	// =================================================================================================
	
	// 충돌을 담당하는 캡슐
	UPROPERTY(EditAnywhere)
	class UCapsuleComponent *CapsuleComponent;

	// 외형만 보여주는 메쉬
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *ParabolaMesh;
	
	// CollisionResponsesType : OnHit or Overlap // 콜리전 반응 타입
	UPROPERTY(EditAnywhere, Category = "MYDP_CollisionType")
	ECollisionResponsesType CollisionResponses = ECollisionResponsesType::Overlap;

	// OwnerType : Player or Enemy // 주인 타입
	UPROPERTY(EditAnywhere, Category = "MYDP_CollisionType")
	ECharacterType ProjectileOwnerType = ECharacterType::Player;
	
	// =================================================================================================
	// 데미지 및 범위 공격관련
	// =================================================================================================

	// 데미지
	float Damage = 10.f;

	// 폭심지 반지름
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	float FirstRadialDamageRange = 500.f;

	// 스플래시 반지름
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	float SecondRadialDamageRange = 1000.f;
	
	// =================================================================================================
	// 유틸 및 이펙트
	// =================================================================================================
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Util")
	bool DebugOnOff = false;


	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	class UNiagaraSystem *N_ShotEffect;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	UParticleSystem *ShotEffect;

	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	FEffectTransform ShotEffectTransform = FEffectTransform();

	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	USoundBase *ShotSound;
	

	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	class UNiagaraSystem *N_HitEffect;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	UParticleSystem *HitEffect;

	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	FEffectTransform HitEffectFTransform = FEffectTransform();
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	USoundBase *HitSound;

	// =================================================================================================
	// 물리
	// =================================================================================================

	//투사체 속도(unreal unit / second)
	UPROPERTY(EditAnywhere, Category = "MYDP_Physics")
	float Speed = 5000.f;

	//최소 체공 시간
	UPROPERTY(EditAnywhere, Category = "MYDP_Physics")
	float MinFlightTime = 1.f;

	//자주포 도달시간 계산식의 계수
	UPROPERTY(EditAnywhere, Category = "MYDP_Physics")
	float ParabolaArrivalTimeCoefficient = 0.05f;

	//낙하 속도
	float FallSpeed = 0.f;

	//상승 속도
	float AscentSpeed = 0.f;
	
	//목표 위치
	FVector GoalLocation = FVector::ZeroVector;

	//시작 위치
	FVector StartLocation = FVector::ZeroVector;

	//포탄 진행 방향
	FVector Direction = FVector::ZeroVector;

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
	AParabolaBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// 생성 후 즉시 효과 적용 및 파괴
	virtual void DestroyEvent();
	
	// 히트시 호출해서 데미지 적용, 투사체 파괴 등을 수행
	UFUNCTION()
	void OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult);
	
	virtual void _OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult);

	// 오버랩시 호출해서 데미지 적용, 투사체 파괴 등을 수행
	UFUNCTION()
	void BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult);
	
	virtual void _BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult);

private:
	// 캡슐콜리전 반응을 ECollisionResponsesType 과 EProjectileOwnerType 에 따라 설정합니다.
	// 현재 생성자와 BeginPlay 에 한줄씩 있음. 
	void SetCapsuleCollisionResponses();

public:
	/////////////////////////////////////////////////////////////////////
	// Getter, Setter //
	void SetDamage(const float& inDamage) { Damage = inDamage; }

	void SetGoalLocation(FVector InGoalLocation){GoalLocation = InGoalLocation;}

	const ECharacterType& GetProjectileOwnerType() const {return ProjectileOwnerType;}
};
