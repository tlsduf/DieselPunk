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
	HousingActorComponent = CreateDefaultSubobject<UHousingActorComponent>(TEXT("Housing Actor Component"));

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> material(TEXT("/Script/Engine.Material'/Game/DieselPunk/Material/M_Housing.M_Housing'"));
	if(material.Succeeded())
		HousingMaterial = material.Object;
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterTurret::BeginPlay()
{
	Super::BeginPlay();

	//Material Instance Dynamic 생성
	HousingDynamicMaterial = UMaterialInstanceDynamic::Create(HousingMaterial.Get(), this);

	//터렛이 가지고 있는 모든 메쉬 컴포넌트 추출
	TArray<UMeshComponent*> meshComponents;
	GetComponents<UMeshComponent>(meshComponents);

	//스켈레탈 메시, 스태틱 메시 추출
	for(UMeshComponent* meshComponent : meshComponents)
	{
		if(meshComponent->GetName() == FString(TEXT("StaticMeshComponent_0")))
			continue;
		if(Cast<USkeletalMeshComponent>(meshComponent) == nullptr && Cast<UStaticMeshComponent>(meshComponent) == nullptr)
			continue;
		
		TArray<TWeakObjectPtr<UMaterialInterface>>& material = OriginalMaterials.FindOrAdd(meshComponent);
		for(int i = 0; i < meshComponent->GetNumMaterials(); ++i)
			material.Add(meshComponent->GetMaterial(i));
	}

	//배치용 머터리얼로 변경
	ChangeMaterialByHousingEffect(true);

	//캡슐 콜리전 끄기
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	UActorComponent* actor = GetComponentByClass(UBoxComponent::StaticClass());
	if(actor != nullptr)
	{
		Box = Cast<UBoxComponent>(actor);
		if(Box != nullptr)
		{
			Box->SetGenerateOverlapEvents(false);
			Box->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
			Box->SetCanEverAffectNavigation(false);
		}
	}
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

	SetTurretTarget();

	// 애니메이션 타겟 SET
	UTurretAnimInstace* TurretAnimInstace = Cast<UTurretAnimInstace>(GetMesh()->GetAnimInstance());
	if(TurretAnimInstace != nullptr)
		TurretAnimInstace->SetCurTarget(Cast<ACharacterNPC>(Target));
}

// =============================================================
// 터렛 생성
// =============================================================
bool ACharacterTurret::CompleteHousingTurret() 
{
	if(HousingActorComponent->CompleteHousingTurret())
	{
		RunAi();
		ChangeMaterialByHousingEffect(false);

		GetCapsuleComponent()->SetGenerateOverlapEvents(true);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Block);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel4, ECollisionResponse::ECR_Block);

		Box->SetGenerateOverlapEvents(true);
		Box->SetCollisionResponseToChannel(ECC_EngineTraceChannel5, ECR_Block);
		Box->SetCanEverAffectNavigation(true);


		return true;
	}
	return false;
}

// =============================================================
// AI 시작
// =============================================================
void ACharacterTurret::RunAi()
{
	ANPCAIController* aiController = Cast<ANPCAIController>(GetController());
	if(aiController)
		aiController->RunAi(this, true);
}

// =============================================================
// 
// =============================================================
void ACharacterTurret::ChangeMaterialByHousingEffect(bool InRenderHousingEffect)
{
	if(InRenderHousingEffect)
	{
		for(TPair<TWeakObjectPtr<UMeshComponent>, TArray<TWeakObjectPtr<UMaterialInterface>>> pair : OriginalMaterials)
			pair.Key->SetMaterial(0, HousingDynamicMaterial.Get());
	}
	else
	{
		for(TPair<TWeakObjectPtr<UMeshComponent>, TArray<TWeakObjectPtr<UMaterialInterface>>> pair : OriginalMaterials)
		{
			for(int i = 0; i < pair.Value.Num(); ++i)
				pair.Key->SetMaterial(i, pair.Value[0].Get());
		}
	}
}

// =============================================================
// 
// =============================================================
void ACharacterTurret::ChangeHousingMaterialParameterChange(bool InHousing)
{
	if(InHousing)
		HousingDynamicMaterial->SetScalarParameterValue(FName(TEXT("IsHousing")), 1);
	else
		HousingDynamicMaterial->SetScalarParameterValue(FName(TEXT("IsHousing")), 0);
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
		//1 베이스 스캐닝 플로우 : 
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
