// Copyright GuardiansW. All Rights Reserved.


#include "UserWidgetBase.h"
#include <Blueprint/WidgetTree.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(UserWidgetBase)


// =============================================================
// 위젯 비저빌리티 제어 함수
// =============================================================
void UUserWidgetBase::SetVisibility( ESlateVisibility InVisibility )
{
	Super::SetVisibility( InVisibility );
}

// =============================================================
// 생성자
// =============================================================
void UUserWidgetBase::OnCreated()
{
	if ( !WidgetTree ) return;

	// 위젯 트리에 달려있는 커스텀 위젯들도 정상적으로 초기화되도록 호출
	WidgetTree->ForEachWidget( [] ( UWidget* InWidget )
	{
		if ( !InWidget ) return;

		if ( UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( InWidget ) )
		{
			userWidgetBase->OnCreated();
		}
	} );
}

// =============================================================
// 틱
// =============================================================
void UUserWidgetBase::NativeTick( const FGeometry& MyGeometry, float InDeltaTime )
{
	if ( LongPressedTimer.Tick( InDeltaTime ) )
	{
		OnWidgetLongPressed();
	}
}

// =============================================================
// 소멸자
// =============================================================
void UUserWidgetBase::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// 화면에 보여지기 시작하는 시점에 호출되는 함수
// =============================================================
void UUserWidgetBase::OnAppearing()
{
	if ( !WidgetTree ) return;

	WidgetTree->ForEachWidget( [] ( UWidget* InWidget )
	{
		if ( !InWidget ) return;

		if ( UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( InWidget ) )
		{
			userWidgetBase->OnAppearing();
		}
	} );
}

// =============================================================
// 화면에 보이는 시점에 호출되는 함수
// =============================================================
void UUserWidgetBase::OnAppeared()
{
	if ( !WidgetTree ) return;

	WidgetTree->ForEachWidget( [] ( UWidget* InWidget )
	{
		if ( !InWidget ) return;

		if ( UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( InWidget ) )
		{
			userWidgetBase->OnAppeared();
		}
	} );
}

// =============================================================
// 화면에서 사라지기 시작하는 시점에 호출되는 함수
// =============================================================
void UUserWidgetBase::OnDisappearing()
{
	if ( !WidgetTree ) return;

	WidgetTree->ForEachWidget( [] ( UWidget* InWidget )
	{
		if ( !InWidget ) return;

		if ( UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( InWidget ) )
		{
			userWidgetBase->OnDisappearing();
		}
	} );
}

// =============================================================
// 화면에서 사라지는 시점에 호출되는 함수
// =============================================================
void UUserWidgetBase::OnDisappeared()
{
	if ( !WidgetTree ) return;

	WidgetTree->ForEachWidget( [] ( UWidget* InWidget )
	{
		if ( !InWidget ) return;

		if ( UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( InWidget ) )
		{
			userWidgetBase->OnDisappeared();
		}
	} );
}

// =============================================================
// 마우스 버튼이 클릭되었음을 처리하는 함수
// =============================================================
FReply UUserWidgetBase::NativeOnMouseButtonDown( const FGeometry& InGeometry, const FPointerEvent& InMouseEvent )
{
	FReply reply = Super::NativeOnMouseButtonDown( InGeometry, InMouseEvent );

	LastTouchPosition = InMouseEvent.GetScreenSpacePosition();
	LongPressedTimer.Reset( DA_UI( LongPressedTime ), 1 );
	IsMousePressed = true;

	return reply;
}

// =============================================================
// 마우스 버튼이 떼어졌음을 처리하는 함수
// =============================================================
FReply UUserWidgetBase::NativeOnMouseButtonUp( const FGeometry& InGeometry, const FPointerEvent& InMouseEvent )
{
	FReply reply = Super::NativeOnMouseButtonUp( InGeometry, InMouseEvent );

	LongPressedTimer.Stop();
	IsMousePressed = false;

	return reply;
}

// =============================================================
// 위젯 위에 마우스 커서가 위치하는 경우 호출되는 함수
// =============================================================
FReply UUserWidgetBase::NativeOnMouseMove( const FGeometry& InGeometry, const FPointerEvent& InMouseEvent )
{
	FReply reply = Super::NativeOnMouseMove( InGeometry, InMouseEvent );

	if ( IsMousePressed )
	{
		LastTouchPosition = InMouseEvent.GetScreenSpacePosition();
	}

	return reply;
}

// =============================================================
// 위젯을 오래 클릭하고 있는 경우 호출되는 함수
// =============================================================
void UUserWidgetBase::OnWidgetLongPressed()
{
	LongPressedTimer.Stop();
}
