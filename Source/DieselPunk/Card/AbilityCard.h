// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Card.h"

/**
 * 터렛 카드입니다.
 */

class ACharacterPC;
class DIESELPUNK_API FAbilityCard : public FCard
{
	EAbilityCardType AbilityCardType;
	TArray<FString> BlueprintNames;
public:
	FAbilityCard(int32 InKey, const FString& InCardName, TWeakObjectPtr<ACharacterPC> InOwner);
	virtual ~FAbilityCard() override;

private:
	//카드 사용 함수
	virtual void _Activate(bool& OutSuccess, int32 InCost) override;
	//카드 사용 완료 함수
	virtual void _Complete(bool& OutSuccess, int32 InCost) override;
};
