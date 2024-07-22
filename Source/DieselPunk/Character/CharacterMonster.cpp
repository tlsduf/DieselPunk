// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterMonster.h"


// =============================================================
// 생성자
// =============================================================
ACharacterMonster::ACharacterMonster()
{
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterMonster::BeginPlay()
{
	Super::BeginPlay();
	CharacterType = ECharacterType::Monster;
	
}

// =============================================================
// Tick
// =============================================================
void ACharacterMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// =============================================================
// SetupPlayerInputComponent
// =============================================================
void ACharacterMonster::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
}