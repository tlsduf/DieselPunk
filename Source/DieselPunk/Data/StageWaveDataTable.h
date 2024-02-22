// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/DataTable.h>

#include "StageWaveDataTable.generated.h"

//한 스포너에 스폰시킬 몬스터 정보입니다.
USTRUCT(BlueprintType)
struct FStageWaveInfo
{
	GENERATED_USTRUCT_BODY()

	// Defcon : 웨이브 시작 전, 준비시간에 대한 정보입니다.
	
	// 데프콘(준비시간)유무입니다. true면 사용, false면 비사용
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDefconTimeUse = false;

	// 데프콘 시간(준비시간)입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DefconTime = 0;
	
	//스폰할 몬스터의 이름입니다. DT_Character와 행 이름이 동일해야합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> WaveModuleInfoID;

	// 웨이브가 끝난 후, 보상관련 정보입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CostReward = 0;
};


USTRUCT()
struct DIESELPUNK_API FStageWaveDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//몬스터 스폰 정보입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FStageWaveInfo> StageWaveInfo;
};
