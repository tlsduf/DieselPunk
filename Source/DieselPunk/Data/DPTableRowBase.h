// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/DataTable.h>
#include "DPTableRowBase.generated.h"

/**
 * 데이터 테이블 기본 형태입니다.
 * ID를 기록합니다.
 */
USTRUCT()
struct DIESELPUNK_API FDPTableRowBase : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//데이터 ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DataID = 0;
};
