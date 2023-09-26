// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileBase.h"
#include "../Util/UtilCollision.h"
#include "DieselPunk/Util/UtilEffect.h"
#include "../Manager/ObjectManager.h"
#include "ProjectilePathingSpline.h"

#include <NiagaraFunctionLibrary.h>
#include <NiagaraComponent.h>

#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Kismet/GameplayStatics.h>


// Sets default values
AProjectileBase::AProjectileBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// 캡슐 컴포넌트
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->InitCapsuleSize(44.f, 60.f);
	SetRootComponent(CapsuleComponent);
	SetCapsuleCollisionResponses();	// 캡슐 CollisionResponses Set
	
	// 메쉬
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileMesh->SetupAttachment(CapsuleComponent);
	ProjectileMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	// ProjectileMovement
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovementComponent->MaxSpeed = 1300.f;
	ProjectileMovementComponent->InitialSpeed = 1300.f;
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	// 콜리전 반응 설정
	SetCapsuleCollisionResponses();

	// 사운드, 이펙트 재생
	if (ShotEffect)
		UtilEffect::SpawnParticleComponent(ShotEffect, GetActorLocation(), GetActorRotation(), ShotEffectScale);
	if (ShotSound)
		UGameplayStatics::PlaySoundAtLocation(this, ShotSound, GetActorLocation());

	// 1틱만 사용시 처리
	if(bUseOneTick)
		OneTickTask();

	// 투사체 10초 뒤 자동 파괴
	TWeakObjectPtr<AProjectileBase> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(
		DestroyTimeHandler,[thisPtr]()
		{
			if(thisPtr.IsValid())
				thisPtr->Destroy();
		}, 10, false);
	
	if(CollisionResponses == ECollisionResponsesType::OnHit && !bUseOneTick)
		CapsuleComponent->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
	else if(CollisionResponses == ECollisionResponsesType::Overlap && !bUseOneTick)
		CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBase::BeginOverlapEvent);

	// 스플라인(투사체 경로) 생성 및 수명설정
	if(bPathingSpline && ProjectilePathingSplineClass)
	{
		ProjectilePathingSpline = GetWorld()->SpawnActor<AProjectilePathingSpline>(ProjectilePathingSplineClass, GetActorLocation(), GetActorRotation());
		SplineLength = ProjectilePathingSpline->_GetSplineLength();
		// ProjectilePathingSpline 애니메이터
		StartAnimator();
	}
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddActorLocalRotation(UpdateRotation);
	
	// 호밍여부 true 시, 호밍타겟을 세팅
	if(ProjectileMovementComponent->bIsHomingProjectile)
		SetHomingTargetActor();

	if(bPathingSpline && ProjectilePathingSplineClass)
	{
		// ProjectilePathingSpline 애니메이터
		AlphaAnimator.Update(DeltaTime);

		// 투사체의 위치와 방향을 애니메이팅된 알파로 세팅합니다.
		SetActorLocation(ProjectilePathingSpline->_GetLocationAtDistanceAlongSpline(Alpha * SplineLength, ESplineCoordinateSpace::Type::World));
		SetActorRotation(ProjectilePathingSpline->_GetRotationAtDistanceAlongSpline(Alpha * SplineLength, ESplineCoordinateSpace::Type::World));
	}
}

void AProjectileBase::SetCapsuleCollisionResponses()
{
	CapsuleComponent->SetCollisionProfileName(TEXT("Custom"));
	CapsuleComponent->CanCharacterStepUpOn = ECB_No;
	
	// 모든 반응 Ignore로 초기화하고 시작
	CapsuleComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	if(ProjectileOwnerType == EProjectileOwnerType::Player)
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
	else if(ProjectileOwnerType == EProjectileOwnerType::Enemy)
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

void AProjectileBase::OneTickTask()
{
	auto ownerPawn = Cast<APawn>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;
	
	if (HitEffect)
		UtilEffect::SpawnParticleComponent(HitEffect, GetActorLocation(), GetActorRotation(), HitEffectScale);
	
	TArray<FHitResult> sweepResults;
	FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
	FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
	UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, ProjectileOwnerType, DebugOnOff);
	if(!sweepResults.IsEmpty())
	{
		for (auto It = sweepResults.CreateIterator(); It; It++)
		{
			UGameplayStatics::ApplyDamage(It->GetActor(), Damage, ownerController, ownerPawn, nullptr);
		}
	}

	Destroy();
}

// _OnHit 호출용으로 사용
void AProjectileBase::OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult)
{
	_OnHit(InHitComp, InOtherActor, InOtherComp, InNormalImpulse, InHitResult);
}

