// Copyright Epic Games, Inc. All Rights Reserved.

#include "CharacterPC.h"
#include "../Logic/PlayerControllerBase.h"
#include "../Core/DpGameMode.h"

#include "../Skill/PlayerSkill.h"
#include "../Interface/PlayerInputInterface.h"
#include "..\Util\UtilLevelCalc.h"
#include "../Handler/DeckHandler.h"
#include "../Card/Card.h"

#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <Components/SkeletalMeshComponent.h>

#include <GameFramework/Controller.h>

#include "CharacterTurret.h"
#include "../Manager/UIManager.h"
#include "../UI/UserWidgetBase.h"
#include "../UI/HUD/Hand.h"
#include "Components/DecalComponent.h"

#include "DieselPunk/Actor/Weapon.h"
#include "DieselPunk/Animation/SoldierAnimInstance.h"
#include "DieselPunk/Component/StatControlComponent.h"
#include "DieselPunk/Raw/BuffStatusEffect.h"
#include "DieselPunk/Skill/SkillPC/SkillSpawnTurret.h"
#include "DieselPunk/UI/HUD/DPHud.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterPC)

void ACharacterPC::CheckViewMiddleForInteractInstallationUI()
{
	FHitResult result;
	TArray<const AActor*> ignore;
	ignore.Add(this);
	
	if(UtilCollision::GetViewMiddle(GetWorld(), Cast<APlayerController>(GetController()), result, 99999, ignore))
	{
		ACharacterHousing* housing = Cast<ACharacterHousing>(result.GetActor());
		LookInstallation = housing;
	}
	else
	{
		LookInstallation = nullptr;
	}
	TWeakObjectPtr<UDPHud> hud = Cast<UDPHud>(FindWidgetBase(Cast<APlayerControllerBase>(Controller)->GetHUDId()));
	if(hud.IsValid())
	{
		hud->SetViewInteractionUI(LookInstallation.IsValid() || SelectInstallation.IsValid());
		hud->SelectedInteractionUI(SelectInstallation.IsValid());
	}
}

void ACharacterPC::InitHud()
{
	TWeakObjectPtr<UDPHud> hud = Cast<UDPHud>(FindWidgetBase(Cast<APlayerControllerBase>(Controller)->GetHUDId()));
	if(hud.IsValid())
		hud->InitPlayerHpBar(GetStat(ECharacterStatType::Hp), GetStat(ECharacterStatType::MaxHp));
}

ACharacterPC::ACharacterPC()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = true;

	// Configure character movement
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;			 // Character moves in the direction of input...

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArm->TargetArmLength = DefaultTargetArmLength;
	SpringArm->SetRelativeLocation(DefaultTargetArmLocation);
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetRelativeLocation(DefaultCameraLocation);
	FollowCamera->SetFieldOfView(DefaultFieldOfView);
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false;								// Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character)
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)


	static ConstructorHelpers::FObjectFinder<UMaterialInterface> materialIndicator(TEXT("/Script/Engine.Material'/Game/DieselPunk/Assets/Fx/Indicator/Material/M_Indicator.M_Indicator'"));
	if(materialIndicator.Succeeded())
		IndicatorMaterial = materialIndicator.Object;

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> materialIndicatorBase(TEXT("/Script/Engine.Material'/Game/DieselPunk/Assets/Fx/Indicator/Material/M_IndicatorBase.M_IndicatorBase'"));
	if(materialIndicatorBase.Succeeded())
		IndicatorBaseMaterial = materialIndicatorBase.Object;
}

