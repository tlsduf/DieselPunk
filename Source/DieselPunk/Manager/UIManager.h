// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "../Core/SingletonBase.h"
#include "..\Core\DpGameDelegate.h"
#include "../UI/UserWidgetBase.h"
#include <UObject/ConstructorHelpers.h>
#include <Tickable.h>


class FUIController;
class UMainUI;


// UI 매니저
// 앞으로 모든 UI 는 해당 매니저를 통해 관리되어집니다
class FUIManager : public TSingletonBase<FUIManager>, public FTickableGameObject
{
private:
	typedef TWeakObjectPtr< UUserWidget >          FUserWidgetPtr;
	typedef TSet< FUserWidgetPtr >                 FUserWidgetList;
	typedef TMap< const UClass*, FUserWidgetList > FUIMap;

private:
	FUIController*          UIController;           // 추후 삭제 될 듯
	FUIMap                  ManagedUIList;          // 매니저가 관리중인 UI 목록
	TWeakObjectPtr<UMainUI> MainUI;                 // Main UI

	TArray< Animator >      AppearanceAnimators;    // 등장 애니메이션에 사용될 애니메이터 리스트
	TArray< Animator >      DisappearanceAnimators; // 퇴장 애니메이션에 사용될 애니메이터 리스트

public:
	// 생성자
	FUIManager();

	// 소멸자
	virtual ~FUIManager();

	// 초기화
	virtual void InitSingleton() override;

	// 데이터 정리
	virtual void ClearSingleton() override;

	// Tick
	virtual void Tick( float InDeltaTime ) override;

	// GetStatId ( FTickableGameObject 인터페이스 )
	virtual TStatId GetStatId() const override;

	// 월드 이동이 완료되었음을 알린다.
	void OnWorldMoveFinished();

	// UI를 화면에 출력한다.
	void ShowUI( UUserWidget* InUserWidget, int32 InZOrder = UIConst::DefaultZ );

	// UI를 제거한다.
	bool RemoveUI( UUserWidget* InUserWidget );

	// UI를 즉시 제거한다 ( 애니메이션 없이 즉시 반납 )
	void RemoveImmediatelyUI( UUserWidget* InUserWidget );

	// Type 에 해당하는 위젯을 검색하고 반환한다.
	UUserWidget* FindUI( const UClass* InClass );

	// Type 에 해당하는 보여지고 있는 위젯을 검색하고 반환한다.
	UUserWidget* FindVisibleUI( const UClass* InClass );

	// 메인 UI를 반환한다
	UMainUI* GetMainUI( bool InCreateUI = true );

	// UI 매니저가 관리하지 않을 UI를 생성한다.
	template< typename Type >
	Type* CreateUnmanagedUI( const FString& InPath );

	// UI 매니저가 관리할 UI를 생성한다.
	template< typename Type >
	Type* CreateUI( const FString& InPath );

	// Type 에 해당하는 위젯을 검색하고 반환한다.
	template< typename Type >
	Type* FindUI();

	// Type 에 해당하는 보여지고 있는 위젯을 검색하고 반환한다.
	template< typename Type >
	Type* FindVisibleUI();

private:
	// UI를 생성한다.
	template< typename Type >
	Type* _CreateUI( const FString& InPath );

	// 모든 UI를 제거한다.
	void _RemoveUIAll();

	// 관리중인 UI에서 해당 UI를 제거한다
	void _RemoveUIAtManagedList( UUserWidget* InUserWidget );
};


GENERATE_SINGLETON_GETTER( UIManager )


// =============================================================
// UI 매니저가 관리하지 않을 UI를 생성한다.
// 일반적인 상황에서는 관리자를 통해 관리되어야 하기 때문에
// 인자값이 아닌 함수 이름으로 구분
// =============================================================
template< typename Type >
Type* FUIManager::CreateUnmanagedUI( const FString& InPath )
{
	Type* userWidget = _CreateUI<Type>( InPath );
	if ( userWidget )
		userWidget->RemoveFromRoot();

	return userWidget;
}

// =============================================================
// UI 매니저가 관리할 UI를 생성한다.
// =============================================================
template< typename Type >
Type* FUIManager::CreateUI( const FString& InPath )
{
	Type* userWidget = _CreateUI<Type>( InPath );
	if ( !userWidget ) 
		return nullptr;

	FUserWidgetList& userWidgetList = ManagedUIList.FindOrAdd( Type::StaticClass() );
	userWidgetList.Add( userWidget );

	return userWidget;
}

// =============================================================
// Type 에 해당하는 위젯을 검색하고 반환한다.
// =============================================================
template< typename Type >
Type* FUIManager::FindUI()
{
	FUserWidgetList* userWidgetList = ManagedUIList.Find( Type::StaticClass() );
	if ( !userWidgetList )
		return nullptr;

	for ( FUserWidgetPtr& userWidgetPtr : *userWidgetList )
	{
		if ( !userWidgetPtr.IsValid() )
			continue;

		return userWidgetPtr.Get();
	}

	return nullptr;
}

// =============================================================
// Type 에 해당하는 보여지고 있는 위젯을 검색하고 반환한다.
// =============================================================
template< typename Type >
Type* FUIManager::FindVisibleUI()
{
	FUserWidgetList* userWidgetList = ManagedUIList.Find( Type::StaticClass() );
	if ( !userWidgetList )
		return nullptr;

	for ( FUserWidgetPtr& userWidgetPtr : *userWidgetList )
	{
		if ( !userWidgetPtr.IsValid() )
			continue;

		if( !userWidgetPtr->IsVisible() )
			continue;

		return userWidgetPtr.Get();
	}

	return nullptr;
}

// =============================================================
// UI를 생성한다
// Show 되기 전에는 화면에 보여지지 않는다
// =============================================================
template< typename Type >
Type* FUIManager::_CreateUI( const FString& InPath )
{
	TRACE_CPUPROFILER_EVENT_SCOPE( FUIManager::_CreateUI );

	FString path = UtilPath::GetUIPath( InPath );
	UClass* widgetClass = ConstructorHelpersInternal::FindOrLoadClass( path, UUserWidget::StaticClass() );
	if ( !widgetClass )
	{
		return nullptr;
	}

	UUserWidget* userWidget = CreateWidget<UUserWidget>( DpGetWorld(), widgetClass );
	if ( userWidget )
	{
		userWidget->AddToRoot();

		UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( userWidget );
		if ( userWidgetBase )
		{
			userWidgetBase->OnCreated();
			userWidgetBase->_SetUserWidgetClass( Type::StaticClass() );
		}

		FDpGameDelegate::Get().GetDelegateUserWidgetCreated().Broadcast( *userWidgetBase );

		return Cast<Type>( userWidget );
	}

	return nullptr;
}