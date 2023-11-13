// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterPC.h"
#include "CharacterNPC.generated.h"

class UHousingActorComponent;
class UPlayerSkill;
class UEnemyStatusUI;

UCLASS()
class DIESELPUNK_API ACharacterNPC : public ACharacterBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadwrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretTopMesh;
	
	/////////////////////////////////////////////////////////////////////
	// for UI //
	UPROPERTY()
	TWeakObjectPtr< UEnemyStatusUI > EnemyStatusUI;		// 상태 UI 포인터

	FTimerHandle EnemyStatusUISetHiddenInGameTHandle;
	
public:
	/////////////////////////////////////////////////////////////////////
	// for Character info Management //
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	ENPCType NPCType = ENPCType::Enemy;						// NPC 타입
	
	/////////////////////////////////////////////////////////////////////
	// for skill //
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "skills", meta = (AllowPrivateAccess = "true"))
	UPlayerSkill *MeleeAttack;

	// [TODO] 범용 스킬 클래스를 자손으로 만들어서 예외처리?
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "skills", meta = (AllowPrivateAccess = "true"))
	UPlayerSkill *ProjectileAttack;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	UParticleSystem *GrenadeMuzzleEffect;

	int8 SoldierStack = 0;

	
public:
	ACharacterNPC();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	// 상태 UI 위젯을 생성한다.
	virtual void CreateStatusUI() override;
	
	// TakeDamageHandle
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	//void SetTimerWithDelegate(FTimerHandle& TimerHandle, TBaseDelegate<void> ObjectDelegate, float Time, bool bLoop);

	void EnemyStatusUISetHiddenInGame();
public:
	float DoMeleeAttack();
	void TempDoMeleeAttack();
	void DoProjectileAttack();
};
