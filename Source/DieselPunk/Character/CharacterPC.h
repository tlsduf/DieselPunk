// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CharacterBase.h"
#include "InputActionValue.h"
#include "DieselPunk/Skill/SkillManager.h"
#include "CharacterPC.generated.h"

class UPlayerSkill;
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
	/////////////////////////////////////////////////////////////////////
	// for movement //
	
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool IsJog = false;				// w눌린상태>달리기가능   달리는상태>w때기>달리기종료

	bool CanJog = true;				// Jog 가능여부
	
	/////////////////////////////////////////////////////////////////////
	// for viewport //
	
	int32 TempLevel;						// 레벨정보 담아두고 Level이 변화될 때 활용.
	
	bool IsZoomed = false;					// 현재 줌인 상태인지
	bool CanZoom = true;					// 현재 줌을 할 수 있는 상태인지 (전투상태면 줌 못함)
	float ZoomInterpTime = 6;				// InterpTime
	
	float MyTargetArmLength = 400.0f;								// Default 카메라 뷰 Set / Zoomed : 250	   / Run : 600
	FVector MyTargetArmLocation = FVector(0, 0, 55);		// Default 카메라 뷰 Set / Zoomed : (0,0,0) / Run : (0,0,55)
	FVector MyCameraLocation = FVector(0, 0, 55);		// Default 카메라 뷰 Set / Zoomed : (0,0,0) / Run : (0,0,55)
	
	bool CanCameraControl = true;			// 카메라 조종 가능여부
	
	/////////////////////////////////////////////////////////////////////
	// for Skill //
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	TMap<EAbilityType, TSubclassOf<UPlayerSkill>> SkillInfos;		// 스킬을 할당받기 위한 배열입니다. (BP에서도 받을 수 있도록 TSubClassOf로 하였습니다)
	
	UPROPERTY()
	TMap<EAbilityType, TObjectPtr<UPlayerSkill>> Skills;			// 런타임에 인스턴스화된 스킬들을 담는 배열입니다. (실제로 이 배열에 담긴 스킬들을 호출)
	
	TMap<EAbilityType, bool> SkillActivating;					// 각 스킬이 작동중인지 확인하는 티맵. Key(EAbilityType)의 값이 1이면 작동중입니다.
	SkillManager PCSkillManager;								// 스킬 특성 업그레이드 지원 매니저
	
private:
	
	/////////////////////////////////////////////////////////////////////
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float MoveForward = 0;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float MoveRight = 0;

public:
	DECLARE_DYNAMIC_DELEGATE(FDelegateInteractTask);

	//상호작용 액터용 댈리게이트, 컨트롤러에서 입력 시 Execute 
	FDelegateInteractTask DelegateInteractTask;
	
public:
	ACharacterPC();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
	
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent *GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent *GetFollowCamera() const { return FollowCamera; }

	
	/////////////////////////////////////////////////////////////////////
	// for movement //
	
	/** Called for movement input */
	void Move(const FInputActionValue &Value);

	/** Called for looking input */
	void Look(const FInputActionValue &Value);
	
	virtual void Jump() override;

	// 조건에따라 bool IsJog를 설정합니다. Tick에서 IsJog의 상태에 따라 캐릭터의 이동속도를 설정합니다.
	void StartJog();
	void StopJog();
	
	// Pawn 회전 함수 // 전투상태일 때만 자동회전합니다. Tick에서 구현
	void RotatePawn(float DeltaTime);
	

	/////////////////////////////////////////////////////////////////////
	// for viewport //
	
	// Zoom 줌 관련 함수입니다.
	void SetZoomInProp();
	void SetZoomOutProp();
	// 달릴 때의 카메라 프롭을 설정합니다.
	void SetRunZoomOutProp();
	// Tick에서 작동합니다. 애니메이션 담당
	void ZoomInOut(float DeltaTime);

	
	/////////////////////////////////////////////////////////////////////
	// for Skill //
	
	// 런타임에 스킬들을 인스턴스화 시킵니다. PlayerController에서 Pose시 호출합니다.
	void InitSkills();

	// 런타임에 인스턴스화 된 Skills Getter입니다.
	FORCEINLINE const TMap<EAbilityType, TObjectPtr<UPlayerSkill>> &GetSkills() const { return Skills; }

	// PlayerController에서 호출될 스킬 발동 함수들입니다.
	void SkillStarted(const EAbilityType InAbilityType);
	void SkillOngoing(const EAbilityType InAbilityType);
	void SkillTriggered(const EAbilityType InAbilityType);
	void SkillCompleted(const EAbilityType InAbilityType);
	void SkillCanceled(const EAbilityType InAbilityType);

	// 스킬을 실행할 때, 다른 스킬이 작동중인지 확인하는 함수. 다른 스킬이 작동중이면 1 반환
	bool GetOtherSkillActivating(EAbilityType inType);

	// 스킬 쿨타임을 반환합니다. 
	UFUNCTION(BlueprintPure)
	float GetSkillCoolTimePercent(EAbilityType inType);
	
	// Level 이 올라갔을때, 이벤트를 발동시킵니다.
	void LevelUpEvent();
};
