// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/DataTable.h>

#include "StatDataTable.generated.h"
/**
 * 스탯 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FStatDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Hp;

	//체력 회복 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HpRecoverySpeed;

	//공격력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Atk;

	//공격 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AtkSpeed;

	//방어력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Def;

	//방어 관통력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ArmorPen;

	//치명타 확률
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CriticalPer;

	//치명타 공격력
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CriticalAtk;

	//이동 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MoveSpeed;

	//점프 횟수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int JumpCount;

	//행운
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Luck;

	//스킬 쿨타임 감소
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CoolDown;
};
