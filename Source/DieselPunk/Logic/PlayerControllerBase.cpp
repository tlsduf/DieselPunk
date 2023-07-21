// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerBase.h"
#include "../Skill/PlayerSkill.h"
#include "..\Character\CharacterPC.h"

#include <Blueprint/UserWidget.h>
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(PlayerControllerBase)

void APlayerControllerBase::BeginPlay()
{
    Super::BeginPlay();

    if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(MappingContext, 0);
    }

    HUD = CreateWidget(this, HUDClass);
    if (HUD != nullptr)
    {
        HUD->AddToViewport();
    }
}

void APlayerControllerBase::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &APlayerControllerBase::Jump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &APlayerControllerBase::StopJumping);

        EnhancedInputComponent->BindAction(InputC, ETriggerEvent::Started, this, &APlayerControllerBase::ToggleJog);
        EnhancedInputComponent->BindAction(InputW, ETriggerEvent::Started, this, &APlayerControllerBase::WPressed);
        EnhancedInputComponent->BindAction(InputW, ETriggerEvent::Completed, this, &APlayerControllerBase::WReleased);

        EnhancedInputComponent->BindAction(MouseWheelUp, ETriggerEvent::Started, this, &APlayerControllerBase::SetZoomInProp);
        EnhancedInputComponent->BindAction(MouseWheelDown, ETriggerEvent::Started, this, &APlayerControllerBase::SetZoomOutProp);

        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Look);

        //스킬 호출에 관한 바인딩
        for (uint8 i = 0; i < SkillInputActions.Num(); ++i)
        {
        EnhancedInputComponent->BindAction(SkillInputActions[i], ETriggerEvent::Started, this, &APlayerControllerBase::OnInputSkillStarted);
        EnhancedInputComponent->BindAction(SkillInputActions[i], ETriggerEvent::Ongoing, this, &APlayerControllerBase::OnInputSkillOngoing);
        EnhancedInputComponent->BindAction(SkillInputActions[i], ETriggerEvent::Triggered, this, &APlayerControllerBase::OnInputSkillTriggered);
        EnhancedInputComponent->BindAction(SkillInputActions[i], ETriggerEvent::Completed, this, &APlayerControllerBase::OnInputSkillCompleted);
        EnhancedInputComponent->BindAction(SkillInputActions[i], ETriggerEvent::Canceled, this, &APlayerControllerBase::OnInputSkillCanceled);
        }
    }
}

// =============================================================
// 캐릭터가 포즈되었을때 호출됩니다.
// 캐릭터 변경 시스템을 위해 캐릭터가 변경되면, 바뀐 캐릭터의 스킬을 인스턴스화 시키고 trigger 타입을 리매핑합니다.
// =============================================================
void APlayerControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	RemapSkillTriggerTypes();
}

void APlayerControllerBase::RemapSkillTriggerTypes()
{
	// 스킬에 관한 바인딩
	if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
	{
		character->InitSkills(); // TSubClassOf로 설정된 캐릭터의 스킬들을 인스턴스화 시킵니다.
		
		uint8 index = 0;
		while(index < character->GetSkills().Num() && index < SkillInputActions.Num())
		{
			// 설정해둔 트리거 타입을 넣습니다.
			SkillInputActions[index]->Triggers.Reset();
			SkillInputActions[index]->Triggers.Add(character->GetSkills()[index]->GetTriggerType());
			index++;
		}
	}
	
	// 추후 확인해야 할지도 모름.
	// If you have made changes to the triggers/modifiers associated with a UInputAction that was previously mapped a flush is required to reset the tracked data for that action.
	// 위에서 Trigger를 변경하여 리빌드 진행.
	if (UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		subSystem->RequestRebuildControlMappings(FModifyContextOptions(), EInputMappingRebuildType::RebuildWithFlush);
	}
}

