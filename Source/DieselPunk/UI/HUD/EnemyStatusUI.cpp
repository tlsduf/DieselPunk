// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyStatusUI.h"
#include <Components/ProgressBar.h>


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
}
