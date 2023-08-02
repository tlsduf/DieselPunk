// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierShift.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"

#include <GameFramework/Character.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <Components/SkeletalMeshComponent.h>

USkillSoldierShift::USkillSoldierShift() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierShift::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierShift::SkillTriggered()
{
	Super::SkillTriggered();

	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
		return;

	const FVector currentAcceleration = ownerPawn->GetCharacterMovement()->GetCurrentAcceleration();
	float currentAccelLength = currentAcceleration.SizeSquared();
	if (CanDash && currentAccelLength > 0)
	{
		// const FRotator Rotation = Controller->GetControlRotation();	//카메라방향으로 대쉬
		const FRotator rotation = ownerPawn->GetActorRotation();	//이동방향으로 대쉬
		const FRotator yawRotation(0, rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
		ownerPawn->GetCharacterMovement()->BrakingFrictionFactor = 0.f;
		ownerPawn->LaunchCharacter(currentAcceleration.GetSafeNormal() * DashDistance, true, true);
		// GetCharacterMovement()->MaxWalkSpeed = DashDistance;	//다른종류의 대쉬(일정시간동안 스피드업)

		//UParticleSystemComponent *ParticleSystemComponent = UGameplayStatics::SpawnEmitterAttached(DashEffect, GetRootComponent());

		//*후행 조건 설정부
		IsDash = true;
		CanDash = false;
		InCooldownDash = true;

		ownerPawn->SetZoomOutProp();

		ownerPawn->GetWorldTimerManager().SetTimer(DashTHandle, this, &USkillSoldierShift::StopDashing, DashingTime, false);

		//애니메이션 재생?
		USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance());
		if (!animInst)
			return;

		animInst->PlayMontage(EAbilityType::Shift, ESoldierSkillMontageType::AroundAttack1);
	}
}
void USkillSoldierShift::StopDashing()
{
	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
	{
		return;
	}
	ownerPawn->GetCharacterMovement()->StopMovementImmediately();
	ownerPawn->GetWorldTimerManager().SetTimer(DashTHandle, this, &USkillSoldierShift::ResetDash, 0.2f, false);
	ownerPawn->GetCharacterMovement()->BrakingFrictionFactor = 2.f;
}
void USkillSoldierShift::ResetDash()
{
	auto ownerPawn = Cast<ACharacterPC>(GetOwner());
	if(ownerPawn == nullptr)
	{
		return;
	}
	IsDash = false;
	CanDash = true;
	//SetInCombatFalse();
	ownerPawn->IsJog = true;

	ownerPawn->GetWorldTimerManager().SetTimer(DashTHandle, this, &USkillSoldierShift::ResetCooldownDash, ShiftCooldownTime, false);
}
void USkillSoldierShift::ResetCooldownDash()
{
	InCooldownDash = false;
}