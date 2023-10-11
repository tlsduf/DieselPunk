// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillBase.h"
#include "../Handler/CoolTimeHandler.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(SkillBase)

// Sets default values for this component's properties
USkillBase::USkillBase()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void USkillBase::BeginPlay()
{
	Super::BeginPlay();
	
	CoolTimeHandler = new FCoolTimeHandler(this);
}

void USkillBase::BeginDestroy()
{
	if(CoolTimeHandler)
		delete CoolTimeHandler;
	CoolTimeHandler = nullptr;
	
	Super::BeginDestroy();
}

// Called every frame
void USkillBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// =============================================================
// 능력이 사용 가능한지 확인합니다.
// 마나, 상태 이상 등 더 필요한 것들을 추후 추가할 예정입니다.
// 더 자세한 확인 필요 시 오버라이드하여 Super::를 통해 같이 호출하여 사용하시면 됩니다.
// =============================================================
bool USkillBase::CanActivateAbility()
{
	return (CoolTimeHandler->GetCoolTime() <= 0.f);
}

float USkillBase::GetCoolTime()
{
	return CoolTimeHandler->GetCoolTime();
}

float USkillBase::GetCoolTimePercent()
{
	return CoolTimeHandler->GetCoolTime() / CoolTime;
}
