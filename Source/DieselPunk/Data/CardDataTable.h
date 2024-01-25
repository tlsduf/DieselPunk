// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/DataTable.h>

#include "CardDataTable.generated.h"
/**
 * 캐릭터 데이터 테이블입니다.
 */
USTRUCT()
struct DIESELPUNK_API FCardDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
	//카드 타입
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardType CardType = ECardType::Turret;

	//코스트
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Cost = 0;

	//카드 이미지 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ImageNames;

	//카드 최대 티어
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxTier = 1;

	//설치할 포탑, 설치물 이름. 어빌리티 카드의 경우 공란으로 두시면 됩니다. FCharacterData에 등록한 이름으로 등록하면 됩니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterName = "";

	//어빌리티 타입을 설정합니다. 어빌리티 카드가 아닌 경우 None으로 두시면 됩니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAbilityCardType AbilityCardType = EAbilityCardType::None;

};
