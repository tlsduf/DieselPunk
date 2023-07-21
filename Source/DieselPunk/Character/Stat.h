// Copyright GuardiansW. All Rights Reserved.


#pragma once


class ACharacterBase;


// ===========================================================================================
// 스텟 처리 클래스
// 
// FEventStatChanged	장점 - 특정 객체가 스텟 변경하는 이벤트를 Bind
//						단점 - 어떤 스텟인지 구분하지 않고 Bind -> 받는 함수에서 예외 처리
// 
// FTR_SET_STAT			장점 - 특정 스텟 변경에 따른 이벤트 처리
//						단점 - 어떤 객체인지 구분하지 않고 _Set
// ===========================================================================================
class FStat
{
private:
	// 스텟 변경 시 호출할 이벤트
	// 만약 특정 스텟에서만 처리해야하는 이벤트라면 델리게이트보단 FTR_SET_STAT 을 활용하는 법도
	DECLARE_EVENT_FourParams( FStat, FEventStatChanged, FObjId, EActorStatType, int64, int64 );

private:
	typedef std::function<void( FStat&, int64, int64 )> FTR_SET_STAT;

public:
	FEventStatChanged                  EventStatChanged;   // 스텟 변경 이벤트

private:
	TMap<EActorStatType, int64>        Values;             // 스텟 정보
	TMap<EActorStatType, FTR_SET_STAT> FtrSet;             // _Set 스텟 함수
	ACharacterBase*                    Owner;              // 소유자 식별자

public:
	// 생성자
	FStat();

	// 소멸자
	~FStat();

	// 초기화한다.
	void Initialize( ACharacterBase* InOwner );

	// 초기화
	void Reset();

	// 스텟 설정
	void Set( EActorStatType InType, int64 InValue );

	// 스텟 반환
	int64 Get( EActorStatType InType ) const;

	// 스텟 변경 이벤트를 반환한다.
	FORCEINLINE FEventStatChanged& GetEventStatChanged() { return EventStatChanged; }

private:
	// ===========================================================================================
	// 특정 스텟은 별도의 로직을 처리해야 한다면 SetStat 에서
	// switch 로 처리하는 것 보단 아래 방식이 좀 더 깔끔해보임
	// 
	// int64 OldValue, int64 NewValue 로 인자 맞춰서 Bind 하기
	// ===========================================================================================
	// Hp 갱신을 처리한다.
	void _SetHp( int64 InOldValue, int64 InNewValue );

	// MaxHp 갱신을 처리한다.
	void _SetMaxHp( int64 InOldValue, int64 InNewValue );
};