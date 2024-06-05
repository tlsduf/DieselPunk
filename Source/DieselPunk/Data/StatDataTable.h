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
	
	//체력
	UPROPERTY(EditAnywhere)
	int Hp = 0;

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

	// 최대 사거리
	UPROPERTY(EditAnywhere)
	int AtkMaxRange = 0;

	// 대공 최대 사거리
	UPROPERTY(EditAnywhere)
	int AtkMaxRangeForFly = 0;

	// 최소 사거리
	UPROPERTY(EditAnywhere)
	int AtkMinRange = 0;

	// 코스트
	UPROPERTY(EditAnywhere)
	int Cost = 0;

	// Shell Fall
	UPROPERTY(EditAnywhere)
	int32 ShellFall = 20;
	
	UPROPERTY(EditAnywhere)
	USkeletalMesh* UpgradeMesh = nullptr;
};
