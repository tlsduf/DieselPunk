// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "../UserWidgetBase.h"
#include "MainUI.generated.h"


/**
 * 
 */
UCLASS()
class DIESELPUNK_API UMainUI : public UUserWidgetBase
{
	GENERATED_BODY()
	
private:

public:
	// UI를 생성한다.
	static UMainUI* CreateUI();

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
