// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractInstallation.h"
#include "../../Character/CharacterPC.h"
#include "../../Manager/ObjectManager.h"

#include <Components/Image.h>
#include <Components/TextBlock.h>
#include <Blueprint/WidgetTree.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(InteractInstallation)


// =============================================================
// 생성자
// =============================================================
void UInteractInstallation::OnCreated()
{
	Super::OnCreated();
}

// =============================================================
// 틱
// =============================================================
void UInteractInstallation::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UInteractInstallation::Selected(bool InSelected)
{
	if(InSelected)
	{
		Description1Text->SetText(FText::FromString(TEXT("선택 취소")));
		Description2Text->SetText(FText::FromString(TEXT("강화")));
		Description3Text->SetText(FText::FromString(TEXT("판매")));
	}
	else
	{
		Description1Text->SetText(FText::FromString(TEXT("선택")));
		Description2Text->SetText(FText::FromString(TEXT("상호작용")));
		Description3Text->SetText(FText::FromString(TEXT("수리")));
	}
}
