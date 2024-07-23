// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "CharacterPC.h"
#include "DieselPunk/Interface/ThrowableInterface.h"
#include "CharacterNPC.generated.h"

class UHousingActorComponent;
class USkillBase;
class UDPNavigationComponent;
class UEnemyStatusUI;
class UNPCAttack;

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
class DIESELPUNK_API ACharacterNPC : public ACharacterBase, public IThrowableInterface
{
	GENERATED_BODY()

	DECLARE_MULTICAST_DELEGATE_TwoParams(FDelegateUpgrade, ACharacterNPC*, int32)

	// TimerHandle
	FTimerHandle PathTHandle1;
	FTimerHandle PathTHandle2;
	FTimerHandle PathTHandle3;

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

	UPROPERTY()
	TMap<EAbilityType, TObjectPtr<UNPCAttack>> NPCAttacks;

	TArray<EAbilityType> UseableSkills;

	EAbilityType CurrentUseAbilityType = EAbilityType::None;	
	
	//포탑의 세로 사이즈입니다. 1그리드 = 100입니다.
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	int32 GridSizeVertical = 1;

	//포탑의 가로 사이즈입니다. 1그리드 = 100입니다.
	UPROPERTY(EditDefaultsOnly, Category="MYDP_Setting", meta=(AllowPrivateAccess="true"))
	int32 GridSizeHorizontal = 1;

	
	UPROPERTY(BlueprintReadOnly, Category = "MYDP_Skill")
	UDPNavigationComponent *DPNavigationComponent;
	
	FVector NowGoalLoc = FVector::ZeroVector;	// 처음으로 도달할 목표 위치 // 처음으로 도달할 경유지점 위치
	TMap<FVector, FRoutingLine> RoutingLines;	// GoalLoc를 업데이트 해주기 위한 선분과 경유지점 TMap입니다.
	
	TWeakObjectPtr<AActor> Target = nullptr;	// 공격할 타겟
	
	int32 TargetedTurretID = -9997;				// 공격할 터렛 ID

	bool InRange = false;		// 타겟이 범위 안에 있으면 true
	
	TArray<FVector> ShortestPath;	//최단거리
	FVector BlockedTargetLoc = FVector::ZeroVector;	// 공격할 타겟 위치
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Setting")
	UAnimSequence* SpawnAnimation = nullptr;

	UPROPERTY()
	TWeakObjectPtr<UBehaviorTree> CachedBehaviorTree = nullptr;

	float CachedMass = 100.f;

	bool IsThrowingActor = false;

	/////////////////////////////////////////////////////////////////////
	// for Targeting //

	FSearchAreaData SearchAreaData;

	//사각형 포인트
	TArray<FVector> RectanglePoints;

	//탐색을 위한 전방 벡터
	FVector OriginForwardVector = FVector::ZeroVector;

	/////////////////////////////////////////////////////////////////////
	// for Upgrade //
	FDelegateUpgrade DelegateUpgrade;
	
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
	
	// 몬스터의 RoutingLines TMap에 값을 추가합니다.
	void AddEnemyRoutingLines(FVector inGoalLoc, FVector inStart, FVector inEnd);
	// RoutingLines에서 GoalLoc(Key)들을 배열로 만들어 반환합니다.
	TArray<FVector> GetGoalLocArrayFromRoutingLines();
	// self와 선분사이의 거리를 반환합니다.
	float DistanceSegmentToSelf(FVector inStart, FVector inEnd);
	// '몬스터'의 GoalLoc를 갱신합니다. // GoalLoc는 경유지점입니다. // Tick , 조건
	void UpdateEnemyGoalLoc();

	// 길이 막혔을 때, '몬스터'의 타겟을 지정합니다. // 현재 사용x
	bool SetBlockedAttackTarget(TWeakObjectPtr<AActor> InTarget, const TArray<FVector>& InPath = TArray<FVector>(), int InIndex = -1);

	// Curved Spline으로 된 경로를 생성합니다.
	// 몬스터 스폰완료시, 포탑 설치/파괴시, Target이 Nexus로 업데이트될 때 호출합니다.
	void UpdateSplinePath();
	void _UpdateSplinePath();
	void __UpdateSplinePath();
	
	// Getter, Setter
	ENPCType GetNPCType() const { return NPCType; }

	void SetAIController(AAIController* inController) { AIController = inController; }

	bool GetInRange() const { return InRange; }
	
	TWeakObjectPtr<AActor> GetAttackTarget() const { return Target; }
	
	const TArray<FVector>& GetShortestPath() const { return ShortestPath; }
	
	int32 GetGridSizeVertical() const { return GridSizeVertical; }
	
	int32 GetGridSizeHorizontal() const { return GridSizeHorizontal; }
	
	FVector GetBlockedAttackTargetLoc() const { return BlockedTargetLoc; }

	ENPCType GetNPCType(){return NPCType;}

	FDelegateUpgrade& GetDelegateUpgrade(){return DelegateUpgrade;}
	
	//스폰 애니메이션을 실행하고 애니메이션의 길이를 반환합니다. 애니메이션이 없을 경우 0을 반환합니다.
	float PlaySpawnAnim();
public:
	void DoNPCSkill(EAbilityType InAbilityType);
	
	virtual void AbilityShot(double InDamageCoefficient) override;

	const TArray<EAbilityType>& GetUseableSkills(){return UseableSkills;}
	EAbilityType GetTopPriorityUseableSkill();
	bool IsAllParabolaAttack();
	const UNPCAttack* GetNPCAttack(EAbilityType InAbilityType);

	virtual void ThrowReady(TWeakObjectPtr<AActor> InThrowingOwner) override;
	virtual void ThrowExecute(TWeakObjectPtr<AActor> InThrowingOwner) override;
	virtual void ThrowComplete() override;
};
