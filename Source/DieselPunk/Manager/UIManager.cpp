// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "../Logic/UIController.h"
#include "../Util/UtilPath.h"
#include "../UI/HUD/MainUI.h"


// =============================================================
// 생성자
// =============================================================
FUIManager::FUIManager()
{

}

// =============================================================
// 소멸자
// =============================================================
FUIManager::~FUIManager()
{

}

// =============================================================
// 초기화
// =============================================================
void FUIManager::InitSingleton()
{
	UIController = new FUIController();

	FDpGameDelegate::Get().GetDelegateWorldMoveFinished().AddRaw( this, &FUIManager::OnWorldMoveFinished );
}

// =============================================================
// 데이터 정리
// =============================================================
void FUIManager::ClearSingleton()
{
	if ( UIController ) 
		delete UIController;

	UIController = nullptr;

	MainUI = nullptr;

	_RemoveUIAll();
}

// =============================================================
// Tick
// =============================================================
void FUIManager::Tick( float InDeltaTime )
{
	for ( auto iter = AppearanceAnimators.CreateIterator(); iter; iter++ )
	{
		Animator& animator = *iter;

		animator.Update( InDeltaTime );

		if ( !animator.IsRunning() )
			iter.RemoveCurrent();
	}

	for ( auto iter = DisappearanceAnimators.CreateIterator(); iter; iter++ )
	{
		Animator& animator = *iter;

		animator.Update( InDeltaTime );

		if ( !animator.IsRunning() )
			iter.RemoveCurrent();
	}
}

// =============================================================
// GetStatId ( FTickableGameObject 필수 인터페이스 )
// =============================================================
TStatId FUIManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT( FUIManager, STATGROUP_Tickables );
}

// =============================================================
// 월드 이동이 완료되었음을 알린다.
// =============================================================
void FUIManager::OnWorldMoveFinished()
{
	GetMainUI();
}

// =============================================================
// UI를 화면에 출력한다.
// =============================================================
void FUIManager::ShowUI( UUserWidget* InUserWidget, int32 InZOrder )
{
	if ( !InUserWidget )
		return;

	// 별도의 부모에 종속되어있는 경우는 여기서 뷰포트에 추가할 필요 X
	if ( InUserWidget->GetParent() )
		return;

	// 등장 / 퇴장 애니메이션시 별도의 포지션에서 시작하게할건지..?  고민... 일단 추후 작업
	if ( UUserWidgetBase* userWidgetBase = Cast< UUserWidgetBase >( InUserWidget ) )
	{
		TWeakObjectPtr< UUserWidgetBase > widgetPtr = userWidgetBase;

		AnimatorParam param;
		param.AnimType = EAnimType::CubicEaseInOut;
		param.StartValue = 0.f;
		param.EndValue = 1.f;
		param.DurationTime = DA_UI( AppearanceSpeed );
		param.DurationFunc = [ widgetPtr ] ( float InValue )
		{
			if ( !widgetPtr.IsValid() ) return;

			widgetPtr->SetRenderOpacity( InValue );

			// RenderScale 애니메이션은 별로 이쁘지않은듯?
			//widgetPtr->SetRenderScale( FVector2D( InValue, InValue ) );

			widgetPtr->OnAppearing();
		};

		param.CompleteFunc = [ widgetPtr, InZOrder ] ( float InValue )
		{
			if ( !widgetPtr.IsValid() ) return;

			widgetPtr->SetRenderOpacity( InValue );
			//widgetPtr->SetRenderScale( FVector2D( InValue, InValue ) );

			widgetPtr->OnAppeared();
		};

		AppearanceAnimators.Emplace( param );
	}

	FDpGameDelegate::Get().GetDelegateUserWidgetShowed().Broadcast( *InUserWidget );

	InUserWidget->AddToViewport( InZOrder );
}

