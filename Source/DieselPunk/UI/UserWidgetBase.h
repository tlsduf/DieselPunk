// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include <Blueprint/UserWidget.h>
#include "UserWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class DIESELPUNK_API UUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()
protected:
	TWeakObjectPtr<AActor> Owner = nullptr;
public:
	UWidget* operator[](const TCHAR* InWidgetName);

public:
	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

	// 생성시 호출해줘야되는 함수
	virtual void OnCreated();

	FORCEINLINE void SetOwner(AActor* InOwner){Owner = InOwner;}
};
