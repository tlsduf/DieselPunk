// Copyright Epic Games, Inc. All Rights Reserved.

#include "DpGameMode.h"
#include "..\Logic\PlayerControllerBase.h"

#include <GameFramework/Pawn.h>
#include <UObject/ConstructorHelpers.h>


#include <Blueprint/UserWidget.h>

#include "Kismet/GameplayStatics.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(DpGameMode)

ADpGameMode::ADpGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APlayerControllerBase::StaticClass();
	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/DieselPunk/Blueprints/Characters/BP_CharacterPC.BP_CharacterPC_C'"));
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

	HandleGameStart();
}

void ADpGameMode::PawnKilled(APawn *PawnKilled)
{
	// [TODO] 플레이어 컨트롤러 Get 하는 방법 수정해야됨.
	if(PawnKilled->GetController() != UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		//LOG_SCREEN(TEXT("EnemyDied"))
		return;
	}
	auto PlayerController = Cast<APlayerControllerBase>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		//LOG_SCREEN(TEXT("Disable Input"))
		PlayerController->SetPlayerEnabledState(false);

		// 임시 UI 불러오기
		TWeakObjectPtr<ADpGameMode> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(
			GameEndTHandle, [thisPtr]()
			{
				if(thisPtr.IsValid())
					Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(thisPtr->GetWorld(), 0))->SetEndUI();
			},
			1.5f, false);
		//PlayerController->SetEndUI();
		
		EndGame();
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

void ADpGameMode::EndGame()
{
}

