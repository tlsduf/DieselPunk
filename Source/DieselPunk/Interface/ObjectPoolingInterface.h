// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <UObject/Interface.h>
#include "ObjectPoolingInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UObjectPoolingInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 오브젝트 풀링 대상입니다.
 */
class DIESELPUNK_API IObjectPoolingInterface
{
	GENERATED_BODY()
public:
	virtual void Initialize()=0;
	virtual void Release()=0;
};
