// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include <Blueprint/UserWidget.h>
#include "UserWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class DIESELPUNK_API UUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()

private:
	friend class FUIManager;

private:
	UClass*        UserWidgetClass;   // UI Manager 에서 사용하기 위한 네이티브 클래스 정보
	FVector2D      LastTouchPosition; // 가장 최근에 터치가 된 위치
	bool           IsMousePressed;    // 마우스가 눌려지고 있는지 여부
	FIntervalTimer LongPressedTimer;  // 롱 프레스 인식 타이머

public:
	// 위젯 비저빌리티 제어 함수
	virtual void SetVisibility( ESlateVisibility InVisibility ) override;

	// 가장 최근에 터치된 지점을 반환한다.
	FORCEINLINE FVector2D GetLastTouchPosition() { return LastTouchPosition; }

protected:
	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

	// 생성자
	virtual void OnCreated();

	// 소멸자
	virtual void BeginDestroy() override;

	// 화면에 보여지기 시작하는 시점에 호출되는 함수
	virtual void OnAppearing();

	// 화면에 보이는 시점에 호출되는 함수
	virtual void OnAppeared();

	// 화면에서 사라지기 시작하는 시점에 호출되는 함수
	virtual void OnDisappearing();

	// 화면에서 사라지는 시점에 호출되는 함수
	virtual void OnDisappeared();

	// 마우스 버튼이 클릭되었음을 처리하는 함수
	virtual FReply NativeOnMouseButtonDown( const FGeometry& InGeometry, const FPointerEvent& InMouseEvent ) override;

	// 마우스 버튼이 떼어졌음을 처리하는 함수
	virtual FReply NativeOnMouseButtonUp( const FGeometry& InGeometry, const FPointerEvent& InMouseEvent ) override;

	// 위젯 위에 마우스 커서가 위치하는 경우 호출되는 함수
	virtual FReply NativeOnMouseMove( const FGeometry& InGeometry, const FPointerEvent& InMouseEvent ) override;

	// 위젯을 오래 클릭하고 있는 경우 호출되는 함수
	virtual void OnWidgetLongPressed();
	
	// 위젯을 검색 후 변수로 설정한다.
	template<typename T>
	bool _InitControl( T*& InWidget, const FName& InWidgetName );

private:
	//  UI Manager 에서 사용하기 위한 네이티브 클래스 정보를 반환한다.
	FORCEINLINE const UClass* _GetUserWidgetClass() const { return UserWidgetClass; }

	//  UI Manager 에서 사용하기 위한 네이티브 클래스 정보를 설정한다.
	FORCEINLINE void _SetUserWidgetClass( UClass* InClass ) { UserWidgetClass = InClass; }
};


// =============================================================
// 위젯을 검색 후 변수로 설정한다.
// =============================================================
template<typename T>
bool UUserWidgetBase::_InitControl( T*& InWidget, const FName& InWidgetName )
{
	InWidget = Cast< T >( GetWidgetFromName( InWidgetName ) );

	return InWidget != nullptr;
}
