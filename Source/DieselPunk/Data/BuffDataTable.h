// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "BuffDataTable.generated.h"

USTRUCT()
struct FBuffStatInfo
{
	GENERATED_BODY()

	//변경할 스탯
	UPROPERTY(EditAnywhere)
	ECharacterStatType StatContrlType = ECharacterStatType::Hp;

	//버프 종료 시 스탯 복구할 지
	UPROPERTY(EditAnywhere)
	bool IsStore = false;
	
	//버프 배율 타입(곱연산/합연산)
	UPROPERTY(EditAnywhere)
	EBuffValueType BuffValueType = EBuffValueType::Sum;

	//밸류
	UPROPERTY(EditAnywhere)
	double Value = 0.0;
};

USTRUCT()
struct FBuffStatusEffectInfo
{
	GENERATED_BODY()

	//상태이상 시 플레이할 애니메이션 몽타주의 섹션
	UPROPERTY(EditAnywhere)
	FName PlaySectionName = NAME_None;

	//상태이상 중 이동이 가능한가
	UPROPERTY(EditAnywhere)
	bool IsMove = false;

	//상태이상 중 기본 공격이 가능한가
	UPROPERTY(EditAnywhere)
	bool IsAttack = false;
	
	//상태이상 중 스킬 사용이 가능한가
	UPROPERTY(EditAnywhere)
	bool IsSkill = false;
};

/**
 * 버프 데이터 테이블입니다.
 * 행 이름인 버프 네임과 버프 정보를 가지고 있습니다.
 */
USTRUCT()
struct DIESELPUNK_API FBuffDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//버프 타입
	UPROPERTY(EditAnywhere)
	EBuffType BuffType = EBuffType::Stat;

	//버프 중첩 시 시간 타입
	UPROPERTY(EditAnywhere)
	EBuffDuplicateTimeType BuffDuplicateTime = EBuffDuplicateTimeType::AddTime;
	
	//버프 적용 시간
	UPROPERTY(EditAnywhere)
	double BuffTime = 5.0;
	
	//틱 적용 빈도 (틱 적용 빈도 == 버프 적용 시간 이라면 버프에 걸리자마자 변화를 줍니다.)
	UPROPERTY(EditAnywhere, meta=(ClampMin = "0.01"))
	double Frequency = 1.0;

	//스탯 버프 시 채워줘야할 정보
	UPROPERTY(EditAnywhere, meta=(EditCondition="BuffType == EBuffType::Stat"))
	FBuffStatInfo BuffStatInfo;

	//상태이상 버프 시 채워줘야할 정보
	UPROPERTY(EditAnywhere, meta=(EditCondition="BuffType == EBuffType::StatusEffect"))
	FBuffStatusEffectInfo BuffStatusEffectInfo;
};
