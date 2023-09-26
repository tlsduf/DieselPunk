// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "../Core/SingletonBase.h"
#include "../Data/InfoGroupBase.h"
#include "../Util/UtilPath.h"


// =============================================================
// DataTableManager 가 관리하는 데이터 테이블로 등록한다
// 
// Type =>	InfoBase, InfoGroupBase 기반의 struct 자료형
// Name =>	Info 이름을 붙인다
//			ex) DECLARE_DATATABLE_INFO( FAbcInfo, TestInfo )
//			    FAbcInfo* GetTestInfo(FInfoId InInfoId) 형태로 생김
//				멤버 변수의 이름은 Name 에 s 를 붙여서 생성됨
// =============================================================
#define DECLARE_DATATABLE_INFO(Type, Name)                           \
private:                                                             \
	TMap<FInfoId, const Type*> Name##s;                              \
public:                                                              \
	const Type* Get##Name( FInfoId InInfoId ) const                  \
	{                                                                \
		const Type* const* infoPtr = Name##s.Find( InInfoId );       \
		if( !infoPtr )                                               \
			return nullptr;                                          \
		return *infoPtr;                                             \
	}

#define DECLARE_DATATABLE_INFO_GROUP(Type, Name)                     \
private:                                                             \
	typedef TArray<const Type*> Type##s;                             \
private:                                                             \
	TMap<FInfoId, Type##s> Name##Groups;                             \
public:                                                              \
	const Type##s* Get##Name##Group( FInfoId InInfoId ) const        \
	{                                                                \
		const Type##s* infoGroupPtr = Name##Groups.Find( InInfoId ); \
		return infoGroupPtr;                                         \
	}


struct FCharacterInfo;
struct FTestInfo;

// 데이터 테이블 관리자 : 모든 데이터 테이블을 관리
class FDataTableManager : public TSingletonBase<FDataTableManager>
{
private:
	typedef TArray< FSimpleCallback > FSimpleCallbackList;

private:
	FSimpleCallbackList ClearCallbackList; // 게임 종료시 데이터 테이블을 정리하는 콜백 함수 리스트

private:
	// =============================================================
	// 추가되는 데이터 테이블은 아래에서 차례대로 선언
	// =============================================================
	// 캐릭터들의 스텟 정보가 담겨있는 데이터 테이블
	DECLARE_DATATABLE_INFO( FCharacterInfo, CharacterInfo );
	// 그룹 데이터 테이블 테스트용 테이블
	DECLARE_DATATABLE_INFO( FTestInfo,      TestInfo      );
	
	// =============================================================
	// 그룹 데이터는 여기 밑에서 선언
	// =============================================================
	// 그룹 데이터 테이블 테스트용
	DECLARE_DATATABLE_INFO_GROUP( FTestInfo,	TestInfo	);

public:
	// 생성자
	FDataTableManager();

	// 소멸자
	virtual ~FDataTableManager();

	// 초기화
	virtual void InitSingleton() override;

	// 데이터 정리
	virtual void ClearSingleton() override;


private:
	// 데이터 테이블을 모두 로드한다.
	void _LoadDataTableAll();

	// 데이터 테이블을 로드한다.
	template<typename DataTable, typename InfoMap>
	typename TEnableIf<TIsDerivedFrom<DataTable, FInfoBase>::Value>::Type _LoadDataTable( InfoMap& InInfoMap, const FString& InFileName );

	// FInfoBase 상속이 아님에도 호출되는 경우 체크
	template<typename DataTable, typename InfoMap>
	typename TEnableIf<!TIsDerivedFrom<DataTable, FInfoBase>::Value>::Type  _LoadDataTable( InfoMap& InInfoMap, const FString& InFileName );

	// 데이터 테이블을 로드한다. ( 그룹 정보 포함 )
	template<typename DataTable, typename InfoMap, typename InfoGroupMap>
	typename TEnableIf<TIsDerivedFrom<DataTable, FInfoGroupBase>::Value>::Type _LoadDataTableGroup( InfoMap& InInfoMap, InfoGroupMap& InInfoGroupMap, const FString& InFileName );

	// FInfoGroupBase 상속이 아님에도 호출되는 경우 체크
	template<typename DataTable, typename InfoMap, typename InfoGroupMap>
	typename TEnableIf<!TIsDerivedFrom<DataTable, FInfoGroupBase>::Value>::Type  _LoadDataTableGroup( InfoMap& InInfoMap, InfoGroupMap& InInfoGroupMap, const FString& InFileName );
};


GENERATE_SINGLETON_GETTER( DataTableManager )


// =============================================================
// 데이터 테이블을 로드한다.
// FInfoBase 와 상속 관계가 아닌 경우 에러 출력
// =============================================================
template<typename DataTable, typename InfoMap>
typename TEnableIf<!TIsDerivedFrom<DataTable, FInfoBase>::Value>::Type 
FDataTableManager::_LoadDataTable( InfoMap& InInfoMap, const FString& InFileName )
{
	ensureMsgf( false, TEXT( "%s Is Not Based FInfoBase DataTable" ), *InFileName );
}