void ACharacterPC::BeginPlay()
{
	InitCameraSetting();
	
	//스탯이 초기화 되기 전 델리게이트를 위한 함수호출입니다. Super::BeginPlay를 호출하기 전에 실행합니다.
	//핸드UI를 초기화합니다
	TWeakObjectPtr<UUserWidgetBase> hud = FindWidgetBase(Cast<APlayerControllerBase>(Controller)->GetHUDId());
	if(hud.IsValid())
	{
		UHand* handUi = Cast<UHand>((*hud)[TEXT("Hand")]);
		handUi->Initailize(this);
	}
	
	Super::BeginPlay();
	CharacterType = ECharacterType::Player;
	
	DeckHandler = new FDeckHandler(this);
	
	DeckHandler->BeginPlay();

	//테스트를 위한 패를 추가합니다.
	for(const TPair<FString, int32>& initCard : InitHaveCard)
	{
		for(int i = 0; i < initCard.Value; ++i)
			DeckHandler->AddCard(initCard.Key);
	}
	DeckHandler->BeginPlayStage();

	//패를 HUD에 등록합니다.
	TArray<FCard*> hand = DeckHandler->GetHands();
	Cast<APlayerControllerBase>(GetController())->RegisterHands(hand);
	
	//Skill Stat Set
	for(const auto& It : Skills)
	{
		It.Value->InitSkill();
	}

	TArray<AActor*> childActors;
	GetAllChildActors(childActors);
	for(AActor* actor : childActors)
	{
		if(AWeapon* weapon = Cast<AWeapon>(actor))
		{
			Weapon = weapon;
			Weapon->SetOwnerPlayer(this);
			break;
		}
	}

	// 플레이어 정보를 UI에 전달합	니다.
	InitHud();

	// 맵에 배치된 PlayerStarts의 위치를 받아옵니다.
	GetPlyaerStartsLocation();
}

// Called every frame
void ACharacterPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LOG_SCREEN(FColor::White, TEXT("isjog : %hhd Incombat : %hhd"), IsJog, InCombat);
	// 뛰는 상태인지 판별하여 MaxWalkSpeed 초기화.
	if (IsJog)
	{
		GetCharacterMovement()->MaxWalkSpeed = GetStat(ECharacterStatType::MoveSpeed) * JogRate;
		SetZoomOutProp();
		bUseControllerRotationYaw = false;	// 컨트롤러에 의한 캐릭터 yaw 회전
		GetCharacterMovement()->bOrientRotationToMovement = true;			 // Character moves in the direction of input...
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = GetStat(ECharacterStatType::MoveSpeed);
		SetDefaultZoomProp();
		bUseControllerRotationYaw = true;	// 컨트롤러에 의한 캐릭터 yaw 회전
		GetCharacterMovement()->bOrientRotationToMovement = false;			 // Character moves in the direction of input...
		//StopJog();
	}

	// 줌을 해도 되는지 판별
	if (CanZoom)
		ZoomInOut(DeltaTime);

	// 전투상태인지 판별하고, 전투상태라면 줌아웃
	if (InCombat)
	{
		//전투상태면 뛰는걸 멈춤
		StopJog();

		//줌아웃
		if (IsZoomed)
			SetDefaultZoomProp();
	}
	
	// 레벨이 올랐음을 감지하는 구문.
	if(TempLevel != GetStat(ECharacterStatType::Level))
	{
		ChangeStat(ECharacterStatType::Hp , GetStat(ECharacterStatType::MaxHp) - GetStat(ECharacterStatType::Hp));
		TempLevel = GetStat(ECharacterStatType::Level);
		LevelUpEvent();
	}

	// 인디케이터
	if(IndicatorBase.IsValid())
		IndicatorBase->SetWorldLocation(GetActorLocation());
	if(Indicator.IsValid())
	{
		FHitResult result;
		TArray<const AActor*> ignore;
		ignore.Add(this);
		if(UtilCollision::GetViewMiddle(GetWorld(), Cast<APlayerController>(Controller), result, 99999, ignore))
			Indicator->SetWorldLocation(result.Location);
	}

	CheckViewMiddleForInteractInstallationUI();

	CheckLanded();
}

//////////////////////////////////////////////////////////////////////////
// Input //

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

//////////////////////////////////////////////////////////////////////////
// Movement //

