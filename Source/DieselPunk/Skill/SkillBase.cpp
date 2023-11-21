// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillBase.h"
#include "../Character/CharacterBase.h"


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

void USkillBase::AbilityStart()
{
	if(OwnerCharacter == nullptr)
		return;
}

