// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "CharacterPC.h"
#include "CharacterNPC.generated.h"

class UHousingActorComponent;
class USkillBase;
class UEnemyStatusUI;
class UNPCAttack;

struct FSearchAreaData
{
	//탐색 범위 타입
	ESearchAreaType SearchAreaType = ESearchAreaType::Rectangle;

	//사각형 너비 그리드 개수
	float RectangleWidth = 1000.f;
	
	//부채꼴 각도
	float ArcAngle = 30.f;

	//높이
	float CircleHeight = 1000.f;
	
	// 최대 사거리
	int AtkMaxRange = 0;

	// 대공 최대 사거리
	int AtkMaxRangeForFly = 0;

	// 최소 사거리
	int AtkMinRange = 0;
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
	
	/////////////////////////////////////////////////////////////////////
	// for Character info Management //
	
	// NPC 타입
	UPROPERTY(EditAnywhere, Category = "MYDP_info")
	ENPCType NPCType = ENPCType::Enemy;						

	UPROPERTY()
	AAIController* AIController = nullptr;
	
	UPROPERTY()
	AActor* Player = nullptr;
	
	/////////////////////////////////////////////////////////////////////
	// for skill //
	
	UPROPERTY(EditAnywhere, Category="MYDP_Skill")
	TMap<EAbilityType, FName> NPCAttackNames;

	UPROPERTY(EditAnywhere, Category="MYDP_Skill")
	TMap<EAbilityType, UAnimSequence*> NPCAttackAnimations;

	UPROPERTY()
	TMap<EAbilityType, TObjectPtr<UNPCAttack>> NPCAttacks;

	TArray<EAbilityType> UseableSkills;

	EAbilityType CurrentUseAbilityType = EAbilityType::None;	
	
	TWeakObjectPtr<AActor> Target = nullptr;	// 공격할 타겟
	
	bool InRange = false;		// 타겟이 범위 안에 있으면 true

	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	UAnimSequence* SpawnAnimation = nullptr;

	/////////////////////////////////////////////////////////////////////
	// for Targeting //

	FSearchAreaData SearchAreaData;

	//사각형 포인트
	TArray<FVector> RectanglePoints;

	//탐색을 위한 전방 벡터
	FVector OriginForwardVector = FVector::ZeroVector;

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

	void FindUseableAbilityType();
public:
	// 포탑의 사각형 탐색범위를 생성합니다. 
	void MakeSearchArea();

	// inLocation이 유효 범위 안에 있으면 True 반환
	bool InValidSearchArea(FVector InLocation);

	// 다각형 내부에 점이 위치하는지 확인합니다. // Point in polygon algorithm
	bool IsInPolygon(double InX, double InY);
	
	// 사정거리 DrawDebug
	void DrawDebugSearchArea();
	
	const FVector& GetOriginForwardVector(){return OriginForwardVector;}

	virtual void SetTarget(){}

	void InitSkill();
	
	// 타겟을 업데이트하고, 업데이트 조건에 따라 댈리게이트를 실행합니다.
	void ChangeTarget(TWeakObjectPtr<AActor> inTarget);
	
	// Getter, Setter
	ENPCType GetNPCType() const { return NPCType; }

	void SetAIController(AAIController* inController) { AIController = inController; }

	bool GetInRange() const { return InRange; }
	
	TWeakObjectPtr<AActor> GetAttackTarget() const { return Target; }

	ENPCType GetNPCType(){return NPCType;}

	const UAnimSequence* GetNPCAttackAnimation(EAbilityType InAbilityType);
	
	//스폰 애니메이션을 실행하고 애니메이션의 길이를 반환합니다. 애니메이션이 없을 경우 0을 반환합니다.
	float PlaySpawnAnim();
public:
	void DoNPCSkill(EAbilityType InAbilityType);
	
	virtual void AbilityShot(double InDamageCoefficient) override;

	const TArray<EAbilityType>& GetUseableSkills(){return UseableSkills;}
	EAbilityType GetTopPriorityUseableSkill();
	bool IsAllParabolaAttack();
	const UNPCAttack* GetNPCAttack(EAbilityType InAbilityType);
};
