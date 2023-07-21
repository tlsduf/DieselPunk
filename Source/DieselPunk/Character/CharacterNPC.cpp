// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNPC.h"
#include "../Skill/PlayerSkill.h"

#include <Components/InputComponent.h>

#include <TimerManager.h>
#include <Kismet/GameplayStatics.h>
#include <Particles/ParticleSystemComponent.h>
#include <Components/SkeletalMeshComponent.h>


ACharacterNPC::ACharacterNPC()
{
	MeleeAttack = CreateDefaultSubobject<UPlayerSkill>(TEXT("MeleeAttack"));
	ProjectileAttack = CreateDefaultSubobject<UPlayerSkill>(TEXT("ProjectileAttack"));
}

void ACharacterNPC::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterNPC::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	//PlayerInputComponent->BindAction("LeftMouse", IE_Pressed, this, &ABaseEnemyCharacter::MeleeAttackHandle);
	//PlayerInputComponent->BindAction("RightMouse", IE_Pressed, this, &ABaseEnemyCharacter::DoProjectileAttack);
}

void ACharacterNPC::MeleeAttackHandle()
{
	if (CanMeleeAttack)
	{
		GetWorldTimerManager().SetTimer(MeleeAttackTHandle, this, &ACharacterNPC::DoMeleeAttack, 0.50f, false);
		CanMeleeAttack = false;
		GetWorldTimerManager().SetTimer(CanMeleeAttackTHandle, this, &ACharacterNPC::SetCanMeleeAttackTrue, 1.10f, false);
		DoingMeleeAttack = true;
		GetWorldTimerManager().SetTimerForNextTick(this, &ACharacterNPC::SetDoingMeleeAttackFalse);
	}
}
void ACharacterNPC::DoMeleeAttack()
{
	MeleeAttack->SkillTriggered();
}

void ACharacterNPC::SetCanMeleeAttackTrue()
{
	CanMeleeAttack = true;
}
void ACharacterNPC::SetDoingMeleeAttackFalse()
{
	DoingMeleeAttack = false;
}

void ACharacterNPC::DoProjectileAttack()
{
	ProjectileAttack->SkillTriggered();

	FVector Location = GetMesh()->GetSocketLocation("Granade_socket");
	if (GranadeMuzzleEffect)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), GranadeMuzzleEffect, Location, GetActorRotation() + FRotator(0, 180, 0));
	}
}
