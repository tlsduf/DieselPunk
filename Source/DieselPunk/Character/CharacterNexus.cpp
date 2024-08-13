// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNexus.h"
#include "DieselPunk/Manager/ObjectManager.h"


// =============================================================
// 생성자
// =============================================================
ACharacterNexus::ACharacterNexus()
{
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterNexus::BeginPlay()
{
	Super::BeginPlay();
	CharacterType = ECharacterType::Nexus;

	FObjectManager::GetInstance()->AddActor(this);
}

// =============================================================
// Tick
// =============================================================
void ACharacterNexus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}