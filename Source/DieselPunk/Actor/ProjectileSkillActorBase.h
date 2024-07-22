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
#include "ProjectileSkillActorBase.generated.h"

class UCapsuleComponent;
class UProjectileMovementComponent;

UCLASS()
class DIESELPUNK_API AProjectileSkillActorBase : public ASkillActor
{
	GENERATED_BODY()
	
	FTimerHandle DestroyTimeHandler;

protected:
	// =================================================================================================
	// 기본 구성요소
	// =================================================================================================
	
	// 충돌을 담당하는 캡슐
	UPROPERTY(EditAnywhere)
	UCapsuleComponent *CapsuleComponent;

	// 외형만 보여주는 메쉬
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *ProjectileMesh;

	// UProjectileMovementComponent 투사체의 움직임을 제어해주는 엔진함수
	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent *ProjectileMovementComponent;
	
	// CollisionResponsesType : OnHit or Overlap // 콜리전 반응 타입
	UPROPERTY(EditAnywhere, Category = "MYDP_CollisionType")
	ECollisionResponsesType CollisionResponses = ECollisionResponsesType::Overlap;
	
	// =================================================================================================
	// 스킬에게 받아오는 변수
	// =================================================================================================

	//데미지
	float Damage = 0.f;

	//오너 캐릭터 타입
	ECharacterType OwnerTypes = ECharacterType::None;

	//최대 사거리
	float MaxRange = 1000.f;

	// =================================================================================================
	// 데이터 테이블에게 받아오는 변수
	// =================================================================================================

	//테이블 이름
	FName ProjectileSkillActorName = NAME_None;

	//주인 타입
	ECausorType ProjectileOwnerType = ECausorType::Player;

	//범위공격(사거리, 데미지 배수)
	TMap<float, float> RadialAttackInfos;

	//라이프 타임
	float LifeTime = 5.f;

	// =================================================================================================
	// 유틸 및 이펙트
	// =================================================================================================
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Util")
	bool DebugOnOff = false;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	class UNiagaraSystem *N_HitEffect;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	UParticleSystem *HitEffect;

	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	FEffectTransform HitEffectTransform = FEffectTransform();

	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	USoundBase *HitSound;

	// =================================================================================================
	// 내부 사용 변수
	// =================================================================================================

	//출발 위치
	FVector StartLocation = FVector::ZeroVector;
	
public:
	// Sets default values for this actor's properties
	AProjectileSkillActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// 폭발 데미지 적용
	virtual void ApplyRadialDamage();

	// 생성 후 n초 뒤 파괴 바인드, 0초 이하로 설정 시 파괴하지 않고, Tick에 의해 최대 사거리에서 파괴합니다.
	void BindDestroyOnTime();
	
	// 히트시 호출해서 데미지 적용, 투사체 파괴 등을 수행
	UFUNCTION()
	void OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult);
	
	virtual void _OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult){}

	// 오버랩시 호출해서 데미지 적용, 투사체 파괴 등을 수행
	UFUNCTION()
	void BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult);
	
	virtual void _BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult) {}

private:
	// 캡슐콜리전 반응을 ECollisionResponsesType 과 EProjectileOwnerType 에 따라 설정합니다.
	// 현재 생성자와 BeginPlay 에 한줄씩 있음. 
	void SetCapsuleCollisionResponses();

public:
	FORCEINLINE void SetProjectileSkillActorName(const FName& InProjectileSkillActorName){ProjectileSkillActorName = InProjectileSkillActorName;}
	FORCEINLINE void SetDamage(float InDamage){Damage = InDamage;}
	FORCEINLINE void SetMaxRange(float InMaxRange){MaxRange = InMaxRange;}
};
