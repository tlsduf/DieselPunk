// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillBase.h"
#include "../Character/CharacterBase.h"
#include "Tests/AutomationTestSettings.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(SkillBase)

// Sets default values for this component's properties
USkillBase::USkillBase()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void USkillBase::BeginPlay()
{
	Super::BeginPlay();

	if(GetOwner() != nullptr)
	{
		OwnerCharacter = Cast<ACharacterBase>(GetOwner());
		OwnerController = OwnerCharacter->GetController();
	}
}

void USkillBase::BeginDestroy()
{
	Super::BeginDestroy();
}

// Called every frame
void USkillBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// 몬스터클래스가 오버라이드하여 사용합니다.
void USkillBase::AbilityStart(AActor* inTarget)
{
	if(inTarget == nullptr)
		return;
}

// CharacterBase의 Stat.Initialize 후 호출
void USkillBase::InitSkill()
{
	if(OwnerCharacter)
		CharacterStatAtk = static_cast<float>(OwnerCharacter->GetStat().GetStat(ECharacterStatType::Atk));
	Damage = CharacterStatAtk * AtkCoefficient;
}

