// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSkill.h"
#include "../Handler/CoolTimeHandler.h"
#include "../Character/CharacterPC.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(PlayerSkill)

UPlayerSkill::UPlayerSkill() : Super()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerSkill::BeginPlay()
{
	Super::BeginPlay();

	CoolTimeHandler = new FCoolTimeHandler(this);

	OwnerCharacterPC = Cast<ACharacterPC>(OwnerCharacter);
}

void UPlayerSkill::BeginDestroy()
{
	if(CoolTimeHandler)
		delete CoolTimeHandler;
	CoolTimeHandler = nullptr;
	
	Super::BeginDestroy();
}

void UPlayerSkill::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// 스킬 사용이 취소되면 호출됩니다.
void UPlayerSkill::CancelSkill()
{
	Super::CancelSkill();
}

// =============================================================
// 능력이 사용 가능한지 확인합니다.
// 마나, 상태 이상 등 더 필요한 것들을 추후 추가할 예정입니다.
// 더 자세한 확인 필요 시 오버라이드하여 Super::를 통해 같이 호출하여 사용하시면 됩니다.
// =============================================================
bool UPlayerSkill::CanActivateAbility()
{
	return (CoolTimeHandler->GetCoolTime() <= 0.f);
}

float UPlayerSkill::GetCoolTime()
{
	return CoolTimeHandler->GetCoolTime();
}

float UPlayerSkill::GetCoolTimePercent()
{
	return CoolTimeHandler->GetCoolTime() / CoolTime;
}

void UPlayerSkill::SetOwnerCharacter(ACharacterBase* InCharacter)
{
	OwnerCharacter = InCharacter;
	OwnerCharacterPC = Cast<ACharacterPC>(InCharacter);
	OwnerController = OwnerCharacter->GetController();
}
