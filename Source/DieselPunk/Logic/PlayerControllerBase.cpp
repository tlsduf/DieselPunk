// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerBase.h"
#include "../Character/CharacterPC.h"
#include "../Skill/PlayerSkill.h"
#include "../UI/HUD/SkillUpgradeUI.h"
#include "../Core/DpCheatManager.h"
#include "../Handler/DeckHandler.h"
#include "../Card/Card.h"
#include "../UI/DeckInterface/Deck.h"
#include "../UI/HUD/Hand.h"
#include "../Manager/UIManager.h"
#include "../Core/DPLevelScriptActor.h"

#include <Blueprint/UserWidget.h>
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include <GameFramework/WorldSettings.h>
#include <Blueprint/WidgetTree.h>
#include <Components/ScrollBox.h>
#include <Components/SizeBox.h>
#include <Engine/Level.h>
#include <Animation/WidgetAnimation.h>

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

	FUIManager::GetInstance()->SetController(this);
	
    if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
        Subsystem->AddMappingContext(MappingContext, 0);
	
	// 마우스 위치 Set // 시간 멈춤 // 캐릭터 회전 불가
	SetUIControlOn();
	
	// 시작 메뉴 생성
	if(StartMenuClass)
		StartMenu = CreateWidget(this, StartMenuClass);
	if (StartMenu)
		StartMenu->AddToViewport();
	
	// HUD 생성
	if(HUDClass)
	{
		HUDId = FUIManager::GetInstance()->CreateWidgetBase(HUDClass, TEXT("HUD"));
		HUD = FindWidgetBase(HUDId).Get();
	}
	if (HUD)
		HUD->AddToViewport();
	Hand = Cast<UHand>((*HUD)[TEXT("WBP_Hand")]);
	if(Hand == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("APlayerControllerBase::BeginPlay(): WBP_Hand에 해당하는 위젯을 찾지 못했습니다."))
		return;
	}
	Hand->OnCreated();

	DeckInterfaceOpen = false;
}

void APlayerControllerBase::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Jump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &APlayerControllerBase::StopJumping);

        EnhancedInputComponent->BindAction(InputCtrl, ETriggerEvent::Started, this, &APlayerControllerBase::StartJog);
        EnhancedInputComponent->BindAction(InputCtrl, ETriggerEvent::Completed, this, &APlayerControllerBase::StopJog);
    	EnhancedInputComponent->BindAction(InputC, ETriggerEvent::Completed, this, &APlayerControllerBase::ReplaceCard);

        //EnhancedInputComponent->BindAction(MouseWheelUp, ETriggerEvent::Started, this, &APlayerControllerBase::SetZoomInProp);
        //EnhancedInputComponent->BindAction(MouseWheelDown, ETriggerEvent::Started, this, &APlayerControllerBase::SetZoomOutProp);
    	EnhancedInputComponent->BindAction(MouseWheelUp, ETriggerEvent::Triggered, this, &APlayerControllerBase::WheelUpCardSelect);
    	EnhancedInputComponent->BindAction(MouseWheelDown, ETriggerEvent::Triggered, this, &APlayerControllerBase::WheelDownCardSelect);

        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Look);

    	//EnhancedInputComponent->BindAction(InputF, ETriggerEvent::Started, this, &APlayerControllerBase::Interaction);
    	EnhancedInputComponent->BindAction(InputM, ETriggerEvent::Started, this, &APlayerControllerBase::Pause);
    	EnhancedInputComponent->BindAction(InputB, ETriggerEvent::Started, this, &APlayerControllerBase::WaveStart);

    	EnhancedInputComponent->BindAction(InputDeckInterface, ETriggerEvent::Started, this, &APlayerControllerBase::OpenCloseDeckInterface);

        //스킬 호출에 관한 바인딩
        for (EAbilityType type : TEnumRange<EAbilityType>())
        {
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Started, this, &APlayerControllerBase::OnInputSkillStarted);
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Ongoing, this, &APlayerControllerBase::OnInputSkillOngoing);
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Triggered, this, &APlayerControllerBase::OnInputSkillTriggered);
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Completed, this, &APlayerControllerBase::OnInputSkillCompleted);
        EnhancedInputComponent->BindAction(SkillInputActions[type], ETriggerEvent::Canceled, this, &APlayerControllerBase::OnInputSkillCanceled);
        }

    	for(int i = 0; i < FDeckHandler::MaxHand; ++i)
    	{
    		EnhancedInputComponent->BindAction(InputUseCard[i], ETriggerEvent::Started, this, &APlayerControllerBase::UseCard, i);
    	}
    }
}

