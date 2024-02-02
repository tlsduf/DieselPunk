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
 *  2. EProjectileOwnerType		: 소유자Type // Player , Enemy
 *		소유자Type에 따라 투사체 캡슐콜리전 및 캡슐스윕 의 TraceChannel Set
*/ 
// =========================================


#include "SkillActor.h"
#include "../Util/SplineConstructor.h"
#include "ProjectileBase.generated.h"

UCLASS()
class DIESELPUNK_API AProjectileBase : public ASkillActor
{
	GENERATED_BODY()
	
	FTimerHandle DestroyTimeHandler;

protected:
	// =================================================================================================
	// 기본 구성요소
	// =================================================================================================
	
	// 충돌을 담당하는 캡슐
	UPROPERTY(EditAnywhere)
	class UCapsuleComponent *CapsuleComponent;

	// 외형만 보여주는 메쉬
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *ProjectileMesh;

	// UProjectileMovementComponent 투사체의 움직임을 제어해주는 엔진함수
	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent *ProjectileMovementComponent;
	
	// CollisionResponsesType : OnHit or Overlap // 콜리전 반응 타입
	UPROPERTY(EditAnywhere, Category = "MYDP_CollisionType")
	ECollisionResponsesType CollisionResponses = ECollisionResponsesType::Overlap;

	// OwnerType : Player or Enemy // 주인 타입
	UPROPERTY(EditAnywhere, Category = "MYDP_CollisionType")
	EProjectileOwnerType ProjectileOwnerType = EProjectileOwnerType::Player;

	
public:
	// =================================================================================================
	// 데미지 및 범위 공격관련
	// =================================================================================================

	// 데미지
	float Damage = 10.f;

	// 한 틱만 사용
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool bUseOneTick = false;

	// TimeToDestroy 뒤에 파괴
	float TimeToDestroy = 3.f;
	
	FSplinePath SplinePath;					// 곡사궤도
	float SplineLength = 0;					// 스플라인의 길이
	float Alpha;							// 투사체 스플라인 위치 알파
	Animator AlphaAnimator;					// 투사체의 스플라인 위치를 애니메이팅 합니다.

	
	// 범위공격을 할 것인지 (구)
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool DoRadialDamage = false;

	// 구의 반지름
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	float AttackRadius = 100.f;

	
	// 관통여부 (0이면 비관통, n 이면 n번 관통)
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	int32 bPiercing = 0;

	int32 PiercedCount = 0;
	
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
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// 생성 후 즉시 효과 적용 및 파괴
	virtual void DestroyEvent();

	// 생성 후 n초 뒤 파괴 바인드
	void BindDestroyOnTime();

	// Projectile 궤도 애니메이터
	void StartAnimator();
	
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
};
