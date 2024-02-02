// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <UObject/Interface.h>
#include "DpManagementTargetInterFace.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDpManagementTargetInterFace : public UInterface
{
	GENERATED_BODY()
};

/**
 * 플레이어로부터 입력을 받아야 하는 객체일 경우 사용하는 인터페이스입니다. 
 */
class DIESELPUNK_API IDpManagementTargetInterFace
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
