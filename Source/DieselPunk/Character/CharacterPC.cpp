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
#include <DrawDebugHelpers.h>
#include <EnhancedInputComponent.h>
#include <Engine/DamageEvents.h>
#include <Components/WidgetComponent.h>

#include <GameFramework/WorldSettings.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterPC)

ACharacterPC::ACharacterPC()
	:
	Exp(0), Level(1), TempLevel(Level), TempMaxHealth(MaxHealth)
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
	//InitSkills();
	
	TODO( "레벨에 미리 세팅되어있는 액터들이라 이곳에서 등록, 추후 논의 필요", 크로 )
	if ( InfoId == G_InvalidInfoId )
	{
		InfoId = TestInfoId;
	}

	if ( ObjId == G_InvalidObjId )
	{
		//ObjId = GetObjectManager().GeneratorObjId();
		//GetObjectManager().RegisterObject( ObjId, this );
	}
	
	Super::BeginPlay();

	// 게임시작시 기본체력초기화
	Health = MaxHealth;
	TempPercent = Health / MaxHealth;
	TempPercentAfterImage = Health / MaxHealth;
	JumpMaxCount = ThisJumpMaxCount;
}

// Called every frame
void ACharacterPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(TempMaxHealth != MaxHealth)
	{
		_UpdateHp(Health, MaxHealth);
		TempMaxHealth = MaxHealth;
	}
	
	// 뛰는 상태인지 판별하여 MaxWalkSpeed 초기화.
	if (IsJog && IsWPressed)
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
		IsJog = false;
		
		if (IsZoomed)
			SetZoomOutProp();
		
		auto Acceleration = GetCharacterMovement()->GetCurrentAcceleration().Length();
		if(Acceleration == 0)
		{
			RotatePawn(DeltaTime);
		}
		else
		{
			SetActorRotation(FRotator(0, GetController()->GetControlRotation().Yaw, 0));
		}
	}

	// 체력 애니메이팅 [TODO]추후 UI로 
	AnimatorHealthPercent.Update(DeltaTime);
	AnimatorHealthPercentAfterImage.Update(DeltaTime);

	if(TempLevel != Level)
	{
		Health = MaxHealth;
		TempLevel = Level;
		LevelUpEvent();
	}
}

// =============================================================
// 상태 UI 위젯을 생성한다.
// =============================================================
void ACharacterPC::CreateStatusUI()
{

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
	Skills.Empty();
	for (const TPair<EAbilityType, TSubclassOf<USkillBase>>& ability : SkillInfos)
	{
		Skills.Add(ability.Key, NewObject<USkillBase>(this, ability.Value));
		Skills[ability.Key]->RegisterComponent(); // 컴포넌트를 등록합니다.
	}

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
	//LOG_SCREEN(TEXT("%s || GetCoolTime : %f"), *Skills[InAbilityType]->GetName(), Skills[InAbilityType]->GetCoolTime());
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

// Debug #BP on/off
void ACharacterPC::DebugActorRotation()
{
	const FRotator Rotation = GetActorRotation();
	FVector Start = GetActorLocation();
	FVector End = GetActorLocation() + Rotation.Vector() * 300;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, 0, -1);
	DrawDebugDirectionalArrow(GetWorld(),
							  Start - Rotation.Vector() * 150,
							  Start + Rotation.Vector() * 150,
							  120.f,
							  FColor::Red,
							  0,
							  -1.f,
							  0,
							  3.f);
}

//================================================================
// 줌인아웃 함수 // 변수값은 protected 이므로 에이밍, 특수스킬 뷰 변경 등에 활용가능하다.
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
void ACharacterPC::ZoomInOut(float DeltaTime)
{
	CameraBoom->TargetArmLength = FMath::FInterpTo(
		CameraBoom->TargetArmLength,
		MyTargetArmLength,
		DeltaTime,
		ZoomInterpTime);
	CameraBoom->SetRelativeLocation(FMath::VInterpTo(
		CameraBoom->GetRelativeLocation(),
		MyTargetArmLocation,
		DeltaTime,
		ZoomInterpTime));
	FollowCamera->SetRelativeLocation(FMath::VInterpTo(
		FollowCamera->GetRelativeLocation(),
		MyCameraLocation,
		DeltaTime,
		ZoomInterpTime));
	if (CameraBoom->TargetArmLength == MyTargetArmLength)
	{
		CanZoom = false; // 줌인아웃이 완료되면 함수실행중지
	}
}

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

