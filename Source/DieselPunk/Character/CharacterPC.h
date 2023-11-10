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
	
	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent *GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent *GetFollowCamera() const { return FollowCamera; }
	
public:
	// Zoom 줌 관련 함수입니다.
	void SetZoomInProp();
	void SetZoomOutProp();
	// Tick에서 작동합니다. 애니메이션 담당
	void ZoomInOut(float DeltaTime);
	// 달릴 때의 카메라 프롭을 설정합니다.
	void SetRunZoomOutProp();

	// 조건에따라 bool IsJog를 설정합니다. Tick에서 IsJog의 상태에 따라 캐릭터의 이동속도를 설정합니다.
	void StartJog();
	void StopJog();

	/** 
	* Make the character jump on the next update.	 
	* If you want your character to jump according to the time that the jump key is held,
	* then you can set JumpMaxHoldTime to some non-zero value. Make sure in this case to
	* call StopJumping() when you want the jump's z-velocity to stop being applied (such 
	* as on a button up event), otherwise the character will carry on receiving the 
	* velocity until JumpKeyHoldTime reaches JumpMaxHoldTime.
	*/
	virtual void Jump() override;
	
	// Pawn 회전 함수 // 전투상태일 때만 자동회전합니다. Tick에서 구현
	void RotatePawn(float DeltaTime);
	
	// 스킬 쿨타임을 반환합니다. 
	UFUNCTION(BlueprintPure)
	float GetSkillCoolTimePercent(EAbilityType inType);

	// 각 스킬이 작동중인지 확인하는 티맵. Key(EAbilityType)의 값이 1이면 작동중입니다.
	TMap<EAbilityType, bool> SkillActivating;

	// 스킬을 실행하려할 때, 다른 스킬이 작동중인지 확인하는 함수. 다른 스킬이 작동중이면 1 반환
	bool GetOtherSkillActivating(EAbilityType inType);

public:
	// 레벨정보 담아두고 Level이 변화될 때 활용.
	int32 TempLevel;
	
	// Level 이 올라갔을때, 이벤트를 발동시킵니다.
	void LevelUpEvent();

	// * 줌인아웃
	bool IsZoomed = false;
	bool CanZoom = true;
	float ZoomInterpTime = 6;
	
	float MyTargetArmLength = 400.0f;
	FVector MyTargetArmLocation = FVector(0, 0, 45);
	FVector MyCameraLocation = FVector(0, 0, 70);

	// 카메라를 조종 가능한지
	bool CanCameraControl = true;

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
