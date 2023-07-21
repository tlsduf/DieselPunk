// Copyright Epic Games, Inc. All Rights Reserved.


#pragma once


#include "SingletonBase.h"
#include <Templates/Function.h>


class FSingletonLib
{
private:
	struct FItem
	{
		TFunction<void()> InitFunc;
		TFunction<void()> ClearFunc;
		TFunction<void()> ReleaseFunc;
	};

private:
	TArray<FItem> ItemList;

public:
	// 싱글톤 매니저들을 초기화한다.
	void InitSingletons()
	{
		for (FItem& item : ItemList)
		{
			item.InitFunc();
		}
	}

	// 싱글톤 매니저 데이터들을 정리한다.
	void ClearSingletons()
	{
		TODO( "역순 반복으로 돌아야 함", 크로 );
		for (FItem& item : ItemList)
		{
			item.ClearFunc();
		}
	}

	// 싱글톤 매니저 포인터를 정리한다.
	void ReleaseSingletons()
	{
		ClearSingletons();

		while (ItemList.Num())
		{
			const FItem& item = ItemList.Pop();
			item.ReleaseFunc();
		}

		ItemList.Empty();
	}

	// 싱글톤을 등록한다.
	template<typename Type>
	void RegisterSingleton(Type* InInstance)
	{
		FItem item;
		item.InitFunc		= [InInstance]() { ( ( Type* )InInstance )->InitSingleton();  };
		item.ClearFunc		= [InInstance]() { ( ( Type* )InInstance )->ClearSingleton(); };
		item.ReleaseFunc	= []()			 { Type::ReleasePtr();						  };

		ItemList.Add(item);
	}
};


// 싱글톤 매니저를 등록한다.
#define REGISTER_SINGLETON(CLASS) SL.RegisterSingleton<CLASS>( CLASS::CreateInstance() );