// Fill out your copyright notice in the Description page of Project Settings.


#include "HudFadeCanvas.h"

#include "Animation/WidgetAnimation.h"
#include "Components/BackgroundBlur.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "DieselPunk/Character/CharacterBase.h"
#include "DieselPunk/Core/DPLevelScriptActor.h"
#include "DieselPunk/Logic/PlayerControllerBase.h"
#include "Engine/Level.h"
#include "Kismet/GameplayStatics.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(HudFadeCanvas)


// =============================================================
// 생성자
// =============================================================
void UHudFadeCanvas::OnCreated()
{
	Super::OnCreated();

	InitUIVisibility(FHudFadeCanvasUIType::LeftText);
	PlayScaleUpAnimation();
	PlayFadeInAnimation();
}

void UHudFadeCanvas::InitUIVisibility(uint8 InVisibilityUIType)
{
	if(InVisibilityUIType & (uint8)FHudFadeCanvasUIType::BackgroundBlur)
		BackgroundBlur->SetVisibility(ESlateVisibility::Visible);
	else
		BackgroundBlur->SetVisibility(ESlateVisibility::Hidden);
	
	if(InVisibilityUIType & (uint8)FHudFadeCanvasUIType::TopText)
		TopText->SetVisibility(ESlateVisibility::Visible);
	else
		TopText->SetVisibility(ESlateVisibility::Hidden);

	if(InVisibilityUIType & (uint8)FHudFadeCanvasUIType::Button)
		Button->SetVisibility(ESlateVisibility::Visible);
	else
		Button->SetVisibility(ESlateVisibility::Hidden);

	if(InVisibilityUIType & (uint8)FHudFadeCanvasUIType::ButtonText)
		ButtonText->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	else
		ButtonText->SetVisibility(ESlateVisibility::Hidden);
	
	if(InVisibilityUIType & (uint8)FHudFadeCanvasUIType::BottomText_Upper)
		BottomText_Upper->SetVisibility(ESlateVisibility::Visible);
	else
		BottomText_Upper->SetVisibility(ESlateVisibility::Hidden);
	
	if(InVisibilityUIType & (uint8)FHudFadeCanvasUIType::BottomText_Under)
		BottomText_Under->SetVisibility(ESlateVisibility::Visible);
	else
		BottomText_Under->SetVisibility(ESlateVisibility::Hidden);

	if(InVisibilityUIType & (uint8)FHudFadeCanvasUIType::LeftText)
	{
		LeftText->SetVisibility(ESlateVisibility::Visible);
		LeftButtonImage->SetVisibility(ESlateVisibility::Visible);
		LeftButtonText->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		LeftText->SetVisibility(ESlateVisibility::Hidden);
		LeftButtonImage->SetVisibility(ESlateVisibility::Hidden);
		LeftButtonText->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UHudFadeCanvas::StopAllAnimation()
{
	if(IsPlayingAnimation())
		StopAllAnimations();
}

void UHudFadeCanvas::SetTextBlock(FHudFadeCanvasUIType InUIType, const FText& InText, float InFontSize, FColor InColor)
{
	if(InUIType > FHudFadeCanvasUIType::LeftText)
		return;

	FSlateColor color(InColor);
	if(InUIType & FHudFadeCanvasUIType::TopText)
	{
		FSlateFontInfo fontInfo = TopText->GetFont();
		fontInfo.Size = InFontSize;

		TopText->SetColorAndOpacity(color);
		TopText->SetText(InText);
	}
	else if(InUIType & FHudFadeCanvasUIType::ButtonText)
	{
		FSlateFontInfo fontInfo = ButtonText->GetFont();
		fontInfo.Size = InFontSize;

		ButtonText->SetColorAndOpacity(color);
		ButtonText->SetText(InText);
	}
	else if(InUIType & FHudFadeCanvasUIType::BottomText_Upper)
	{
		FSlateFontInfo fontInfo = BottomText_Upper->GetFont();
		fontInfo.Size = InFontSize;

		BottomText_Upper->SetColorAndOpacity(color);
		BottomText_Upper->SetText(InText);
		
	}
	else if(InUIType & FHudFadeCanvasUIType::BottomText_Under)
	{
		FSlateFontInfo fontInfo = BottomText_Under->GetFont();
		fontInfo.Size = InFontSize;

		BottomText_Under->SetColorAndOpacity(color);
		BottomText_Under->SetText(InText);
	}
	else if(InUIType & FHudFadeCanvasUIType::LeftText)
	{
		FSlateFontInfo fontInfo = LeftText->GetFont();
		fontInfo.Size = InFontSize;

		LeftText->SetColorAndOpacity(color);
		LeftText->SetText(InText);
	}
}

FOnButtonClickedEvent& UHudFadeCanvas::GetButtonClickedEvent()
{
	return Button->OnClicked;
}

// 웨이브가 시작했을 때, TopText(웨이브시작)만 보이게 하고 효과를 적용합니다.
void UHudFadeCanvas::OnWaveStarted()
{
	//Setting Properties
	SetTextBlock(FHudFadeCanvasUIType::TopText, FText::FromString(FString::Printf(TEXT("전투개시"))), 10, FColor::White);

	//Setting Visibility
	InitUIVisibility(FHudFadeCanvasUIType::TopText);

	//Setting Animation
	StopAllAnimation();
	PlayFadeInOutAnimation();
	PlayScaleUpAnimation();
}

void UHudFadeCanvas::OnWaveCleared()
{
	//Setting Properties
	SetTextBlock(FHudFadeCanvasUIType::TopText, FText::FromString(FString::Printf(TEXT("웨이브클리어"))), 10, FColor::White);

	//Setting Visibility
	InitUIVisibility(FHudFadeCanvasUIType::TopText | FHudFadeCanvasUIType::LeftText);

	//Setting Animation
	StopAllAnimation();
	PlayFadeInOutAnimation();
	PlayScaleUpAnimation();
}

void UHudFadeCanvas::CountDefconTime(int32 InDefconTime)
{
	//Setting Properties
	FText text = FText::FromString(FString::Printf(TEXT("다음침공까지 %d"), InDefconTime));
	SetTextBlock(FHudFadeCanvasUIType::TopText, text, 4, FColor::White);

	//Setting Visibility
	InitUIVisibility(FHudFadeCanvasUIType::TopText | FHudFadeCanvasUIType::LeftText);

	//Setting Animation
	StopAllAnimation();
	PlayFadeInAnimation();
	PlayScaleUpAnimation();

	//Special Task
	DefconCount = InDefconTime;
	GetWorld()->GetTimerManager().SetTimer(DefconTHandle, this, &UHudFadeCanvas::CountingDefconTime, 1.0f, true);
}

void UHudFadeCanvas::CountingDefconTime()
{
	DefconCount--;

	if(DefconCount <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(DefconTHandle);
		return;
	}
	
	if(DefconCount > 3)
	{
		FText text = FText::FromString(FString::Printf(TEXT("다음침공까지 %d"), DefconCount));
		SetTextBlock(FHudFadeCanvasUIType::TopText, text, 8, FColor::White);
		return;
	}

	FText text = FText::FromString(FString::Printf(TEXT("%d"), DefconCount));
	SetTextBlock(FHudFadeCanvasUIType::TopText, text, 10, FColor::White);
}

void UHudFadeCanvas::OnMainPCDieScreen(int32 InReSpawnTime)
{
	//Setting Properties
	SetTextBlock(FHudFadeCanvasUIType::TopText, FText::FromString(FString::Printf(TEXT("중상을 당해 후송 되었습니다."))), 7, FColor::Red);
	SetTextBlock(FHudFadeCanvasUIType::BottomText_Upper, FText::FromString(FString::Printf(TEXT("임무 재배치 까지"))), 4, FColor::White);
	FText text = FText::FromString(FString::Printf(TEXT("%d"), InReSpawnTime));
	SetTextBlock(FHudFadeCanvasUIType::BottomText_Under, text, 7, FColor::White);
	
	//Setting Visibility
	InitUIVisibility(FHudFadeCanvasUIType::TopText | FHudFadeCanvasUIType::BottomText_Upper | FHudFadeCanvasUIType::BottomText_Under);

	//Setting Animation
	StopAllAnimation();
	PlayFadeInAnimation();
	PlayScaleUpAnimation();

	//Special Task
	ReSpawnTime = InReSpawnTime;
	GetWorld()->GetTimerManager().SetTimer(DefconTHandle, this, &UHudFadeCanvas::CountingReSpawnTime, 1.0f, true);
}

void UHudFadeCanvas::CountingReSpawnTime()
{
	ReSpawnTime--;

	if(ReSpawnTime <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(DefconTHandle);
		//Setting Animation
		StopAllAnimation();
		PlayFadeOutAnimation();
		PlayScaleDownAnimation();
		return;
	}

	FText text = FText::FromString(FString::Printf(TEXT("%d"), ReSpawnTime));
	SetTextBlock(FHudFadeCanvasUIType::BottomText_Under, text, 7, FColor::White);
}

void UHudFadeCanvas::LevelClearScreen()
{
	//Setting Properties
	SetTextBlock(FHudFadeCanvasUIType::TopText, FText::FromString(FString::Printf(TEXT("레벨 클리어"))), 10, FColor::White);

	//Setting Visibility
	InitUIVisibility(FHudFadeCanvasUIType::TopText | FHudFadeCanvasUIType::BackgroundBlur);

	//Setting Animation
	StopAllAnimation();
	PlayFadeInAnimation();
	PlayScaleUpAnimation();
	PlayBlurOnAnimation();
}

void UHudFadeCanvas::GameOverScreen()
{
	//Setting Properties
	SetTextBlock(FHudFadeCanvasUIType::TopText, FText::FromString(FString::Printf(TEXT("임무 실패"))), 10, FColor::White);

	//Setting Visibility
	InitUIVisibility(FHudFadeCanvasUIType::TopText | FHudFadeCanvasUIType::ButtonText | FHudFadeCanvasUIType::Button | FHudFadeCanvasUIType::BackgroundBlur);

	//Setting Animation
	StopAllAnimation();
	PlayFadeInAnimation();
	PlayScaleUpAnimation();
	PlayBlurOnAnimation();

	//Binding Button
	Button->OnClicked.AddDynamic(this, &UHudFadeCanvas::OnLevelRestarted);

	//Setting MouseControl
	ACharacterBase* charBase = Cast<ACharacterBase>(Owner);
	if(charBase)
	{
		if(APlayerControllerBase* playerController = Cast<APlayerControllerBase>(charBase->GetController()))
		{
			playerController->ClearAllBindInputActions();
			playerController->SetUIControlOn();
			//playerController->SetShowMouseCursor(true);
			//SetCursor(EMouseCursor::Type::Default);
			FInputModeUIOnly inputMode;
			inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			playerController->SetInputMode(inputMode);
		}
	}
}

void UHudFadeCanvas::OnLevelRestarted()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(*GetWorld()->GetName()), false);
	Button->OnClicked.Clear();
}

