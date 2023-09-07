// Copyright GuardiansW. All Rights Reserved.

#pragma once

#include <UObject/Interface.h>
#include "PlayerInputInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlayerInputInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 플레이어로부터 입력을 받아야 하는 객체일 경우 사용하는 인터페이스입니다. 
 */
class DIESELPUNK_API IPlayerInputInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// 입력 시작시 호출됩니다.
	virtual void SkillStarted() {};
	
	// 입력 시작시 호출됩니다.
	virtual void SkillOngoing() {};

	// 입력이 Triggered일 때 호출됩니다.
	virtual void SkillTriggered() = 0;

	// 입력이 끝나면 호출됩니다.
	virtual void SkillCompleted() {};

	// 입력이 끝나면 호출됩니다.
	virtual void SkillCanceled() {};
};
