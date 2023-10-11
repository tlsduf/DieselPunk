// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "../UserWidgetBase.h"
#include "ItemGuideUI.generated.h"


class UTextBlock;

UCLASS()
class DIESELPUNK_API UItemGuideUI : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	// 생성자
	virtual void OnCreated() override;

	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

private:
	// 위젯을 초기화한다.
	void InitWidget();

};
