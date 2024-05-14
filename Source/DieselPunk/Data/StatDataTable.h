// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "StatDataTable.generated.h"

class USkeletalMesh;

USTRUCT(BlueprintType)
struct FStatDataInfo
{
	GENERATED_BODY()

	//체력
	UPROPERTY(EditAnywhere)
	int Hp = 0;

	//체력 회복 속도
	UPROPERTY(EditAnywhere)
	int HpRecoverySpeed = 0;

	//공격력
	UPROPERTY(EditAnywhere)
	int Atk = 0;
	
	//대공 공격력
	UPROPERTY(EditAnywhere)
	int AtkForFly = 0;

	//공격 속도
	UPROPERTY(EditAnywhere)
	int AtkSpeed = 0;

	//방어력
	UPROPERTY(EditAnywhere)
	int Def = 0;

	//방어 관통력
	UPROPERTY(EditAnywhere)
	int ArmorPen = 0;

	//치명타 확률
	UPROPERTY(EditAnywhere)
	int CriticalPer = 0;

	//치명타 공격력
	UPROPERTY(EditAnywhere)
	int CriticalAtk = 0;

	//이동 속도
	UPROPERTY(EditAnywhere)
	int MoveSpeed = 0;

	//점프 횟수
	UPROPERTY(EditAnywhere)
	int JumpCount = 0;

	//행운
	UPROPERTY(EditAnywhere)
	int Luck = 0;

	//스킬 쿨타임 감소
	UPROPERTY(EditAnywhere)
	int CoolDown = 0;

	// 최대 사거리
	UPROPERTY(EditAnywhere)
	int AttackMaxRange = 0;

	// 대공 최대 사거리
	UPROPERTY(EditAnywhere)
	int AttackMaxRangeForFly = 0;

	// 최소 사거리
	UPROPERTY(EditAnywhere)
	int AttacMinRange = 0;

	// 코스트
	UPROPERTY(EditAnywhere)
	int Cost = 0;
	
	UPROPERTY(EditAnywhere)
	USkeletalMesh* UpgradeMesh = nullptr;
};

/**
 * 스탯 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FStatDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()

	// 스탯 정보(순서대로 레벨 1, 2, 3, Ace 스탯을 채우면 됩니다.)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FStatDataInfo> StatInfos;

	// 에이스 강화 확률(100분율)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AceChance = 10;
};