void ACharacterPC::Move(const FInputActionValue &Value)
{
	if(!CanMove)
		return;
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

		HorizontalForce = MovementVector;
		
		MoveForward = MovementVector.Y;
		MoveRight = MovementVector.X;
	}
}
void ACharacterPC::Look(const FInputActionValue &Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	APlayerController* playerController = Cast<APlayerController>(Controller);
	if (playerController != nullptr && CanCameraControl)
	{
		if(!CanMove && !CanAttack && !CanSkill)
		{
			FRotator newRotator = GetCameraBoom()->GetRelativeRotation();
			newRotator.Yaw += LookAxisVector.X * playerController->InputYawScale_DEPRECATED;
			newRotator.Pitch = FMath::Clamp(newRotator.Pitch + LookAxisVector.Y * playerController->InputPitchScale_DEPRECATED, -80.f, 80.f);
			GetCameraBoom()->SetRelativeRotation(newRotator);
		}
		else
		{
			// add yaw and pitch input to controller
			AddControllerYawInput(LookAxisVector.X);
			AddControllerPitchInput(LookAxisVector.Y);
		}
	}
}

void ACharacterPC::Jump()
{
	if(GetMovementComponent()->IsMovingOnGround() || (GetMovementComponent()->IsFalling() && GetMovementComponent()->Velocity.Z < 0))
	{
		if(DelegateJumpAction.IsBound())
			DelegateJumpAction.Execute();
		Super::Jump();
	}
}

void ACharacterPC::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	if(DelegateLandAction.IsBound())
		DelegateLandAction.Execute(Hit);
}

// 컨트롤러의 pitch를 +-50 이상 회전한 후, 공중에서 착지 시, 캐릭터가 착지하지 않아 강제로 SetMovementMode(MOVE_Walking)를 호출합니다.
void ACharacterPC::CheckLanded()
{
	// Get the character's location and trace downward
	FVector Start = GetActorLocation();
	FVector End = Start - FVector(0.0f, 0.0f, GetCapsuleComponent()->GetScaledCapsuleHalfHeight()); // Adjust the trace distance as needed

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECC_Visibility,	//착지 오류 시, 트레이스 채널 확인.
		CollisionParams
	);
	
	if(bHit)
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
}

//================================================================
// Jog //W가 눌린 상태일때만 뛸 수 있음 
//================================================================
void ACharacterPC::StartJog()
{
	InCombat = false;
	IsJog = true;
	
	/*
	//Player의 이동방향
	FVector playerMovementDirection = GetMovementComponent()->Velocity;
	playerMovementDirection.Z = 0;
	playerMovementDirection.Normalize();

	//Controller 방향
	FVector controllerDirection = Controller->GetControlRotation().Vector();
	controllerDirection.Z = 0;
	controllerDirection.Normalize();

	//내적을 통해 사잇각 확인
	const double dotResult = FVector::DotProduct(playerMovementDirection, controllerDirection);
	
	if (dotResult > 0.01)
	{
		IsJog = true;
		InCombat = false;
	}
	*/
}

void ACharacterPC::StopJog()
{
	IsJog = false;
}

//================================================================
// Pawn 회전 함수 // 전투상태일 때만 자동회전. Tick에서 구현
//================================================================
void ACharacterPC::RotatePawn(float DeltaTime)
{
	const FRotator rotation = GetActorRotation();
	const FRotator toRotation = Controller->GetControlRotation();
	
	const FRotator yawRotation(0, toRotation.Yaw, 0);

	SetActorRotation(FMath::RInterpTo(
		rotation,
		yawRotation,
		DeltaTime,
		10));
}

//================================================================
// 줌인아웃 프로퍼티의 값을 설정합니다.
//================================================================
void ACharacterPC::SetZoomInProp()
{
	if (!IsZoomed && !InCombat)
	{
		MyTargetArmLength = 400.0f;
		MyTargetArmLocation = FVector(0, 0, 0);
		MyCameraLocation = FVector(0, 0, 0);

		IsZoomed = true;
		ZoomInterpTime = 6;
		CanZoom = true;
	}
}
void ACharacterPC::SetDefaultZoomProp()
{
	if (IsZoomed)
	{
		MyTargetArmLength = DefaultTargetArmLength;
		MyTargetArmLocation = DefaultTargetArmLocation;
		MyCameraLocation = DefaultCameraLocation;
		MyFieldOfView = DefaultFieldOfView;
		
		IsZoomed = false;
		ZoomInterpTime = 6;
		CanZoom = true;
	}
}

