// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SingletonLib.h"
#include "Engine/GameInstance.h"
#include "DpGameInstance.generated.h"

/**
 *
 */
UCLASS()
class DIESELPUNK_API UDpGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	FSingletonLib SL;
	
public:
	// 생성자
	UDpGameInstance();

	// 소멸자
	virtual ~UDpGameInstance();

	// 게임이 시작될 때마다 호출됨 ( 에디터의 경우 시작 버튼을 눌렀을 때 )
	virtual void Init() override;

	// 게임이 종료될 때마다 호출됨 ( 에디터의 경우 종료 버튼을 눌렀을 때 )
	virtual void Shutdown() override;

	// 게임이 종료될 때의 정리되어야 할 데이터들을 처리한다.
	void Clear();

	// 싱글톤 매니저들을 초기화한다.
	void InitSingletons();

	// 싱글톤 매니저들의 데이터를 정리한다.
	void ClearSingletons();

	// 싱글톤 매니저들을 등록한다.
	void RegisterSingleton();
};
