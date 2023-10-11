// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CharacterBase.h"
#include "InputActionValue.h"
#include "DieselPunk/Skill/SkillManager.h"
#include "CharacterPC.generated.h"

class USkillBase;
enum class EAbilityType : uint8;

UCLASS(config = Game)
class ACharacterPC : public ACharacterBase
{
	GENERATED_BODY()
	
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent *CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent *FollowCamera;


public:
	// 스킬을 할당받기 위한 배열입니다. (BP에서도 받을 수 있도록 TSubClassOf로 하였습니다)
	UPROPERTY(EditAnywhere, Category = Skill)
	TMap<EAbilityType, TSubclassOf<USkillBase>> SkillInfos;

	// 런타임에 인스턴스화된 스킬들을 담는 배열입니다. (실제로 이 배열에 담긴 스킬들을 호출)
	UPROPERTY()
	TMap<EAbilityType, TObjectPtr<USkillBase>> Skills;

public:
	ACharacterPC();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
	
	// 런타임에 스킬들을 인스턴스화 시킵니다. PlayerController에서 Pose시 호출합니다.
	void InitSkills();

	// 런타임에 인스턴스화 된 Skills Getter입니다.
	FORCEINLINE const TMap<EAbilityType, TObjectPtr<USkillBase>> &GetSkills() const { return Skills; }

	// PlayerController에서 호출될 스킬 발동 함수들입니다.
	void SkillStarted(const EAbilityType InAbilityType);
	void SkillOngoing(const EAbilityType InAbilityType);
	void SkillTriggered(const EAbilityType InAbilityType);
	void SkillCompleted(const EAbilityType InAbilityType);
	void SkillCanceled(const EAbilityType InAbilityType);

	SkillManager PCSkillManager;
public:
	/** Called for movement input */
	void Move(const FInputActionValue &Value);

	/** Called for looking input */
	void Look(const FInputActionValue &Value);

	// !MyCode------------------------------------------------------
protected:
	// 로테이션 레이트 RotationRate
	float GetRotationRateVelocity();
	
	// Debug
	void DebugActorRotation();

public:
	// Zoom 줌 관련 함수입니다.
	void SetZoomInProp();
	void SetZoomOutProp();
	// Tick에서 작동합니다. 애니메이션 담당
	void ZoomInOut(float DeltaTime);
	// 달릴 때의 카메라 프롭을 설정합니다.
	void SetRunZoomOutProp();

	// 조건에따라 bool IsJog를 설정합니다. Tick에서 IsJog의 상태에 따라 캐릭터의 이동속도를 설정합니다.
	void Jog();

	// 캐릭터 이동속도 설정함수
	void SetThisSpeed(float Speed);
	void SetThisJogSpeed(float JogSpeed);
	
	// Pawn 회전 함수 // 전투상태일 때만 자동회전합니다. Tick에서 구현
	void RotatePawn(float DeltaTime);

	// 데미지 받는 함수
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	// 데미지를 받을 때, 데미지 받는 애니메이션 출력을 위한 함수. TakeDamage에서 호출합니다. ABP에서 활용됩니다.
	// [TODO] 구조상 타이머를 쓰고있는데, 타이머를 쓰지말라는 조언이 있어서 구조변경 요함.
	void SetTakeDamageAnimFalse();
	void SetCanTakeDamageAnimTrue();

	// 데미지 받는 애니메이션 출력을 위한 ABP에서 직접적으로 활용되는 변수입니다.
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool TakeDamageAnim = false;

	bool CanTakeDamageAnim = true;
	
	FTimerHandle TakeDamageHandle;

	
	// 전투상태 핸들링 함수 // 전투상태 돌입 5초 후, 전투상태 자동 해제. // 해제 전 갱신 시, 5초갱신.
	void HandleCombatState();
	void SetInCombatFalse();

	// * 전투state
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool InCombat = false;

	FTimerHandle CombatStateTHandle;
	
	//=================================================================================
	// UI 에서 활용될 변수 및 함수
	//=================================================================================
	// ABP에서 Die 애니메이션 재생
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	// 체력 퍼센테이지 반환 애니메이팅
	void _UpdateHp(int InCurHp, int InMaxHp);
	float TempPercent;
	float TempPercentAfterImage;

