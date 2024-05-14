// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "LevelBgmDataTable.generated.h"

/**
 * 레벨 BGM 데이터 테이블입니다.
 * 행 이름인 레벨 네임과 실행할 레벨Bgm 정보를 가지고 있습니다.
 */
USTRUCT()
struct DIESELPUNK_API FLevelBgmDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()

	//실행할 에셋 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AssetName = TEXT("");
	
	//볼륨 곱연산
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VolumeMultiplier = 1.f;

	//피치 곱연산
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PitchMultiplier = 1.f;;
};
