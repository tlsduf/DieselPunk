// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyStatusUI.h"

#include <Components/TextBlock.h>
#include <Components/ProgressBar.h>
#include <Components/Image.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(EnemyStatusUI)


void UEnemyStatusUI::SetHPPercent(float inPercent)
{
	if ( InProgressBarHP )
		InProgressBarHP->SetPercent( inPercent );
}

void UEnemyStatusUI::SetHPPercentAfterImage(float inPercent)
{
	if ( InProgressBarHPAfterImage )
		InProgressBarHPAfterImage->SetPercent( inPercent );
}

void UEnemyStatusUI::SetTextStack(int inNumber)
{
	InStack->SetText( FText::FromString( FString::FromInt(inNumber) ) );
	if( InStack == 0 )
		InStack;
	else
		InStack;
}

// =============================================================
// 생성자
// =============================================================
void UEnemyStatusUI::OnCreated()
{
	Super::OnCreated();

	InitWidget();
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void UEnemyStatusUI::InitWidget()
{
	if(Cast<UProgressBar>( GetWidgetFromName("ProgressBarHP")) != nullptr)
		InProgressBarHP = Cast<UProgressBar>( GetWidgetFromName("ProgressBarHP"));
	if(Cast<UProgressBar>( GetWidgetFromName("ProgressBarHPAfterImage")) != nullptr)
		InProgressBarHPAfterImage = Cast<UProgressBar>( GetWidgetFromName("ProgressBarHPAfterImage"));
	if(Cast<UTextBlock>( GetWidgetFromName("Stack")) != nullptr)
		InStack = Cast<UTextBlock>( GetWidgetFromName("Stack"));
	if(Cast<UTextBlock>( GetWidgetFromName("StackMulti")) != nullptr)
		InStackMulti = Cast<UTextBlock>( GetWidgetFromName("StackMulti"));
	if(Cast<UImage>( GetWidgetFromName("ImageIcon")) != nullptr)
		InImageIcon = Cast<UImage>( GetWidgetFromName("ImageIcon"));
}
