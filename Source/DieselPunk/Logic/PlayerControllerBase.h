// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <InputActionValue.h>
#include <GameFramework/PlayerController.h>
#include "PlayerControllerBase.generated.h"

class UInputAction;
class UInputMappingContext;
struct FInputActionInstance;
enum class EAbilityType : uint8;
class ACharacterPC;

UCLASS()
class DIESELPUNK_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

	// 빙의 된 플레이어 캐릭터
	TWeakObjectPtr<ACharacterPC> PC;

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
	const EAbilityType GetAbilityKeyFromAction(const FInputActionInstance& inInstance) const;
	
	// 스킬 관련 바인딩
	void OnInputSkillStarted(const FInputActionInstance &inInstance);
	void OnInputSkillOngoing(const FInputActionInstance &inInstance);
	void OnInputSkillTriggered(const FInputActionInstance &inInstance);
	void OnInputSkillCompleted(const FInputActionInstance &inInstance);
	void OnInputSkillCanceled(const FInputActionInstance &inInstance);

private:
	UPROPERTY()
	UUserWidget* StartMenu;

	UPROPERTY(EditAnywhere, Category="MYDP_UI")
	TSubclassOf<UUserWidget> StartMenuClass;
	
	UPROPERTY()
	UUserWidget* HUD;

	UPROPERTY(EditAnywhere, Category="MYDP_UI")
	TSubclassOf<UUserWidget> HUDClass;

public:
	
	// (임시) 블루프린트에서 활용할 UI컨트롤을 위한 시간, 컨트롤 제어
	UFUNCTION(BlueprintCallable)
	void SetUIControlOn();

	UFUNCTION(BlueprintCallable)
	void SetUIControlOff();
};