// =============================================================
// 데이터 테이블을 로드한다.
// FInfoGroupBase 와 상속 관계가 아닌 경우 에러 출력
// =============================================================
template<typename DataTable, typename InfoMap, typename InfoGroupMap>
typename TEnableIf<!TIsDerivedFrom<DataTable, FInfoGroupBase>::Value>::Type
FDataTableManager::_LoadDataTableGroup( InfoMap& InInfoMap, InfoGroupMap& InInfoGroupMap, const FString& InFileName )
{
	ensureMsgf( false, TEXT( "%s Is Not Based FInfoGroupBase DataTable" ), *InFileName );
}

// =============================================================
// 데이터 테이블을 로드한다.
// =============================================================
template<typename DataTable, typename InfoMap>
typename TEnableIf<TIsDerivedFrom<DataTable, FInfoBase>::Value>::Type 
FDataTableManager::_LoadDataTable( InfoMap& InInfoMap, const FString& InFileName )
{
	UDataTable* data = LoadObject<UDataTable>( nullptr, *UtilPath::GetDataTablePath( InFileName ) );
	if ( !data )
	{
		WARN_LOG( TEXT( "Load %s Is Fail" ), *InFileName );
		return;
	}

	// C++ 17 버전부터 지원하는 Range-based for loop 문법
	// Map 의 Key 가 rowName, Value 가 value 로 받아집니다
	for ( const auto& [ rowName, value ] : data->GetRowMap() )
	{
		if ( DataTable* info = ( DataTable* )( value ) )
		{
			// InfoId == 0 인지 체크
			if ( !ensureMsgf( info->InfoId != G_InvalidInfoId, TEXT( "InfoId ( %d ) Is Invalid Value at %s" ), info->InfoId, *InFileName ) )
				continue;

			// InfoId 중복 체크
			if ( !ensureMsgf( !InInfoMap.Find( info->InfoId ), TEXT( "Duplication InfoId : %d at %s" ), info->InfoId, *InFileName ) )
				continue;

			InInfoMap.Add( info->InfoId, info );
		}
	}

	// ClearSingleton 호출 시 테이블 정보 비우도록 ( 다시 로드할 수 있게 )
	ClearCallbackList.Add( [ &InInfoMap ] () 
	{ 
		InInfoMap.Empty(); 
	} );

	LOG( TEXT( "Load %s Is Complete" ), *InFileName );
}

// =============================================================
// 데이터 테이블을 로드한다. ( 그룹 정보 포함 )
// =============================================================
template<typename DataTable, typename InfoMap, typename InfoGroupMap>
typename TEnableIf<TIsDerivedFrom<DataTable, FInfoGroupBase>::Value>::Type
FDataTableManager::_LoadDataTableGroup( InfoMap& InInfoMap, InfoGroupMap& InInfoGroupMap, const FString& InFileName )
{
	UDataTable* data = LoadObject<UDataTable>( nullptr, *UtilPath::GetDataTablePath( InFileName ) );
	if ( !data )
	{
		WARN_LOG( TEXT( "Load %s Is Fail" ), *InFileName );
		return;
	}

	// C++ 17 버전부터 지원하는 Range-based for loop 문법
	// Map 의 Key 가 rowName, Value 가 value 로 받아집니다
	for ( const auto& [rowName, value] : data->GetRowMap() )
	{
		if ( DataTable* info = ( DataTable* )( value ) )
		{
			// InfoId == 0 인지 체크
			if ( !ensureMsgf( info->InfoId != G_InvalidInfoId, TEXT( "InfoId ( %d ) Is Invalid Value at %s" ), info->InfoId, *InFileName ) )
				continue;

			// GroupId == 0 인지 체크
			if ( !ensureMsgf( info->GroupId != G_InvalidInfoId, TEXT( "GroupId ( %d ) Is Invalid Value at %s" ), info->GroupId, *InFileName ) )
				continue;

			// InfoId 중복 체크
			if ( !ensureMsgf( !InInfoMap.Find( info->InfoId ), TEXT( "Duplication InfoId : %d at %s" ), info->InfoId, *InFileName ) )
				continue;

			auto& infoList = InInfoGroupMap.FindOrAdd( info->GroupId );
			InInfoMap.Add( info->InfoId, info );
			infoList.Add( info );
		}
	}

	// ClearSingleton 호출 시 테이블 정보 비우도록 ( 다시 로드할 수 있게 )
	ClearCallbackList.Add( [ &InInfoMap, &InInfoGroupMap ] ()
	{
		for ( auto& infoGroupPair : InInfoGroupMap )
		{
			infoGroupPair.Value.Empty();
		}
		InInfoGroupMap.Empty();
		InInfoMap.Empty();
	} );

	LOG( TEXT( "Load %s Is Complete" ), *InFileName );
}