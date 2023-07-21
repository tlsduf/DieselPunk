// Fill out your copyright notice in the Description page of Project Settings.


#include "Stat.h"
#include "CharacterBase.h"


// =============================================================
// 생성자
// =============================================================
FStat::FStat()
	:
	Owner( nullptr )
{

}

// =============================================================
// 소멸자
// =============================================================
FStat::~FStat()
{
	Values.Empty();
	FtrSet.Empty();
}

// =============================================================
// 초기화한다.
// =============================================================
void FStat::Initialize( ACharacterBase* InOwner )
{
	Owner = InOwner;

	auto ftrBind = [this] ( EActorStatType InType, const FTR_SET_STAT& InFunc )
	{
		FtrSet.FindOrAdd( InType, InFunc );
	};

	// _Set 함수 추가할때 이곳에 Bind 해주셔야 등록후 정상 호출됩니다.
	ftrBind( EActorStatType::Hp,    &FStat::_SetHp    );
	ftrBind( EActorStatType::MaxHp, &FStat::_SetMaxHp );
}

// =============================================================
// 초기화한다.
// =============================================================
void FStat::Reset()
{
	Values.Empty();
}

// =============================================================
// 스텟 설정
// =============================================================
void FStat::Set( EActorStatType InType, int64 InValue )
{
	if ( !Owner ) return;

	int64& value    = Values.FindOrAdd( InType );
	int64  oldValue = value;

	value = InValue;

	if ( FtrSet.Find( InType ) )
	{
		FtrSet[ InType ]( *this, oldValue, value );
	}

	// 추후 ACharacterBase 가 넘어가는게 필요하다면 그때 가서 고민하기..
	EventStatChanged.Broadcast( Owner->GetObjId(), InType, oldValue, value );
}

// =============================================================
// 스텟 반환
// =============================================================
int64 FStat::Get( EActorStatType InType ) const
{
	const int64* value = Values.Find( InType );

	return value ? *value : 0;
}

// =============================================================
// Hp 갱신을 처리한다.
// =============================================================
void FStat::_SetHp( int64 InOldValue, int64 InNewValue )
{
	if ( !Owner )
		return;


	// HP 가 0보다 낮은 경우는 사망 처리
	if(InNewValue > 0 )
		return;

	Owner->Die();
}

// =============================================================
// MaxHp 갱신을 처리한다.
// =============================================================
void FStat::_SetMaxHp( int64 InOldValue, int64 InNewValue )
{

}
