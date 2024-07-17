// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "NPCSkillDataTable.generated.h"

USTRUCT()
struct FThrowingSkillData
{
	GENERATED_BODY()

	//던질 액터 클래스
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ThrowingActorClass = nullptr;

	//최대 체공 시간
	UPROPERTY(EditAnywhere)
	double MaxFlightTime = 3.f;

	//ArcValue
	UPROPERTY(EditAnywhere, meta=(ClampMin=0.0, ClampMax=1.0))
	double ArcValue = 0.5;
};

USTRUCT()
struct FRectangleRangeData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FVector BoxExtend = FVector::ZeroVector;
};

USTRUCT()
struct FArcRangeData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta=(ClampMin = 0.f, ClampMax = 180.f))
	float Angle = 0.f;
};

USTRUCT()
struct FMeleeAttackData
{
	GENERATED_BODY()

	//스킬 타격 범위
	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	ESearchAreaType	SkillHittingRange = ESearchAreaType::Rectangle;

	UPROPERTY(EditAnywhere, Category = "MYDP_Skill", meta=(EditCondition="SkillHittingRange == ESearchAreaType::Rectangle"))
	FRectangleRangeData RectangleRangeData;
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Skill", meta=(EditCondition="SkillHittingRange == ESearchAreaType::Arc"))
	FArcRangeData ArcRangeData;

	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	bool RadialImpulse = false;

	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	float RadialImpulseStrength = 100.f;

	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	TArray<FName> Buffs;
};

/**
 * 스킬 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FNPCSkillDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//스킬 영어 이름
	UPROPERTY(EditAnywhere)
	FName NameEN = NAME_None;

	//스킬 한글 이름
	UPROPERTY(EditAnywhere)
	FName NameKR = NAME_None;

	//스킬 설명
	UPROPERTY(EditAnywhere, meta=(MultiLine=true))
	FText Explain = FText();

	//스킬 거리 타입
	UPROPERTY(EditAnywhere)
	ESkillDistanceType SkillRangeType = ESkillDistanceType::RangedAttack;

	//스킬 최대 사거리
	UPROPERTY(EditAnywhere)
	float MaxRange = 1000.f;

	//쿨타임
	UPROPERTY(EditAnywhere)
	float CoolDown = 0.f;

	//스킬 지속시간
	UPROPERTY(EditAnywhere)
	float Duration = 0.f;

	//스킬 계수(캐릭터의 공격력에 곱해집니다.)
	UPROPERTY(EditAnywhere)
	float SkillCoefficient = 1.f;

	//공격방식
	UPROPERTY(EditAnywhere)
	EProjectileType ProjectileType = EProjectileType::TargetAttack;

	//발사할 발사체 이름, ProjectileType이 Straight, Parabola일 때 설정해야 합니다.
	UPROPERTY(EditAnywhere, meta=(EditCondition="ProjectileType == EProjectileType::Straight || ProjectileType == EProjectileType::Parabola"))
	FName ProjectileName = NAME_None;

	//던질 액터 정보
	UPROPERTY(EditAnywhere, meta=(EditCondition="ProjectileType == EProjectileType::Throwing"))
	FThrowingSkillData ThrowingSkillData;

	//자폭 범위
	UPROPERTY(EditAnywhere, meta=(EditCondition="ProjectileType == EProjectileType::SuicideBomb"))
	double SuicideBombRadius = 1000.0;

	//근접 공격 정보(Projectile이 Melee이고 SkillRangeType이 MeleeAttack이어야 합니다.)
	UPROPERTY(EditAnywhere, meta=(EditCondition="ProjectileType == EProjectileType::Melee && SkillRangeType == ESkillDistanceType::MeleeAttack"))
	FMeleeAttackData MeleeAttackData;

	//발사 시 재생할 나이아가라 이펙트
	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* N_ShotEffect = nullptr;
	
	//발사 시 재생할 캐스케이드 이펙트
	UPROPERTY(EditAnywhere)
	UParticleSystem* ShotEffect = nullptr;

	//발사 오프셋 트랜스폼
	UPROPERTY(EditAnywhere)
	FEffectTransform ShotEffectTransform = FEffectTransform();

	//발사 시 재생할 사운드
	UPROPERTY(EditAnywhere)
	USoundBase* ShotSound = nullptr;

	//히트 시 재생할 나이아가라 이펙트
	UPROPERTY(EditAnywhere, meta=(EditCondition="ProjectileType == EProjectileType::TargetAttack || ProjectileType == EProjectileType::Melee"))
	class UNiagaraSystem* N_HitEffect = nullptr;
	
	//히트 시 재생할 캐스케이드 이펙트
	UPROPERTY(EditAnywhere, meta=(EditCondition="ProjectileType == EProjectileType::TargetAttack || ProjectileType == EProjectileType::Melee"))
	UParticleSystem* HitEffect = nullptr;

	//히트 오프셋 트랜스폼
	UPROPERTY(EditAnywhere, meta=(EditCondition="ProjectileType == EProjectileType::TargetAttack || ProjectileType == EProjectileType::Melee"))
	FEffectTransform HitEffectTransform = FEffectTransform();

	//히트 시 재생할 사운드
	UPROPERTY(EditAnywhere, meta=(EditCondition="ProjectileType == EProjectileType::TargetAttack || ProjectileType == EProjectileType::Melee"))
	USoundBase* HitSound = nullptr;
};