	// 체력 퍼센트를 반환합니다.
	UFUNCTION(BlueprintPure)
	float GetHealthPercent();

	// 체력 퍼센트를 반환합니다.
	UFUNCTION(BlueprintPure)
	float GetHealthPercentAfterImage();

	// 스킬 쿨타임을 반환합니다. 
	UFUNCTION(BlueprintPure)
	float GetSkillCoolTimePercent(EAbilityType inType);
	//=================================================================================


	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent *GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent *GetFollowCamera() const { return FollowCamera; }

	// !MyCode------------------------------------------------------
public:
	// 레벨을 구현하기위한 변수
	int Exp;
	int Level;
	int TempLevel;

	// Level 이 올라갔을때, 이벤트를 발동시킵니다.
	void LevelUpEvent();

	// HUD에서 받을 Level
	UFUNCTION(BlueprintPure)
	int GetCharacterLevel();
	
	// HUD에서 받을 Exp 퍼센트
	UFUNCTION(BlueprintPure)
	float GetCharacterExpPercent();

	// 각 스킬이 작동중인지 확인하는 티맵. Key(EAbilityType)의 값이 1이면 작동중입니다.
	TMap<EAbilityType, bool> SkillActivating;

	// 스킬을 실행하려할 때, 다른 스킬이 작동중인지 확인하는 함수. 다른 스킬이 작동중이면 1 반환
	bool GetOtherSkillActivating(EAbilityType inType);
	
	// * 디버그on/off
	UPROPERTY(EditDefaultsOnly, Category = "Debug")
	bool DebugOnOff = 0;

	// * 줌인아웃
	bool IsZoomed = false;
	bool CanZoom = true;
	float ZoomInterpTime = 6;

	UPROPERTY()
	float MyTargetArmLength = 400.0f;

	UPROPERTY()
	FVector MyTargetArmLocation = FVector(0, 0, 45);

	UPROPERTY()
	FVector MyCameraLocation = FVector(0, 0, 70);

	// 카메라를 조종 가능한지
	bool CanCameraControl = true;

	// * Pawn Rotate
	bool IsRotate = false;
	bool CanRotate = false;

	//=================================================================================
	//	이동관련 변수들
	// TODO ThisSpeed = DefaultSpeed + DefaultSpeed * 아이템효과
	//=================================================================================
	UPROPERTY(EditAnywhere, Category = "BaseMovement")
	float ThisSpeed = 600.f;

	UPROPERTY(EditAnywhere, Category = "BaseMovement")
	float ThisJogSpeed = 1200.f;

	// * w눌린상태>달리기가능   달리는상태>w때기>달리기종료
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool IsJog = false;

	bool CanJog = true;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool IsWPressed = false;

	bool IsSPressed = false;

	// * 연속점프횟수 bp에서 간접적으로 건드리기
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseMovement", meta = (AllowPrivateAccess = "true"))
	int32 ThisJumpMaxCount = 1;


	
	//=================================================================================
	// * 체력 및 방어력 및 특수
	//=================================================================================
	// 최대체력
	UPROPERTY(EditDefaultsOnly, Category = "Defensive")
	int MaxHealth = 100;

	// 현재체력
	UPROPERTY(VisibleAnywhere, Category = "Defensive")
	int Health;

	// 임의체력 (체력 애니메이팅에 활용되었음)
	float TempMaxHealth;

	// 방어력 변수. 아직 활용X. 기획 기다려야됨
	UPROPERTY(EditDefaultsOnly, Category = "Defensive")
	int Armor = 0;

	// DamageImmunity 가 True 면 데미지를 안 입게 했습니다. TakeDamage 함수에서 활용합니다.
	UPROPERTY(EditAnywhere, Category = "Defensive")
	bool DamageImmunity = false;

	// * 공격관련 변수
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "CombatProp")
	float FireRate = 0.25f;
	// !------------------------------------------------------------

private:
	// 레일 타는 거 임시구현!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	virtual void Landed(const FHitResult& Hit) override;
	
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float MoveForward = 0;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float MoveRight = 0;

public:
	DECLARE_DYNAMIC_DELEGATE(FDelegateInteractTask);

	//상호작용 액터용 댈리게이트, 컨트롤러에서 입력 시 Excute 
	FDelegateInteractTask DelegateInteractTask;
};
