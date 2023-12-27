// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "../UserWidgetBase.h"
#include "CardDetail.generated.h"

class UButton;
class FDeckHandler;

UCLASS()
class DIESELPUNK_API UCardDetail : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	FDeckHandler* DeckHandler;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetOptional))
	UUserWidgetBase* Tier0;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetOptional))
	UUserWidgetBase* Tier1;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetOptional))
	UUserWidgetBase* Tier2;

	TArray<TWeakObjectPtr<UUserWidgetBase>> Cards;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* PreviousCard;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* NextCard;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* PreviousTier;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* NextTier;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* Exit;

	int32 TierIndex;
	int32 MaxTier;
	int32 CurrentKey;
public:
	// 생성자
	virtual void OnCreated() override;

	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

	void SetDeckHandler(FDeckHandler* InDeckHandler){DeckHandler = InDeckHandler;}

	void OpenCardDetail(int32 InKey);
public:
	UFUNCTION()
	void PreviousCardButtonExecute();
	UFUNCTION()
	void NextCardButtonExecute();
	UFUNCTION()
	void PreviousTierButtonExecute();
	UFUNCTION()
	void NextTierButtonExecute();
	UFUNCTION()
	void ExitCardDetail();
};

