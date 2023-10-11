// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemGuideUI.h"
#include <Components/TextBlock.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(ItemGuideUI)


// =============================================================
// 생성자
// =============================================================
void UItemGuideUI::OnCreated()
{
	Super::OnCreated();

	InitWidget();
}

void UItemGuideUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

// =============================================================
// 위젯을 초기화한다.
// =============================================================
void UItemGuideUI::InitWidget()
{
	
}

