// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillBase.h"
#include "../Character/CharacterBase.h"
#include "../Actor/Weapon.h"
#include "../Animation/DPAnimInstance.h"


#include <Components/SkeletalMeshComponent.h>
#include "Tests/AutomationTestSettings.h"


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

	if(GetOwner() != nullptr)
	{
		if(ACharacterBase* charBase = Cast<ACharacterBase>(GetOwner()))
		{
			OwnerCharacter = charBase;
			OwnerController = OwnerCharacter->GetController();
		}
		if(AWeapon* weapon = Cast<AWeapon>(GetOwner()))
		{
			OwnerCharacter = weapon->GetOwnerPlayer();
			if(OwnerCharacter)
				OwnerController = OwnerCharacter->GetController();
		}
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
	CoolDownDelta = CoolDownDelta - DeltaTime < 0.f ? 0.f : CoolDownDelta - DeltaTime;
}

void USkillBase::AbilityStart(AActor* InTarget)
{
}

void USkillBase::AbilityShot(AActor* InTarget)
{
	CoolDownDelta = CoolDown;
}

// CharacterBase의 Stat.Initialize 후 호출
void USkillBase::InitSkill()
{
	if(OwnerCharacter)
		CharacterStatAtk = static_cast<float>(OwnerCharacter->GetStat(ECharacterStatType::Atk));
	Damage = CharacterStatAtk * AtkCoefficient;
}

bool USkillBase::IsUseableSkill(const TWeakObjectPtr<AActor>& InTarget)
{
	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(OwnerCharacter->GetMesh()->GetAnimInstance()))
	{
		float distance = FVector::Distance(InTarget->GetActorLocation(), OwnerCharacter->GetActorLocation());
		return distance <= MaxRange && animInst->GetAttackSign() == EAbilityType::None && CoolDownDelta <= 0.f;
	}
	
	return false;	
}