// Base Movement
// TODO 속도함수 맹글기
void ACharacterPC::SetThisSpeed(float Speed)
{
	ThisSpeed = Speed;
}
void ACharacterPC::SetThisJogSpeed(float JogSpeed)
{
	ThisJogSpeed = JogSpeed;
}
void ACharacterPC::CalculateSpeed()
{
	// ThisSpeed = DefaultSpeed + DefaultSpeed * (ItemVar * ItemCoff + OtherItemVar * OtherItemCoff);
}

//================================================================
// Jog //W가 눌린 상태일때만 뛸 수 있음 //W 때면 jog중지
//================================================================
void ACharacterPC::Jog()
{
	if (!IsJog && IsWPressed && CanJog)
	{
		IsJog = true;
		SetZoomOutProp();
		SetInCombatFalse();
	}
	else if (IsJog)
	{
		IsJog = false;
	}
}
void ACharacterPC::WPressed()
{
	IsWPressed = true;
}
void ACharacterPC::WReleased()
{
	IsWPressed = false;
}

void ACharacterPC::SPressed()
{
	IsSPressed = true;
}

void ACharacterPC::SReleased()
{
	IsSPressed = false;
}

//================================================================
// 데미지 받는 함수
//================================================================
// TakeDamageHandle
float ACharacterPC::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	// DamageImmunity가 false 일 때 데미지계산
	if (!DamageImmunity && EventInstigator != Controller)
	{
		HandleCombatState();
		//================================================================
		// 1.데미지이벤트 판별
		//================================================================
		
		if (DamageEvent.IsOfType(FPointDamageEvent::ClassID))
		{
			UE_LOG(LogTemp, Warning, TEXT("Taken Point Damage"));
			LOG_SCREEN(TEXT("Taken Point Damage"));
			const FPointDamageEvent *PointDamageEvent = static_cast<const FPointDamageEvent *>(&DamageEvent);
			if (0 == (PointDamageEvent->HitInfo.BoneName).Compare(FName(TEXT("Head"))))
			{
				// TODO 부위별 데미지 기능 실현
				Damage *= 5;
			}
		}
		else if (DamageEvent.IsOfType(FRadialDamageEvent::ClassID))
		{
			UE_LOG(LogTemp, Warning, TEXT("Taken Radial Damage"));
			LOG_SCREEN(TEXT("Taken Radial Damage"));
			const FRadialDamageEvent *RadialDamageEvent = static_cast<const FRadialDamageEvent *>(&DamageEvent);
		}

		//================================================================
		// 2.데미지 계산(공식적용-올림내림)
		//================================================================
		// TODO 방어력, 공격효과 적용해서 데미지공식 적용하기
		// TODO 효과적용 방식 : 체력비례피해(최대or현재), 고정피해(방어구관통), 지속피해(틱뎀), 방어력감소(영구or시간), 폭발스택
		Damage = Damage * (100 / (100 + Armor));
		Damage = (int)(Damage + 0.2); // 데미지 소수점 처리 *소수점첫째자리가 0.8 이상이면 올림, 미만시 내림

		Damage = FMath::Min(Health, (int)Damage);
		_UpdateHp(Health - Damage, MaxHealth);
		Health -= Damage;
		DisplayDamage(Damage);
		
		//================================================================
		// 3.애니메이션 플레이 //bool 변수로 0.3초마다 애니메이션 실행
		//================================================================
		if (CanTakeDamageAnim)
		{
			TakeDamageAnim = true;
			GetWorldTimerManager().SetTimerForNextTick(this, &ACharacterPC::SetTakeDamageAnimFalse);
			CanTakeDamageAnim = false;
			GetWorldTimerManager().SetTimer(TakeDamageHandle, this, &ACharacterPC::SetCanTakeDamageAnimTrue, 0.3f, false);
		}

		//================================================================
		// 4.죽음구현
		//================================================================
		if (IsDead())
		{
			//LOG_SCREEN(TEXT("He Died"));
			ADpGameMode *GameMode = GetWorld()->GetAuthGameMode<ADpGameMode>();
			if (GameMode != nullptr)
			{
				GameMode->PawnKilled(this);
			}

			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision); // 캡슐콜리전 무효
			// 20초 뒤 액터 destroy // 이거 크래시남 왜인지는 몰 루?
			TWeakObjectPtr<ACharacterPC> thisPtr = this;
			GetWorld()->GetTimerManager().SetTimer(
				TakeDamageHandle, [thisPtr]()
				{
					if(thisPtr.IsValid())
						thisPtr->Destroy();
				},
				20.0f, false);

			auto DamageCauserPlayer = Cast<ACharacterPC>(DamageCauser);
			// 플레이어의 경험치를 1 올림 //TODO NPC와 구분지어서 레벨디자인 할 수 있게끔
			DamageCauserPlayer->Exp = DamageCauserPlayer->Exp + 1;
			DamageCauserPlayer->Level = UtilLevelCal::LevelCal(DamageCauserPlayer->Exp);
			DamageCauserPlayer->MaxHealth = UtilLevelCal::MaxHealthCal(DamageCauserPlayer->Level);
			LOG_SCREEN(TEXT("MAxHealth : %d Exp : %d Level : %d"), DamageCauserPlayer->MaxHealth , DamageCauserPlayer->Exp, DamageCauserPlayer->Level);
		}

		//LOG_SCREEN(TEXT("Now Health : %f"), Health);
		return Damage;
	}
	else // DamageImmunity가 true 일 때 Damage = 0
	{
		HandleCombatState();
		Damage = 0.f;
		DisplayDamage(Damage);
		
		// 애니메이션 플레이 //bool 변수로 0.3초마다 애니메이션 실행
		if (CanTakeDamageAnim)
		{
			TakeDamageAnim = true;
			GetWorldTimerManager().SetTimerForNextTick(this, &ACharacterPC::SetTakeDamageAnimFalse);
			CanTakeDamageAnim = false;
			GetWorldTimerManager().SetTimer(TakeDamageHandle, this, &ACharacterPC::SetCanTakeDamageAnimTrue, 0.3f, false);
		}
		LOG_SCREEN(TEXT("Damage Immune! || Now Health : %d"), Health);
		return Damage;
	}
}
void ACharacterPC::SetTakeDamageAnimFalse()
{
	TakeDamageAnim = false;
}
void ACharacterPC::SetCanTakeDamageAnimTrue()
{
	CanTakeDamageAnim = true;
}

