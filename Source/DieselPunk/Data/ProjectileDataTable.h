// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "ProjectileDataTable.generated.h"

USTRUCT()
struct FExplosionSplashInfo
{
	GENERATED_BODY()

	//폭발 데미지 거리
	UPROPERTY(EditAnywhere)
	float Radius = 100.f;

	//폭발 계수, 원래 데미지 * DamageCoefficient의 데미지를 입힙니다.
	float DamageCoefficient = 1.f;
};

/**
 * 스킬 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FProjectileDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//발사체 영어 이름
	UPROPERTY(EditAnywhere)
	FName NameEN = NAME_None;

	//발사체 한글 이름
	UPROPERTY(EditAnywhere)
	FName NameKR = NAME_None;

	//발사체 설명
	UPROPERTY(EditAnywhere, meta=(MultiLine=true))
	FText Explain = FText();
	
	//폭발 스플래시 정보
	UPROPERTY(EditAnywhere)
	TArray<FExplosionSplashInfo> ExplosionSplashInfos; 
};
