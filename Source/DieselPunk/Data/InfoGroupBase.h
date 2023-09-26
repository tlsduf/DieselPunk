// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "InfoBase.h"
#include "InfoGroupBase.generated.h"


/**
 *  GroupId 를 베이스로 여러 묶음의 FInfoBase 데이터 테이블을 TArray 로 가져올수 있는 클래스
 */
USTRUCT()
struct DIESELPUNK_API FInfoGroupBase : public FInfoBase
{
	GENERATED_USTRUCT_BODY()

	// 테이블 그룹 아이디, Group Key 값
	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	int32 GroupId = G_InvalidInfoId;

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
// InfoGroupPtr 클래스 매크로
// 
// 필요에 따라 구현 ( 대체로 선언해두는게 쓰기 편함 )
// =============================================================
#define GENERATED_INFO_GROUP_PTR(Type)                                            \
class Type##GroupPtr                                                              \
{                                                                                 \
	FInfoId GroupId;                                                              \
	const TArray<const Type*>* InfoGroup;                                         \
	                                                                              \
public:                                                                           \
	Type##GroupPtr();                                                             \
	Type##GroupPtr(FInfoId InGroupId);                                            \
	FInfoId GetGroupId() const;                                                   \
	const TArray<const Type*>* Get() const;                                       \
	const TArray<const Type*>& operator*() const;                                 \
	const TArray<const Type*>* operator->() const;                                \
	Type##GroupPtr& operator=( const Type##GroupPtr& InOther );                   \
	bool operator!() const;                                                       \
	bool operator==( const Type##GroupPtr& InOther ) const;                       \
	bool operator<( const Type##GroupPtr& InOther ) const;                        \
};

// =============================================================
// InfoGroupPtr 클래스 매크로 cpp 몸체 구현 부분
// 
// cpp 에서 DataTableManager를 Include 해서 헤더가 꼬이지 않도록 방지
// =============================================================
#define GENERATED_INFO_GROUP_PTR_CPP(Type, InfoName )                             \
Type##GroupPtr::Type##GroupPtr()                                                  \
	:                                                                             \
	GroupId( G_InvalidInfoId ),                                                   \
	InfoGroup( nullptr )                                                          \
{                                                                                 \
                                                                                  \
}                                                                                 \
Type##GroupPtr::Type##GroupPtr( FInfoId InGroupId )                               \
	:                                                                             \
	GroupId( InGroupId ),                                                         \
	InfoGroup( GetDataTableManager().Get##InfoName##Group( InGroupId ) )          \
{                                                                                 \
                                                                                  \
}                                                                                 \
FInfoId Type##GroupPtr::GetGroupId() const                                        \
{                                                                                 \
	return GroupId;                                                               \
}                                                                                 \
const TArray<const Type*>* Type##GroupPtr::Get() const                            \
{                                                                                 \
	return InfoGroup;                                                             \
}                                                                                 \
const TArray<const Type*>& Type##GroupPtr::operator*() const                      \
{                                                                                 \
	return *InfoGroup;                                                            \
}                                                                                 \
const TArray<const Type*>* Type##GroupPtr::operator->() const                     \
{                                                                                 \
	return InfoGroup;                                                             \
}                                                                                 \
Type##GroupPtr& Type##GroupPtr::operator=( const Type##GroupPtr& InOther )        \
{                                                                                 \
	GroupId = InOther.GetGroupId();                                               \
	InfoGroup = InOther.Get();                                                    \
	return *this;                                                                 \
}                                                                                 \
bool Type##GroupPtr::operator!() const                                            \
{                                                                                 \
	return !InfoGroup;                                                            \
}                                                                                 \
bool Type##GroupPtr::operator==( const Type##GroupPtr& InOther ) const            \
{                                                                                 \
	return InfoGroup == InOther.Get();                                            \
}                                                                                 \
bool Type##GroupPtr::operator<( const Type##GroupPtr& InOther ) const             \
{                                                                                 \
	return GroupId < InOther.GetGroupId();                                        \
}