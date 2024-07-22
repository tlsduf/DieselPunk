// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterNPC.h"
#include "CharacterMonster.generated.h"

UCLASS()
class DIESELPUNK_API ACharacterMonster : public ACharacterNPC
{
	GENERATED_BODY()

protected:
	ACharacterMonster();
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
};
