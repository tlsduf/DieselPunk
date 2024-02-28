// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/DataTable.h>
#include "BuffDataTable.generated.h"

/**
 * 버프 데이터 테이블입니다.
 * 행 이름인 버프 네임과 버프 정보를 가지고 있습니다.
 */
USTRUCT()
struct DIESELPUNK_API FBuffDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//변경할 스탯
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECharacterStatType CharacterStatType = ECharacterStatType::Hp;

	//버프 종료 시 스탯 복구할 지
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsStore = false;
	
	//버프가 틱으로 동작할건 지
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsTick = false;
	
	//버프 배율 타입(백분율/상수)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBuffValueType BuffValueType = EBuffValueType::Constant;

	//밸류
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double Value = 0.0;
	
	//버프 적용 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double BuffTime = 5.0;

	//틱 적용 빈도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(EditConditionHides = "IsTick"))
	double Frequency = 1.0;
};
