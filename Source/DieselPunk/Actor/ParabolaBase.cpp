// Fill out your copyright notice in the Description page of Project Settings.

#include "ParabolaBase.h"
#include "../Character/CharacterBase.h"

#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Kismet/GameplayStatics.h>
#include "../Manager/ObjectManager.h"

#include "Weapon.h"


// =============================================================
// 생성자
// =============================================================
AParabolaBase::AParabolaBase()
{
	PrimaryActorTick.bCanEverTick = true;

	// CapsuleComponent Set // 캡슐 컴포넌트 설정
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->InitCapsuleSize(44.f, 60.f);
	SetRootComponent(CapsuleComponent);
	SetCapsuleCollisionResponses();	// 캡슐 CollisionResponses Set
	
	// StaticMesh Set // 스태틱메쉬 설정
	ParabolaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Parabola Mesh"));
	ParabolaMesh->SetupAttachment(CapsuleComponent);
	ParabolaMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
}

// =============================================================
// BeginPlay
// =============================================================
void AParabolaBase::BeginPlay()
{
	Super::BeginPlay();

	if(!ensure(OwnerCharacter.IsValid()))
		return;
	
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
	
	// OnHit Event Bind
	if(CollisionResponses == ECollisionResponsesType::OnHit)
		CapsuleComponent->OnComponentHit.AddDynamic(this, &AParabolaBase::OnHit);
	// Overlap Event Bind
	if(CollisionResponses == ECollisionResponsesType::Overlap)
		CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AParabolaBase::BeginOverlapEvent);

	Damage = OwnerCharacter->GetStat(ECharacterStatType::Atk);

	StartLocation = GetActorLocation();

	DistanceAtGoal = FVector::Distance(GoalLocation, StartLocation);

	FlightTime = MinFlightTime + ParabolaArrivalTimeCoefficient *
		(DistanceAtGoal - OwnerCharacter->GetStat(ECharacterStatType::AtkMinRange)) / OwnerCharacter->GetStat(ECharacterStatType::ShellFall);

	FallTime = FlightTime * 0.5f;
	
	Direction = ((GoalLocation - StartLocation) / 3 + FVector(0.0, 0.0, Speed));
	Direction.Normalize();

	SetActorRotation(Direction.Rotation());

	AscentSpeed = Speed;
}

// =============================================================
// Tick
// =============================================================
void AParabolaBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(DeltaFlightTime >= FlightTime - FallTime && !IsFalling)
	{
		Direction = FVector(0.0, 0.0, -1.0);
		SetActorRotation(Direction.Rotation());
		SetActorLocation(GoalLocation - Direction * Speed * FallTime);
		IsFalling = true;
	}
	
	DeltaFlightTime += DeltaTime;
	OldLocation = GetActorLocation();
	if(IsFalling)
	{
		FallSpeed += Speed * DeltaTime * 2.f;
		AddActorWorldOffset(Direction * FallSpeed * DeltaTime);
	}
	else
	{
		AscentSpeed -= Speed * DeltaTime / ((FlightTime - FallTime) * 2.f);
		AddActorWorldOffset(Direction * Speed * DeltaTime);
	}

	FCollisionQueryParams param;
	if(OwnerCharacter.IsValid())
		param.AddIgnoredActor(OwnerCharacter.Get());
	FHitResult result;
	if(GetWorld()->LineTraceSingleByChannel(result, OldLocation, GetActorLocation(), ECC_WorldStatic, param))
	{
		SetActorLocation(result.GetActor()->GetActorLocation());
	}
}

