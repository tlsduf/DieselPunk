// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/DataTable.h>

#include "WaveSetDataTable.generated.h"

//한 스포너에 스폰시킬 몬스터 정보입니다.
USTRUCT(BlueprintType)
struct FWaveInfo
{
	GENERATED_USTRUCT_BODY()

	//스폰할 웨이브 모듈 이름입니다. DT_WaveModule와 행 이름과 동일해야합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WaveModuleID;

	//웨이브 모듈 스폰 시작까지의 딜레이 시간입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StartDelay  = 0.f;
};


USTRUCT()
struct DIESELPUNK_API FWaveSetDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//몬스터 스폰 정보입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWaveInfo> WaveSetInfo;
};
