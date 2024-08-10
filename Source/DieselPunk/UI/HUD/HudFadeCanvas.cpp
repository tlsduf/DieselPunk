// Fill out your copyright notice in the Description page of Project Settings.


#include "HudFadeCanvas.h"

#include "Components/BackgroundBlur.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(HudFadeCanvas)


// =============================================================
// 생성자
// =============================================================
void UHudFadeCanvas::OnCreated()
{
	Super::OnCreated();
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
		ButtonText->SetVisibility(ESlateVisibility::Visible);
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
}

void UHudFadeCanvas::PlayFadeOutAnimation()
{
	if(IsPlayingAnimation())
		StopAllAnimations();
	
	PlayAnimation(FadeOutAnimation);
}

void UHudFadeCanvas::PlayFadeInAnimation()
{
	if(IsPlayingAnimation())
		StopAllAnimations();
	
	PlayAnimation(FadeInAnimation);
}

void UHudFadeCanvas::SetTextBlock(FHudFadeCanvasUIType InUIType, const FText& InText, float InFontSize, FColor InColor)
{
	if(InUIType > FHudFadeCanvasUIType::BottomText_Under)
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
		FSlateFontInfo fontInfo = TopText->GetFont();
		fontInfo.Size = InFontSize;

		TopText->SetColorAndOpacity(color);
		TopText->SetText(InText);
	}
	else if(InUIType & FHudFadeCanvasUIType::BottomText_Upper)
	{
		FSlateFontInfo fontInfo = TopText->GetFont();
		fontInfo.Size = InFontSize;

		TopText->SetColorAndOpacity(color);
		TopText->SetText(InText);
		
	}
	else if(InUIType & FHudFadeCanvasUIType::BottomText_Under)
	{
		FSlateFontInfo fontInfo = TopText->GetFont();
		fontInfo.Size = InFontSize;

		TopText->SetColorAndOpacity(color);
		TopText->SetText(InText);
	}
}

FOnButtonClickedEvent& UHudFadeCanvas::GetButtonClickedEvent()
{
	return Button->OnClicked;
}
