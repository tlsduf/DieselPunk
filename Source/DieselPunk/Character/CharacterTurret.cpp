// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterTurret.h"

#include "../Component/HousingActorComponent.h"
#include "..\Logic\NPCAIController.h"
#include "../Animation/TurretAnimInstace.h"
#include "../Manager/ObjectManager.h"

#include <Components/SkeletalMeshComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/CapsuleComponent.h>
#include <Materials/MaterialInstanceDynamic.h>
#include <Components/BoxComponent.h>




// =============================================================
// 생성자
// =============================================================
ACharacterTurret::ACharacterTurret()
{
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterTurret::BeginPlay()
{
	Super::BeginPlay();
	CharacterType = ECharacterType::Turret;
}

// =============================================================
// 소멸자
// =============================================================
void ACharacterTurret::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// Tick
// =============================================================
void ACharacterTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(NPCType == ENPCType::Alliance)
		SetTurretTarget();

	// 애니메이션 타겟 SET
	UTurretAnimInstace* TurretAnimInstace = Cast<UTurretAnimInstace>(GetMesh()->GetAnimInstance());
	if(TurretAnimInstace != nullptr)
		TurretAnimInstace->SetCurTarget(Cast<ACharacterNPC>(Target));
}

void ACharacterTurret::RunAi()
{
	Super::RunAi();
	ANPCAIController* aiController = Cast<ANPCAIController>(GetController());
	if(aiController)
		aiController->RunAi(this, true);
}

// =============================================================
// 터렛의 조건에 따라 타겟을 결정합니다.
// =============================================================
void ACharacterTurret::SetTurretTarget()
{
	// * 터렛은 현재 목표가 없으면 탐색을 하여, 사거리가 유효한 가장 가까운 적을 목표로 삼는다.
	// * 목표가 사거리에서 벗어나면 목표를 재탐색한다.
	
	//현재 타겟이 유효한가 //유효하지 않다면 탐색 // 유효하다면 타겟 추적
	if(!Target.IsValid())
	{
		//1 기본 탐색 흐름 : 
		//타입 조건에 맞는(Enemy) 액터 어레이 반환(ObjectManager)
		TArray<int32> outActors;
		FObjectManager::GetInstance()->FindActorArrayByPredicate(outActors, [](AActor* InActor)
		{
			if(ACharacterNPC* thisNPC = Cast<ACharacterNPC>(InActor))
				if(thisNPC->NPCType == ENPCType::Enemy)
					return true;
        
			return false;
		});
		//범위 조건에 맞는 액터 어레이 반환
		TWeakObjectPtr<ACharacterTurret> thisPtr = this;
		outActors.RemoveAll([thisPtr](int32 ID)
		{
			if(thisPtr.IsValid())
				return !thisPtr->InValidArea(FObjectManager::GetInstance()->FindActor(ID)->GetActorLocation());
			return true;
		});
		//기준점(대게 this)에 가장 가까운(또는 다른 조건) 액터(또는 어레이) 반환
		TWeakObjectPtr<AActor> tempTarget = Cast<ACharacterNPC>(FObjectManager::GetInstance()->FindActor(
			FObjectManager::GetInstance()->GetNearestACtorByRangeAndIds(GetActorLocation(), outActors)));
		
		//2 타겟 유효성 검사 :
		//현재 타겟이 유효한가
		if(!tempTarget.IsValid())
			return;
		//타겟을 공격할 수 있는가(벽에 막히거나)
		//TODO
		
		//3 타겟 등록(NPC 프롭) : 위 조건에 맞는 타겟 등록
		Target = tempTarget;
	}
	else
	{
		// 유효하다면 타겟 추적
		// 목표와의 거리 측정 // 거리가 유효하지 않으면 초기화
		float distance = FVector::Dist(GetActorLocation(), Target->GetActorLocation());
		if(distance > GetStat().GetStat(ECharacterStatType::AttackRange))
			Target = nullptr;
	}
}

// =============================================================
// inLocation이 유효 범위 안에 있으면 True 반환
// =============================================================
bool ACharacterTurret::InValidArea(FVector inLocation)
{
	float distance = FVector::Dist(GetActorLocation(), inLocation);
	bool inMaxDistance = distance < GetStat().GetStat(ECharacterStatType::AttackRange);		// 최대거리 안에 위치?
	bool inMinDistance = true; //distance > GetStat().GetStat(ECharacterStatType::AttackMinRange);	//최소거리 밖에 위치?

	float forwardDir = GetActorForwardVector().GetSafeNormal().Rotation().Yaw;
	float toTargetDir = (inLocation - GetActorLocation()).GetSafeNormal().Rotation().Yaw;
	bool inDegree = true; // ( -30 < (forwardDir - toTargetDir) ) && ( (forwardDir - toTargetDir) < 30 );	// 각도 내에 위치?
	
	return inMaxDistance && inMinDistance && inDegree;
}
