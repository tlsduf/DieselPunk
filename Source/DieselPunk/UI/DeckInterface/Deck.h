// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "../UserWidgetBase.h"
#include "Deck.generated.h"

class UScrollBox;
class FCard;
class UDeckCardRow;

UCLASS()
class DIESELPUNK_API UDeck : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UScrollBox* SBox;

	UPROPERTY(EditAnywhere, Category="MYDP_UI")
	TSubclassOf<UUserWidget> CardRowClass;
	
	TArray<TWeakObjectPtr<UDeckCardRow>> CardRows;

public:
	// 생성자
	virtual void OnCreated() override;

	virtual void BeginDestroy() override;

	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

public:
	//카드를 등록합니다.
	void RegisterCards(TArray<const FCard*> InCards);
};

