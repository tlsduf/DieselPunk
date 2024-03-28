// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include <Components/StaticMeshComponent.h>

#include "../Character/CharacterPC.h"
#include "../Skill/PlayerSkill.h"
#include "Components/SkeletalMeshComponent.h"


// =============================================================
// 생성자
// =============================================================
AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(DefaultSceneRoot);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	Mesh->SetupAttachment(DefaultSceneRoot);
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
		Skill_LM->RegisterComponent();
		Skill_LM->InitSkill();
	}
	if(SkillInfo_RM != nullptr)
	{
		Skill_RM = NewObject<UPlayerSkill>(this, SkillInfo_RM);
		Skill_RM->RegisterComponent();
		Skill_LM->InitSkill();
	}

	if(OwnerCharacter == nullptr)
		return;

	if(ACharacterPC* pc = Cast<ACharacterPC>(OwnerCharacter))
	{
		pc->OnPossessWeapon(this);
		
		AttachToComponent(pc->GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, false),
			FName(TEXT("WeaponSocket")));
	}
}

// =============================================================
// Tick
// =============================================================
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