// =============================================================
// 파괴 시 이펙트 및 효과 적용
// =============================================================
void AParabolaBase::DestroyEvent()
{
	// Effect
	HitEffectFTransform.Location = HitEffectFTransform.Location + GetActorLocation();
	HitEffectFTransform.Rotation = HitEffectFTransform.Rotation + GetActorRotation();

	if (N_HitEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, HitEffectFTransform);
	if (HitEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, HitEffectFTransform);
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
	
	TArray<FHitResult> sweepResults;
	FVector startLocation = GetActorLocation();
	FVector endLocation = startLocation;
	if(!OwnerCharacter.IsValid())
		return;
	
	if(OwnerCharacter->GetDebugOnOff())
	{
		DrawDebugSphere(GetWorld(), startLocation, FirstRadialDamageRange, 16, FColor::Red, false, 3, 0, 1);
		DrawDebugSphere(GetWorld(), startLocation, SecondRadialDamageRange, 16, FColor::Yellow, false, 3, 0, 1);
	}
	UtilCollision::CapsuleSweepMulti(GetWorld(), sweepResults, startLocation, endLocation, FirstRadialDamageRange, ProjectileOwnerType, DebugOnOff);
	if(!sweepResults.IsEmpty())
	{
		for (auto it = sweepResults.CreateIterator(); it; it++)
		{
			UGameplayStatics::ApplyDamage(it->GetActor(), Damage, OwnerController.Get(), OwnerCharacter.Get(), nullptr);
		}
	}
	TArray<FHitResult> sweepSecondResults;
	UtilCollision::CapsuleSweepMulti(GetWorld(), sweepSecondResults, startLocation, endLocation, SecondRadialDamageRange, ProjectileOwnerType, DebugOnOff);
	if(!sweepSecondResults.IsEmpty())
	{
		for (auto it = sweepResults.CreateIterator(); it; it++)
		{
			AActor* hitActor = it->GetActor();
			if(sweepResults.FindByPredicate([hitActor](const FHitResult& hit)
			{
				return hit.GetActor() == hitActor;
			}) != nullptr)
				continue;
			
			UGameplayStatics::ApplyDamage(it->GetActor(), Damage * 0.5f, OwnerController.Get(), OwnerCharacter.Get(), nullptr);
		}
	}

	FObjectManager::GetInstance()->DestroyActor(this);
}

// =============================================================
// OnHit
// =============================================================
void AParabolaBase::OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult)
{
	_OnHit(InHitComp, InOtherActor, InOtherComp, InNormalImpulse, InHitResult);
}

// =============================================================
// 히트시 호출해서 데미지 적용, 투사체 파괴 등을 수행
// =============================================================
void AParabolaBase::_OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult)
{
	// Effect
	FEffectTransform hitEffectFTransform;
	hitEffectFTransform.Location = HitEffectFTransform.Location + GetActorLocation();
	hitEffectFTransform.Rotation = HitEffectFTransform.Rotation + GetActorRotation();
	hitEffectFTransform.Scale = HitEffectFTransform.Scale;

	if (N_HitEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitEffectFTransform);
	if (HitEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitEffectFTransform);
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());

	// 데미지 전달
	if (InOtherActor && InOtherActor != this && InOtherActor != GetOwner())
	{
		if(Cast<AWeapon>(GetOwner()) == nullptr || InOtherActor != Cast<AWeapon>(GetOwner())->GetOwnerPlayer())
		{
			//범위 데미지 및 파괴
			DestroyEvent();
		}
	}
}

// =============================================================
// Overlap
// =============================================================
void AParabolaBase::BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
	bool InbFromSweep, const FHitResult & InSweepResult)
{
	_BeginOverlapEvent(InOverlappedComponent, InOtherActor, InOtherComp, InOtherBodyIndex,
		InbFromSweep, InSweepResult);
}

// =============================================================
// 오버랩시 호출해서 데미지 적용, 투사체 파괴 등을 수행
// =============================================================
void AParabolaBase::_BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
	bool InbFromSweep, const FHitResult & InSweepResult)
{
	// Effect
	FEffectTransform hitEffectFTransform;
	hitEffectFTransform.Location = HitEffectFTransform.Location + GetActorLocation();
	hitEffectFTransform.Rotation = HitEffectFTransform.Rotation + GetActorRotation();
	hitEffectFTransform.Scale = HitEffectFTransform.Scale;

	if (N_HitEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitEffectFTransform);
	if (HitEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitEffectFTransform);
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());

	// 데미지 전달
	if (InOtherActor && InOtherActor != this && InOtherActor != GetOwner())
	{
		if(Cast<AWeapon>(GetOwner()) == nullptr || InOtherActor != Cast<AWeapon>(GetOwner())->GetOwnerPlayer())
		{
			//범위 데미지 및 파괴
			DestroyEvent();
		}
	}
}

void AParabolaBase::SetCapsuleCollisionResponses()
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