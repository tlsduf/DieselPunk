// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterPC.h"
#include "CharacterNPC.generated.h"

class UHousingActorComponent;
class USkillBase;
class UDPNavigationComponent;
class UEnemyStatusUI;

// 경유지점 생성을 위한 가로 세로 비율
struct FProportion
{
	float Width = 0;
	float Length = 0;
};
// 경유지점 업데이트를 위한 선분의 시작, 끝 점
struct FRoutingLine
{
	FVector Start;
	FVector End;
	FRoutingLine() { Start = FVector::ZeroVector; End = FVector::ZeroVector; }
	FRoutingLine(FVector inStart, FVector inEnd) : Start(inStart), End(inEnd) {}
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
	
	// NPC 타입
	UPROPERTY(EditAnywhere, Category = "MYDP_info")
	ENPCType NPCType = ENPCType::Enemy;						

	
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

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MYDP_Skill")
	UDPNavigationComponent *DPNavigationComponent;
	
	FVector NowGoalLoc = FVector::ZeroVector;	// 처음으로 도달할 목표 위치 // 처음으로 도달할 경유지점 위치
	TMap<FVector, FRoutingLine> RoutingLines;	// GoalLoc를 업데이트 해주기 위한 선분과 경유지점 TMap입니다.
	
	TWeakObjectPtr<AActor> Target = nullptr;	// 공격할 타겟
	int32 TargetedTurretID = -9997;				// 공격할 터렛 ID

	bool InRange = false;		// 타겟이 범위 안에 있으면 true
	
	TArray<FVector> ShortestPath;	//최단거리
	FVector BlockedTargetLoc = FVector::ZeroVector;	// 공격할 타겟 위치
	
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
	
	// '몬스터'의 Target을 설정합니다. // Tcik , 조건
	void UpdateEnemyTarget();
	TWeakObjectPtr<AActor> GetAttackTarget() { return Target; }
	
	// 몬스터의 RoutingLines TMap에 값을 추가합니다.
	void AddEnemyRoutingLines(FVector inGoalLoc, FVector inStart, FVector inEnd);
	// RoutingLines에서 GoalLoc(Key)들을 배열로 만들어 반환합니다.
	TArray<FVector> GetGoalLocArrayFromRoutingLines();
	// self와 선분사이의 거리를 반환합니다.
	float DistanceSegmentToSelf(FVector inStart, FVector inEnd);
	// '몬스터'의 GoalLoc를 갱신합니다. // GoalLoc는 경유지점입니다. // Tick , 조건
	void UpdateEnemyGoalLoc();
	FVector GetNowGoalLoc() { return NowGoalLoc; }
	
	// 길이 막혔을 때, 파괴시 진행할 수 있는 포탑의 위치를 찾습니다.
	bool FindShortestPath(const FVector& InEndLocation);
	const TArray<FVector>& GetShortestPath() { return ShortestPath; } 
	int32 GetGridSize() const { return GridSize; }

	// 길이 막혔을 때, '몬스터'의 타겟을 지정합니다.
	bool SetBlockedAttackTarget(TWeakObjectPtr<AActor> InTarget, const TArray<FVector>& InPath = TArray<FVector>(), int InIndex = -1);
	FVector GetBlockedAttackTargetLoc() { return BlockedTargetLoc; }

	// Curved Spline으로 된 경로를 생성합니다.
	// 몬스터 스폰완료시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
	void UpdateSplinePath();
	void _UpdateSplinePath();

	// Enemy 타입을 가진 모든 NPC들의 경로를 재탐색 합니다.
	void UpdateSplinePathAll();
};
