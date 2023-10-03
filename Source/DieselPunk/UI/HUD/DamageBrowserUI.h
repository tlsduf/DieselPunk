// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "../UserWidgetBase.h"
#include "DamageBrowserUI.generated.h"


class UTextBlock;

UCLASS()
class DIESELPUNK_API UDamageBrowserUI : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY()
	UTextBlock* DamageText;				// 왼쪽 스킬 할당키
	
public:
	// UI를 생성한다.
	static UDamageBrowserUI* CreateUI();
	
protected:
	// 생성자
	virtual void OnCreated() override;

	// 소멸자
	virtual void BeginDestroy() override;

	// 화면에 보이는 시점에 호출되는 함수
	virtual void OnAppeared() override;

	// 화면에서 사라지는 시점에 호출되는 함수
	virtual void OnDisappeared() override;

private:
	// 위젯을 초기화한다.
	void _InitControls();


};
