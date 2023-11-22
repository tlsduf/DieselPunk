// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "../UserWidgetBase.h"
#include "EnemyStatusUI.generated.h"

class UProgressBar;

UCLASS()
class DIESELPUNK_API UEnemyStatusUI : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	UProgressBar*			InProgressBarHP;				// HP 바
	UProgressBar*			InProgressBarHPAfterImage;		// HP 바 잔상

public:
	void SetHPPercent(float inPercent);
	void SetHPPercentAfterImage(float inPercent);
	
protected:
	// 생성자
	virtual void OnCreated() override;

private:
	// 위젯을 초기화한다.
	void InitWidget();

};
