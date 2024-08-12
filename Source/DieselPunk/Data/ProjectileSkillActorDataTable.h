// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "ProjectileSkillActorDataTable.generated.h"

USTRUCT()
struct FStarightSkillActorData
{
	GENERATED_BODY()

	//관통 횟수
	UPROPERTY(EditAnywhere)
	int32 Piercing = 0;

	//속도
	UPROPERTY(EditAnywhere)
	double Speed = 5000.0;
};

USTRUCT()
struct FParabolaSkillActorData
{
	GENERATED_BODY()

	//투사체 속도
	UPROPERTY(EditAnywhere)
	float Speed = 5000.f;
	
	//최소 체공 시간
	UPROPERTY(EditAnywhere)
	float MinFlightTime = 1.f;

	//자주포 도달시간 계산식의 계수
	UPROPERTY(EditAnywhere)
	float ParabolaArrivalTimeCoefficient = 0.05f;
};

class AProjectileSkillActorBase;

/**
 * 발사체 스킬 액터 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FProjectileSkillActorDataTable : public FDPTableRowBase
{
	GENERATED_BODY()

	//발사체 영어 이름
	UPROPERTY(EditAnywhere, Category="MYDP_Explain")
	FName NameEN = NAME_None;

	//발사체 한글 이름
	UPROPERTY(EditAnywhere, Category="MYDP_Explain")
	FName NameKR = NAME_None;
	
	//발사체 설명
	UPROPERTY(EditAnywhere, Category="MYDP_Explain", meta=(MultiLine=true))
	FText Explain = FText();

	//스폰할 스킬 액터 클래스
	UPROPERTY(EditAnywhere, Category="MYDP_Data")
	TSubclassOf<AProjectileSkillActorBase> ProjectileSkillActorClass = nullptr;

	//주인 타입
	UPROPERTY(EditAnywhere, Category="MYDP_Data")
	ECharacterType ProjectileOwnerType = ECharacterType::Player;

	//범위공격(사거리, 데미지 배수)
	UPROPERTY(EditAnywhere, Category="MYDP_Data")
	TMap<float, float> RadialAttackInfos;

	//라이프 타임
	UPROPERTY(EditAnywhere, Category="MYDP_Data")
	float LifeTime = 5.f;

	//발사체 타입(TargetAttack으로 설정하면 안됩니다.)
	UPROPERTY(EditAnywhere, Category="MYDP_Data")
	EProjectileType ProjectileType = EProjectileType::TargetAttack;
	
	//직사 발사체 정보
	UPROPERTY(EditAnywhere, Category="MYDP_Data", meta=(EditCondition="ProjectileType == EProjectileType::Straight"))
	FStarightSkillActorData StraightSkillActorData;

	//곡사 발사체 정보
	UPROPERTY(EditAnywhere, Category="MYDP_Data", meta=(EditCondition="ProjectileType == EProjectileType::Parabola"))
	FParabolaSkillActorData ParabolaSkillActorData;

	//히트 시 재생할 나이아가라 이펙트
	UPROPERTY(EditAnywhere, Category="MYDP_Effect")
	class UNiagaraSystem *N_HitEffect = nullptr;
	
	//히트 시 재생할 캐스케이드 이펙트
	UPROPERTY(EditAnywhere, Category="MYDP_Effect")
	UParticleSystem *HitEffect = nullptr;

	//히트 오프셋 트랜스폼
	UPROPERTY(EditAnywhere, Category="MYDP_Effect")
	FEffectTransform HitEffectTransform = FEffectTransform();

	//히트 시 재생할 사운드
	UPROPERTY(EditAnywhere, Category="MYDP_Effect")
	USoundBase *HitSound = nullptr;
};
