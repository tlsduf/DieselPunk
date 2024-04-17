// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "StatDataTable.generated.h"
/**
 * 스탯 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FStatDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Hp = 0;

	//체력 회복 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HpRecoverySpeed = 0;

	//공격력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Atk = 0;
	
	//대공 공격력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AtkForFly = 0;

	//공격 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AtkSpeed = 0;

	//방어력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Def = 0;

	//방어 관통력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ArmorPen = 0;

	//치명타 확률
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CriticalPer = 0;

	//치명타 공격력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CriticalAtk = 0;

	//이동 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoveSpeed = 0;

	//점프 횟수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int JumpCount = 0;

	//행운
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Luck = 0;

	//스킬 쿨타임 감소
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CoolDown = 0;

	// 최대 사거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AttackMaxRange = 0;

	// 대공 최대 사거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AttackMaxRangeForFly = 0;

	// 최소 사거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AttacMinRange = 0;

	// 코스트
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cost = 0;

	// 에이스 강화 확률(100분율)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AceChance = 10;
};
