// Copyright Epic Games, Inc. All Rights Reserved.

#include "CharacterPC.h"
#include "../Logic/PlayerControllerBase.h"
#include "..\Core\DpGameMode.h"
#include "../Skill/SkillBase.h"
#include "../Interface/PlayerInputInterface.h"
#include "../Util/UtilLevelCal.h"

#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <GameFramework/Controller.h>
#include <TimerManager.h>
#include <EnhancedInputComponent.h>
#include "AIHelpers.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterPC)

ACharacterPC::ACharacterPC()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;			 // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;		// The camera follows at this distance behind the character
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false;								// Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character)
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void ACharacterPC::BeginPlay()
{
	Super::BeginPlay();

	PCSkillManager.ResetSkill();
}

// Called every frame
void ACharacterPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// 뛰는 상태인지 판별하여 MaxWalkSpeed 초기화.
	if (IsJog)
	{
		GetCharacterMovement()->MaxWalkSpeed = ThisJogSpeed;
		SetRunZoomOutProp();
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = ThisSpeed;
		IsJog = false;
		SetZoomOutProp();
	}

	// 줌을 해도 되는지 판별
	if (CanZoom)
		ZoomInOut(DeltaTime);

	// 전투상태인지 판별하고, 전투상태라면 줌아웃
	if (InCombat)
	{
		//전투상태면 뛰는걸 멈춤
		IsJog = false;

		//줌아웃
		if (IsZoomed)
			SetZoomOutProp();
		
		auto Acceleration = GetCharacterMovement()->GetCurrentAcceleration().Length();
		if(Acceleration == 0)
			RotatePawn(DeltaTime);
		else
			SetActorRotation(FRotator(0, GetController()->GetControlRotation().Yaw, 0));
	}

	// 레벨이 올랐음을 감지하는 구문.
	if(TempLevel != Stat.GetStat(ECharacterStatType::Level))
	{
		Stat.ChangeStat(ECharacterStatType::Hp , Stat.GetStat(ECharacterStatType::MaxHp));
		TempLevel = Stat.GetStat(ECharacterStatType::Level);
		LevelUpEvent();
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ACharacterPC::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACharacterPC::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}
void ACharacterPC::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void ACharacterPC::Move(const FInputActionValue &Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);

		MoveForward = MovementVector.Y;
		MoveRight = MovementVector.X;
	}
}
void ACharacterPC::Look(const FInputActionValue &Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr && CanCameraControl)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

// =============================================================
// SkillInfos의 TSubClassOf들을 설정된 순서대로 Skills 배열에 인스턴스화 시킵니다.
// =============================================================
void ACharacterPC::InitSkills()
{
	if(Skills.Num() > 0)
		Skills.Empty();
	for (const TPair<EAbilityType, TSubclassOf<USkillBase>>& ability : SkillInfos)
	{
		Skills.Add(ability.Key, NewObject<USkillBase>(this, ability.Value));
		Skills[ability.Key]->RegisterComponent(); // 컴포넌트를 등록합니다.
	}

	if(SkillActivating.Num() < 0)
		SkillActivating.Empty();
	SkillActivating.Add(EAbilityType::MouseLM, false);
	SkillActivating.Add(EAbilityType::MouseRM, false);
	SkillActivating.Add(EAbilityType::Shift, false);
	SkillActivating.Add(EAbilityType::SkillQ, false);
	SkillActivating.Add(EAbilityType::SkillE, false);
	SkillActivating.Add(EAbilityType::SkillR, false);
}

// =============================================================
// 아래부터 각 상황에 맞는 스킬 호출 함수입니다. PlayerController에서 호출하면, 받아온 Index대로
// 인스턴스화 된 배열의 스킬에서 상황에 맞는 함수를 호출합니다.
// =============================================================
void ACharacterPC::SkillStarted(const EAbilityType InAbilityType)
{
	if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[InAbilityType]))
	{
		ability->SkillStarted();
	}
}
void ACharacterPC::SkillOngoing(const EAbilityType InAbilityType)
{
	if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[InAbilityType]))
	{
		ability->SkillOngoing();
	}
}
void ACharacterPC::SkillTriggered(const EAbilityType InAbilityType)
{
	if (Skills[InAbilityType]->CanActivateAbility() && !GetOtherSkillActivating(InAbilityType))
	{
		HandleCombatState();
		if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[InAbilityType]))
		{
			ability->SkillTriggered();
		}
	}
}
void ACharacterPC::SkillCompleted(const EAbilityType InAbilityType)
{
	if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[InAbilityType]))
	{
		ability->SkillCompleted();
	}
}
void ACharacterPC::SkillCanceled(const EAbilityType InAbilityType)
{
	if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[InAbilityType]))
	{
		ability->SkillCanceled();
	}
}

