// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UNiagaraSystem;
class AProjectilePathingSpline;

UCLASS()
class DIESELPUNK_API AProjectileBase : public AActor
{
	GENERATED_BODY()
private:
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

	// UProjectileMovementComponent 투사체의 움직임을 제어해주는 언리얼함수
	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent *ProjectileMovementComponent;

	// OnHit or Overlap
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	ECollisionResponsesType CollisionResponses = ECollisionResponsesType::Overlap;

	// Player or Enemy
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	EProjectileOwnerType ProjectileOwnerType = EProjectileOwnerType::Player;

	// =================================================================================================
	// 데미지 및 범위 공격관련
	// =================================================================================================

public:
	// 데미지
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	float Damage = 10.f;

	// 한 틱만 사용
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	bool bUseOneTick = false;
	
	// applydamage 프레임워크 ApplyRadialDamage 의 경우 중심에서 멀어질수록 약해지는 데미지를 입힐지말지 //현재 사용x
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	bool DoFullDamage = true;
	
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	bool DoRadialDamage = false;
	
	// 소유한 액터의 위치와 캡슐이 스윕을 시작하는 위치 사이의 거리
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	float AttackStartPoint = 0.f;

	// 스윕이 시작하는 위치와 스윕이 끝나는 위치 사이의 거리
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	float AttackRange = 50.f;

	// 캡슐의 반지름
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	float AttackRadius = 100.f;

	
	// =================================================================================================
	// 호밍 // 궤적
	// =================================================================================================

	// 로테이션
	FRotator UpdateRotation = FRotator(0,0,0);
	
	// 호밍 유무
	bool bIsHoming = false;
	
	// 호밍 거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float HomingRange = 300;
	
	// Projectile이 따라갈 경로입니다.
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	TSubclassOf<AProjectilePathingSpline> ProjectilePathingSplineClass;

	UPROPERTY()
	AProjectilePathingSpline *ProjectilePathingSpline;

	// 스플라인을 따를것인지?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool bPathingSpline = 0;

	// Duration은 CollisionInfo의 LifeTime으로 초기화해줍니다.
	// PathingSpline의 시작~끝 재생시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Duration = 3;

	float SplineLength;						// 스플라인의 길이
	float Alpha;							// 투사체 스플라인 위치 알파

	
	// =================================================================================================
	// 유틸 및 이펙트
	// =================================================================================================
	
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	bool DebugOnOff = false;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	TSoftObjectPtr<UNiagaraSystem> HitEffect = nullptr;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	FVector HitEffectScale = FVector(1);

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	TSoftObjectPtr<UNiagaraSystem> ShotEffect = nullptr;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	FVector ShotEffectScale = FVector(1);

	// 발사 사운드
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	USoundBase *ShotSound;
	
	// hit 사운드
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
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
	// 캡슐콜리전 반응을 ECollisionResponsesType 과 EProjectileOwnerType 에 따라 설정합니다. 현재 생성자와 BeginPlay 에 한줄씩 있음. 
	void SetCapsuleCollisionResponses();

	// bUseOneTick = true 일 시, 처리를 담당
	virtual void OneTickTask();
	
	// 히트시 호출해서 데미지 적용, 투사체 파괴 등을 수행
	UFUNCTION()
	void OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult);

	// OnHit의 실질적인 기능을 담고있는 함수 // OnHit이 상속이안됨.
	virtual void _OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult);

	// 오버랩시 호출해서 데미지 적용, 투사체 파괴 등을 수행
	UFUNCTION()
	void BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult);

	// Overlap의 실질적인 기능을 담고있는 함수 // Overlap이 상속이안됨.
	virtual void _BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult);

public:
	// 데미지 변경함수
	void SetDamage(float inDamage);

	// 가장 가까운 액터가 HomingRange 보다 가까울 경우, 그 액터를 HomingTargetComponent로 지정한다.
	void SetHomingTargetActor();

	// 투사체의 업데이트 로테이션을 셋합니다. 틱에서 세팅된 로테이션값 만큼 업데이트합니다.
	void SetUpdateRotation(const FRotator& inRotate);
};