//================================================================
// 전투상태 핸들링 함수 // 전투상태 돌입 5초 후, 전투상태 자동 해제. // 해제 전 갱신 시, 5초갱신.
//================================================================
void ACharacterPC::HandleCombatState()
{
	// InCombat을 true로 설정합니다.
	InCombat = true;

	// 만약 타이머가 이미 실행 중이면, 타이머를 초기화하고 5초 후에 다시 호출합니다.
	if (GetWorldTimerManager().IsTimerActive(CombatStateTHandle))
	{
		GetWorldTimerManager().ClearTimer(CombatStateTHandle);
		GetWorldTimerManager().SetTimer(CombatStateTHandle, this, &ACharacterPC::SetInCombatFalse, 5.f, false);
	}
	else
	{
		// 타이머가 실행 중이 아니면, 5초 후에 InCombat을 false로 설정합니다.
		GetWorldTimerManager().SetTimer(CombatStateTHandle, this, &ACharacterPC::SetInCombatFalse, 5.f, false);
	}
}
void ACharacterPC::SetInCombatFalse()
{
	InCombat = false;
}

bool ACharacterPC::GetCombatState()
{
	return InCombat;
}

void ACharacterPC::LevelUpEvent()
{
	GetWorldSettings()->SetTimeDilation(0.f);
}

