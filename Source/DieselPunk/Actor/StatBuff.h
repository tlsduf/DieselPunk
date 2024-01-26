// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// =========================================
/*
 * 스탯버프 템플릿 클래스입니다.
 * 
 *  * 투사체는 생성 후 1가지 루트로 파괴에 이릅니다.
 *	1. 일정 시간 후 파괴
*/ 
// =========================================


#include "SkillActor.h"
#include "StatBuff.generated.h"

class UNiagaraSystem;
class UParticleSystem;
class USoundBase;

USTRUCT()
struct FEffectData
{
	GENERATED_BODY()
	
	//이펙트 재생 타입
	UPROPERTY(EditAnywhere)
	EEffectPlayType EffectPlayType;
	
	//나이아가라 이펙트
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* N_Effect;

	//파티클시스템 이펙트
	UPROPERTY(EditAnywhere)
	UParticleSystem* Effect;

	//사운드
	UPROPERTY(EditAnywhere)
	USoundBase* Sound;
};

class AProjectilePathingSpline;

UCLASS()
class DIESELPUNK_API AStatBuff : public ASkillActor
{
	GENERATED_BODY()
	
	FTimerHandle DestroyTimeHandler;

protected:
	// =================================================================================================
	// 기본 구성요소
	// =================================================================================================
	
	// 외형만 보여주는 메쉬
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *Mesh;
	
public:
	// =================================================================================================
	// 데미지 및 범위 공격관련
	// =================================================================================================

	// 적용 대상
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	ECharacterType TargetType = ECharacterType::None;
	
	// 버프 밸류
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float Value = 10.f;

	// 적용 스탯 타입
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	ECharacterStatType CharacterStatType = ECharacterStatType::Hp;

	// 스탯 버프 범위
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float AttackRange = 50.f;
	
	// 스탯 적용 최대 갯수(1보다 작을 경우 무한대로 적용)
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	int32 Count = 1;

	// 도트 틱 반복 빈도(단위 초)
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float TickTime = 1.f;

	// 도트 재생 시간(단위 초)
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float MaxTime = 1.f;

	float TimeCount = 0.f;
	int32 TickCount = 0;
	int32 TickMaxCount = 0;
	
	// =================================================================================================
	// 유틸 및 이펙트
	// =================================================================================================
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Util")
	bool DebugOnOff = false;

	UPROPERTY(EditAnywhere, Category = "MYDP_Effect")
	TArray<FEffectData> Effects;
	
public:
	// Sets default values for this actor's properties
	AStatBuff();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	TArray<int32> FindBuffTarget();
	void StartEffect(EEffectPlayType InEffectPlayType, FTransform InTransform);
	void Buff();
};
