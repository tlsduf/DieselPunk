// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#define TURRET_MAX_LV 3

//언리얼 에디터에 로그를 띄웁니다.
#define LOG_SCREEN(Color, Text, ...)			\
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, Color, FString::Printf(Text, __VA_ARGS__));

//언리얼 에디터에 로그를 띄웁니다. 근데 1틱
#define LOG_SCREEN_TICK(Color, Text, ...)			\
	GEngine->AddOnScreenDebugMessage(-1, 0.f, Color, FString::Printf(Text, __VA_ARGS__));

//싱글톤 선언입니다. 싱글톤으로 제작하려는 클래스 .h의 멤버에 선언합니다. 
#define Singleton_Declare(ClassName)						\
	private:												\
	ClassName();											\
	~ClassName();											\
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