//================================================================
// 달릴 때의 카메라 프롭을 설정합니다.
//================================================================
void ACharacterPC::SetZoomOutProp()
{
	MyTargetArmLength = WideViewTargetArmLength;
	MyTargetArmLocation = WideViewTargetArmLocation;
	MyCameraLocation = WideViewCameraLocation;
	MyFieldOfView = WideViewFieldOfView;

	IsZoomed = true;
	ZoomInterpTime = 6;
	CanZoom = true;
}
// 카메라 세팅을 Default값으로 초기화 합니다.
void ACharacterPC::InitCameraSetting()
{
	SpringArm->TargetArmLength = DefaultTargetArmLength;
	SpringArm->SetRelativeLocation(DefaultTargetArmLocation);
	FollowCamera->SetRelativeLocation(DefaultCameraLocation);
	FollowCamera->SetFieldOfView(DefaultFieldOfView);
	MyTargetArmLength = DefaultTargetArmLength;
	MyTargetArmLocation = DefaultTargetArmLocation;
	MyCameraLocation = DefaultCameraLocation;
	MyFieldOfView = DefaultFieldOfView;
}

//================================================================
// Tick에서 작동합니다. 애니메이션 담당
//================================================================
void ACharacterPC::ZoomInOut(float InDeltaTime)
{
	SpringArm->TargetArmLength = FMath::FInterpTo(
		SpringArm->TargetArmLength,
		MyTargetArmLength,
		InDeltaTime,
		ZoomInterpTime);
	SpringArm->SetRelativeLocation(FMath::VInterpTo(
		SpringArm->GetRelativeLocation(),
		MyTargetArmLocation,
		InDeltaTime,
		ZoomInterpTime));
	FollowCamera->SetRelativeLocation(FMath::VInterpTo(
		FollowCamera->GetRelativeLocation(),
		MyCameraLocation,
		InDeltaTime,
		ZoomInterpTime));
	FollowCamera->SetFieldOfView(FMath::FInterpTo(
		FollowCamera->FieldOfView,
		MyFieldOfView,
		InDeltaTime,
		ZoomInterpTime));
	if (SpringArm->TargetArmLength == MyTargetArmLength)
		CanZoom = false; // 줌인아웃이 완료되면 함수실행중지
}

// =============================================================
// SkillInfos의 TSubClassOf들을 설정된 순서대로 Skills 배열에 인스턴스화 시킵니다.
// =============================================================
void ACharacterPC::InitSkills()
{
	if(Skills.Num() > 0)
		Skills.Empty();
	for (const TPair<EAbilityType, TSubclassOf<UPlayerSkill>>& ability : SkillInfos)
	{
		if(ability.Key == EAbilityType::MouseLM || ability.Key == EAbilityType::MouseRM)
			continue;
		
		if(ability.Value != nullptr)
		{
			Skills.Add(ability.Key, NewObject<UPlayerSkill>(this, ability.Value));
			Skills[ability.Key]->RegisterComponent(); // 컴포넌트를 등록합니다.
		}
		else
		{
			FString inPath = TEXT("/Script/Engine.DataTable'/Game/DieselPunk/Blueprints/Skill/BP_VoidPlayerSkill.BP_VoidPlayerSkill_C'");
			Skills.Add(ability.Key, NewObject<UPlayerSkill>(this, ConstructorHelpersInternal::FindOrLoadClass(inPath , UPlayerSkill::StaticClass())));
			Skills[ability.Key]->RegisterComponent(); // 빈 스킬을 등록합니다.
		}
	}
	CachedSkills = Skills;

	if(CardSkillInfo != nullptr)
	{
		CardSkill = NewObject<UPlayerSkill>(this, CardSkillInfo);
		CardSkill->RegisterComponent();
	}

	if(SkillActivating.Num() < 0)
		SkillActivating.Empty();
	for(auto It : SkillInfos)
	{
		SkillActivating.Add(It.Key, false);
	}
}

