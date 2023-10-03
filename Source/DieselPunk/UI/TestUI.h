// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "UserWidgetBase.h"
#include "TestUI.generated.h"


class UButton;


/**
 * 
 */
UCLASS()
class DIESELPUNK_API UTestUI : public UUserWidgetBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	UButton* ButtonExit;

protected:
	// 생성자
	virtual void OnCreated() override;

	// 소멸자
	virtual void BeginDestroy() override;

	// 화면에 보이는 시점에 호출되는 함수
	virtual void OnAppeared() override;

	// 화면에서 사라지는 시점에 호출되는 함수
	virtual void OnDisappeared() override;

	// Exit 버튼이 눌렸음을 처리하는 함수
	UFUNCTION()
	void OnExitButtonClicked();

private:
	// 위젯을 초기화한다.
	void _InitControls();
};
