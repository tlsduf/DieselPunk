// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "../UserWidgetBase.h"
#include "InteractInstallation.generated.h"

class UTextBlock;
class ACharacterBase;
class UHorizontalBox;
class FCard;
class ACharacterPC;
struct CardInfo;
UCLASS()
class DIESELPUNK_API UInteractInstallation : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UHorizontalBox* Button1;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UHorizontalBox* Button2;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UHorizontalBox* Button3;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Button3Additional;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Description1Text;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Description2Text;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Description3Text;

public:
	// 생성자
	virtual void OnCreated() override;

	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

	void Selected(bool InSelected);
};