// =============================================================
// UI를 제거한다.
// =============================================================
bool FUIManager::RemoveUI( UUserWidget* InUserWidget )
{
	TRACE_CPUPROFILER_EVENT_SCOPE( FUIManager::RemoveUI );

	if ( !InUserWidget )
		return false;

	_RemoveUIAtManagedList( InUserWidget );

	if ( UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( InUserWidget ) )
	{
		TWeakObjectPtr< UUserWidgetBase > widgetPtr = userWidgetBase;

		AnimatorParam param;
		param.AnimType = EAnimType::CubicEaseInOut;
		param.StartValue = 1.f;
		param.EndValue = 0.f;
		param.DurationTime = DA_UI( DisappearanceSpeed );
		param.DurationFunc = [ widgetPtr ] ( float InValue )
		{
			if ( !widgetPtr.IsValid() ) return;

			widgetPtr->SetRenderOpacity( InValue );
			//widgetPtr->SetRenderScale( FVector2D( InValue, InValue ) );

			widgetPtr->OnDisappearing();
		};

		// TODO( "UI Object Pool 고민해보기");
		param.CompleteFunc = [ widgetPtr ] ( float InValue )
		{
			if ( !widgetPtr.IsValid() ) return;

			widgetPtr->SetRenderOpacity( InValue );
			//widgetPtr->SetRenderScale( FVector2D( InValue, InValue ) );

			widgetPtr->OnDisappeared();

			widgetPtr->RemoveFromRoot();
			widgetPtr->RemoveFromParent();

			FDpGameDelegate::Get().GetDelegateUserWidgetRemoved().Broadcast( *widgetPtr.Get() );
		};

		DisappearanceAnimators.Emplace( param );
		return true;
	}

	if ( InUserWidget->IsValidLowLevel() )
	{
		InUserWidget->RemoveFromRoot();
		InUserWidget->RemoveFromParent();

		FDpGameDelegate::Get().GetDelegateUserWidgetRemoved().Broadcast( *InUserWidget );
	}

	return true;
}

// =============================================================
// UI를 즉시 제거한다 ( 애니메이션 없이 즉시 반납 )
// =============================================================
void FUIManager::RemoveImmediatelyUI( UUserWidget* InUserWidget )
{
	if ( !InUserWidget->IsValidLowLevel() )
		return;

	_RemoveUIAtManagedList( InUserWidget );

	InUserWidget->RemoveFromRoot();
	InUserWidget->RemoveFromParent();
}

// =============================================================
// Type 에 해당하는 위젯을 검색하고 반환한다.
// =============================================================
UUserWidget* FUIManager::FindUI( const UClass* InClass )
{
	FUserWidgetList* userWidgetList = ManagedUIList.Find( InClass );
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
UUserWidget* FUIManager::FindVisibleUI( const UClass* InClass )
{
	FUserWidgetList* userWidgetList = ManagedUIList.Find( InClass );
	if ( !userWidgetList )
		return nullptr;

	for ( FUserWidgetPtr& userWidgetPtr : *userWidgetList )
	{
		if ( !userWidgetPtr.IsValid() )
			continue;

		if ( !userWidgetPtr->IsVisible() )
			continue;

		return userWidgetPtr.Get();
	}

	return nullptr;
}

// =============================================================
// 메인 UI를 반환한다
// =============================================================
UMainUI* FUIManager::GetMainUI( bool InCreateUI )
{
	if ( !MainUI.IsValid() )
	{
		MainUI = UMainUI::CreateUI();
		if ( !MainUI.IsValid() )
			return nullptr;

		ShowUI( MainUI.Get() );
	}

	return MainUI.Get();
}

// =============================================================
// 모든 UI를 제거한다.
// =============================================================
void FUIManager::_RemoveUIAll()
{
	for ( auto& managedUIPair : ManagedUIList )
	{
		for ( auto& userWidget : managedUIPair.Value )
		{
			if ( !userWidget.IsValid() )
				continue;

			if ( !userWidget->IsValidLowLevel() )
				continue;

			userWidget->RemoveFromRoot();
			userWidget->RemoveFromParent();
		}

		managedUIPair.Value.Empty();
	}

	ManagedUIList.Empty();
}

// =============================================================
// 관리중인 UI에서 해당 UI를 제거한다
// =============================================================
void FUIManager::_RemoveUIAtManagedList( UUserWidget* InUserWidget )
{
	UUserWidgetBase* userWidgetBase = Cast< UUserWidgetBase >( InUserWidget );
	const UClass* widgetClass = userWidgetBase ? userWidgetBase->_GetUserWidgetClass() : InUserWidget->StaticClass();

	FUserWidgetList* userWidgetList = ManagedUIList.Find( widgetClass );
	if ( !userWidgetList )
		return;

	FUserWidgetPtr* userWidget = userWidgetList->Find( InUserWidget );
	if ( !userWidget || !userWidget->IsValid() )
		return;

	userWidgetList->Remove( InUserWidget );

	if ( !userWidgetList->IsEmpty() )
		return;

	ManagedUIList.Remove( InUserWidget->StaticClass() );
}
