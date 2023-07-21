// Copyright GuardiansW. All Rights Reserved.
//
// 데이터 에셋 관련 편의 함수 모음


#pragma once


#include "DpDataAssetForUI.h"
//#include "DpDataAssetForPCStateLv.h"
#include "../Util/UtilPath.h"


namespace DpDataAssetHelper
{
	// 데이터 에셋을 불러온다.
	template<typename Type>
	const Type* GetDataAsset( const FString& InFileName );
}


// =============================================================
// 데이터 에셋을 불러온다.
// UE_SCOPED_TIMER 로 시간 측정시 static 이나 별도의 캐싱 없어도 현재 1ms 미만으로 동작
// =============================================================
template<typename Type>
const Type* DpDataAssetHelper::GetDataAsset( const FString& InFileName )
{
	UE_SCOPED_TIMER( *InFileName, DpLog, Log );

	Type* dataAsset = LoadObject< Type >( nullptr, *UtilPath::GetDataAssetPath( InFileName ) );
	return dataAsset;
}


// =============================================================
// 매번 Get 함수 쓰기 번거로운 경우
// 아래 매크로 선언해서 사용
// =============================================================
#define DA_UI( Value ) \
	DpDataAssetHelper::GetDataAsset< UDpDataAssetForUI >( TEXT( "DA_UI" ) )->##Value

#define DA_PC_STATE_LV( Value ) \
	DpDataAssetHelper::GetDataAsset< UDpDataAssetForPCStateLv >( TEXT("DA_PCStateLv") )->StatesLvInfos[##Value##]