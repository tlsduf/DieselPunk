// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterPC.h"
#include "CharacterNPC.generated.h"

class UHousingActorComponent;
class USkillBase;
class UEnemyStatusUI;

struct FProportion
{
	float Width = 0;
	float Length = 0;
};

UCLASS()
class DIESELPUNK_API ACharacterNPC : public ACharacterBase
{
	GENERATED_BODY()
	
protected:
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
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MYDP_Skill", meta = (AllowPrivateAccess = "true"))
	USkillBase *TargetAttack;
	
	
	//포탑의 사이즈입니다. 1그리드 = 100입니다.
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	int32 GridSize = 1;

	
	TArray<FVector> GoalLocArray;	//도달할 목표위치 배열
	int32 GoalLocNum = 0;			//도달할 목표위치 순서

	TArray<FVector> ShortestPath;	//최단거리
	FVector GoalLoc = FVector::ZeroVector;			//도달할 타겟 위치
	TWeakObjectPtr<AActor> Target = nullptr;		//공격할 타겟
	FVector BlockedTargetLoc = FVector::ZeroVector;	//공격할 타겟 위치

protected:
	ACharacterNPC();
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

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
	void DoTargetAttack();
	
	// 스폰시 '몬스터'의 TargetArray를 설정합니다.
	void SetTargetArray(TArray<FVector> inTargetArray);
	// '몬스터'의 Target을 설정합니다.
	void SetEnemyTarget();
	
	bool FindShortestPath(const FVector& InEndLocation);
	const TArray<FVector>& GetShortestPath() {return ShortestPath;} 
	int32 GetGridSize() const {return GridSize;}

	bool SetAttackTarget(TWeakObjectPtr<AActor> InTarget, const TArray<FVector>& InPath = TArray<FVector>(), int InIndex = -1);
	TWeakObjectPtr<AActor> GetAttackTarget() {return Target;}
	FVector GetTargetLoc() { return GoalLoc; }
	FVector GetAttackTargetLoc() { return BlockedTargetLoc; }

};