int ACharacterPC::GetCharacterLevel()
{
	return Level;
}

float ACharacterPC::GetCharacterExpPercent()
{
	if(Level == 1)
		return (float)Exp / (float)10;
		
	return ((float)Exp - (float)UtilLevelCal::MaxExpCal(Level - 1)) / ((float)UtilLevelCal::MaxExpCal(Level) - (float)UtilLevelCal::MaxExpCal(Level - 1));
}

bool ACharacterPC::GetOtherSkillActivating(EAbilityType inType)
{
	switch(inType)
	{
	case EAbilityType::MouseLM :
		return
		( SkillActivating[EAbilityType::MouseRM]|| SkillActivating[EAbilityType::Shift]|| SkillActivating[EAbilityType::SkillQ] || SkillActivating[EAbilityType::SkillE]|| SkillActivating[EAbilityType::SkillR] );
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

// ufunction 으로 임시 anim 재생
bool ACharacterPC::IsDead() const
{
	return Health <= 0;
}

void ACharacterPC::_UpdateHp(int InCurHp, int InMaxHp)
{
	float curPercent = Health / TempMaxHealth;
	curPercent = FMath::Clamp( curPercent, 0.f, 1.f );

	float destPercent = ( float )InCurHp / ( float )InMaxHp;
	destPercent = FMath::Clamp( destPercent, 0.f, 1.f );

	float percentAmount = curPercent - destPercent;
	
	// 체력바 애니메이터
	TempPercent = curPercent;

	if( AnimatorHealthPercent.IsRunning() )
		AnimatorHealthPercent.Stop();
	
	AnimatorParam param;
	param.AnimType = EAnimType::CubicEaseOut;
	param.StartValue = curPercent;
	param.EndValue = destPercent;
	param.DurationTime = 0.6f;
	TWeakObjectPtr<ACharacterPC> thisPtr = this;
	param.DurationFunc = [ thisPtr ] ( float InValue )
	{
		if(thisPtr.IsValid())
			thisPtr->TempPercent = InValue;
	};
	param.CompleteFunc = [ thisPtr ] ( float InValue )
	{
		if(thisPtr.IsValid())
			thisPtr->TempPercent = InValue;
	};

	AnimatorHealthPercent.Start( param );
	
	// 체력바잔상 애니메이터
	TempPercentAfterImage = curPercent;

	if( AnimatorHealthPercentAfterImage.IsRunning() )
		AnimatorHealthPercentAfterImage.Stop();
	
	AnimatorParam paramAfterImage;
	paramAfterImage.AnimType = EAnimType::CubicEaseIn;
	paramAfterImage.StartValue = curPercent;
	paramAfterImage.EndValue = destPercent;
	paramAfterImage.DurationTime =
		(0.f <= percentAmount && percentAmount < 0.2f) ? 0.6f
	: (0.2f <= percentAmount && percentAmount < 0.4f) ? 0.85f
	:													1.1f;
	paramAfterImage.DurationFunc = [ thisPtr ] ( float InValue )
	{
		thisPtr->TempPercentAfterImage = InValue;
	};
	paramAfterImage.CompleteFunc = [ thisPtr ] ( float InValue )
	{
		thisPtr->TempPercentAfterImage = InValue;
	};

	AnimatorHealthPercentAfterImage.Start( paramAfterImage );
}

float ACharacterPC::GetHealthPercent()
{
	return TempPercent;
}
float ACharacterPC::GetHealthPercentAfterImage()
{
	return TempPercentAfterImage;
}

float ACharacterPC::GetSkillCoolTimePercent(EAbilityType inType)
{
	return Skills[inType]->GetCoolTimePercent();
}