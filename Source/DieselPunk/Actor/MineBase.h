// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// =========================================
/*
 * 지뢰 템플릿 클래스입니다.
 * 
 *  * 지뢰는 생성 후 2가지 루트로 파괴에 이릅니다.
 *	1. 설치 후 Overlap 이벤트
 *	2. 발사 후 60초 뒤 자동 파괴
 *
 *  * 투사체는 1가지의 상태를 가집니다.
 *  1. EProjectileOwnerType		: 소유자Type // Player , Enemy
 *		소유자Type에 따라 투사체 캡슐콜리전 및 캡슐스윕 의 TraceChannel Set
*/ 
// =========================================


#include "SkillActor.h"
#include "MineBase.generated.h"

class AProjectilePathingSpline;

UCLASS()
class DIESELPUNK_API AMineBase : public ASkillActor
{
	GENERATED_BODY()
	
	FTimerHandle DestroyTimeHandler;

protected:
	// =================================================================================================
	// 기본 구성요소
	// =================================================================================================
	
	// 충돌을 담당하는 캡슐
	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComponent;

	// 외형만 보여주는 메쉬
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MineMesh;

	// UProjectileMovementComponent 투사체의 움직임을 제어해주는 엔진함수
	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent;

	// OwnerType : Player or Enemy // 주인 타입
	UPROPERTY(EditAnywhere, Category = "MYDP_CollisionType")
	ECausorType ProjectileOwnerType = ECausorType::Player;

	
public:
	// =================================================================================================
	// 데미지 및 범위 공격관련
	// =================================================================================================

	// 데미지
	float Damage = 10.f;

	// 한 틱만 사용
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool bUseOneTick = false;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool DoRadialDamage = false;
	
	// 소유한 액터의 위치와 캡슐이 스윕을 시작하는 위치 사이의 거리
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	float AttackStartPoint = 0.f;

	// 스윕이 시작하는 위치와 스윕이 끝나는 위치 사이의 거리
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	float AttackRange = 50.f;

	// 캡슐의 반지름
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	float AttackRadius = 100.f;

	
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

	
public:
	// Sets default values for this actor's properties
	AMineBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:

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
};
