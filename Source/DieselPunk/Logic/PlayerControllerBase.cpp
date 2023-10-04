// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerBase.h"
#include "..\Character\CharacterPC.h"
#include "../Util/UtilEnum.h"
#include "../Skill/SkillBase.h"
#include "../Skill/PlayerSkill.h"
#include "../Core/DpCheatManager.h"
#include "../UI/HUD/SkillUpgradeUI.h"
#include "..\UI\HUD\DamageBrowserUI.h"


#include <Blueprint/UserWidget.h>
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>

#include <GameFramework/WorldSettings.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(PlayerControllerBase)

// =============================================================
// 생성자
// =============================================================
APlayerControllerBase::APlayerControllerBase()
{
	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Default;
	
	CheatClass = UDpCheatManager::StaticClass();
}

void APlayerControllerBase::BeginPlay()
{
    Super::BeginPlay();

	SetMappingContextByInputType();
	
    if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(MappingContext, 0);
    }

	if(HUDClass)
		HUD = CreateWidget(this, HUDClass);
	if (HUD)
		HUD->AddToViewport();

	SkillBrowser = UDamageBrowserUI::CreateUI();
	if (SkillBrowser)
		SkillBrowser->AddToViewport();
	SkillBrowser->SetVisibility(ESlateVisibility::Hidden);
	
	SkillUpgradeUI = USkillUpgradeUI::CreateUI();
	if(SkillUpgradeUI)
		SkillUpgradeUI->AddToViewport();
	SkillUpgradeUI->SetVisibility(ESlateVisibility::Hidden);
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
    	EnhancedInputComponent->BindAction(InputS, ETriggerEvent::Started, this, &APlayerControllerBase::SPressed);
    	EnhancedInputComponent->BindAction(InputS, ETriggerEvent::Completed, this, &APlayerControllerBase::SReleased);

        EnhancedInputComponent->BindAction(MouseWheelUp, ETriggerEvent::Started, this, &APlayerControllerBase::SetZoomInProp);
        EnhancedInputComponent->BindAction(MouseWheelDown, ETriggerEvent::Started, this, &APlayerControllerBase::SetZoomOutProp);

        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Look);

    	EnhancedInputComponent->BindAction(InputF, ETriggerEvent::Started, this, &APlayerControllerBase::Interaction);
    	EnhancedInputComponent->BindAction(InputK, ETriggerEvent::Started, this, &APlayerControllerBase::SetOnSkillBrowser);
    	EnhancedInputComponent->BindAction(InputM, ETriggerEvent::Started, this, &APlayerControllerBase::Pause);

        //스킬 호출에 관한 바인딩
        for (EAbilityType type : ENUM_RANGE(EAbilityType))
        {
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Started, this, &APlayerControllerBase::OnInputSkillStarted);
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Ongoing, this, &APlayerControllerBase::OnInputSkillOngoing);
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Triggered, this, &APlayerControllerBase::OnInputSkillTriggered);
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Completed, this, &APlayerControllerBase::OnInputSkillCompleted);
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Canceled, this, &APlayerControllerBase::OnInputSkillCanceled);
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
	SetMappingContextByInputType();
}

// =============================================================
// InputType에 맞춰 MappingContext을 적용하는 함수입니다.
// =============================================================
void APlayerControllerBase::SetMappingContextByInputType()
{
	// 스킬에 관한 바인딩
	DpGetPlayer()->InitSkills(); // TSubClassOf로 설정된 캐릭터의 스킬들을 인스턴스화 시킵니다.
		
	for (const TPair<EAbilityType, TObjectPtr<UInputAction>>& inputActions : SkillInputActions)
	{
		// 설정해둔 트리거 타입을 넣습니다.
		SkillInputActions[inputActions.Key]->Triggers.Reset();
		SkillInputActions[inputActions.Key]->Triggers.Add(Cast<UPlayerSkill>(DpGetPlayer()->GetSkills()[inputActions.Key])->GetTriggerType());
	}
	
	
	if (UEnhancedInputLocalPlayerSubsystem *subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// Setting에 맞는 Mapping Context를 추가합니다.
		subSystem->AddMappingContext(MappingContext,0);
	}
}

