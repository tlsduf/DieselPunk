// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "CharacterDataTable.generated.h"
/**
 * 캐릭터 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FCharacterDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//BP 경로
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BluePrintPath = TEXT("");
};
