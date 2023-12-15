// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "../UserWidgetBase.h"
#include "DeckCardRow.generated.h"

class UTextBlock;
class UButton;
struct CardInfo;

UCLASS()
class DIESELPUNK_API UDeckCardRow : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* Card0;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* Card1;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* Card2;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* Card3;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* Card4;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Text0;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Text1;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Text2;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Text3;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Text4;
	
public:
	// 생성자
	virtual void OnCreated() override;

	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

public:
	//카드를 등록합니다.
	void RegisterCard(int InIndex, const CardInfo* InCardInfo);

	//카드 등록을 해지합니다. SetVisibility를 Hidden으로 변경합니다.
	void UnRegisterCard(int InIndex);
};

