// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyStatusUI.h"
#include "../../Manager/UIManager.h"

#include <Components/TextBlock.h>
#include <Components/ProgressBar.h>
#include <string>
#include <Components/Image.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(EnemyStatusUI)


void UEnemyStatusUI::SetHPPercent(float inPercent)
{
	if ( ProgressBarHP )
		ProgressBarHP->SetPercent( inPercent );
}

void UEnemyStatusUI::SetHPPercentAfterImage(float inPercent)
{
	if ( ProgressBarHPAfterImage )
		ProgressBarHPAfterImage->SetPercent( inPercent );
}

void UEnemyStatusUI::SetTextStack(int inNumber)
{
	Stack->SetText( FText::FromString( FString::FromInt(inNumber) ) );
	if( Stack == 0 )
		Stack;
	else
		Stack;
}

// =============================================================
// 생성자
// =============================================================
void UEnemyStatusUI::OnCreated()
{
	Super::OnCreated();

	_InitControls();
}

// =============================================================
// 소멸자
// =============================================================
void UEnemyStatusUI::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// 화면에 보이는 시점에 호출되는 함수
// =============================================================
void UEnemyStatusUI::OnAppeared()
{
	Super::OnAppeared();
}

// =============================================================
// 화면에서 사라지는 시점에 호출되는 함수
// =============================================================
void UEnemyStatusUI::OnDisappeared()
{
	Super::OnDisappeared();
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void UEnemyStatusUI::_InitControls()
{
	_InitControl( ProgressBarHP, TEXT( "ProgressBarHP" ) );
	_InitControl( ProgressBarHPAfterImage, TEXT( "ProgressBarHPAfterImage" ) );
	_InitControl( Stack, TEXT( "Stack" ) );
	_InitControl( StackMulti, TEXT( "StackMulti" ) );
	_InitControl( ImageIcon, TEXT( "ImageIcon" ) );
}
