// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../UserWidgetBase.h"
#include "DpStartMenu.generated.h"

class UButton;
class APlayerControllerBase;
/**
 * HUD UI 클래스입니다.
 */
UCLASS()
class DIESELPUNK_API UDpStartMenu : public UUserWidgetBase
{
	GENERATED_BODY()
	TWeakObjectPtr<APlayerControllerBase> PlayerControllerBase = nullptr;
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* StartButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* EndButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* SettingButton = nullptr;
public:
	virtual void OnCreated() override;

	UFUNCTION()
	void ClickedButtonStart();

	UFUNCTION()
	void ClickedButtonEnd();

	UFUNCTION()
	void ClickedButtonSetting();

public:
	void SetPlayerControllerBase(APlayerControllerBase* InPlayerControllerBase);
};
