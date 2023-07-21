// Copyright Epic Games, Inc. All Rights Reserved.


#pragma once


template<typename Type>
class TSingletonBase
{
public:
	typedef Type* ReturnType;

private:
	static Type* Instance;						// 전역 인스턴스

public:
	// 생성자
	TSingletonBase();

	// 소멸자
	virtual ~TSingletonBase();

	// 싱글톤 데이터 초기화
	virtual void InitSingleton() = 0;

	// 싱글톤 데이터 정리
	virtual void ClearSingleton() = 0;

	// 생성
	static Type* CreateInstance();

	// 전역 인스턴스를 반환한다.
	static Type& GetInstance();

	// 전역 인스턴스 포인터를 반환한다.
	static Type* GetInstancePtr();

	// 전역 인스턴스 포인터를 해제한다.
	static void ReleasePtr();

	// 인스턴스가 유효한지 반환한다.
	static bool IsValid();
};

#define GENERATE_SINGLETON_GETTER_IMPL(Type, Name)	\
	inline Type* Get##Name##Ptr()					\
	{												\
		return Type::GetInstancePtr();				\
	}												\
	inline Type& Get##Name##()						\
	{												\
		return Type::GetInstance();					\
	}												\

#define GENERATE_SINGLETON_GETTER(Name)	GENERATE_SINGLETON_GETTER_IMPL(F##Name, Name)


#include "SingletonBase.inl"