// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierShift.h"
#include "..\..\Character\CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Handler/CoolTimeHandler.h"

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

void USkillSoldierShift::SkillStarted()
{
	Super::SkillStarted();
	
	OwnerCharacterPC->StartJog();
}

void USkillSoldierShift::SkillTriggered()
{
	Super::SkillTriggered();

	//OwnerCharacterPC->StartJog();
	//StartDash();
}

void USkillSoldierShift::SkillCompleted()
{
	OwnerCharacterPC->StopJog();
}

void USkillSoldierShift::StartDash()
{
		//Player의 이동방향
	FVector playerMovementDirection = OwnerCharacterPC->GetMovementComponent()->Velocity;
	playerMovementDirection.Z = 0;
	playerMovementDirection.Normalize();

	//Controller 방향
	FVector controllerDirection = OwnerCharacterPC->GetController()->GetControlRotation().Vector();
	controllerDirection.Z = 0;
	controllerDirection.Normalize();

	//내적을 통해 사잇각 확인
	double dotResult = FVector::DotProduct(playerMovementDirection, controllerDirection);

	// 뒤로가는 키(s) 가 눌려있을 때 즉, 뒤로가는 중이면 리턴
	if(dotResult < -0.01)
		return;
	
	// 쿨타임!!!!!!!!!!!!!!!!!!
	CoolTimeHandler->SetCoolTime(CoolTime);
	OwnerCharacterPC->SkillActivating[EAbilityType::Shift] = true;
	TWeakObjectPtr<USkillSoldierShift> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(PlaySkillTHandle, [thisPtr]()
	{
		if(thisPtr.IsValid())
			thisPtr->OwnerCharacterPC->SkillActivating[EAbilityType::Shift] = false;
	},SkillPlayTime, false);
	
	const FVector currentAcceleration = OwnerCharacterPC->GetCharacterMovement()->GetCurrentAcceleration();
	float currentAccelLength = currentAcceleration.SizeSquared();
	if (CanDash && currentAccelLength > 0 )
	{
		// (Run)
		OwnerCharacterPC->StartJog();
		
		// 카메라방향으로 대쉬
		const FRotator rotation = OwnerController->GetControlRotation();	//카메라방향으로 대쉬
		const FVector direction = FRotationMatrix(rotation).GetUnitAxis(EAxis::X);
		OwnerCharacterPC->GetCharacterMovement()->BrakingFrictionFactor = 0.f;
		OwnerCharacterPC->LaunchCharacter(direction * DashDistance, true, true);
		

		// 액터정면방향으로 대쉬 (Yaw방향) //
		/*
		const FRotator rotation = OwnerCharacterPC->GetActorRotation();	//이동방향으로 대쉬
		const FRotator yawRotation(0, rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
		OwnerCharacterPC->GetCharacterMovement()->BrakingFrictionFactor = 0.f;
		OwnerCharacterPC->LaunchCharacter(Direction * DashDistance, true, true);
		*/
		
		// 액터의 진행방향으로 대쉬 (Yaw방향) //
		/*
		OwnerCharacterPC->GetCharacterMovement()->BrakingFrictionFactor = 0.f;
		OwnerCharacterPC->LaunchCharacter(currentAcceleration.GetSafeNormal() * DashDistance, true, true);	//현재 가고있는방향으로 대쉬
		*/
		
		// 일정시간동안 스피드업 //
		/*
		OwnerCharacterPC->GetCharacterMovement()->MaxWalkSpeed = DashDistance;	//다른종류의 대쉬(일정시간동안 스피드업)
		*/

		//*후행 조건 설정부
		IsDash = true;
		CanDash = false;
		
		GetWorld()->GetTimerManager().SetTimer(DashTHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->StopDashing();
			},DashingTime, false);

		//애니메이션 재생
		if(USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(OwnerCharacterPC->GetMesh()->GetAnimInstance()))
		{
			animInst->Montage_Stop(0.1);
			animInst->PlayMontage(EAbilityType::Shift, ESoldierSkillMontageType::Attack);
		}
	}
}

void USkillSoldierShift::StopDashing()
{
	OwnerCharacterPC->GetCharacterMovement()->StopMovementImmediately();
	TWeakObjectPtr<USkillSoldierShift> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(DashTHandle, [thisPtr](){
		if(thisPtr.IsValid())
			thisPtr->ResetDash();
	},0.2f, false);
	OwnerCharacterPC->GetCharacterMovement()->BrakingFrictionFactor = 2.f;
}
void USkillSoldierShift::ResetDash()
{
	IsDash = false;
	CanDash = true;
}
