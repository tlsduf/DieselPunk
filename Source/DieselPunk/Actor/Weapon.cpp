// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"

#include "../Character/CharacterPC.h"
#include "../Skill/PlayerSkill.h"
#include "Components/SkeletalMeshComponent.h"
#include "DieselPunk/Component/StatControlComponent.h"
#include "DieselPunk/Raw/BuffStatusEffect.h"


// =============================================================
// 생성자
// =============================================================
AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComp");
	SetRootComponent(Mesh);
}

// =============================================================
// BeginPlay
// =============================================================
void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	if(SkillInfo_LM != nullptr)
	{
		Skill_LM = NewObject<UPlayerSkill>(this, SkillInfo_LM);
		//Skill_LM->GetDelegateAbilityShot().AddUObject(this, &AWeapon::OnAbilityBeShot);
		Skill_LM->RegisterComponent();
		Skill_LM->InitSkill();
	}
	if(SkillInfo_RM != nullptr)
	{
		Skill_RM = NewObject<UPlayerSkill>(this, SkillInfo_RM);
		Skill_RM->RegisterComponent();
		Skill_LM->InitSkill();
	}

	AmmoLeft = MaxAmmo;
}

// =============================================================
// Tick
// =============================================================
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeapon::SetOwnerPlayer(ACharacterBase* InOwner)
{
	OwnerCharacter = InOwner;
	if(Skill_LM)
		Skill_LM->SetOwnerCharacter(InOwner);
	if(Skill_RM)
		Skill_RM->SetOwnerCharacter(InOwner);

	if(ACharacterPC* pc = Cast<ACharacterPC>(OwnerCharacter))
		pc->OnPossessWeapon(this);
}

void AWeapon::SkillStarted(const EAbilityType& InAbilityType, TWeakObjectPtr<UPlayerSkill>& OutCachedSkill)
{
	if(!OwnerCharacter)
		return;
	//이미 장전중이면 처리 못하게
	if(OwnerCharacter->GetStatControlComponent()->GetBuff(ReloadBuffName))
		return;
	
	if(AmmoLeft <= 0)
	{
		//장전 해야함.
		//장전은 플레이어에게 상태이상 버프를 넣는 방식으로 처리
		OwnerCharacter->GetStatControlComponent()->AddBuff(ReloadBuffName);
		FBuffStatusEffect* statusBuff = static_cast<FBuffStatusEffect*>(OwnerCharacter->GetStatControlComponent()->GetBuff(ReloadBuffName));
		if(!statusBuff)
			return;

		//장전 상태이상 버프가 끝난 후, AmmoLeft 충전
		TWeakObjectPtr<AWeapon> thisPtr = this;
		statusBuff->SetReleaseCallFunction([thisPtr](AActor* InActor)
		{
			if(!IsValid(InActor) || !thisPtr.IsValid())
				return;
			TArray<AActor*> childActors;
			InActor->GetAllChildActors(childActors);

			for(AActor* child : childActors)
			{
				if(child == thisPtr)
				{
					thisPtr->ReloadWeapon();
					break;
				}
			}
		});
	}
}

void AWeapon::SkillTriggered(const EAbilityType& InAbilityType, TWeakObjectPtr<UPlayerSkill>& OutCachedSkill)
{
	if(!OwnerCharacter)
		return;
	//이미 장전중이면 처리 못하게
	if(OwnerCharacter->GetStatControlComponent()->GetBuff(ReloadBuffName))
		return;
	if(AmmoLeft <= 0)
		return;
	
	switch (InAbilityType)
	{
	case EAbilityType::MouseLM:
		Skill_LM->SkillTriggered();
		OutCachedSkill = Skill_LM;
		break;
	case EAbilityType::MouseRM:
		Skill_RM->SkillTriggered();
		OutCachedSkill = Skill_RM;
		break;
	default:
		break;
	}
}

bool AWeapon::CanActivateAbility(const EAbilityType& InAbilityType)
{
	switch (InAbilityType)
	{
	case EAbilityType::MouseLM:
		if(Skill_LM)
			return Skill_LM->CanActivateAbility();
		return false;
	case EAbilityType::MouseRM:
		if(Skill_RM)
			return Skill_RM->CanActivateAbility();
		return false;
	default:
		return false;
	}
}

void AWeapon::ReloadWeapon()
{
	AmmoLeft = MaxAmmo;
	LOG_SCREEN(FColor::Green, TEXT("Reload! Ammo Left: %d"), AmmoLeft);
}

void AWeapon::OnAbilityBeShot()
{
	--AmmoLeft;
	LOG_SCREEN(FColor::White, TEXT("Shot! Ammo Left: %d"), AmmoLeft);
}
