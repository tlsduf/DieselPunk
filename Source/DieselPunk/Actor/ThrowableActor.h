// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "../Interface/DpManagementTargetInterFace.h"
#include "DieselPunk/Interface/ThrowableInterface.h"
#include "ThrowableActor.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UCapsuleComponent;
class ACharacterBase;
class UPlayerSkill;

UCLASS()
class DIESELPUNK_API AThrowableActor : public AActor, public IDpManagementTargetInterFace, public IThrowableInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCapsuleComponent> CapsuleComponent = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> Mesh = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USphereComponent> SphereComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category="MYDP_Buff")
	TArray<FName> BuffNames;

	FTimerHandle NextTickDestroyHandle;

	float CachedMass = 100.f;

	float Damage = 100.f;
	
public:
	// Sets default values for this actor's properties
	AThrowableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetDamage(float InDamage){Damage = InDamage;}

public:
	virtual void ThrowReady(TWeakObjectPtr<AActor> InThrowingOwner) override;
	virtual void ThrowExecute(TWeakObjectPtr<AActor> InThrowingOwner) override;
	virtual void ThrowComplete() override;
};