// =============================================================
// 아래부터 각 상황에 맞는 스킬 호출 함수입니다. PlayerController에서 호출하면, 받아온 Index대로
// 인스턴스화 된 배열의 스킬에서 상황에 맞는 함수를 호출합니다.
// =============================================================
void ACharacterPC::SkillStarted(const EAbilityType inAbilityType)
{
	if(inAbilityType == EAbilityType::MouseLM && !CanAttack)
		return;

	if(inAbilityType != EAbilityType::MouseLM && !CanSkill)
		return;
	//if((inAbilityType == EAbilityType::MouseLM || inAbilityType == EAbilityType::MouseRM) && !UseCard)
	//{
	//	if(Weapon->CanActivateAbility(inAbilityType) && !GetOtherSkillActivating(inAbilityType))
	//	{
	//		if(inAbilityType != EAbilityType::Shift)
	//			HandleCombatState();
	//		Weapon->SkillStarted(inAbilityType, CurrentCachedSkill);
	//	}
	//}
	//else
	//{
		if(Skills.Find(inAbilityType) != nullptr)
			if (Skills[inAbilityType]->CanActivateAbility() && !GetOtherSkillActivating(inAbilityType))
			{
				if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[inAbilityType]))
				{
					ability->SkillStarted();
					CurrentCachedSkill = Skills[inAbilityType];
				}
			}
	//}
}
void ACharacterPC::SkillOngoing(const EAbilityType inAbilityType)
{
	if(inAbilityType == EAbilityType::MouseLM && !CanAttack)
		return;

	if(inAbilityType != EAbilityType::MouseLM && !CanSkill)
		return;
	
	if(Skills.Find(inAbilityType) != nullptr)
		if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[inAbilityType]))
		{
			ability->SkillOngoing();
			CurrentCachedSkill = Skills[inAbilityType];
		}
}
void ACharacterPC::SkillTriggered(const EAbilityType inAbilityType)
{
	if(inAbilityType == EAbilityType::MouseLM && !CanAttack)
		return;

	if(inAbilityType != EAbilityType::MouseLM && !CanSkill)
		return;

	//if((inAbilityType == EAbilityType::MouseLM || inAbilityType == EAbilityType::MouseRM) && !UseCard)
	//{
	//	if(Weapon->CanActivateAbility(inAbilityType) && !GetOtherSkillActivating(inAbilityType))
	//	{
	//		if(inAbilityType != EAbilityType::Shift)
	//			HandleCombatState();
	//		Weapon->SkillTriggered(inAbilityType, CurrentCachedSkill);
	//	}
	//}
	//else
	//{
		if(Skills.Find(inAbilityType) != nullptr)
			if (Skills[inAbilityType]->CanActivateAbility() && !GetOtherSkillActivating(inAbilityType))
			{
				if(inAbilityType != EAbilityType::Shift)
					HandleCombatState();
				if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[inAbilityType]))
				{
					ability->SkillTriggered();
					CurrentCachedSkill = Skills[inAbilityType];
				}
			}
	//}
}
void ACharacterPC::SkillCompleted(const EAbilityType inAbilityType)
{
	if(inAbilityType == EAbilityType::MouseLM && !CanAttack)
		return;

	if(inAbilityType != EAbilityType::MouseLM && !CanSkill)
		return;

	if(inAbilityType == EAbilityType::MouseLM)
		if(USoldierAnimInstance* soldierAnimInst = Cast<USoldierAnimInstance>(GetMesh()->GetAnimInstance()))
			soldierAnimInst->AttackEndSign();
	
	if(Skills.Find(inAbilityType) != nullptr)// && !UseCard)
		if (Skills[inAbilityType]->CanActivateAbility() && !GetOtherSkillActivating(inAbilityType))
		{
			if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[inAbilityType]))
			{
				ability->SkillCompleted();
				CurrentCachedSkill = Skills[inAbilityType];
			}
		}
}
void ACharacterPC::SkillCanceled(const EAbilityType inAbilityType)
{
	if(inAbilityType == EAbilityType::MouseLM && !CanAttack)
		return;

	if(inAbilityType != EAbilityType::MouseLM && !CanSkill)
		return;
	
	if(Skills.Find(inAbilityType) != nullptr)
		if(IPlayerInputInterface* ability = Cast<IPlayerInputInterface>(Skills[inAbilityType]))
		{
			ability->SkillCanceled();
			CurrentCachedSkill = Skills[inAbilityType];
		}
}

