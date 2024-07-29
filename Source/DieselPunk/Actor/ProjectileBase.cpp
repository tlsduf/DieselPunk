// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileBase.h"
#include "../Character/CharacterBase.h"

#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Kismet/GameplayStatics.h>

#include "Weapon.h"


// =============================================================
// 생성자
// =============================================================
AProjectileBase::AProjectileBase()
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
void AProjectileBase::BeginPlay()
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


	
	// 생성 후 즉시 효과 적용 및 파괴
	if(bUseOneTick)
		DestroyEvent();
	
	// OnHit Event Bind
	if(CollisionResponses == ECollisionResponsesType::OnHit)
		CapsuleComponent->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
	// Overlap Event Bind
	if(CollisionResponses == ECollisionResponsesType::Overlap)
		CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBase::BeginOverlapEvent);
	// CollisionResponses이 None이면 아무것도 바인드 하지 않음 >> n초 뒤 자동파괴


	// 투사체 궤도 애니메이터
	if(SplinePath.IsValid())
	{
		SplineLength = SplinePath.GetSplineLength();
		TimeToDestroy = SplinePath.Path.Position.Points[1].IsCurveKey() ? SplineLength / ProjectileMovementComponent->GetMaxSpeed() / 1.5 : 0.1f;
		StartAnimator();
	}
	
	// 투사체 TimeToDestroy 뒤 자동 파괴
	BindDestroyOnTime();
}

// =============================================================
// Tick
// =============================================================
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(SplineLength > 0)
	{
		// 투사체의 위치와 방향을 궤도를 따라 움직이도록 합니다.
		AlphaAnimator.Update(DeltaTime);
		SetActorLocation(SplinePath.GetLocationAtDistanceAlongSpline(Alpha * SplineLength));
		SetActorRotation(SplinePath.GetRotationAtDistanceAlongSpline(Alpha * SplineLength));
	}
}

// =============================================================
// 파괴 시 이펙트 및 효과 적용
// =============================================================
void AProjectileBase::DestroyEvent()
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
	
	if(OwnerCharacter.IsValid() && DoRadialDamage)
	{
		TArray<FHitResult> sweepResults;
		FVector startLocation = GetActorLocation();
		FVector endLocation = startLocation;
		if(OwnerCharacter->GetDebugOnOff())
			DrawDebugSphere(GetWorld(), startLocation, AttackRadius, 16, FColor::Red, false, 3, 0, 1);
		UtilCollision::CapsuleSweepMulti(GetWorld(), sweepResults, startLocation, endLocation, AttackRadius, ProjectileOwnerType, DebugOnOff);
		if(!sweepResults.IsEmpty())
		{
			for (auto it = sweepResults.CreateIterator(); it; it++)
			{
				UGameplayStatics::ApplyDamage(it->GetActor(), Damage, OwnerController.Get(), OwnerCharacter.Get(), nullptr);
			}
		}
	}

	Destroy();
}

// =============================================================
// 생성 후 n초 뒤 파괴 바인드
// =============================================================
void AProjectileBase::BindDestroyOnTime()
{
	TWeakObjectPtr<AProjectileBase> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(DestroyTimeHandler,[thisPtr](){
			if(thisPtr.IsValid())
				thisPtr->DestroyEvent();
		}, TimeToDestroy, false);
}

// =============================================================
// Projectile 궤도 애니메이터
// =============================================================
void AProjectileBase::StartAnimator()
{
	TWeakObjectPtr<AProjectileBase> thisPtr = this;

	float durationTime = SplinePath.Path.Position.Points[1].IsCurveKey() ? SplineLength / ProjectileMovementComponent->GetMaxSpeed() / 1.5 : 0.1f;
	
	AnimatorParam param;
	param.StartValue = 0.f;
	param.EndValue = 1.f;
	param.DurationTime = durationTime;
	param.AnimType = EAnimType::Linear;	
	param.DurationFunc = [thisPtr](float InCurValue)
	{
		if(thisPtr.IsValid())
			thisPtr->Alpha = InCurValue;
	};
	AlphaAnimator.SetParam(param);
	AlphaAnimator.Start();
}

// =============================================================
// OnHit
// =============================================================
void AProjectileBase::OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult)
{
	_OnHit(InHitComp, InOtherActor, InOtherComp, InNormalImpulse, InHitResult);
}

// =============================================================
// 히트시 호출해서 데미지 적용, 투사체 파괴 등을 수행
// =============================================================
void AProjectileBase::_OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult)
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
	if (OwnerCharacter.IsValid() && InOtherActor && InOtherActor != this && InOtherActor != GetOwner())
	{
		if(Cast<AWeapon>(GetOwner()) == nullptr || InOtherActor != Cast<AWeapon>(GetOwner())->GetOwnerPlayer())
		{
			if(DoRadialDamage)
			{
				TArray<FHitResult> sweepResults;
				FVector startLocation = GetActorLocation();
				FVector endLocation = startLocation;
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
	}

	// Projectile 파괴
	Destroy();
}

// =============================================================
// Overlap
// =============================================================
void AProjectileBase::BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
	bool InbFromSweep, const FHitResult & InSweepResult)
{
	_BeginOverlapEvent(InOverlappedComponent, InOtherActor, InOtherComp, InOtherBodyIndex,
		InbFromSweep, InSweepResult);
}

// =============================================================
// 오버랩시 호출해서 데미지 적용, 투사체 파괴 등을 수행
// =============================================================
void AProjectileBase::_BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
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
	if (OwnerCharacter.IsValid() && InOtherActor && InOtherActor != this && InOtherActor != GetOwner())
	{
		if(DoRadialDamage)
		{
			TArray<FHitResult> sweepResults;
			FVector startLocation = GetActorLocation();
			FVector endLocation = startLocation;
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
	if(bPiercing <= 0)
		Destroy();

	PiercedCount++;
	if(bPiercing <= PiercedCount)
		Destroy();
}

void AProjectileBase::SetCapsuleCollisionResponses()
{
	CapsuleComponent->SetCollisionProfileName(TEXT("Custom"));
	CapsuleComponent->CanCharacterStepUpOn = ECB_No;
	
	// 모든 반응 Ignore로 초기화하고 시작
	CapsuleComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	if(ProjectileOwnerType == ECausorType::Player)
	{
		CapsuleComponent->SetCollisionObjectType(ECC_DP_ProjectilePlayer);
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
			CapsuleComponent->SetCollisionResponseToChannel(ECC_DP_Enemy, ECollisionResponse::ECR_Block);
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
			CapsuleComponent->SetCollisionResponseToChannel(ECC_DP_Enemy, ECollisionResponse::ECR_Overlap);
		}
	}
	else if(ProjectileOwnerType == ECausorType::Enemy)
	{
		CapsuleComponent->SetCollisionObjectType(ECC_DP_ProjectileEnemy);
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
			CapsuleComponent->SetCollisionResponseToChannel(ECC_DP_Player, ECollisionResponse::ECR_Block);
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
			CapsuleComponent->SetCollisionResponseToChannel(ECC_DP_Player, ECollisionResponse::ECR_Overlap);
		}
	}
}