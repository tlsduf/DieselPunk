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
 * 오브젝트 매니저로부터 관리되는 관리 대상입니다.
 */
class DIESELPUNK_API IDpManagementTargetInterFace
{
	GENERATED_BODY()
protected:
	int32 ObjectId = -1;

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	void SetObjectId(int32 InObjectId){ ObjectId = InObjectId; }
	const int32& GetObjectId(){ return ObjectId; }
};
