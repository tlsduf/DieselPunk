// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DPTableRowBase.h"
#include "SkillDataTable.generated.h"

/**
 * 스킬 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FSkillDataTable : public FDPTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//스킬 영어 이름
	UPROPERTY(EditAnywhere)
	FName NameEN = NAME_None;

	//스킬 한글 이름
	UPROPERTY(EditAnywhere)
	FName NameKR = NAME_None;

	//스킬 설명
	UPROPERTY(EditAnywhere, meta=(MultiLine=true))
	FText Explain = FText();

	//발동 방식?

	//액티브 타입?

	//쿨타임
	UPROPERTY(EditAnywhere)
	float CoolDown = 0.f;

	//스킬 지속시간
	UPROPERTY(EditAnywhere)
	float Duration = 0.f;

	//피격 횟수
	UPROPERTY(EditAnywhere)
	int32 Count = 1;

	//피격 간격
	UPROPERTY(EditAnywhere)
	float CountInterval = 0.f;

	//적용 대상
	UPROPERTY(EditAnywhere)
	TArray<ECharacterType> Targets;

	//스킬 계수
	UPROPERTY(EditAnywhere)
	float SkillCoefficient = 0.f;

	//발사할 발사체 이름
	UPROPERTY(EditAnywhere)
	FName ProjectileNameEN = NAME_None;
};
