// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "CharacterNPC.h"
#include "CharacterNexus.generated.h"

class UHousingActorComponent;
class USkillBase;
class UEnemyStatusUI;
class UNPCAttack;

UCLASS()
class DIESELPUNK_API ACharacterNexus : public ACharacterNPC
{
	GENERATED_BODY()
	
public:
	ACharacterNexus();
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
};
