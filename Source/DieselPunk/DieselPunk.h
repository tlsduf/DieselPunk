// Copyright Epic Games, Inc. All Rights Reserved.





#pragma once


// =============================================================
// Unreal Engine Header
// =============================================================
#include <CoreMinimal.h>
#include <TimerManager.h>
#include <Engine/World.h>
#include <Engine/Engine.h>
#include <Engine/GameInstance.h>
#include <UObject/ObjectMacros.h>
#include <UObject/ConstructorHelpers.h>
#include <Misc/Build.h>
#include <Templates/SubclassOf.h>
#include <Templates/Function.h>
#include <ProfilingDebugging/ScopedTimers.h>


// =============================================================
// C++ Header
// =============================================================
#include <functional>


// =============================================================
// GuardiansW Header
//		(전역 인클루드가 굳이 필요한지?)
//		Include-What-You-Use (IWYU) 를 지키는지 꼭 확인
//		컴파일 시간에 직접적인 영향을 줍니다
// =============================================================
#include "Common/Const.h"
//#include "Common/Define.h"
#include "Common/Enum.h"
#include "Common/Typedef.h"
#include "Common/DpLog.h"
#include "Common/DpUserData.h"
#include "Common/RTTI.h"
#include "DataAsset/DpDataAssetHelper.h"
#include "Util/Animator.h"
#include "Util/UtilFunctor.h"


class ACharacterPC;


// 월드를 반환한다.
UWorld* DpGetWorld( UObject* InObject = nullptr );

// 현재 월드가 프리뷰 월드 ( 블루 프린트 월드 ) 인지 반환한다.
bool DpIsPreviewWorld( UWorld* InWorld );

// 게임 인스턴스를 반환한다.
UGameInstance* DpGetGameInstance( UWorld* InWorld = nullptr );

// 내 플레이어 컨트롤러를 반환한다.
APlayerController* DpGetPlayerController();

// 내 플레이어 캐릭터를 반환한다.
ACharacterPC* DpGetPlayer();


DECLARE_LOG_CATEGORY_EXTERN(LogDieselPunk, Log, All);


// =============================================================
// 게임 인스턴스를 반환한다.
// UGameInstance 기반 클래스로 캐스팅해서 반환
// =============================================================
template<typename Type>
Type* DpGetGameInstance( UWorld* InWorld = nullptr )
{
	return Cast< Type >(DpGetGameInstance( InWorld ));
}

// =============================================================
// 내 플레이어 컨트롤러를 반환한다.
// APlayerController 기반 클래스로 캐스팅해서 반환
// =============================================================
template<typename Type>
Type* DpGetPlayerController()
{
	return Cast< Type >(DpGetPlayerController( InWorld ));
}

// =============================================================
// delete
// =============================================================
template<typename Type>
void DpDelete( Type*& InPointer )
{
	if ( InPointer )
		delete InPointer;
	InPointer = nullptr;
}