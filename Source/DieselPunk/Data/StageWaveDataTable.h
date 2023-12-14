// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/DataTable.h>

#include "StageWaveDataTable.generated.h"

//한 스포너에 스폰시킬 몬스터 정보입니다.
USTRUCT(BlueprintType)
struct FStageWaveInfo
{
	GENERATED_USTRUCT_BODY()

	// 웨이브 시작 전, 준비시간에 대한 정보입니다. (임시)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DefconInfo = 0.f;
	
	//스폰할 몬스터의 이름입니다. DT_Character와 행 이름이 동일해야합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> WaveInfoID;

	// 웨이브가 끝난 후, 보상관련 정보입니다. (임시)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SupplyInfo = 0.f;
};


USTRUCT()
struct DIESELPUNK_API FStageWaveDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//몬스터 스폰 정보입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FStageWaveInfo> StageWaveInfo;
};
