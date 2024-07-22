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
public:
	virtual void SetTarget() override;
	
	// '몬스터'의 Target을 설정합니다. // Tcik , 조건
	void UpdateEnemyTarget();
	
	// 조건이 맞다면 '몬스터'의 타겟을 플레이어로 설정합니다.
	bool bPlayerTargeting();
	
	// 몬스터와 목표의 거리에 따른 조건 설정 // BT 활용
	void SetInRange();
};
