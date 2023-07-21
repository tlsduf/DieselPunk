// Copyright Epic Games, Inc. All Rights Reserved.

#include "DpGameMode.h"
#include "..\Logic\PlayerControllerBase.h"

#include <UObject/ConstructorHelpers.h>



ADpGameMode::ADpGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APlayerControllerBase::StaticClass();
	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/GuardiansW/Blueprints/Characters/BP_CharacterPC.BP_CharacterPC_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Script/Engine.Blueprint'/Game/GuardiansW/Blueprints/PlayerController/BP_PlayerControllerBase.BP_PlayerControllerBase_C'"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	
}

void ADpGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

void ADpGameMode::PawnKilled(APawn *PawnKilled)
{
	if(PawnKilled->GetController() != DpGetPlayerController())
	{
		LOG_SCREEN(TEXT("EnemyDied"))
		return;
	}
	auto PlayerController = Cast<APlayerControllerBase>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		LOG_SCREEN(TEXT("Disable Input"))
		PlayerController->SetPlayerEnabledState(false);
		EndGame(false);
	}

 	/*for (ABaseEnemyAIController *Controller : TActorRange<ABaseEnemyAIController>(GetWorld()))
	{
		if (!Controller->IsDead())
		{
			return;
		}
	} 

	EndGame(true);*/
	
}

void ADpGameMode::HandleGameStart()
{
}

void ADpGameMode::EndGame(bool bIsPlayerWinner)
{
	LOG_SCREEN(TEXT("YouDied"));
}