//================================================================
// 스킬을 실행하려할 때, 다른 스킬이 작동중인지 확인하는 함수. 다른 스킬이 작동중이면 1 반환
//================================================================
bool ACharacterPC::GetOtherSkillActivating(EAbilityType inType)
{
	switch(inType)
	{
	case EAbilityType::MouseLM :
		return ( SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::Shift]|| SkillActivating[EAbilityType::SkillQ] || SkillActivating[EAbilityType::SkillE]|| SkillActivating[EAbilityType::SkillR] );
	case EAbilityType::MouseRM :
		return ( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::Shift]|| SkillActivating[EAbilityType::SkillQ] || SkillActivating[EAbilityType::SkillE]|| SkillActivating[EAbilityType::SkillR]);
	case EAbilityType::Shift :
		return ( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::SkillQ] || SkillActivating[EAbilityType::SkillE]|| SkillActivating[EAbilityType::SkillR]);
	case EAbilityType::SkillQ :
		return ( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::Shift] || SkillActivating[EAbilityType::SkillE]|| SkillActivating[EAbilityType::SkillR]);
	case EAbilityType::SkillE :
		return ( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::Shift] || SkillActivating[EAbilityType::SkillQ]|| SkillActivating[EAbilityType::SkillR]);
	case EAbilityType::SkillR :
		return ( SkillActivating[EAbilityType::MouseLM]|| SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::Shift] || SkillActivating[EAbilityType::SkillQ]|| SkillActivating[EAbilityType::SkillE]);
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
	if(Skills.Find(inType) != nullptr)
		return Skills[inType]->GetCoolTimePercent();

	return 0.f;
}

//================================================================
// Level 이 올라갔을때, 이벤트를 발동시킵니다.
//================================================================
void ACharacterPC::LevelUpEvent()
{
	// SetEvent!
}

//카드 Activate를 실행합니다.
bool ACharacterPC::ExecuteCardActivate()
{
	APlayerControllerBase* controller = Cast<APlayerControllerBase>(GetController());
	if(controller == nullptr)
		return false;
	
	bool IsSuccessActivate = false;
	if(DelegateCardActivate.IsBound())
		DelegateCardActivate.Execute(IsSuccessActivate, GetStat(ECharacterStatType::Cost));

	if(!IsSuccessActivate)
		return false;
	
	int32 value = controller->PostActivateCard();
	
	//LOG_SCREEN(FColor::White, TEXT("%d카드를 사용합니다."), value)
	
	DelegateCardActivate.Unbind();
	return true;
}

bool ACharacterPC::ExecuteCardCancel()
{
	APlayerControllerBase* controller = Cast<APlayerControllerBase>(GetController());
	if(controller == nullptr)
		return false;
	
	if(DelegateCardCancel.IsBound())
		DelegateCardCancel.Execute();
	USkillSpawnTurret* spawnskill = Cast<USkillSpawnTurret>(CardSkill);
	spawnskill->SpawnCancel();

	int32 value = controller->PostCancelCard();

	//LOG_SCREEN(FColor::White, TEXT("캔슬 완료"))

	DelegateCardComplete.Unbind();

	UnBindSkillUseCard();
	return true;
}

//카드 Complete를 실행합니다.
bool ACharacterPC::ExecuteCardComplete()
{
	APlayerControllerBase* controller = Cast<APlayerControllerBase>(GetController());
	if(controller == nullptr)
		return false;
	
	bool IsSuccessComplete = false;
	if(DelegateCardComplete.IsBound())
		DelegateCardComplete.Execute(IsSuccessComplete, GetStat(ECharacterStatType::Cost));

	if(!IsSuccessComplete)
		return false;

	int32 value = controller->PostCompleteCard();
	ChangeStat(ECharacterStatType::Cost, -DeckHandler->GetHands()[value]->GetCardInfo().Cost);
	DeckHandler->UseCard(value);

	//LOG_SCREEN(FColor::White, TEXT("사용 완료"))

	DelegateCardComplete.Unbind();
	return true;
}

