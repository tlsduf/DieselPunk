// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "../InfoGroupBase.h"
#include "TestInfo.generated.h"


/**
 * 그냥 테스트용 임시 테이블
 */
USTRUCT()
struct DIESELPUNK_API FTestInfo : public FInfoGroupBase
{
	GENERATED_USTRUCT_BODY()

	// 테스트 스트링
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	FString TestString = TEXT( "" );
};

GENERATED_INFO_PTR      ( FTestInfo );
GENERATED_INFO_GROUP_PTR( FTestInfo );