// =============================================================
// 입력된 ActionInput의 이름을 비교하여 무슨 능력인지 (Key)를 알아 내는 함수입니다.
// =============================================================
const EAbilityType APlayerControllerBase::GetAbilityKeyFromAction(const FInputActionInstance &InInstance) const
{
	if (const UInputAction *inputAction = InInstance.GetSourceAction())
	{
		if (inputAction->GetName().Contains(TEXT("IA_LeftMouse")))
			return EAbilityType::MouseLM;
		
		else if (inputAction->GetName().Contains(TEXT("IA_RightMouse")))
			return EAbilityType::MouseRM;
		
		else if (inputAction->GetName().Contains(TEXT("IA_LeftShift")))
			return EAbilityType::Shift;
		
		else if (inputAction->GetName().Contains(TEXT("IA_InputQ")))
			return EAbilityType::SkillQ;
		
		else if (inputAction->GetName().Contains(TEXT("IA_InputE")))
			return EAbilityType::SkillE;
		
		else if (inputAction->GetName().Contains(TEXT("IA_InputR")))
			return EAbilityType::SkillR;
	}
	return EAbilityType::None;
}

// =============================================================
// 스킬들에 대한 바인딩입니다. 각 스킬별로 Started, Ongoing, Triggered, Completed, Canceled에 대해 바인딩하며,
// 입력된 ActionInput의 이름을 비교하여 몇번 째 스킬인지 (Index)를 알아 낸 후,
// 호출할 index에 스킬이 들어 있는지 크기를 통해 확인하고,
// 캐릭터의 각 타입에 맞는 기능을 호출합니다.
// =============================================================
void APlayerControllerBase::OnInputSkillStarted(const FInputActionInstance& InInstance)
{
	const EAbilityType abilityKey = GetAbilityKeyFromAction(InInstance);
	if (abilityKey != EAbilityType::None)
		DpGetPlayer()->SkillStarted(abilityKey);
}

void APlayerControllerBase::OnInputSkillOngoing(const FInputActionInstance& InInstance)
{
	const EAbilityType abilityKey = GetAbilityKeyFromAction(InInstance);
	if (abilityKey != EAbilityType::None)
		DpGetPlayer()->SkillOngoing(abilityKey);
}

void APlayerControllerBase::OnInputSkillTriggered(const FInputActionInstance& InInstance)
{
	const EAbilityType abilityKey = GetAbilityKeyFromAction(InInstance);
	if (abilityKey != EAbilityType::None)
		DpGetPlayer()->SkillTriggered(abilityKey);
}

void APlayerControllerBase::OnInputSkillCompleted(const FInputActionInstance& InInstance)
{
	const EAbilityType abilityKey = GetAbilityKeyFromAction(InInstance);
	if (abilityKey != EAbilityType::None)
		DpGetPlayer()->SkillCompleted(abilityKey);
}

void APlayerControllerBase::OnInputSkillCanceled(const FInputActionInstance& InInstance)
{
	const EAbilityType abilityKey = GetAbilityKeyFromAction(InInstance);
	if (abilityKey != EAbilityType::None)
		DpGetPlayer()->SkillCanceled(abilityKey);
}


void APlayerControllerBase::Jump()
{
	DpGetPlayer()->Jump();
}

void APlayerControllerBase::StopJumping()
{
	DpGetPlayer()->StopJumping();
}

void APlayerControllerBase::ToggleJog()
{
    DpGetPlayer()->Jog();
}

void APlayerControllerBase::WPressed()
{
    DpGetPlayer()->WPressed();
}

void APlayerControllerBase::WReleased()
{
    DpGetPlayer()->WReleased();
}

void APlayerControllerBase::SPressed()
{
	DpGetPlayer()->SPressed();
}

void APlayerControllerBase::SReleased()
{
	DpGetPlayer()->SReleased();
}

void APlayerControllerBase::SetZoomInProp()
{
	DpGetPlayer()->SetZoomInProp();
}

void APlayerControllerBase::SetZoomOutProp()
{
	DpGetPlayer()->SetZoomOutProp();
}

void APlayerControllerBase::Interaction()
{
	if(DpGetPlayer()->DelegateInteractTask.IsBound())
		DpGetPlayer()->DelegateInteractTask.Execute();
}

void APlayerControllerBase::Move(const FInputActionValue &Value)
{
    DpGetPlayer()->Move(Value);
}

void APlayerControllerBase::Look(const FInputActionValue &Value)
{
	DpGetPlayer()->Look(Value);
}

void APlayerControllerBase::SetPlayerEnabledState(bool bPlayerEnabled)
{
	// enhanced input 용으로 만들어야됨
    bShowMouseCursor = bPlayerEnabled;
}


