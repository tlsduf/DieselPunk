// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemGuideUI.h"
#include "../../Manager/UIManager.h"
#include <Components/TextBlock.h>

#include <string>

#include UE_INLINE_GENERATED_CPP_BY_NAME(ItemGuideUI)


// =============================================================
// 생성자
// =============================================================
void UItemGuideUI::OnCreated()
{
	Super::OnCreated();

	_InitControls();

}

// =============================================================
// 소멸자
// =============================================================
void UItemGuideUI::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// 화면에 보이는 시점에 호출되는 함수
// =============================================================
void UItemGuideUI::OnAppeared()
{
	Super::OnAppeared();
}

// =============================================================
// 화면에서 사라지는 시점에 호출되는 함수
// =============================================================
void UItemGuideUI::OnDisappeared()
{
	Super::OnDisappeared();
}

void UItemGuideUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void UItemGuideUI::_InitControls()
{
	_InitControl( DamageText, TEXT( "DamageText" ) );
}