bool ACharacterPC::ExecuteRotateInstallation(int32 InRotateAngle)
{
	if(DelegateRotateInstallation.IsBound())
		DelegateRotateInstallation.Execute(InRotateAngle);

	return true;
}

void ACharacterPC::DrawCard()
{
	APlayerControllerBase* controller = Cast<APlayerControllerBase>(GetController());

	if(controller == nullptr)
		return;
	
	if(DeckHandler->Draw())
		controller->RenewHand();
}

void ACharacterPC::SetSelectInstallation(TWeakObjectPtr<ACharacterHousing> InInstallation)
{
	SelectInstallation = InInstallation;
}

void ACharacterPC::BindSkillUseCard()
{
	Skills.FindOrAdd(EAbilityType::MouseLM) = CardSkill;
	if(Skills.Find(EAbilityType::MouseLM) != nullptr)
		Skills[EAbilityType::MouseLM] = CardSkill;
	CardSkill->SkillStarted();
	//UseCard = true;
}

void ACharacterPC::UnBindSkillUseCard()
{
	TObjectPtr<UPlayerSkill>* findSkill = CachedSkills.Find(EAbilityType::MouseLM);
	if(findSkill != nullptr)
		Skills[EAbilityType::MouseLM] = *findSkill;
	else
		Skills.Remove(EAbilityType::MouseLM);
	if(DelegateCardActivate.IsBound())
		DelegateCardActivate.Unbind();
	if(DelegateCardCancel.IsBound())
		DelegateCardCancel.Unbind();
	if(DelegateCardComplete.IsBound())
		DelegateCardComplete.Unbind();
	if(DelegateRotateInstallation.IsBound())
		DelegateRotateInstallation.Unbind();

	//UseCard = false;
}

bool ACharacterPC::CardSkillIsExpectedUnBind()
{
	if(Skills.Find(EAbilityType::MouseLM) == nullptr)
		return false;
	
	USkillSpawnTurret* skill = Cast<USkillSpawnTurret>(Skills[EAbilityType::MouseLM]);
	if(skill)
		return skill->IsExpectedUnBind();
	return false;
}

void ACharacterPC::RestoreSkillBind()
{
	APlayerControllerBase* controller = Cast<APlayerControllerBase>(GetController());
	if(controller == nullptr)
		return;

	UnBindSkillUseCard();

	controller->RestoreSkillBind();
}

bool ACharacterPC::ReplaceCard(TArray<int32>& OutUseIndex)
{
	int32 value = 50 * FMath::Pow(2.f, ReplaceUseCostCount - 1);

	if(ReplaceUseCostCount != 0 && GetStat(ECharacterStatType::Cost) < value)
		return false;
	
	if(ReplaceUseCostCount != 0)
		ChangeStat(ECharacterStatType::Cost, -value);
	++ReplaceUseCostCount;
	
	OutUseIndex = DeckHandler->Replace(); 
		
	return true;
}

void ACharacterPC::SpawnDecalComponent(double InMaxRange, double InRange)
{
	if(IndicatorBaseMaterial.IsValid())
		IndicatorBase = UGameplayStatics::SpawnDecalAtLocation(this, IndicatorBaseMaterial.Get(), FVector(InMaxRange), GetActorLocation());

	if(IndicatorMaterial.IsValid())
		Indicator = UGameplayStatics::SpawnDecalAtLocation(this, IndicatorMaterial.Get(), FVector(InRange), GetActorLocation());
}

void ACharacterPC::DestroyDecalComponent()
{
	if(Indicator.IsValid())
		Indicator->DestroyComponent();
	if(IndicatorBase.IsValid())
		IndicatorBase->DestroyComponent();
}

void ACharacterPC::OnPossessWeapon(AWeapon* InWeapon)
{
	Skills.FindOrAdd(EAbilityType::MouseLM) = InWeapon->GetSkill_LM();
	CachedSkills.FindOrAdd(EAbilityType::MouseLM) = InWeapon->GetSkill_LM();
	
	Skills.FindOrAdd(EAbilityType::MouseRM) = InWeapon->GetSkill_RM();
	CachedSkills.FindOrAdd(EAbilityType::MouseRM) = InWeapon->GetSkill_RM();
}