void APlayerControllerBase::SetOnSkillBrowser()
{
	if(!OnSkillBrowser)
	{
		// 시간 정지
		GetWorldSettings()->SetTimeDilation(0.f);

		// 기존 HUD Remove
		if (HUD)
			HUD->SetVisibility(ESlateVisibility::Hidden);
	
		// 스킬브라우저 UI Add
		if (SkillBrowser)
			SkillBrowser->SetVisibility(ESlateVisibility::Visible);
		
		DpGetPlayer()->CanCameraControl = false;
		
		OnSkillBrowser = true;
	}
	else
	{
		// 시간 재게
		GetWorldSettings()->SetTimeDilation(1.f);
	
		//  스킬브라우저 UI Remove
		if (SkillBrowser)
			SkillBrowser->SetVisibility(ESlateVisibility::Hidden);

		// 기존 HUD Add
		if (HUD)
			HUD->SetVisibility(ESlateVisibility::Visible);

		DpGetPlayer()->CanCameraControl = true;
		
		OnSkillBrowser = false;
	}
}

/*void APlayerControllerBase::SetOffSkillBrowser()
{
	if(OnSkillBrowser)
	{
		// 시간 재게
		GetWorldSettings()->SetTimeDilation(1.f);
	
		//  스킬브라우저 UI Remove
		if (SkillBrowser)
			SkillBrowser->SetVisibility(ESlateVisibility::Hidden);

		// 기존 HUD Add
		if (HUD)
			HUD->SetVisibility(ESlateVisibility::Visible);
	}
}*/

void APlayerControllerBase::SkillUpgradeEventStart()
{
	// 시간 정지
	GetWorldSettings()->SetTimeDilation(0.f);
	
	// 기존 HUD Remove
	if (HUD)
		HUD->SetVisibility(ESlateVisibility::Hidden);
	
	// 스킬 업그레이드 UI Add
	if (SkillUpgradeUI)
	{
		SkillUpgradeUI->SetVisibility(ESlateVisibility::Visible);
		Cast<USkillUpgradeUI>(SkillUpgradeUI)->SetControls();
	}
	
	// 마우스 위치 세팅 // 마우스 커서 on //키보드 입력 off
	int32 ScreenWidth;
	int32 ScreenHeight;
	GetViewportSize(ScreenWidth, ScreenHeight);
	SetMouseLocation(ScreenWidth * 0.5f, ScreenHeight * 0.5f);
	bShowMouseCursor = true;
	DpGetPlayer()->CanCameraControl = false;
}

void APlayerControllerBase::SkillUpgradeEventEnd()
{
	// 시간 재게
	GetWorldSettings()->SetTimeDilation(1.f);
	
	//  스킬 업그레이드 UI Remove
	if (SkillUpgradeUI)
		SkillUpgradeUI->SetVisibility(ESlateVisibility::Hidden);

	// 기존 HUD Add
	if (HUD)
		HUD->SetVisibility(ESlateVisibility::Visible);
	
	// 마우스 커서 off //키보드 입력 on
	bShowMouseCursor = false;
	DpGetPlayer()->CanCameraControl = true;
}

void APlayerControllerBase::ThisPause()
{
	
}

void APlayerControllerBase::SetUIControlOnForStartMenu()
{	
// 시간 정지
 	GetWorldSettings()->SetTimeDilation(0.f);
 	
 	// 마우스 위치 세팅 // 마우스 커서 on //키보드 입력 off
 	int32 ScreenWidth;
 	int32 ScreenHeight;
 	GetViewportSize(ScreenWidth, ScreenHeight);
 	SetMouseLocation(ScreenWidth * 0.5f, ScreenHeight * 0.5f);
 	bShowMouseCursor = true;
}

void APlayerControllerBase::SetUIControlOn()
{
	// 시간 정지
	GetWorldSettings()->SetTimeDilation(0.f);
	
	// 마우스 위치 세팅 // 마우스 커서 on //키보드 입력 off
	int32 ScreenWidth;
	int32 ScreenHeight;
	GetViewportSize(ScreenWidth, ScreenHeight);
	SetMouseLocation(ScreenWidth * 0.5f, ScreenHeight * 0.5f);
	bShowMouseCursor = true;
	DpGetPlayer()->CanCameraControl = false;
}

void APlayerControllerBase::SetUIControlOff()
{
	// 시간 재게
	GetWorldSettings()->SetTimeDilation(1.f);

	// 마우스 커서 off //키보드 입력 on
	bShowMouseCursor = false;
	DpGetPlayer()->CanCameraControl = true;
}

void APlayerControllerBase::SetEndUI()
{
	if(EndUIClass)
		EndUI = CreateWidget(this, EndUIClass);
	if (EndUI)
		EndUI->AddToViewport();

	SetUIControlOn();
}