// =============================================================
// 캐릭터가 포즈되었을때 호출됩니다.
// =============================================================
void APlayerControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	PC = Cast<ACharacterPC>(GetCharacter());
	
	SetMappingContextByInputType();
}

// =============================================================
// InputType에 맞춰 MappingContext을 적용하는 함수입니다.
// =============================================================
void APlayerControllerBase::SetMappingContextByInputType()
{
	// 스킬에 관한 바인딩
	if (PC.IsValid())
	{
		PC->InitSkills(); // TSubClassOf로 설정된 캐릭터의 스킬들을 인스턴스화 시킵니다.
		
		for (const TPair<EAbilityType, TObjectPtr<UInputAction>>& inputActions : SkillInputActions)
		{
			// 설정해둔 트리거 타입을 넣습니다.
			SkillInputActions[inputActions.Key]->Triggers.Reset();
			SkillInputActions[inputActions.Key]->Triggers.Add(Cast<UPlayerSkill>(PC->GetSkills()[inputActions.Key])->GetTriggerType());
		}
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
const EAbilityType APlayerControllerBase::GetAbilityKeyFromAction(const FInputActionInstance &inInstance) const
{
	if (const UInputAction *inputAction = inInstance.GetSourceAction())
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

		else if (inputAction->GetName().Contains(TEXT("IA_InputF")))
			return EAbilityType::Interact;
	}
	return EAbilityType::None;
}

// =============================================================
// 스킬들에 대한 바인딩입니다. 각 스킬별로 Started, Ongoing, Triggered, Completed, Canceled에 대해 바인딩하며,
// 입력된 ActionInput의 이름을 비교하여 몇번 째 스킬인지 (Index)를 알아 낸 후,
// 호출할 index에 스킬이 들어 있는지 크기를 통해 확인하고,
// 캐릭터의 각 타입에 맞는 기능을 호출합니다.
// =============================================================
void APlayerControllerBase::OnInputSkillStarted(const FInputActionInstance& inInstance)
{
	if (PC.IsValid())
	{
		const EAbilityType abilityKey = GetAbilityKeyFromAction(inInstance);
		if (abilityKey != EAbilityType::None)
			PC->SkillStarted(abilityKey);
	}
}

void APlayerControllerBase::OnInputSkillOngoing(const FInputActionInstance& inInstance)
{
	if (PC.IsValid())
	{
		const EAbilityType abilityKey = GetAbilityKeyFromAction(inInstance);
		if (abilityKey != EAbilityType::None)
			PC->SkillOngoing(abilityKey);
	}
}

void APlayerControllerBase::OnInputSkillTriggered(const FInputActionInstance& inInstance)
{
	if (PC.IsValid())
	{
		const EAbilityType abilityKey = GetAbilityKeyFromAction(inInstance);
		if (abilityKey != EAbilityType::None)
			PC->SkillTriggered(abilityKey);
	}
}

void APlayerControllerBase::OnInputSkillCompleted(const FInputActionInstance& inInstance)
{
	if (PC.IsValid())
	{
		const EAbilityType abilityKey = GetAbilityKeyFromAction(inInstance);
		if (abilityKey != EAbilityType::None)
			PC->SkillCompleted(abilityKey);
	}
}

void APlayerControllerBase::OnInputSkillCanceled(const FInputActionInstance& inInstance)
{
	if (PC.IsValid())
	{
		const EAbilityType abilityKey = GetAbilityKeyFromAction(inInstance);
		if (abilityKey != EAbilityType::None)
			PC->SkillCanceled(abilityKey);
	}
}

//덱 인터페이스 켜기/끄기
void APlayerControllerBase::OpenCloseDeckInterface()
{
	if(!PC.IsValid())
		return;

	if(!DeckInterfaceOpen)
	{
		if(!DeckInterfaceClass)
			return;
		
		DeckInterface = Cast<UDeck>(FindWidgetBase(FUIManager::GetInstance()->CreateWidgetBase(DeckInterfaceClass, TEXT("DeckInterface"))));
		if(!DeckInterface)
			return;
		
		//카드 정보를 가져옵니다.
		TArray<const FCard*> cards;
		PC->GetDeckHandler()->GetDeckInterfaceCards(cards, ECardFilterType::All);

		//카드를 등록합니다.
		DeckInterface->RegisterCards(cards);

		//후처리
		DeckInterface->AddToViewport();
		SetUIControlOn();
		DeckInterfaceOpen = true;
	}
	else
	{
		DeckInterface->SetVisibility(ESlateVisibility::Collapsed);
		
		//덱 인터페이스를 Destruct합니다.
		DeckInterface->Destruct();
		DeckInterface = nullptr;

		//후처리
		SetUIControlOff();
		DeckInterfaceOpen = false;
	}
}

void APlayerControllerBase::UseCard(int32 InCardIndex)
{
	//이미 카드를 선택했을 경우 해당 오브젝트를 파괴합니다.
	if(IsCardActivate && UseCardNum != InCardIndex)
	{
		PC->ExecuteCardCancel();
	}
	else if(UseCardNum == InCardIndex)
		return;
	
	if(!PC.IsValid())
		return;
	if(InCardIndex >= FDeckHandler::MaxHand)
		return;
	const FDeckHandler* handler = PC->GetDeckHandler();
	if(handler == nullptr)
		return;

	if(handler->GetHands()[InCardIndex] == nullptr)
		return;

	LOG_SCREEN(FColor::White, TEXT("%d카드가 등록되었습니다. Key : %d"), InCardIndex, handler->GetHands()[InCardIndex]->GetCardInfo().Key)
	
	for(int i = 0; i < FDeckHandler::MaxHand; ++i)
	{
		if(i == InCardIndex)
			Hand->ResizeHandCard(i, FVector2d(1.5, 1.5));
		else
			Hand->ResizeHandCard(i, FVector2d(1.0, 1.0));
	}
	UseCardNum = InCardIndex;

	handler->GetHands()[InCardIndex]->BindCardActivate();
	handler->GetHands()[InCardIndex]->BindCardCancel();
	handler->GetHands()[InCardIndex]->BindCardComplete();
	handler->GetHands()[InCardIndex]->BindRotateInstallation();

	
	PC->BindSkillUseCard();
	if (UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		for(auto& inputHandle : PreInputHandle)
			EnhancedInputComponent->RemoveBindingByHandle(inputHandle);
		PreInputHandle.Empty();
		PreInputHandle.Add(EnhancedInputComponent->BindAction(SkillInputActions[EAbilityType::MouseRM], ETriggerEvent::Triggered, this, &APlayerControllerBase::UnUseCard).GetHandle());
		PreInputHandle.Add(EnhancedInputComponent->BindAction(SkillInputActions[EAbilityType::SkillE], ETriggerEvent::Started, this, &APlayerControllerBase::RotateInstallationCW).GetHandle());
		PreInputHandle.Add(EnhancedInputComponent->BindAction(SkillInputActions[EAbilityType::SkillQ], ETriggerEvent::Started, this, &APlayerControllerBase::RotateInstallationCCW).GetHandle());
	}
}

void APlayerControllerBase::UnUseCard()
{
	if(IsCardActivate)
	{
		PC->ExecuteCardCancel();
	}
	
	if(!PC.IsValid())
		return;

	const FDeckHandler* handler = PC->GetDeckHandler();
	if(handler == nullptr)
		return;

	for(int i = 0; i < FDeckHandler::MaxHand; ++i)
		Hand->ResizeHandCard(i, FVector2d(1.0, 1.0));
	
	UseCardNum = -1;

	PC->UnBindSkillUseCard();
	if (UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		for(auto& inputHandle : PreInputHandle)
			EnhancedInputComponent->RemoveBindingByHandle(inputHandle);
		PreInputHandle.Empty();
		PreInputHandle.Add(EnhancedInputComponent->BindAction(SkillInputActions[EAbilityType::MouseRM], ETriggerEvent::Triggered, this, &APlayerControllerBase::OnInputSkillTriggered).GetHandle());
		PreInputHandle.Add(EnhancedInputComponent->BindAction(SkillInputActions[EAbilityType::SkillE], ETriggerEvent::Started, this, &APlayerControllerBase::OnInputSkillStarted).GetHandle());
		PreInputHandle.Add(EnhancedInputComponent->BindAction(SkillInputActions[EAbilityType::SkillQ], ETriggerEvent::Started, this, &APlayerControllerBase::OnInputSkillStarted).GetHandle());
	}
}

//필터 변경 시 블루프린트 호출
void APlayerControllerBase::CallBlueprint_ChangeFilter(ECardFilterType InFilterType)
{
	TArray<const FCard*> cards;
	PC->GetDeckHandler()->GetDeckInterfaceCards(cards, InFilterType);

	DeckInterface->RegisterCards(cards);
}

//정렬 변경 시 블루프린트 호출
void APlayerControllerBase::CallBlueprint_ChangeSort(ECardSortType InSortType)
{
	TArray<const FCard*> cards;
	PC->GetDeckHandler()->GetDeckInterfaceCards(cards, ECardFilterType::None, InSortType);

	DeckInterface->RegisterCards(cards);
}

void APlayerControllerBase::Jump()
{
	if (PC.IsValid())
		PC->Jump();
}

void APlayerControllerBase::StopJumping()
{
	if (PC.IsValid())
		PC->StopJumping();
}

void APlayerControllerBase::StartJog()
{
	if (PC.IsValid())
		PC->StartJog();
}

void APlayerControllerBase::StopJog()
{
	if (PC.IsValid())
		PC->StopJog();
}

void APlayerControllerBase::SetZoomInProp()
{
	if (PC.IsValid())
		PC->SetZoomInProp();
}

void APlayerControllerBase::SetZoomOutProp()
{
	if (PC.IsValid())
		PC->SetZoomOutProp();
}

void APlayerControllerBase::WheelUpCardSelect()
{
	const FDeckHandler* handler = PC->GetDeckHandler();
	if(handler == nullptr)
		return;

	TArray<int32> indices = handler->GetActivateHandIndex();
	int index = -1;
	
	if(UseCardNum == -1)
		index = 0;
	else
	{
		int count = 0;
		for(count; count < indices.Num(); ++count)
			if(indices[count] == UseCardNum)
				break;

		index = (count + 1) % indices.Num();
	}
	UseCardNum = indices[index];
	UseCard(UseCardNum);
}

void APlayerControllerBase::WheelDownCardSelect()
{
	const FDeckHandler* handler = PC->GetDeckHandler();
	if(handler == nullptr)
		return;

	TArray<int32> indices = handler->GetActivateHandIndex();
	int index = -1;
	
	if(UseCardNum == -1)
		index = indices.Num() - 1;
	else
	{
		int count = 0;
		for(count; count < indices.Num(); ++count)
			if(indices[count] == UseCardNum)
				break;

		index = count - 1;
		if(index < 0)
			index += indices.Num();
	}
	UseCardNum = indices[index];
	UseCard(UseCardNum);
}

void APlayerControllerBase::Interaction()
{
	if (PC.IsValid())
	{
		if(PC->DelegateInteractTask.IsBound())
			PC->DelegateInteractTask.Execute();
	}
}

void APlayerControllerBase::Move(const FInputActionValue &Value)
{
	if (PC.IsValid())
		PC->Move(Value);
}

void APlayerControllerBase::Look(const FInputActionValue &Value)
{
	if (PC.IsValid())
		PC->Look(Value);
}

void APlayerControllerBase::WaveStart()
{
	if (PC.IsValid())
		if(auto level = Cast<ADPLevelScriptActor>(PC->GetLevel()->GetLevelScriptActor()))
		{
			level->BindStartWave();
			level->CallStartWave();
		}
}


// =============================================================
// (임시) 블루프린트에서 활용할 UI컨트롤을 위한 시간, 컨트롤 제어
// =============================================================
void APlayerControllerBase::SetUIControlOn()
{
	if (PC.IsValid())
	if (PC == nullptr)
		return;
	
	// 시간 정지
 	GetWorldSettings()->SetTimeDilation(0.f);
 	
 	// 마우스 위치 세팅 // 마우스 커서 on //키보드 입력 off
 	int32 ScreenWidth;
 	int32 ScreenHeight;
 	GetViewportSize(ScreenWidth, ScreenHeight);
 	//SetMouseLocation(ScreenWidth * 0.5f, ScreenHeight * 0.5f);
 	bShowMouseCursor = true;
	//PC->CanCameraControl = false;	// << 이거 오류남;;
}


// =============================================================
// (임시) 블루프린트에서 활용할 UI컨트롤을 위한 시간, 컨트롤 제어
// =============================================================
void APlayerControllerBase::SetUIControlOff()
{
	if (PC.IsValid())
	if (PC == nullptr)
		return;
	
	// 시간 재게
	GetWorldSettings()->SetTimeDilation(1.f);

	// 마우스 커서 off //키보드 입력 on
	bShowMouseCursor = false;
	//PC->CanCameraControl = true;
}

//카드를 Activate한 후 처리를 담당합니다.
int32 APlayerControllerBase::PostActivateCard()
{
	//Hand->UnRegisterHand(UseCardNum);

	IsCardActivate = true;
	
	return UseCardNum;
}

int32 APlayerControllerBase::PostCancelCard()
{
	IsCardActivate = false;
	
	Hand->ResizeHandCard(UseCardNum, FVector2d(1.0, 1.0));
	
	int returnUseCardNum = UseCardNum;

	UseCardNum = -1;
	
	return returnUseCardNum;
}

//카드를 Complete한 후 처리를 담당합니다.
int32 APlayerControllerBase::PostCompleteCard()
{
	IsCardActivate = false;
	
	Hand->ResizeHandCard(UseCardNum, FVector2d(1.0, 1.0));
	Hand->PlayHandToHangerAnimation(UseCardNum);

	int returnUseCardNum = UseCardNum;

	UseCardNum = -1;
	
	return returnUseCardNum;
}

void APlayerControllerBase::RotateInstallationCW()
{
	if(!PC.IsValid())
		return;

	PC->ExecuteRotateInstallation(90);
}

void APlayerControllerBase::RotateInstallationCCW()
{
	if(!PC.IsValid())
		return;

	PC->ExecuteRotateInstallation(-90);
}

//드로우 한 후 카드 정보를 갱신합니다.
void APlayerControllerBase::RenewHand()
{
	TArray<FCard*> hand = PC->GetDeckHandler()->GetHands();
	Hand->RegisterHands(hand);
	Hand->PlayDrawAnimation();
}

void APlayerControllerBase::RegisterHands(TArray<FCard*> InCard)
{
	Hand->RegisterHands(InCard);
}

void APlayerControllerBase::ReplaceCard()
{
	//리플레이스 적용
	TArray<int32> toHangerIndex;
	if(PC->ReplaceCard(toHangerIndex) == false)
		return;

	//사용중인 카드가 있다면 파괴
	if(IsCardActivate)
	{
		PC->ExecuteCardCancel();
	}
	
	//적용중인 카드 초기화
	UseCardNum = -1;
	IsCardActivate = false;

	//카드 버리는 애니메이션 재생
	UWidgetAnimation* anim = nullptr;
	for(const int32& index : toHangerIndex)
		 anim = Hand->PlayHandToHangerAnimation(index);

	//카드 버리는 애니메이션이 있다면 해당 애니메이션 종료 후 카드 드로우 애니메이션 재생
	if(anim != nullptr)
	{
		float time = anim->GetEndTime() + 0.1f;
		FTimerHandle handle;
		TWeakObjectPtr<APlayerControllerBase> thisPtr = this;
		GetWorldTimerManager().SetTimer(handle, [thisPtr]()
		{
			if(thisPtr.IsValid())
				thisPtr->RenewHand();
		}, time, false);
	}
}

