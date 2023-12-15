// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "../UserWidgetBase.h"
#include "Hand.generated.h"

class UHorizontalBox;
class FCard;
struct CardInfo;
UCLASS()
class DIESELPUNK_API UHand : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UHorizontalBox* HBox;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidget* Hand0;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidget* Hand1;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidget* Hand2;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidget* Hand3;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidget* Hand4;

public:
	// 생성자
	virtual void OnCreated() override;

	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

public:
	//카드들을 등록합니다
	void RegisterHands(TArray<FCard*> InHands);

	//카드를 등록합니다.
	void RegisterHand(int InIndex, const CardInfo* InCardInfo);

	//카드 등록 해제합니다. Visibility를 Hidden으로 변경합니다.
	void UnRegisterHand(int InIndex);

	//카드의 사이즈를 변경합니다.
	void ResizeHandCard(int InIndex, FVector2d InSize);
};