//================================================================
// 줌인아웃 프로퍼티의 값을 설정합니다.
//================================================================
void ACharacterPC::SetZoomInProp()
{
	if (!IsZoomed && !InCombat)
	{
		MyTargetArmLength = 250.0f;
		MyTargetArmLocation = FVector(0, 0, 0);
		MyCameraLocation = FVector(0, 0, 0);

		IsZoomed = true;
		ZoomInterpTime = 6;
		CanZoom = true;
	}
}
void ACharacterPC::SetZoomOutProp()
{
	if (IsZoomed)
	{
		MyTargetArmLength = 400.0f;
		MyTargetArmLocation = FVector(0, 0, 55);
		MyCameraLocation = FVector(0, 0, 55);

		IsZoomed = false;
		ZoomInterpTime = 6;
		CanZoom = true;
	}
}
//================================================================
// 달릴 때의 카메라 프롭을 설정합니다.
//================================================================
void ACharacterPC::SetRunZoomOutProp()
{
	MyTargetArmLength = 600.0f;
	MyTargetArmLocation = FVector(0, 0, 55);
	MyCameraLocation = FVector(0, 0, 55);

	IsZoomed = true;
	ZoomInterpTime = 6;
	CanZoom = true;
}

//================================================================
// Tick에서 작동합니다. 애니메이션 담당
//================================================================
void ACharacterPC::ZoomInOut(float InDeltaTime)
{
	CameraBoom->TargetArmLength = FMath::FInterpTo(
		CameraBoom->TargetArmLength,
		MyTargetArmLength,
		InDeltaTime,
		ZoomInterpTime);
	CameraBoom->SetRelativeLocation(FMath::VInterpTo(
		CameraBoom->GetRelativeLocation(),
		MyTargetArmLocation,
		InDeltaTime,
		ZoomInterpTime));
	FollowCamera->SetRelativeLocation(FMath::VInterpTo(
		FollowCamera->GetRelativeLocation(),
		MyCameraLocation,
		InDeltaTime,
		ZoomInterpTime));
	if (CameraBoom->TargetArmLength == MyTargetArmLength)
		CanZoom = false; // 줌인아웃이 완료되면 함수실행중지
	
}

//================================================================
// Jog //W가 눌린 상태일때만 뛸 수 있음 //W 때면 jog중지
//================================================================
void ACharacterPC::StartJog()
{
	//Player의 이동방향
	FVector playerMovementDirection = GetMovementComponent()->Velocity;
	playerMovementDirection.Z = 0;
	playerMovementDirection.Normalize();

	//Controller 방향
	FVector controllerDirection = Controller->GetControlRotation().Vector();
	controllerDirection.Z = 0;
	controllerDirection.Normalize();

	//내적을 통해 사잇각 확인
	double dotResult = FVector::DotProduct(playerMovementDirection, controllerDirection);
	
	if (dotResult > 0.01)
	{
		GetCharacterMovement()->MaxWalkSpeed = ThisJogSpeed;
		IsJog = true;
		SetRunZoomOutProp();
		SetInCombatFalse();
	}
}

void ACharacterPC::StopJog()
{
	GetCharacterMovement()->MaxWalkSpeed = ThisSpeed;
	IsJog = false;
	SetZoomOutProp();
}

void ACharacterPC::Jump()
{
	if(GetMovementComponent()->IsMovingOnGround() || (GetMovementComponent()->IsFalling() && GetMovementComponent()->Velocity.Z < 0))
		Super::Jump();
}

//================================================================
// Pawn 회전 함수 // 전투상태일 때만 자동회전. Tick에서 구현
//================================================================
void ACharacterPC::RotatePawn(float DeltaTime)
{
	FRotator rotation = GetActorRotation();
	FRotator toRotation = Controller->GetControlRotation();
	
	FRotator yawRotation(0, toRotation.Yaw, 0);

	//SetActorRotation(yawRotation);

	SetActorRotation(FMath::RInterpTo(
		rotation,
		yawRotation,
		DeltaTime,
		10));
}

//================================================================
// Level 이 올라갔을때, 이벤트를 발동시킵니다.
//================================================================
void ACharacterPC::LevelUpEvent()
{
	//Cast<APlayerControllerBase>(GetController())->SkillUpgradeEventStart();
}

//================================================================
// 스킬을 실행하려할 때, 다른 스킬이 작동중인지 확인하는 함수. 다른 스킬이 작동중이면 1 반환
//================================================================
bool ACharacterPC::GetOtherSkillActivating(EAbilityType inType)
{
	switch(inType)
	{
	case EAbilityType::MouseLM :
		return
		( SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::Shift]|| SkillActivating[EAbilityType::SkillQ] || SkillActivating[EAbilityType::SkillE] );
	case EAbilityType::MouseRM :
		return
		( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::Shift]|| SkillActivating[EAbilityType::SkillQ] || SkillActivating[EAbilityType::SkillE]|| SkillActivating[EAbilityType::SkillR]);
	case EAbilityType::Shift :
		return
		( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::SkillQ] || SkillActivating[EAbilityType::SkillE]|| SkillActivating[EAbilityType::SkillR]);
	case EAbilityType::SkillQ :
		return
		( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::Shift] || SkillActivating[EAbilityType::SkillE]|| SkillActivating[EAbilityType::SkillR]);
	case EAbilityType::SkillE :
		return
		( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::Shift] || SkillActivating[EAbilityType::SkillQ]|| SkillActivating[EAbilityType::SkillR]);
	case EAbilityType::SkillR :
		return
		( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::Shift] || SkillActivating[EAbilityType::SkillQ]|| SkillActivating[EAbilityType::SkillE]);
	case EAbilityType::None :
		return false;
	default:
		return false;
	}
}

//================================================================
// 스킬 쿨타임을 반환합니다.
//================================================================
float ACharacterPC::GetSkillCoolTimePercent(EAbilityType inType)
{
	return Skills[inType]->GetCoolTimePercent();
}
