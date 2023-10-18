// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "DpGameInstance.generated.h"

/**
 *
 */
UCLASS()
class DIESELPUNK_API UDpGameInstance : public UGameInstance
{
	GENERATED_BODY()

	
public:
	// 생성자
	UDpGameInstance();

	// 소멸자
	virtual ~UDpGameInstance();

private:
	void LoadSingletons();

};
