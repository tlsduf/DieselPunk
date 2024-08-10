// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../UserWidgetBase.h"
#include "DPHud.generated.h"

class UHudFadeCanvas;
class UInteractInstallation;
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
	UHudFadeCanvas* HudFadeCanvas = nullptr;

public:
	virtual void OnCreated() override;
	
	void SetViewInteractionUI(bool InView);

	void SelectedInteractionUI(bool InSelected);
};
