// Fill out your copyright notice in the Description page of Project Settings.


#include "../Animation/DPAnimInstance.h"
#include "../Character/CharacterBase.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

UDPAnimInstance::UDPAnimInstance()
{
}

void UDPAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Character = Cast<ACharacterBase>(TryGetPawnOwner());
}

void UDPAnimInstance::NativeUpdateAnimation(float InDeltaSeconds)
{
	Super::NativeUpdateAnimation(InDeltaSeconds);

	if(!Character.IsValid())
		return;
	
	IsInAir = Character->GetCharacterMovement()->IsFalling();
	
	Velocity = Character->GetCharacterMovement()->Velocity;
	
	ActorRotation = Character->GetActorRotation();
	BaseAimRotation = Character->GetBaseAimRotation();
	DeltaRotation = UKismetMathLibrary::NormalizedDeltaRotator( BaseAimRotation, ActorRotation);
	
	CharacterDirectionRotation = Character->GetBaseAimRotation() - ActorRotation;
	CharacterDirectionRotation.Normalize();
		
	Speed = Velocity.Length();
	
	HorizontalSpeed = FVector(Velocity.X, Velocity.Y, 0).Length();
	
	YawDelta = CalYawDelta(InDeltaSeconds);
	RotationLastTick = Character->GetActorRotation();
	
	IsAccelerating = Character->GetCharacterMovement()->GetCurrentAcceleration().Length() > 0;
	
	InCombat = Character->GetInCombat();
	
	IsDead = Character->IsDead();
}

// 캐릭터 회전에 따른 기울기를 계산합니다.
float UDPAnimInstance::CalYawDelta(float InDeltaSeconds)
{
	FRotator normalRot = Character->GetActorRotation() - RotationLastTick;
	normalRot.Normalize();

	return FMath::FInterpTo(
	YawDelta,
	(normalRot.Yaw / InDeltaSeconds) / LeanIntensityScaling,
	InDeltaSeconds,
	6.0);
}

void UDPAnimInstance::AttackSign(EAbilityType InUseSkillType)
{
	UseSkillType = InUseSkillType;
}

void UDPAnimInstance::AttackEndSign()
{
	UseSkillType = EAbilityType::None;
}

