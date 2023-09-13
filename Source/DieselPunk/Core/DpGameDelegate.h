// Copyright GuardiansW. All Rights Reserved.
//
// 게임에서 전역적으로 자주 접근하는 델리게이트 모음


#pragma once


#include <Delegates/Delegate.h>
#include <GameDelegates.h>


class UUserWidget;


// 아무런 인자값이 없는 void() 형태의 델리게이트 타입
DECLARE_MULTICAST_DELEGATE( FDelegateSimple );

// void(AActor*) 형태의 델리게이트 타입
DECLARE_MULTICAST_DELEGATE_OneParam( FDelegateSimpleActor, AActor* );

// void(AActor*, ObjId) 형태의 델리게이트 타입
DECLARE_MULTICAST_DELEGATE_TwoParams( FDelegateActorSpawned, AActor*, FObjId );

// void(UUserWidget*) 형태의 델리게이트 타입
DECLARE_MULTICAST_DELEGATE_OneParam( FDelegateUserWidget, UUserWidget& );

// 월드 이동시 델리게이트 타입
DECLARE_MULTICAST_DELEGATE( FDelegateWorldMoveFinished );


class DIESELPUNK_API FDpGameDelegate
{
public:
	static FDpGameDelegate& Get();

	static void Clear();

public:
	// 액터 생성시 호출되는 델리게이트
	DEFINE_GAME_DELEGATE_TYPED( DelegateActorSpawned, FDelegateActorSpawned );

	// 액터 제거시 호출되는 델리게이트
	DEFINE_GAME_DELEGATE_TYPED( DelegateActorDespawned, FDelegateSimpleActor );

	// 액터 클릭시 호출되는 델리게이트
	DEFINE_GAME_DELEGATE_TYPED( DelegateActorClicked, FDelegateSimpleActor );

	// 타겟팅 갱신시 호출되는 델리게이트
	DEFINE_GAME_DELEGATE_TYPED( DelegateTargetUpdated, FDelegateSimpleActor );

	// UI 생성시 호출되는 델리게이트
	DEFINE_GAME_DELEGATE_TYPED( DelegateUserWidgetCreated, FDelegateUserWidget );

	// UI 생성시 호출되는 델리게이트
	DEFINE_GAME_DELEGATE_TYPED( DelegateUserWidgetShowed, FDelegateUserWidget );

	// UI 제거시 호출되는 델리게이트
	DEFINE_GAME_DELEGATE_TYPED( DelegateUserWidgetRemoved, FDelegateUserWidget );

	// 월드 이동시 호출되는 델리게이트
	DEFINE_GAME_DELEGATE_TYPED( DelegateWorldMoveFinished, FDelegateWorldMoveFinished );
};