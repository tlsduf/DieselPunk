// Fill out your copyright notice in the Description page of Project Settings.

#include "ThrowableActor.h"
#include <Components/StaticMeshComponent.h>

#include "../Character/CharacterPC.h"
#include "../Skill/PlayerSkill.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "DieselPunk/Component/StatControlComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// =============================================================
// 생성자
// =============================================================
AThrowableActor::AThrowableActor()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComponent");
	SetRootComponent(CapsuleComponent);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	Mesh->SetupAttachment(CapsuleComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetupAttachment(CapsuleComponent);

	SphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
}

// =============================================================
// BeginPlay
// =============================================================
void AThrowableActor::BeginPlay()
{
	Super::BeginPlay();
}

// =============================================================
// Tick
// =============================================================
void AThrowableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AThrowableActor::ThrowReady(TWeakObjectPtr<AActor> InThrowingOwner)
{
	IThrowableInterface::ThrowReady(InThrowingOwner);
	ProjectileMovementComponent->Deactivate();
	
	ACharacterBase* charThrowOwner = Cast<ACharacterBase>(ThrowingOwner);
	if(charThrowOwner->GetCharacterType() == ECharacterType::Monster)
	{
		CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECR_Ignore);
	}
	else if(charThrowOwner->GetCharacterType() == ECharacterType::Player || charThrowOwner->GetCharacterType() == ECharacterType::Turret)
	{
		CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECR_Ignore);
	}
}

void AThrowableActor::ThrowExecute(TWeakObjectPtr<AActor> InThrowingOwner)
{
	IThrowableInterface::ThrowExecute(InThrowingOwner);
	ProjectileMovementComponent->Activate();
}

void AThrowableActor::ThrowComplete()
{
	IThrowableInterface::ThrowComplete();

	if(!ThrowingOwner.IsValid())
		return;

	ACharacterBase* charThrowing = Cast<ACharacterBase>(ThrowingOwner);
	if(!charThrowing)
		return;
	
	TArray<FOverlapResult> results;
	if(GetWorld()->OverlapMultiByChannel(results,
		GetActorLocation(),
		GetActorQuat(),
		ECC_WorldStatic,
		FCollisionShape::MakeSphere(SphereComponent->GetScaledSphereRadius())))
	{

		for(const FOverlapResult& result : results)
		{
			if(result.GetActor() == charThrowing)
				continue;

			if(ACharacterBase* hitCharacter = Cast<ACharacterBase>(result.GetActor()))
			{
				if(charThrowing->GetCharacterType() == ECharacterType::Player || charThrowing->GetCharacterType() == ECharacterType::Turret)
				{
					if(hitCharacter->GetCharacterType() == ECharacterType::Monster)
					{
						//데미지 처리, CC기 처리
						UGameplayStatics::ApplyDamage(hitCharacter, Damage, charThrowing->GetController(), charThrowing, nullptr);
						for(const FName& name : BuffNames)
							hitCharacter->GetStatControlComponent()->AddBuff(name);
					}
				}
				else if(charThrowing->GetCharacterType() == ECharacterType::Monster)
				{
					if(hitCharacter->GetCharacterType() == ECharacterType::Player
						|| charThrowing->GetCharacterType() == ECharacterType::Turret
						|| charThrowing->GetCharacterType() == ECharacterType::Installation)
					{
						//데미지 처리, CC기 처리
						UGameplayStatics::ApplyDamage(hitCharacter, Damage, charThrowing->GetController(), charThrowing, nullptr);
						for(const FName& name : BuffNames)
							hitCharacter->GetStatControlComponent()->AddBuff(name);
					}
				}
			}
		}

	}
	Destroy();
}
