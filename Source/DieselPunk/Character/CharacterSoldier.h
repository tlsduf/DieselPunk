// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterPC.h"
#include "CharacterSoldier.generated.h"

/**
 *
 */
UCLASS(config = Game)
class DIESELPUNK_API ACharacterSoldier : public ACharacterPC
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
	bool DrawERange = false;

};
