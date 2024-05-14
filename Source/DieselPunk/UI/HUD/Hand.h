// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "../UserWidgetBase.h"
#include "Hand.generated.h"

class UTextBlock;
class ACharacterBase;
class UHorizontalBox;
class FCard;
class ACharacterPC;
class UWidgetAnimation;

struct CardInfo;
UCLASS()
class DIESELPUNK_API UHand : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UHorizontalBox* HBox;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidgetBase* Hand0;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidgetBase* Hand1;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidgetBase* Hand2;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidgetBase* Hand3;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UUserWidgetBase* Hand4;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* Hand0ToHanger;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* Hand1ToHanger;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* Hand2ToHanger;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* Hand3ToHanger;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* Hand4ToHanger;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* DrawAnimation;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* TextCost;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* TextDeckCount;

	int32 PlayingAnimationCount = 0;
	
	int32 Cost;

	FWidgetAnimationDynamicEvent EventEndAnimation;

public:
	// 생성자
	virtual void OnCreated() override;

	void Initailize(ACharacterPC* InPlayer);

public:
	//카드들을 등록합니다
	void RegisterHands(TArray<FCard*> InHands);

	//카드를 등록합니다.
	void RegisterHand(int InIndex, const CardInfo* InCardInfo);

	//카드 등록 해제합니다. Visibility를 Hidden으로 변경합니다.
	UFUNCTION(BlueprintCallable)
	void UnRegisterHand(int InIndex);

	//핸드에서 행거로 이동하는 애니메이션을 재생합니다.
	UWidgetAnimation* PlayHandToHangerAnimation(int InIndex);

	//드로우 애니메이션을 재생합니다.
	void PlayDrawAnimation();

	//카드의 사이즈를 변경합니다.
	void ResizeHandCard(int InIndex, FVector2d InSize);

	UFUNCTION()
	void ChangeCredit(TWeakObjectPtr<AActor> InCharacter, ECharacterStatType InStatType, int32 InValue);

	UFUNCTION()
	void ChangeDeckCount(int32 InValue);

	bool GetIsPlayingAnimation(){return PlayingAnimationCount > 0;}

	UFUNCTION()
	void FinishAnimation();
};

