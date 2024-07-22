// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileSkillActorBase.h"
#include "../Character/CharacterBase.h"

#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Kismet/GameplayStatics.h>

#include "DieselPunk/Data/ProjectileSkillActorDataTable.h"
#include "DieselPunk/Manager/DatatableManager.h"
#include "DieselPunk/Manager/ObjectManager.h"


// =============================================================
// 생성자
// =============================================================
AProjectileSkillActorBase::AProjectileSkillActorBase()
{
	PrimaryActorTick.bCanEverTick = true;

	// CapsuleComponent Set // 캡슐 컴포넌트 설정
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->InitCapsuleSize(44.f, 60.f);
	SetRootComponent(CapsuleComponent);
	SetCapsuleCollisionResponses();	// 캡슐 CollisionResponses Set
	
	// StaticMesh Set // 스태틱메쉬 설정
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileMesh->SetupAttachment(CapsuleComponent);
	ProjectileMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	// ProjectileMovement Set
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovementComponent->MaxSpeed = 1300.f;
	ProjectileMovementComponent->InitialSpeed = 1300.f;
}

// =============================================================
// BeginPlay
// =============================================================
void AProjectileSkillActorBase::BeginPlay()
{
	Super::BeginPlay();

	//데이터 테이블 조회
	const FProjectileSkillActorDataTable* data =
		FDataTableManager::GetInstance()->GetData<FProjectileSkillActorDataTable>(EDataTableType::ProjectileSkillActor, ProjectileSkillActorName.ToString());

	if(!data)
		return;

	ProjectileOwnerType = data->ProjectileOwnerType;
	RadialAttackInfos = data->RadialAttackInfos;
	LifeTime = data->LifeTime;
	N_HitEffect = data->N_HitEffect;
	HitEffect = data->HitEffect;
	HitEffectTransform = data->HitEffectTransform;
	HitSound = data->HitSound;
	
	StartLocation = GetActorLocation();
	
	// 콜리전 반응 설정
	SetCapsuleCollisionResponses();
	
	// OnHit Event Bind
	if(CollisionResponses == ECollisionResponsesType::OnHit)
		CapsuleComponent->OnComponentHit.AddDynamic(this, &AProjectileSkillActorBase::OnHit);
	// Overlap Event Bind
	if(CollisionResponses == ECollisionResponsesType::Overlap)
		CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectileSkillActorBase::BeginOverlapEvent);
	// CollisionResponses이 None이면 아무것도 바인드 하지 않음 >> n초 뒤 자동파괴
	
	// 투사체 TimeToDestroy 뒤 자동 파괴
	BindDestroyOnTime();

}

// =============================================================
// Tick
// =============================================================
void AProjectileSkillActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(LifeTime <= 0.f)
	{
		if(FVector::Distance(StartLocation, GetActorLocation()) >= MaxRange)
		{
			ApplyRadialDamage();
			FObjectManager::GetInstance()->DestroyActor(this);
		}
	}
}

// =============================================================
// 폭발 데미지 적용
// =============================================================
void AProjectileSkillActorBase::ApplyRadialDamage()
{
	// Effect
	HitEffectTransform.Location = HitEffectTransform.Location + GetActorLocation();
	HitEffectTransform.Rotation = HitEffectTransform.Rotation + GetActorRotation();

	if (N_HitEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, HitEffectTransform);
	if (HitEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, HitEffectTransform);
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());

	for(const TPair<float, float>& info : RadialAttackInfos)
	{
		if(OwnerCharacter.IsValid())
		{
			TArray<FHitResult> sweepResults;
			FVector startLocation = GetActorLocation();
			FVector endLocation = startLocation;
			if(OwnerCharacter->GetDebugOnOff())
				DrawDebugSphere(GetWorld(), startLocation, info.Key, 16, FColor::Red, false, 3, 0, 1);
			UtilCollision::CapsuleSweepMulti(GetWorld(), sweepResults, startLocation, endLocation, info.Key, ProjectileOwnerType, DebugOnOff);
			if(!sweepResults.IsEmpty())
			{
				for (auto it = sweepResults.CreateIterator(); it; it++)
				{
					UGameplayStatics::ApplyDamage(it->GetActor(), Damage * info.Value, OwnerController.Get(), OwnerCharacter.Get(), nullptr);
				}
			}
		}
	}
}

// =============================================================
// 생성 후 n초 뒤 파괴 바인드, 0초 이하로 설정 시 파괴하지 않고, Tick에 의해 최대 사거리에서 파괴합니다.
// =============================================================
void AProjectileSkillActorBase::BindDestroyOnTime()
{
	if(LifeTime <= 0.f)
		return;
	
	TWeakObjectPtr<AProjectileSkillActorBase> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(DestroyTimeHandler,[thisPtr](){
			if(thisPtr.IsValid())
			{
				thisPtr->ApplyRadialDamage();
				FObjectManager::GetInstance()->DestroyActor(thisPtr.Get());
			}
		}, LifeTime, false);
}

// =============================================================
// OnHit
// =============================================================
void AProjectileSkillActorBase::OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult)
{
	_OnHit(InHitComp, InOtherActor, InOtherComp, InNormalImpulse, InHitResult);
}

// =============================================================
// Overlap
// =============================================================
void AProjectileSkillActorBase::BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
	bool InbFromSweep, const FHitResult & InSweepResult)
{
	_BeginOverlapEvent(InOverlappedComponent, InOtherActor, InOtherComp, InOtherBodyIndex,
		InbFromSweep, InSweepResult);
}

void AProjectileSkillActorBase::SetCapsuleCollisionResponses()
{
	CapsuleComponent->SetCollisionProfileName(TEXT("Custom"));
	CapsuleComponent->CanCharacterStepUpOn = ECB_No;
	
	// 모든 반응 Ignore로 초기화하고 시작
	CapsuleComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	if(ProjectileOwnerType == ECausorType::Player)
	{
		CapsuleComponent->SetCollisionObjectType(ECC_GameTraceChannel2);
		if(CollisionResponses == ECollisionResponsesType::OnHit)
		{
			CapsuleComponent->SetGenerateOverlapEvents(false);
			
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Block);
			// ECC_GameTraceChannel3 == Enemy
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Block);
		}
		else if(CollisionResponses == ECollisionResponsesType::Overlap)
		{
			CapsuleComponent->SetGenerateOverlapEvents(true);

			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Overlap);
			// ECC_GameTraceChannel3 == Enemy
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Overlap);
		}
	}
	else if(ProjectileOwnerType == ECausorType::Enemy)
	{
		CapsuleComponent->SetCollisionObjectType(ECC_GameTraceChannel4);
		if(CollisionResponses == ECollisionResponsesType::OnHit)
		{
			CapsuleComponent->SetGenerateOverlapEvents(false);

			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Block);
			// ECC_GameTraceChannel1 == Player
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Block);
		}
		else if(CollisionResponses == ECollisionResponsesType::Overlap)
		{
			CapsuleComponent->SetGenerateOverlapEvents(true);

			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Overlap);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Overlap);
			// ECC_GameTraceChannel1 == Player
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Overlap);
		}
	}
}