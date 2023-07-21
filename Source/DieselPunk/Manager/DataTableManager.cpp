// Copyright GuardiansW. All Rights Reserved.


#include "DataTableManager.h"
#include "../Data/Info/CharacterInfo.h"
#include "../Data/Info/TestInfo.h"

// =============================================================
// 생성자
// =============================================================
FDataTableManager::FDataTableManager()
{
	
}

// =============================================================
// 소멸자
// =============================================================
FDataTableManager::~FDataTableManager()
{

}

// =============================================================
// 초기화
// =============================================================
void FDataTableManager::InitSingleton()
{
	ClearCallbackList.Reserve( 100 );

	_LoadDataTableAll();
}

// =============================================================
// 데이터 정리
// =============================================================
void FDataTableManager::ClearSingleton()
{
	for ( const auto& callback : ClearCallbackList )
	{
		if( callback ) callback();
	}

	ClearCallbackList.Empty();
}

// =============================================================
// 데이터 테이블을 모두 로드한다.
// =============================================================
void FDataTableManager::_LoadDataTableAll()
{
	_LoadDataTable     <FCharacterInfo	 >( CharacterInfos ,								    TEXT( "DT_Character" ) );
	_LoadDataTableGroup<FTestInfo		 >( TestInfos      ,   TestInfoGroups		,		TEXT( "DT_Test"      ) );
	//_LoadDataTableGroup<FAbilityInfo     >( AbilityInfos   ,   AbilityInfoGroups	,   	TEXT( "DT_Ability"   ) );
}