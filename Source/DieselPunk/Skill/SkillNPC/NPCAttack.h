// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../SkillBase.h"
#include "NPCAttack.generated.h"

UCLASS()
class DIESELPUNK_API UNPCAttack : public USkillBase
{
	GENERATED_BODY()

	// 생성자
	UNPCAttack();

protected:
	//NPC Skill 이름
	FName NPCSkillName = NAME_None;

	//공격방식
	EProjectileType ProjectileType = EProjectileType::TargetAttack;

	//Straight, Parabola/////////////////////////////////////////////////////
	//발사할 발사체 이름
	FName ProjectileName = NAME_None;
	/////////////////////////////////////////////////////////////////////////

	//Throwing///////////////////////////////////////////////////////////////
	//던질 액터 클래스
	TSubclassOf<AActor> ThrowingActorClass = nullptr;

	//최대 체공 시간
	double MaxFlightTime = 3.f;

	//곡사 계수
	double ArcValue = 0.5;

	//던진 액터 아이디
	int32 ThrowActorId = -9999;
	/////////////////////////////////////////////////////////////////////////

	//Suicide////////////////////////////////////////////////////////////////
	//자폭 범위
	double SuicideBombRadius = 1000.0;
	/////////////////////////////////////////////////////////////////////////

	//Melee//////////////////////////////////////////////////////////////////
	//스킬 타격 범위
	ESearchAreaType SkillHittingRange = ESearchAreaType::Rectangle;

	//Rectangle시 박스 크기
	FVector RectangleBoxExtend = FVector::ZeroVector;

	//Arc시 각도
	float ArcAngle = 0.f;
	
	//밀치기 사용할건지
	bool RadialImpulse = false;

	//밀치기 힘
	float RadialImpulseStrength = 100.f;

	//버프
	TArray<FName> Buffs;
	/////////////////////////////////////////////////////////////////////////

	/////Melee//////////////////////////////////////////////////////////////////
	bool SnipingStart = false;

	TWeakObjectPtr<AActor> CurrentTarget = nullptr;
	/////////////////////////////////////////////////////////////////////////
	

	//발사 시 재생할 나이아가라 이펙트
	UPROPERTY()
	class UNiagaraSystem* N_ShotEffect = nullptr;
	
	//발사 시 재생할 캐스케이드 이펙트
	UPROPERTY()
	UParticleSystem* ShotEffect = nullptr;

	//발사 오프셋 트랜스폼
	UPROPERTY()
	FEffectTransform ShotEffectTransform = FEffectTransform();

	//발사 시 재생할 사운드
	UPROPERTY()
	USoundBase* ShotSound = nullptr;

	//히트 시 재생할 나이아가라 이펙트
	UPROPERTY()
	class UNiagaraSystem* N_HitEffect = nullptr;
	
	//히트 시 재생할 캐스케이드 이펙트
	UPROPERTY()
	UParticleSystem* HitEffect = nullptr;

	//히트 오프셋 트랜스폼
	UPROPERTY()
	FEffectTransform HitEffectTransform = FEffectTransform();

	//히트 시 재생할 사운드
	UPROPERTY()
	USoundBase* HitSound = nullptr;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void AbilityStart(AActor* InTarget = nullptr) override;

	virtual void AbilityShot(double InDamageCoefficient, AActor* InTarget = nullptr) override;
public:
	void SetNPCSkillName(const FName& InNPCSkillName);

	EProjectileType GetProjectileType() const {return ProjectileType;}
protected:
	void PlayEffect(const FName& InAttachSocketName);
};
