// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileBase.h"
#include "../../Util/UtilCollision.h"
#include "DieselPunk/Util/UtilEffect.h"

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
		UtilEffect::SpawnParticleComponent(ShotEffect, GetActorLocation(), GetActorRotation());
	if (ShotSound)
		UGameplayStatics::PlaySoundAtLocation(this, ShotSound, GetActorLocation());

	// 1틱만 사용시 처리
	if(bUseOneTick)
		OneTickTask();

	// 투사체 10초 뒤 자동 파괴
	GetWorld()->GetTimerManager().SetTimer(DestroyTimeHandler, [this](){Destroy();}, 10, false);
	
	if(CollisionResponses == ECollisionResponsesType::OnHit && !bUseOneTick)
		CapsuleComponent->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
	
	else if(CollisionResponses == ECollisionResponsesType::Overlap && !bUseOneTick)
		CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBase::BeginOverlapEvent);
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectileBase::SetCapsuleCollisionResponses()
{
	CapsuleComponent->SetCollisionProfileName(TEXT("Custom"));
	CapsuleComponent->CanCharacterStepUpOn = ECB_No;
	
	// 모든 반응 Ignore로 초기화하고 시작
	CapsuleComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	if(ProjectileOwnerType == EProjectileOwnerType::Player)
	{
		CapsuleComponent->SetCollisionObjectType(ECC_GameTraceChannel3);
		if(CollisionResponses == ECollisionResponsesType::OnHit)
		{
			CapsuleComponent->SetGenerateOverlapEvents(false);
			
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Block);
			// ECC_GameTraceChannel4 == Enemy
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel4, ECollisionResponse::ECR_Block);
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
			// ECC_GameTraceChannel4 == Enemy
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel4, ECollisionResponse::ECR_Overlap);
		}
	}
	else if(ProjectileOwnerType == EProjectileOwnerType::Enemy)
	{
		CapsuleComponent->SetCollisionObjectType(ECC_GameTraceChannel5);
		if(CollisionResponses == ECollisionResponsesType::OnHit)
		{
			CapsuleComponent->SetGenerateOverlapEvents(false);

			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Block);
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Block);
			// ECC_GameTraceChannel2 == Player
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Block);
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
			// ECC_GameTraceChannel2 == Player
			CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel2, ECollisionResponse::ECR_Overlap);
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
		UtilEffect::SpawnParticleComponent(HitEffect, GetActorLocation(), GetActorRotation());
	
	TArray<FHitResult> sweepResults;
	FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
	FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
	UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, 1, DebugOnOff);
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
void AProjectileBase::OnHit(UPrimitiveComponent *HitComp, AActor *HitActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &HitResult)
{
	_OnHit(HitComp, HitActor, OtherComp, NormalImpulse, HitResult);
}

// 히트시 호출해서 데미지 적용, 투사체 파괴 등을 수행
void AProjectileBase::_OnHit(UPrimitiveComponent *HitComp, AActor *HitActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &HitResult)
{
	auto ownerPawn = Cast<APawn>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;

	if (HitEffect)
		UtilEffect::SpawnParticleComponent(HitEffect, GetActorLocation(), GetActorRotation());
	
	if (ownerPawn == nullptr)
	{
		Destroy();
		return;
	}

	//TODO 리펙토링 해야될듯
	Destroy();
	if (HitActor && HitActor != this && HitActor != ownerPawn)
	{
		if(DoRadialDamage)
		{
			TArray<FHitResult> sweepResults;
			FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
			FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
			UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, 1, DebugOnOff);
			if(!sweepResults.IsEmpty())
			{
				for (auto It = sweepResults.CreateIterator(); It; It++)
				{
					HitActor = It->GetActor();
					UGameplayStatics::ApplyDamage(HitActor, Damage, ownerController, ownerPawn, nullptr);
				}
			}
		}
		else
		{
			UGameplayStatics::ApplyDamage(HitActor, Damage, ownerController, ownerPawn, nullptr);
			// UGameplayStatics::ApplyPointDamage(HitActor, Damage, HitActor->GetActorLocation(), HitResult, ownerController, OwnerPawn, nullptr);
			// UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), RadialDamageRadius, nullptr, TArray<AActor *>(), this, ownerController, DoFullDamage, ECC_WorldStatic);
		}
	}

	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
	/*
	if (HitCameraShakeClass)
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(HitCameraShakeClass);
	*/
}

void AProjectileBase::BeginOverlapEvent(class UPrimitiveComponent* InHitComp, class AActor* InOtherActor, class UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult & InSweepResult)
{
	_BeginOverlapEvent(InHitComp, InOtherActor, InOtherComp, InOtherBodyIndex, InbFromSweep, InSweepResult);
}

void AProjectileBase::_BeginOverlapEvent(class UPrimitiveComponent* InHitComp, class AActor* InOtherActor, class UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult & InSweepResult)
{
	auto ownerPawn = Cast<APawn>(GetOwner());
	if(ownerPawn == nullptr)
		return;
	auto ownerController = ownerPawn->GetController();
	if(ownerController == nullptr)
		return;
	
	//UtilEffect::ActivateDecorator( this, EDecorateUseType::Despawn);
	if (ownerPawn == nullptr)
	{
		Destroy();
		return;
	}

	Destroy();
	if (InOtherActor != nullptr && InOtherActor != ownerPawn)
	{
		if(DoRadialDamage)
		{
			TArray<FHitResult> sweepResults;
			FVector startLocation = GetActorLocation() + GetActorForwardVector() * AttackStartPoint;
			FVector endLocation = startLocation + GetActorForwardVector() * AttackRange;
			UtilCollision::CapsuleSweepMulti(sweepResults, startLocation, endLocation, AttackRadius, true, DebugOnOff);
			for (auto It = sweepResults.CreateIterator(); It; It++)
			{
				InOtherActor = It->GetActor();
				UGameplayStatics::ApplyDamage(InOtherActor, Damage, ownerController, ownerPawn, nullptr);
			}
		}
		else
		{
			UGameplayStatics::ApplyDamage(InOtherActor, Damage, ownerController, ownerPawn, nullptr);
			// UGameplayStatics::ApplyPointDamage(HitActor, Damage, HitActor->GetActorLocation(), HitResult, ownerController, OwnerPawn, nullptr);
			// UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), RadialDamageRadius, nullptr, TArray<AActor *>(), this, ownerController, DoFullDamage, ECC_WorldStatic);
		}
	}
	if (HitEffect)
		UtilEffect::SpawnParticleComponent(HitEffect, GetActorLocation(), GetActorRotation());
	
	if (HitSound)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
}