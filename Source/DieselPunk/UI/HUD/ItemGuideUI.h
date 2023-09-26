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
	UTextBlock* DamageText;		// 데미지 텍스트
	
protected:
	// 생성자
	virtual void OnCreated() override;

	// 소멸자
	virtual void BeginDestroy() override;

	// 화면에 보이는 시점에 호출되는 함수
	virtual void OnAppeared() override;

	// 화면에서 사라지는 시점에 호출되는 함수
	virtual void OnDisappeared() override;

	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

private:
	// 위젯을 초기화한다.
	void _InitControls();
	

};
