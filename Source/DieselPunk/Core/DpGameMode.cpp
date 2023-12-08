// Copyright Epic Games, Inc. All Rights Reserved.

#include "DpGameMode.h"
#include "..\Logic\PlayerControllerBase.h"

#include <UObject/ConstructorHelpers.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(DpGameMode)

ADpGameMode::ADpGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APlayerControllerBase::StaticClass();
	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/DieselPunk/Blueprints/Characters/BP_PC_2.BP_PC_2_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Script/Engine.Blueprint'/Game/DieselPunk/Blueprints/Core/BP_PlayerControllerBase.BP_PlayerControllerBase_C'"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void ADpGameMode::BeginPlay()
{
	Super::BeginPlay();
}


