// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "SearchAreaDataTable.generated.h"

/**
 * 탐색 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FSearchAreaDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()

	//탐색 범위 타입
	UPROPERTY(EditAnywhere, Category="MYDP_Targeting")
	ESearchAreaType SearchAreaType = ESearchAreaType::Rectangle;

	//사각형 너비 그리드 개수
	UPROPERTY(EditAnywhere, Category="MYDP_Targeting", meta=(EditCondition="SearchAreaType == ESearchAreaType::Rectangle"))
	float RectangleWidth = 1000.f;
	
	//부채꼴 각도
	UPROPERTY(EditAnywhere, Category="MYDP_Targeting", meta=(EditCondition="SearchAreaType == ESearchAreaType::Arc"))
	float ArcAngle = 30.f;

	//높이
	UPROPERTY(EditAnywhere)
	float CircleHeight = 1000.f;
	
	// 최대 사거리
	UPROPERTY(EditAnywhere)
	int AtkMaxRange = 0;

	// 대공 최대 사거리
	UPROPERTY(EditAnywhere)
	int AtkMaxRangeForFly = 0;

	// 최소 사거리
	UPROPERTY(EditAnywhere)
	int AtkMinRange = 0;
};