// =============================================================
// 입력된 ActionInput의 이름을 비교하여 몇번째 스킬인지 (Index)를 알아 내는 함수입니다.
// =============================================================
int8 APlayerControllerBase::GetSkillIndexFromAction(const FInputActionInstance& InInstance)
{
	if(const UInputAction* inputAction = InInstance.GetSourceAction())
	{
		if(inputAction->GetName().Contains(TEXT("LeftMouse")))
		{
			return 0;
		}
		else if(inputAction->GetName().Contains(TEXT("RightMouse")))
		{
			return 1;
		}
		else if(inputAction->GetName().Contains(TEXT("Shift")))
		{
			return 2;
		}
		else if(inputAction->GetName().Contains(TEXT("InputQ")))
		{
			return 3;
		}
		else if(inputAction->GetName().Contains(TEXT("InputE")))
		{
			return 4;
		}
        else if(inputAction->GetName().Contains(TEXT("InputR")))
		{
			return 5;
		}
	}
	return -1;
}

// =============================================================
// 스킬들에 대한 바인딩입니다. 각 스킬별로 Started, Ongoing, Triggered, Completed, Canceled에 대해 바인딩하며,
// 입력된 ActionInput의 이름을 비교하여 몇번 째 스킬인지 (Index)를 알아 낸 후,
// 호출할 index에 스킬이 들어 있는지 크기를 통해 확인하고,
// 캐릭터의 각 타입에 맞는 기능을 호출합니다.
// =============================================================
void APlayerControllerBase::OnInputSkillStarted(const FInputActionInstance& InInstance)
{
	if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
	{
		const int8 skillIndex = GetSkillIndexFromAction(InInstance);
		if(skillIndex > -1)
		{
			character->SkillStarted(skillIndex);
		}
	}
}

void APlayerControllerBase::OnInputSkillOngoing(const FInputActionInstance& InInstance)
{
	if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
	{
		const int8 skillIndex = GetSkillIndexFromAction(InInstance);
		if(skillIndex > -1)
		{
			character->SkillOngoing(skillIndex);
		}
	}
}

void APlayerControllerBase::OnInputSkillTriggered(const FInputActionInstance& InInstance)
{
	if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
	{
		const int8 skillIndex = GetSkillIndexFromAction(InInstance);
		if(skillIndex > -1)
		{
			character->SkillTriggered(skillIndex);
		}
	}
}

void APlayerControllerBase::OnInputSkillCompleted(const FInputActionInstance& InInstance)
{
	if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
	{
		const int8 skillIndex = GetSkillIndexFromAction(InInstance);
		if(skillIndex > -1)
		{
			character->SkillCompleted(skillIndex);
		}
	}
}

void APlayerControllerBase::OnInputSkillCanceled(const FInputActionInstance& InInstance)
{
	if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
	{
		const int8 skillIndex = GetSkillIndexFromAction(InInstance);
		if(skillIndex > -1)
		{
			character->SkillCanceled(skillIndex);
		}
	}
}


void APlayerControllerBase::Jump()
{
    if (ACharacter *character = Cast<ACharacter>(GetCharacter()))
    {
        character->Jump();
    }
}

void APlayerControllerBase::StopJumping()
{
    if (ACharacter *character = Cast<ACharacter>(GetCharacter()))
    {
        character->StopJumping();
    }
}

void APlayerControllerBase::ToggleJog()
{
    if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
    {
        character->Jog();
    }
}

void APlayerControllerBase::WPressed()
{
    if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
    {
        character->WPressed();
    }
}

void APlayerControllerBase::WReleased()
{
    if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
    {
        character->WReleased();
    }
}

void APlayerControllerBase::SetZoomInProp()
{
    if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
    {
        character->SetZoomInProp();
    }
}

void APlayerControllerBase::SetZoomOutProp()
{
    if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
    {
        character->SetZoomOutProp();
    }
}

void APlayerControllerBase::Move(const FInputActionValue &Value)
{
    if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
    {
        character->Move(Value);
    }
}

void APlayerControllerBase::Look(const FInputActionValue &Value)
{
    if (ACharacterPC *character = Cast<ACharacterPC>(GetCharacter()))
    {
        character->Look(Value);
    }
}

void APlayerControllerBase::SetPlayerEnabledState(bool bPlayerEnabled)
{
	// enhanced input 용으로 만들어야됨
    bShowMouseCursor = bPlayerEnabled;
}