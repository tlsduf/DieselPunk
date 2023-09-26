// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include <Engine/DataAsset.h>
#include "DpDataAssetForUI.generated.h"


// UI 관련 데이터들을 관리하는 데이터 에셋
UCLASS()
class DIESELPUNK_API UDpDataAssetForUI : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// UI 등장 애니메이션 속도
	UPROPERTY( EditAnywhere, Category = "UI" )
	float AppearanceSpeed = 0.2f;

	// UI 퇴장 애니메이션 속도
	UPROPERTY( EditAnywhere, Category = "UI" )
	float DisappearanceSpeed = 0.2f;

	// 롱 프레스 인식 시간
	UPROPERTY( EditAnywhere, Category = "UI" )
	float LongPressedTime = 0.3f;

	// HP 변화량 속도
	UPROPERTY( EditAnywhere, Category = "UI | HP" )
	float HpAnimSpeed = 0.2f;

public:
	// 생성자
	UDpDataAssetForUI() {}
};
