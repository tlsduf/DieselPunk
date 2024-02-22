// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillActor.h"
#include "../Character/CharacterBase.h"


// =============================================================
// 생성자
// =============================================================
ASkillActor::ASkillActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

// =============================================================
// BeginPlay
// =============================================================
void ASkillActor::BeginPlay()
{
	Super::BeginPlay();

	if(GetOwner() != nullptr)
	{
		OwnerCharacter = Cast<ACharacterBase>(GetOwner());
		OwnerController = OwnerCharacter->GetController();
	}
}

// =============================================================
// Tick
// =============================================================
void ASkillActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 설정한 OffsetTransform만큼 이동하여 초기 위치를 설정합니다.
void ASkillActor::InitTransformOffset()
{
	if(FixOwnerPosition && OwnerCharacter)
		SetActorLocation(OwnerCharacter->GetActorLocation());
	AddActorLocalTransform(OffsetTransform);
}
