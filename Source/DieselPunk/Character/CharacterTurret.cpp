// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterTurret.h"

#include "..\Logic\NPCAIController.h"
#include "../Animation/TurretAnimInstace.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/NavigationManager.h"

#include <Components/SkeletalMeshComponent.h>
#include <Components/StaticMeshComponent.h>

#include "DieselPunk/Component/StatControlComponent.h"
#include "DieselPunk/Skill/SkillBase.h"
#include "DieselPunk/Skill/SkillNPC/NPCAttack.h"


// =============================================================
// 생성자
// =============================================================
ACharacterTurret::ACharacterTurret()
{
}

void ACharacterTurret::UpgradeSkill(const TMap<EAbilityType, FName>& InUpgradeSkillNames)
{
	if(!InUpgradeSkillNames.IsEmpty())
	{
		for(const auto& [key, value] : InUpgradeSkillNames)
		{
			TObjectPtr<UNPCAttack>* attackPtr = NPCAttacks.Find(key);
			if(attackPtr && *attackPtr)
			{
				(*attackPtr)->UnregisterComponent();
				(*attackPtr)->DestroyComponent();
				(*attackPtr) = nullptr;
			}

			TObjectPtr<UNPCAttack>& attack = NPCAttacks.FindOrAdd(key);
			attack = NewObject<UNPCAttack>(this, UNPCAttack::StaticClass());
			attack->RegisterComponent();
			attack->SetNPCSkillName(value);
		}
	}
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

void ACharacterTurret::SetTarget()
{
	Super::SetTarget();
	// 사정거리 Draw
	if(DebugOnOff)
		DrawDebugSearchArea();
	
	// * 터렛은 현재 목표가 없으면 탐색을 하여, 사거리가 유효한 가장 가까운 적을 목표로 삼는다.
	// * 목표가 사거리에서 벗어나면 목표를 재탐색한다.
	
	//현재 타겟이 유효한가 //유효하지 않다면 탐색 // 유효하다면 타겟 추적
	if(!Target.IsValid())
	{
		//1 기본 탐색 흐름 : 
		//타입 조건에 맞는(Enemy) 액터 어레이 반환(ObjectManager)
		TArray<int32> outActors;

		//todo: 포탑이 대공 시너지를 가지고 있는 경우이나 지금은 공중 특성을 가지고 있을 때 처리하도록 만듦(THEQ)
		if(StatControlComponent->IsTrait(ENPCTraitType::Fly))
		{
			FObjectManager::GetInstance()->FindActorArrayByPredicate(outActors, [](AActor* InActor)
			{
				if(ACharacterNPC* thisNPC = Cast<ACharacterNPC>(InActor))
					if(thisNPC->GetNPCType() == ENPCType::Enemy)
						return true;
				return false;
			});
		}
		else
		{
			FObjectManager::GetInstance()->FindActorArrayByPredicate(outActors, [](AActor* InActor)
			{
				if(ACharacterNPC* thisNPC = Cast<ACharacterNPC>(InActor))
				{
					//공중 유닛은 제외하고 대상 찾기
					if(thisNPC->GetNPCType() == ENPCType::Enemy && !thisNPC->GetStatControlComponent()->IsTrait(ENPCTraitType::Fly))
						return true;
				}
				return false;
			});
		}
		
		//범위 조건에 맞는 액터 어레이 반환
		TWeakObjectPtr<ACharacterTurret> thisPtr = this;
		outActors.RemoveAll([thisPtr](int32 ID)
		{
			//todo: 공중 크리쳐의 경우에는 범위 내에 존재하는 지 확인하는 함수 따로 제작 필요(THEQ)
			if(thisPtr.IsValid())
				return !thisPtr->InValidSearchArea(FObjectManager::GetInstance()->FindActor(ID)->GetActorLocation());
			return true;
		});
		//타겟을 공격할 수 있는 조건(벽에 막히거나)
		//TODO
		if(!bPierceWall)
		{
			outActors.RemoveAll([thisPtr](int32 ID)
			{
				if(thisPtr.IsValid())
					return thisPtr->IsOverWall(FObjectManager::GetInstance()->FindActor(ID)->GetActorLocation());
				return true;
			});
		}
		
		//기준점(대게 this)에 가장 가까운(또는 다른 조건) 액터(또는 어레이) 반환
		TWeakObjectPtr<AActor> tempTarget = Cast<ACharacterNPC>(FObjectManager::GetInstance()->FindActor(
			FObjectManager::GetInstance()->GetNearestACtorByRangeAndIds(GetActorLocation(), outActors)));
		
		//2 타겟 유효성 검사 :
		//현재 타겟이 유효한가
		if(!tempTarget.IsValid())
			return;
		
		//3 타겟 등록(NPC 프롭) : 위 조건에 맞는 타겟 등록
		ChangeTarget(tempTarget);
	}
	else
	{
		// 유효하다면 타겟 추적
		// 타겟이 범위안에 있는지 탐색 // 유효하지 않으면 타겟 초기화
		if(!InValidSearchArea(Target->GetActorLocation()))
		{
			ChangeTarget(nullptr);
			return;
		}
		// 타겟과 포탑 사이에 벽이 있는지 탐색 // 벽이 있으면 타겟 초기화
		if(!bPierceWall)
			if(IsOverWall(Target->GetActorLocation()))
				ChangeTarget(nullptr);
	}
}

void ACharacterTurret::InitializeForwardVector()
{
	OriginForwardVector = GetActorForwardVector();
}

// =============================================================
// inLocation까지 트레이스를 하여 맵 구성요소(ex 벽)이 있는지 탐색하고, 있으면 true 반환
// =============================================================
bool ACharacterTurret::IsOverWall(FVector inLocation)
{
	//라인트레이싱에 성공했는가
	TArray<FHitResult> hits;
	FVector start = GetActorLocation();
	FVector end = inLocation;

	// 모든 터렛을 IgnoredActor에 등록합니다. // 플레이어를 IgnoredActor에 등록합니다.
	FCollisionQueryParams params;
	TArray<int32> turretsIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(turretsIDs, [](AActor* InActor)
	{
		if(auto turret = Cast<ACharacterTurret>(InActor))
			if(turret->NPCType == ENPCType::Alliance)
				return true;
		return false;
	});
	for(const int32& ID : turretsIDs)
	{
		params.AddIgnoredActor(FObjectManager::GetInstance()->FindActor(ID));
	}
	params.AddIgnoredActor(FObjectManager::GetInstance()->GetPlayer());
	
	bool bIsWorldObject = false;
	//라인트레이스하여 맵 오브젝트가 있는지 확인. 있으면 true
	if(GetWorld()->LineTraceMultiByChannel(hits, start, end, ECC_DP_CharacterMultiTrace, params))
	{
		for(const auto& hit : hits)
		{
			if(hit.GetActor()->GetClass()->ImplementsInterface(UDpManagementTargetInterFace::StaticClass()))
				continue;
			bIsWorldObject = true;
		}
	}
	return bIsWorldObject;
}