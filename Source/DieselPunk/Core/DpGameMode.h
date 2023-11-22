// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "DpGameMode.generated.h"

UCLASS(minimalapi)
class ADpGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADpGameMode();

protected:
	virtual void BeginPlay() override;

private:
	
	FTimerHandle GameEndTHandle;
};
