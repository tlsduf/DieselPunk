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
class FCard;
class UDeck;
class UHand;
class UUserWidgetBase;

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
	
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
    UInputAction *InputB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	UInputAction *InputDeckInterface;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	TArray<UInputAction*> InputUseCard;
	
	// 6개의 스킬 InputAction // LM, RM, LShift, Q, E, R
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	TMap<EAbilityType, TObjectPtr<UInputAction>> SkillInputActions;

private:
	UPROPERTY()
	UUserWidget* StartMenu;

	UPROPERTY(EditAnywhere, Category="MYDP_UI")
	TSubclassOf<UUserWidget> StartMenuClass;

	UPROPERTY()
	UDeck* DeckInterface;
	
	UPROPERTY(EditAnywhere, Category="MYDP_UI")
	TSubclassOf<UUserWidgetBase> DeckInterfaceClass;
	
	UPROPERTY()
	UUserWidgetBase* HUD;

	UPROPERTY(EditAnywhere, Category="MYDP_UI")
	TSubclassOf<UUserWidgetBase> HUDClass;

	UPROPERTY()
	UHand* Hand;

	int32 HUDId;
	
	bool DeckInterfaceOpen = false;

	int32 UseCardNum = -1;

	//카드가 액티베이트 되어있는 동안 카드를 변경하지 못합니다.
	bool IsCardActivate = false;

	TArray<int32> PreInputHandle;
	
protected:
	APlayerControllerBase();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn *InPawn) override;

private:

	void Jump();
	void StopJumping();

	void StartJog();
	void StopJog();

	void SetZoomInProp();
	void SetZoomOutProp();

	void WheelUpCardSelect();
	void WheelDownCardSelect();

	void Interaction();
	
	void Move(const FInputActionValue &Value);
	void Look(const FInputActionValue &Value);

	void WaveStart();

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

	//덱 인터페이스 켜기/끄기
	void OpenCloseDeckInterface();
	
	//카드 사용 준비
	void UseCard(int32 InCardIndex);
	void UnUseCard();
public:

	//필터 변경 시 블루프린트 호출
	UFUNCTION(BlueprintCallable, Category = "MYDP_Function")
	void CallBlueprint_ChangeFilter(ECardFilterType InFilterType);

	//정렬 변경 시 블루프린트 호출
	UFUNCTION(BlueprintCallable, Category = "MYDP_Function")
	void CallBlueprint_ChangeSort(ECardSortType InSortType);
	
	// (임시) 블루프린트에서 활용할 UI컨트롤을 위한 시간, 컨트롤 제어
	UFUNCTION(BlueprintCallable)
	void SetUIControlOn();

	UFUNCTION(BlueprintCallable)
	void SetUIControlOff();

	//카드를 Activate한 후 처리를 담당합니다.
	int32 PostActivateCard();

	//카드를 Cancel한 후 처리를 담당합니다.
	int32 PostCancelCard();

	//카드를 Complete한 후 처리를 담당합니다.
	int32 PostCompleteCard();

	//설치물을 시계방향으로 90도 회전합니다.
	void RotateInstallationCW();

	//설치물을 반시계방향으로 90도 회전합니다.
	void RotateInstallationCCW();

	//드로우 한 후 카드 정보를 갱신합니다.
	void RenewHand();

	//패에 카드를 등록합니다.
	void RegisterHands(TArray<FCard*> InCard);

	//HUD Id를 반환합니다.
	int32 GetHUDId(){return HUDId;}
};