void ACharacterPC::AbilityShot(double InDamageCoefficient)
{
	Super::AbilityShot(InDamageCoefficient);

	if(CurrentCachedSkill.IsValid())
		CurrentCachedSkill->AbilityShot(InDamageCoefficient);
}

void ACharacterPC::SetBuffStatusEffectRoleType(EBuffStatusEffectRoleType InBuffStatusEffectRolType, bool InCan)
{
	Super::SetBuffStatusEffectRoleType(InBuffStatusEffectRolType, InCan);

	if(!CanSkill)
	{
		APlayerControllerBase* controller = Cast<APlayerControllerBase>(GetController());
		if(controller == nullptr)
			return;

		if(controller->GetIsCardActivate())
			ExecuteCardCancel();
	}

	if(CanMove && CanAttack && CanSkill)
	{
		FRotator springArmRotation = SpringArm->GetRelativeRotation();
		SpringArm->bUsePawnControlRotation = true;
		GetController()->SetControlRotation(GetController()->GetControlRotation() + springArmRotation);
	}
	else if(!CanMove && !CanAttack && !CanSkill)
	{
		FRotator controllerRotation = GetController()->GetControlRotation();
		SpringArm->bUsePawnControlRotation = false;
		SpringArm->SetWorldRotation(controllerRotation);
	}
}

// 플레이어가 사망했을 때의 상태를 세팅합니다.
void ACharacterPC::SetDeadStatePC()
{
	// DeadState
	// visual-invisible // TODO DeadAnimation
	GetMesh()->SetHiddenInGame(true);
	if(Weapon)
		Weapon->SetActorHiddenInGame(true);
	
	// 컨트롤러 세팅
	GetStatControlComponent()->AddBuff(TEXT("Death"));
	APlayerControllerBase* controller = Cast<APlayerControllerBase>(GetController());
	if(controller)
		controller->SetUIControlForPlayerDie();
	// n초 후 캐릭터 리스폰 // 현재는 10초 // TODO property로 빼야함
	FTimerHandle timerHandle;
	TWeakObjectPtr<ACharacterPC> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, [thisPtr](){
			if(thisPtr.IsValid())
				thisPtr->ReSpawnPC();
			},10.f, false);
}

// 플레이어를 리스폰하며, 리스폰할 때의 상태를 세팅합니다.
void ACharacterPC::ReSpawnPC()
{
	// LiveState
	// visual-visible // TODO ReSpawnAnimation
	GetMesh()->SetHiddenInGame(false);
	
	// 컨트롤러 세팅
	APlayerControllerBase* controller = Cast<APlayerControllerBase>(GetController());
	if(controller)
	{
		controller->SetUIControlForPlayerRespawn();
		controller->SetControlRotation(SpawnRotation);
	}

	//플레이어 리스폰(임시) // TODO playerStarts를 상속받는 클래스를 제작해서 오브젝트매니저로 관리
	SetActorLocation(SpawnLocation);
	SetActorRotation(SpawnRotation);
	ChangeStat(ECharacterStatType::Hp, GetStat(ECharacterStatType::MaxHp));
}

void ACharacterPC::GetPlyaerStartsLocation()
{
	TArray<AActor*> PlayerStarts;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), PlayerStarts);
	if (PlayerStarts.Num() > 0)
	{
		if (APlayerStart* SelectedPlayerStart = Cast<APlayerStart>(PlayerStarts[0]))
		{
			SpawnLocation = SelectedPlayerStart->GetActorLocation();
			SpawnRotation = SelectedPlayerStart->GetActorRotation();
		}
	}
}

FVector ACharacterPC::GetGrenadeSocketLocation(const FName& InSocketName)
{
	if(Weapon)
		return Weapon->GetGrenadeSocketLocation(InSocketName);
	
	return Super::GetGrenadeSocketLocation(InSocketName);
}

FRotator ACharacterPC::GetGrenadeSocketRotation(const FName& InSocketName)
{
	if(Weapon)
		return Weapon->GetGrenadeSocketRotation(InSocketName);
	
	return Super::GetGrenadeSocketRotation(InSocketName);
}
