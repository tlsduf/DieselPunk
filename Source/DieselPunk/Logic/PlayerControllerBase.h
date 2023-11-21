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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext *MappingContext;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *LookAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *InputC;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *MouseWheelUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *MouseWheelDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *InputF;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *InputK;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *InputM;
	
	// 6개의 스킬 InputAction // LM, RM, LShift, Q, E, R
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
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

	void StartJog();
	void StopJog();

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
	UPROPERTY()
	UUserWidget* Menu;
	UPROPERTY()
	UUserWidget* HUD;
	UPROPERTY()
	UUserWidget* SkillUpgradeUI;
	UPROPERTY()
    UUserWidget* EndUI;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> UIMenuClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> HUDClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> SkillUpgradeUIClass;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> EndUIClass;

public:
	// 스킬 업그레이드를 하기 위한 위젯 표시/비표시 함수 (임시로 작성된 것이며 추후 재작업 예정)

	// 스킬 업그레이드 UI를 화면에 띄운다
	void SkillUpgradeEventStart();
	// 스킬 업그레이드 UI를 화면에서 제거한다.
	void SkillUpgradeEventEnd();

	
	// (임시) 블루프린트에서 활용할 UI컨트롤을 위한 시간, 컨트롤 제어
	UFUNCTION(BlueprintCallable)
	void SetUIControlOnForStartMenu();
	
	UFUNCTION(BlueprintCallable)
	void SetUIControlOn();

	UFUNCTION(BlueprintCallable)
	void SetUIControlOff();

	// (임시) 게임이 종료되었을 때 띄울 UI 작업 전개
	void SetEndUI();
};
