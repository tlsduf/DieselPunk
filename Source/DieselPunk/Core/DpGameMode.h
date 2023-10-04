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

	void PawnKilled(APawn *PawnKilled);

protected:
	virtual void BeginPlay() override;

private:
	void HandleGameStart();

	
	void EndGame();
	
	FTimerHandle GameEndTHandle;
};
