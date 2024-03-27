// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "WaveModuleDataTable.generated.h"

//한 스포너에 스폰시킬 몬스터 정보입니다.
USTRUCT(BlueprintType)
struct FWaveModuleInfo
{
	GENERATED_USTRUCT_BODY()

	//스폰할 몬스터의 이름입니다. DT_Character와 행 이름이 동일해야합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString MonsterID;

	// 몬스터를 n 만큼 스폰합니다
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SpawnCount = 0.f;
	
	// 스폰을 시작하기 까지 시간입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StartDelay = 0.f;

	// 인터벌 반복을 할 것인지 treu 면 딜레이 시간마다 Reps 번 스폰합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDoRep = false;

	// 인터벌 딜레이 시간입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Delay = 0.f;
	
	// 반복 횟수입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Reps = 0;
};


USTRUCT()
struct DIESELPUNK_API FWaveModuleDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//웨이브 정보입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWaveModuleInfo> WaveModuleInfo;
};
