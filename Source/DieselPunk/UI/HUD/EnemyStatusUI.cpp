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
	_InitControl( InProgressBarHP, TEXT( "ProgressBarHP" ) );
	_InitControl( InProgressBarHPAfterImage, TEXT( "ProgressBarHPAfterImage" ) );
	_InitControl( InStack, TEXT( "Stack" ) );
	_InitControl( InStackMulti, TEXT( "StackMulti" ) );
	_InitControl( InImageIcon, TEXT( "ImageIcon" ) );
}
