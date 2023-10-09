// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterPC.h"
#include "CharacterNPC.generated.h"

class UPlayerSkill;
class UEnemyStatusUI;

UCLASS()
class DIESELPUNK_API ACharacterNPC : public ACharacterPC
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "skills", meta = (AllowPrivateAccess = "true"))
	UPlayerSkill *MeleeAttack;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "skills", meta = (AllowPrivateAccess = "true"))
	UPlayerSkill *ProjectileAttack;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	UParticleSystem *GrenadeMuzzleEffect;

	int8 SoldierStack = 0;

	UPROPERTY()
	TWeakObjectPtr< UEnemyStatusUI > EnemyStatusUI; // 상태 UI 포인터

	FTimerHandle EnemyStatusUISetHiddenInGameTHandle;
	
	ACharacterNPC();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	// TakeDamageHandle
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	//void SetTimerWithDelegate(FTimerHandle& TimerHandle, TBaseDelegate<void> ObjectDelegate, float Time, bool bLoop);

	void EnemyStatusUISetHiddenInGame();

public:
	// 상태 UI 위젯을 생성한다.
	virtual void CreateStatusUI() override;
	
	float DoMeleeAttack();
	void TempDoMeleeAttack();
	void DoProjectileAttack();
};
