// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SkillBase.h"
#include "../Interface/PlayerInputInterface.h"
#include "PlayerSkill.generated.h"


class FCoolTimeHandler;
class ACharacterPC;

UCLASS(Blueprintable)
class DIESELPUNK_API UPlayerSkill : public USkillBase, public IPlayerInputInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	ACharacterPC* OwnerCharacterPC = nullptr;	// CharacterPC로 다운캐스팅 할 소유자
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MYDP_Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputTrigger> TriggerType;		// 해당 스킬이 어떤 입력 방식을 가지는지 설정합니다.
	
	FCoolTimeHandler* CoolTimeHandler;			// 쿨타임을 관리하기 위한 CoolTime Handler입니다.

public:
	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	float CoolTime = 5;							// 스킬 쿨타임 입니다람쥐.
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	float SkillPlayTime = 1;					// 스킬 발동 시간입니다. 해당 시간동안 SkillActivating이 On 됩니다.
protected:
	// 생성자
	UPlayerSkill();

	virtual void BeginPlay() override;

	virtual void BeginDestroy() override;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	
public:
	// TriggerType Getter입니다.
	FORCEINLINE const TObjectPtr<UInputTrigger>& GetTriggerType() const { return TriggerType; }
	
	// Input 상황에 따른 로직 처리 함수들입니다.
	virtual void SkillStarted() override {};
	virtual void SkillOngoing() override {};
	virtual void SkillTriggered() override {};
	virtual void SkillCompleted() override {};
	virtual void SkillCanceled() override {};

	// 스킬이 어떠한 이유로 인해 캔슬될 때 호출됩니다.
	virtual void CancelSkill() override;

	// 능력이 사용 가능한지 확인합니다.
	// 마나, 상태 이상 등 더 필요한 것들을 추후 추가할 예정입니다.
	// 더 자세한 확인 필요 시 오버라이드하여 Super::를 통해 같이 호출하여 사용하시면 됩니다.
	virtual bool CanActivateAbility();

	virtual float GetCoolTime();

	virtual float GetCoolTimePercent();
};





