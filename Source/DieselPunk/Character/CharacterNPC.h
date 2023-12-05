// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterPC.h"
#include "CharacterNPC.generated.h"

class UHousingActorComponent;
class USkillBase;
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

	FTimerHandle EnemyStatusUITHandle;
	
public:
	/////////////////////////////////////////////////////////////////////
	// for Character info Management //
	UPROPERTY(EditAnywhere, Category = "MYDP_info")
	ENPCType NPCType = ENPCType::Enemy;						// NPC 타입

	
	/////////////////////////////////////////////////////////////////////
	// for skill //
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MYDP_Skill", meta = (AllowPrivateAccess = "true"))
	USkillBase *MeleeAttack;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MYDP_Skill", meta = (AllowPrivateAccess = "true"))
	USkillBase *ProjectileAttack;
	
	//포탑의 사이즈입니다. 1그리드 = 100입니다.
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	int32 GridSize = 1;

	TArray<FVector> ShortestPath;	//최단거리

	TWeakObjectPtr<AActor> AttackTarget = nullptr;		//공격할 타겟
	FVector AttackTargetLocation = FVector::ZeroVector;	//공격할 타겟 위치
public:
	ACharacterNPC();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	// 상태 UI 위젯을 생성한다.
	virtual void CreateStatusUI() override;
	
	// UI 컨트롤 하기 위한 오버라이드
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	// UI 타이머 컨트롤
	void HandleStatusUI();

public:
	// 몬스터 스킬
	void DoMeleeAttack();
	void DoProjectileAttack();

	bool FindShortestPath(const FVector& InEndLocation);
	const TArray<FVector>& GetShortestPath() {return ShortestPath;} 
	int32 GetGridSize() const {return GridSize;}

	bool SetAttackTarget(TWeakObjectPtr<AActor> InTarget, const TArray<FVector>& InPath = TArray<FVector>(), int InIndex = -1);
	TWeakObjectPtr<AActor> GetAttackTarget() {return AttackTarget;}
	FVector GetAttackTargetLocation() {return AttackTargetLocation; }
};
