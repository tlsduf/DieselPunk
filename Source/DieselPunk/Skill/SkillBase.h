// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


// =========================================
/*
 * 스킬 템플릿 클래스입니다.
 * 
 * * 상속구조
 * 플레이어 스킬  SkillBase - PlayerSkill - 스킬클래스
 * 몬스터 스킬    SkillBase - 스킬클래스
 *
 * * UPlayerSkill
 * UPlayerSkill 은 TriggerType, CoolTimeHandler, 
*/ 
// =========================================


#include <Components/ActorComponent.h>
#include "SkillBase.generated.h"

class UInputTrigger;
class ACharacterBase;


UCLASS(Blueprintable)
class DIESELPUNK_API USkillBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	ACharacterBase* OwnerCharacter = nullptr;	// 소유자
	
	UPROPERTY()
	AController* OwnerController = nullptr;		// 소유 컨트롤러

	float CharacterStatAtk = 10.f;				// 캐릭터 스텟 공격력
	float Damage = 10;							// 최종 공격력

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	float AtkCoefficient = 1.f;					// 데미지 계수

	
	
protected:
	// Sets default values for this component's properties
	USkillBase();
	
	// Called when the game starts
	virtual void BeginPlay() override;

	// 소멸자 용도로 쓸 BeginDestroy
	virtual void BeginDestroy() override;

	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	// 몬스터클래스가 오버라이드하여 사용합니다.
	virtual void AbilityStart(AActor* inTarget);
	
	// 스킬이 어떠한 이유로 인해 캔슬될 때 호출됩니다.
	virtual void CancelSkill(){};

	// ActorComponent의 BeginPlay가 Character의 BeginPlay 보다 먼저 호출됨
	// CharacterBase의 Stat.Initialize 후 호출
	void InitSkill();
	
};
