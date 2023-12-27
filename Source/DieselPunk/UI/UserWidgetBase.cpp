// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetBase.h"

#include <Blueprint/WidgetTree.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(UserWidgetBase)

// =============================================================
// 생성시 호출해줘야되는 함수
// =============================================================
void UUserWidgetBase::OnCreated()
{

}

UWidget* UUserWidgetBase::operator[](const TCHAR* InWidgetName)
{
	return WidgetTree->FindWidget(InWidgetName);
}

// =============================================================
// 틱
// =============================================================
void UUserWidgetBase::NativeTick( const FGeometry& MyGeometry, float InDeltaTime )
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}
