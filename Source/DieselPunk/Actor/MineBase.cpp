// Fill out your copyright notice in the Description page of Project Settings.

#include "MineBase.h"
#include "../Character/CharacterBase.h"
#include "../Character/CharacterTurret.h"

#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Kismet/GameplayStatics.h>



// =============================================================
// 생성자
// =============================================================
AMineBase::AMineBase()
{
	PrimaryActorTick.bCanEverTick = false;

	// StaticMesh Set // 스태틱메쉬 설정
	MineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mine Mesh"));
	SetRootComponent(MineMesh);
	
	// CapsuleComponent Set // 캡슐 컴포넌트 설정
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(50.f, 50.f, 50.f));
	BoxComponent->SetupAttachment(MineMesh);
	SetCapsuleCollisionResponses();	// 캡슐 CollisionResponses Set
	

	// ProjectileMovement Set
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovementComponent->MaxSpeed = 0.f;
	ProjectileMovementComponent->InitialSpeed = 0.f;
	ProjectileMovementComponent->Velocity = FVector::ZeroVector;
}

// =============================================================
// BeginPlay
// =============================================================
void AMineBase::BeginPlay()
{
	Super::BeginPlay();
	
	// 콜리전 반응 설정
	SetCapsuleCollisionResponses();

	// Effect
	ShotEffectTransform.Location = ShotEffectTransform.Location + GetActorLocation();
	ShotEffectTransform.Rotation = ShotEffectTransform.Rotation + GetActorRotation();

	if (N_ShotEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_ShotEffect, ShotEffectTransform);
	if (ShotEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), ShotEffect, ShotEffectTransform);
	if (ShotSound)
		UGameplayStatics::PlaySoundAtLocation(this, ShotSound, GetActorLocation());
	
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMineBase::BeginOverlapEvent);

	ProjectileMovementComponent->MaxSpeed = 0.f;
	ProjectileMovementComponent->InitialSpeed = 0.f;
	ProjectileMovementComponent->Velocity = FVector::ZeroVector;
	
	// 투사체 60초 뒤 자동 파괴
	TWeakObjectPtr<AMineBase> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(DestroyTimeHandler,[thisPtr](){
			if(thisPtr.IsValid())
				thisPtr->Destroy();
		}, 60, false);
}

// =============================================================
// Tick
// =============================================================
void AMineBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// =============================================================
// Overlap
// =============================================================
void AMineBase::BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
	bool InbFromSweep, const FHitResult & InSweepResult)
{
	_BeginOverlapEvent(InOverlappedComponent, InOtherActor, InOtherComp, InOtherBodyIndex,
		InbFromSweep, InSweepResult);
}

// =============================================================
// 오버랩시 호출해서 데미지 적용, 투사체 파괴 등을 수행
// =============================================================
void AMineBase::_BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
	bool InbFromSweep, const FHitResult & InSweepResult)
{
	//움직이지 않는 물체이면 주인에 따라 오버랩 시킬 지 확인
	if(ProjectileOwnerType == ECausorType::Player)
	{
		if(Cast<ACharacterNPC>(InOtherActor) == nullptr && Cast<ACharacterTurret>(InOtherActor) == nullptr)
			return;
	}
	else if (ProjectileOwnerType == ECausorType::Enemy)
	{
		if(Cast<ACharacterPC>(InOtherActor) == nullptr && Cast<ACharacterTurret>(InOtherActor) == nullptr)
			return;
	}
	
	// Effect
	HitEffectFTransform.Location = HitEffectFTransform.Location + GetActorLocation();
	HitEffectFTransform.Rotation = HitEffectFTransform.Rotation + GetActorRotation();

	if (N_HitEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, HitEffectFTransform);
	if (HitEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, HitEffectFTransform);
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());

	// 데미지 전달
	if (InOtherActor != nullptr && InOtherActor != OwnerCharacter)
	{
		if(DoRadialDamage)
		{
			TArray<FHitResult> sweepResults;
			FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
			FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
			UtilCollision::CapsuleSweepMulti(GetWorld(), sweepResults, startLocation, endLocation, AttackRadius, ProjectileOwnerType, DebugOnOff);
			if(!sweepResults.IsEmpty())
			{
				for (auto It = sweepResults.CreateIterator(); It; It++)
				{
					InOtherActor = It->GetActor();
					UGameplayStatics::ApplyDamage(InOtherActor, Damage, OwnerController.Get(), OwnerCharacter.Get(), nullptr);
				}
			}
		}
		else
		{
			UGameplayStatics::ApplyDamage(InOtherActor, Damage, OwnerController.Get(), OwnerCharacter.Get(), nullptr);
		}
	}

	// Projectile 파괴
	Destroy();
}

void AMineBase::SetCapsuleCollisionResponses()
{
	BoxComponent->SetCollisionProfileName(TEXT("Custom"));
	BoxComponent->CanCharacterStepUpOn = ECB_No;
	
	// 모든 반응 Ignore로 초기화하고 시작
	BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	if(ProjectileOwnerType == ECausorType::Player)
	{
		BoxComponent->SetCollisionObjectType(ECC_GameTraceChannel2);
		
		BoxComponent->SetGenerateOverlapEvents(true);

		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Overlap);
		// ECC_GameTraceChannel3 == Enemy
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Overlap);
		
	}
	else if(ProjectileOwnerType == ECausorType::Enemy)
	{
		BoxComponent->SetCollisionObjectType(ECC_GameTraceChannel4);
		
		BoxComponent->SetGenerateOverlapEvents(true);

		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Overlap);
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Overlap);
		// ECC_GameTraceChannel1 == Player
		BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Overlap);
	}
}