// 히트시 호출해서 데미지 적용, 투사체 파괴 등을 수행
void AProjectileBase::_OnHit(UPrimitiveComponent* InHitComp, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, FVector InNormalImpulse, const FHitResult& InHitResult)
{
	auto ownerPawn = Cast<APawn>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;

	// 이펙트
	if (HitEffect)
		UtilEffect::SpawnParticleComponent(HitEffect, GetActorLocation(), GetActorRotation(), HitEffectScale);
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());

	// ProjectilePathingSpline 파괴
	if(bPathingSpline && ProjectilePathingSplineClass)
		ProjectilePathingSpline->Destroy();

	// Projectile 파괴
	Destroy();

	// 데미지 전달
	if (InOtherActor && InOtherActor != this && InOtherActor != ownerPawn)
	{
		if(DoRadialDamage)
		{
			TArray<FHitResult> sweepResults;
			FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
			FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
			UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, ProjectileOwnerType, DebugOnOff);
			if(!sweepResults.IsEmpty())
			{
				for (auto It = sweepResults.CreateIterator(); It; It++)
				{
					InOtherActor = It->GetActor();
					UGameplayStatics::ApplyDamage(InOtherActor, Damage, ownerController, ownerPawn, nullptr);
				}
			}
		}
		else
		{
			UGameplayStatics::ApplyDamage(InOtherActor, Damage, ownerController, ownerPawn, nullptr);
			// UGameplayStatics::ApplyPointDamage(HitActor, Damage, HitActor->GetActorLocation(), HitResult, ownerController, OwnerPawn, nullptr);
			// UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), RadialDamageRadius, nullptr, TArray<AActor *>(), this, ownerController, DoFullDamage, ECC_WorldStatic);
		}
	}
	
	/*
	if (HitCameraShakeClass)
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(HitCameraShakeClass);
	*/
}

void AProjectileBase::BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
	bool InbFromSweep, const FHitResult & InSweepResult)
{
	_BeginOverlapEvent(InOverlappedComponent, InOtherActor, InOtherComp, InOtherBodyIndex,
		InbFromSweep, InSweepResult);
}

void AProjectileBase::_BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
	bool InbFromSweep, const FHitResult & InSweepResult)
{
	auto ownerPawn = Cast<APawn>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;

	// 이펙트
	if (HitEffect)
		UtilEffect::SpawnParticleComponent(HitEffect, GetActorLocation(), GetActorRotation(), HitEffectScale);
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());

	// ProjectilePathingSpline 파괴
	if(bPathingSpline && ProjectilePathingSplineClass)
		ProjectilePathingSpline->Destroy();

	// Projectile 파괴
	Destroy();

	// 데미지 전달
	if (InOtherActor != nullptr && InOtherActor != ownerPawn)
	{
		if(DoRadialDamage)
		{
			TArray<FHitResult> sweepResults;
			FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
			FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
			UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, ProjectileOwnerType, DebugOnOff);
			if(!sweepResults.IsEmpty())
			{
				for (auto It = sweepResults.CreateIterator(); It; It++)
				{
					InOtherActor = It->GetActor();
					UGameplayStatics::ApplyDamage(InOtherActor, Damage, ownerController, ownerPawn, nullptr);
				}
			}
		}
		else
		{
			UGameplayStatics::ApplyDamage(InOtherActor, Damage, ownerController, ownerPawn, nullptr);
			// UGameplayStatics::ApplyPointDamage(HitActor, Damage, HitActor->GetActorLocation(), HitResult, ownerController, OwnerPawn, nullptr);
			// UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), RadialDamageRadius, nullptr, TArray<AActor *>(), this, ownerController, DoFullDamage, ECC_WorldStatic);
		}
	}
}

void AProjectileBase::SetDamage(float inDamage)
{
	Damage = inDamage;
}

// 가장 가까운 액터가 HomingRange 보다 가까울 경우, 그 액터를 HomingTargetComponent로 지정한다.
void AProjectileBase::SetHomingTargetActor()
{
	// 가장 가까운 액터를 반환한다.
	AActor* homingActor = GetObjectManager().GetNearestActor(this);
	
	// if 액터가 HominRange 보다 가까이 있을 경우, 그 액터를 HomingTargetComponent로 지정한다. else 해제, 속도초기화
	if(GetDistanceTo(homingActor) < HomingRange && homingActor != Cast<AActor>(DpGetPlayerController()->GetPawn()))
	{
		ProjectileMovementComponent->HomingTargetComponent = homingActor->GetRootComponent();
	}
	else
	{
		ProjectileMovementComponent->InitialSpeed = ProjectileMovementComponent->MaxSpeed;
		ProjectileMovementComponent->HomingTargetComponent = nullptr;
	}
}

// ProjectilePathingSpline 애니메이터
void AProjectileBase::StartAnimator()
{
	AnimatorParam param;
	param.AnimType = EAnimType::Linear;
	param.StartValue = 0.f;
	param.EndValue = 1.f;
	param.DurationTime = Duration;

	TWeakObjectPtr<AProjectileBase> thisPtr = this;
	param.DurationFunc = [thisPtr](float InCurValue)
	{
		if(thisPtr.IsValid())
			thisPtr->Alpha = InCurValue;
	};

	AlphaAnimator.Start(param);
}

void AProjectileBase::SetUpdateRotation(const FRotator& inRotate)
{
	UpdateRotation = inRotate;	
}
