// Copyright GuardiansW. All Rights Reserved.


#pragma once


#include "StatusUIBase.h"
#include "EnemyStatusUI.generated.h"

class UProgressBar;
class UTextBlock;
class UImage;

UCLASS()
class DIESELPUNK_API UEnemyStatusUI : public UStatusUIBase
{
	GENERATED_BODY()
	
protected:
	UProgressBar*			ProgressBarHP;				// HP 바
	UProgressBar*			ProgressBarHPAfterImage;	// HP 바 잔상
	UTextBlock*				Stack;						// 스택
	UTextBlock*				StackMulti;					// 곱하기
	UImage*                 ImageIcon;					// 아이콘 이미지

public:
	void SetHPPercent(float inPercent);
	void SetHPPercentAfterImage(float inPercent);
	void SetTextStack(int inNumber);
	
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
