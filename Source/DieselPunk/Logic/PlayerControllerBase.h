// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <InputActionValue.h>
#include <GameFramework/PlayerController.h>
#include "PlayerControllerBase.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;
class UInputAction;
class UInputMappingContext;
struct FInputActionInstance;
enum class EAbilityType : uint8;

UCLASS()
class DIESELPUNK_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

private:
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext *MappingContext;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction *MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction *LookAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction *JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction *InputC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction *InputW;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction *InputS;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction *MouseWheelUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction *MouseWheelDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction *InputF;
	
	// 6개의 스킬 InputAction // 순서대로 LM, RM, LShift, Q, E, R
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TMap<EAbilityType, TObjectPtr<UInputAction>> SkillInputActions;
	
protected:
	APlayerControllerBase();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn *InPawn) override;

private:
	void Move(const FInputActionValue &Value);
	void Look(const FInputActionValue &Value);

	void Jump();
	void StopJumping();

	void ToggleJog();
	void WPressed();
	void WReleased();
	void SPressed();
	void SReleased();

	void SetZoomInProp();
	void SetZoomOutProp();

	void Interaction();

	// InputType에 맞춰 MappingContext을 적용하는 함수입니다.
	UFUNCTION()
	void SetMappingContextByInputType();

	// 입력된 ActionInput의 이름을 비교하여 무슨 능력인지 (Key)를 알아 내는 함수입니다.
	const EAbilityType GetAbilityKeyFromAction(const FInputActionInstance& InInstance) const;
	
	// 스킬 관련 바인딩
	void OnInputSkillStarted(const FInputActionInstance &InInstance);
	void OnInputSkillOngoing(const FInputActionInstance &InInstance);
	void OnInputSkillTriggered(const FInputActionInstance &InInstance);
	void OnInputSkillCompleted(const FInputActionInstance &InInstance);
	void OnInputSkillCanceled(const FInputActionInstance &InInstance);

public:
	void SetPlayerEnabledState(bool bPlayerEnabled);

private:
	UUserWidget *HUD;
	UUserWidget *Menu;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> UIMenuClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;
};
