// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "../UserWidgetBase.h"
#include "HudFadeCanvas.generated.h"

class FOnButtonClickedEvent;
class UButton;
class UBackgroundBlur;
class UTextBlock;
class UWidgetAnimation;

enum FHudFadeCanvasUIType : uint8
{
	TopText = 1,				// 상단에 표시되는 텍스트블록입니다.
	ButtonText = 2,				// 버튼에 표시되는 텍스트블록입니다.
	BottomText_Upper = 4,		// 하단에 표시되는 텍스트블록중 위 텍스트 블록입니다.
	BottomText_Under = 8,		// 하단에 표시되는 텍스트블록중 아래 텍스트 블록입니다.
	LeftText = 16,				// 좌측에 표시되는 텍스트블록입니다.
	BackgroundBlur = 32,
	Button = 64
};

struct CardInfo;
UCLASS()
class DIESELPUNK_API UHudFadeCanvas : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	//UI//////////////////////////////////////////////////////////////////////////
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UBackgroundBlur* BackgroundBlur = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* TopText = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* Button = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* ButtonText = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* BottomText_Upper = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* BottomText_Under = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* LeftText = nullptr;

	//Animation///////////////////////////////////////////////////////////////////
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* ScaleUpAnimation = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* ScaleDownAnimation = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* FadeInOutAnimation = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* FadeInAnimation = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* FadeOutAnimation = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* BlurOnAnimation = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* BlurOutAnimation = nullptr;

	FTimerHandle DefconTHandle;
	int32 DefconCount = 0;
	FTimerHandle ReSpawnTHandle;
	int32 ReSpawnTime = 0;

public:
	// 생성자
	virtual void OnCreated() override;

	//페이드 인/아웃 애니메이션 사용하기 전에 어떤 유아이를 보여줄 건지 넘겨받습니다.
	//enum class FHudFadeCanvasUIType의 타입을 비트단위연산자or로 넘겨주면됩니다.
	//ex) HudFadeCanvas->InitHudFadeCanvasAnimation(FHudFadeCanvasUIType::TopText | FHudFadeCanvasUIType::Button | FHudFadeCanvasUIType::ButtonText)
	//위와 같이 변수를 주게되면, 상단부 텍스트와 버튼, 그리고 버튼의 텍스트만 화면에 출력됩니다. 나머지 UI는 Visibility를 Hidden으로 변경합니다.
	void InitUIVisibility(uint8 InVisibilityUIType);

	void StopAllAnimation();
	void PlayScaleUpAnimation() { PlayAnimation(ScaleUpAnimation); };
	void PlayScaleDownAnimation() { PlayAnimation(ScaleDownAnimation); };
	void PlayFadeInOutAnimation() { PlayAnimation(FadeInOutAnimation); };
	void PlayFadeInAnimation() { PlayAnimation(FadeInAnimation); };
	void PlayFadeOutAnimation() { PlayAnimation(FadeOutAnimation); };
	void PlayBlurOnAnimation() { PlayAnimation(BlurOnAnimation); };
	void PlayBlurOutAnimation() { PlayAnimation(BlurOutAnimation); };

	void SetTextBlock(FHudFadeCanvasUIType InUIType, const FText& InText, float InFontSize, FColor InColor);
	FOnButtonClickedEvent& GetButtonClickedEvent();

	
	void OnWaveStarted();	// 웨이브가 시작했을 때, TopText(웨이브시작)만 보이게 하고 효과를 적용합니다.
	void OnWaveCleared();	// 웨이브가 클리어됐을 때, TopText(웨이브클리어)만 보이게 하고 효과를 적용합니다.
	void CountDefconTime(int32 InDefconTime);	// 웨이브 종료 후, 데프콘 시간이 있을 때, 카운트다운을 표시합니다.
	void CountingDefconTime();
	void OnMainPCDieScreen(int32 InReSpawnTime);		// PC사망시
	void CountingReSpawnTime();
	void LevelClearScreen();	// 레벨을 클리어 했을 때
	void GameOverScreen();	// 넥서스의 체력이 0이하가 됐을 때

	UFUNCTION()
	void OnLevelRestarted();
};

