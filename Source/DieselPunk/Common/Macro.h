// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

//싱글톤 선언입니다. 싱글톤으로 제작하려는 클래스 .h의 멤버에 선언합니다. 
#define Singleton_Declare(ClassName)						\
	private:												\
	ClassName(){}											\
	~ClassName(){}											\
	static ClassName* Instance;								\
	public:													\
	static ClassName* GetInstance();						\
	static void DestroyInstance();

//싱글톤 정의입니다. 싱글톤으로 제작하려는 클래스 .cpp에 선언합니다.
#define Singleton_Defintion(ClassName)						\
	ClassName* ClassName::Instance = nullptr;				\
	ClassName* ClassName::GetInstance()						\
	{														\
		if(Instance == nullptr)								\
		{													\
			Instance = new ClassName();						\
			Instance->Initialize();							\
		}													\
		return Instance;									\
	}														\
	void ClassName::DestroyInstance()						\
	{														\
		if(Instance != nullptr)								\
		{													\
			Instance->Release();							\
			delete Instance;								\
		}													\
		Instance = nullptr;									\
	}
