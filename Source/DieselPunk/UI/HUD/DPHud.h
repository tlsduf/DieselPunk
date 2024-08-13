// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../UserWidgetBase.h"
#include "DPHud.generated.h"

class UHand;
class UHudFadeCanvas;
class UInteractInstallation;
class UProgressBar;
class UTextBlock;
struct CardInfo;
/**
 * HUD UI 클래스입니다.
 */
UCLASS()
class DIESELPUNK_API UDPHud : public UUserWidgetBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UInteractInstallation* InteractionUI = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UHand* Hand = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UHudFadeCanvas* HudFadeCanvas = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UProgressBar* DieselCoreHpBar = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* CurrentWaveText = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* MaxWaveText = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* CurrentMonsterText = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* MaxMonsterText = nullptr;

	int32 DieselCoreHp = 0;
	int32 DieselCoreMaxHp = 0;

	bool OnViewCard = true;
public:
	virtual void OnCreated() override;
	
	void SetViewInteractionUI(bool InView);

	void SelectedInteractionUI(bool InSelected);

	void OnWaveStarted(int32 InCurrentWaveIndex, int32 InMaxWaveCount, int32 InMaxMonster);

	void OnMonsterInSpawnerDead();

	void InitDieselCoreHpBar(int32 InHp, int32 InMaxHp);

	void OnStatChanged(TWeakObjectPtr<AActor> InActor, ECharacterStatType InCharacterType, int32 InValue);

	void OnOffViewCard();

	void SetViewCard(const CardInfo* InCardInfo);
};
