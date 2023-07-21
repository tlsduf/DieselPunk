// Copyright GuardiansW. All Rights Reserved.


#pragma once


#include <Engine/DataTable.h>
#include "InfoBase.generated.h"


/**
 * 
 */
USTRUCT()
struct DIESELPUNK_API FInfoBase : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	// 테이블 아이디, Key 값
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int32 InfoId = G_InvalidInfoId;

public:
	/**
	 * Can be overridden by subclasses; Called on every row when the owning data table is modified
	 * Allows for custom fix-ups, parsing, etc for user changes
	 * This will be called in addition to OnPostDataImport when importing
	 *
	 * @param InDataTable					The data table that owns this row
	 * @param InRowName						The name of the row we're performing fix-up on
	 */
	virtual void OnDataTableChanged( const UDataTable* InDataTable, const FName InRowName ) override;
};



// =============================================================
// InfoPtr 클래스 매크로
// 
// 필요에 따라 구현 ( 대체로 선언해두는게 쓰기 편함 )
// =============================================================
#define GENERATED_INFO_PTR(Type)                                                  \
class Type##Ptr                                                                   \
{                                                                                 \
	FInfoId InfoId;                                                               \
	const Type* Info;                                                             \
	                                                                              \
public:                                                                           \
	Type##Ptr();                                                                  \
	Type##Ptr(FInfoId InInfoId);                                                  \
	FInfoId GetInfoId() const;                                                    \
	const Type* Get() const;                                                      \
	const Type& operator*() const;                                                \
	const Type* operator->() const;                                               \
	Type##Ptr& operator=( const Type##Ptr& InOther );                             \
	bool operator!() const;                                                       \
	bool operator==( const Type##Ptr& InOther ) const;                            \
	bool operator<( const Type##Ptr& InOther ) const;                             \
};

// =============================================================
// InfoPtr 클래스 매크로 cpp 몸체 구현 부분
// 
// cpp 에서 DataTableManager를 Include 해서 헤더가 꼬이지 않도록 방지
// =============================================================
#define GENERATED_INFO_PTR_CPP(Type, InfoName )                                   \
Type##Ptr::Type##Ptr()                                                            \
	:                                                                             \
	InfoId( G_InvalidInfoId ),                                                    \
	Info( nullptr )                                                               \
{                                                                                 \
                                                                                  \
}                                                                                 \
Type##Ptr::Type##Ptr( FInfoId InInfoId )                                          \
	:                                                                             \
	InfoId( InInfoId ),                                                           \
	Info( GetDataTableManager().Get##InfoName##( InInfoId ) )                     \
{                                                                                 \
                                                                                  \
}                                                                                 \
FInfoId Type##Ptr::GetInfoId() const                                              \
{                                                                                 \
	return InfoId;                                                                \
}                                                                                 \
const Type* Type##Ptr::Get() const                                                \
{                                                                                 \
	return Info;                                                                  \
}                                                                                 \
const Type& Type##Ptr::operator*() const                                          \
{                                                                                 \
	return *Info;                                                                 \
}                                                                                 \
const Type* Type##Ptr::operator->() const                                         \
{                                                                                 \
	return Info;                                                                  \
}                                                                                 \
Type##Ptr& Type##Ptr::operator=( const Type##Ptr& InOther )                       \
{                                                                                 \
	InfoId = InOther.GetInfoId();                                                 \
	Info = InOther.Get();                                                         \
	return *this;                                                                 \
}                                                                                 \
bool Type##Ptr::operator!() const                                                 \
{                                                                                 \
	return !Info;                                                                 \
}                                                                                 \
bool Type##Ptr::operator==( const Type##Ptr& InOther ) const                      \
{                                                                                 \
	return Info == InOther.Get();                                                 \
}                                                                                 \
bool Type##Ptr::operator<( const Type##Ptr& InOther ) const                       \
{                                                                                 \
	return InfoId < InOther.GetInfoId();                                          \
}