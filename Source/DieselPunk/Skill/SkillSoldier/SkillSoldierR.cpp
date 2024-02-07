// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierR.h"
#include "../../Actor\ProjectileBase.h"
#include "../../Character/CharacterPC.h"
#include "../../Animation/SoldierAnimInstance.h"
#include "../../Handler/CoolTimeHandler.h"
#include "../../Util/UtilCollision.h"

#include <GameFramework/PlayerController.h>
#include <Kismet/GameplayStatics.h>
#include <Components/SkeletalMeshComponent.h>


USkillSoldierR::USkillSoldierR() : Super()
{
	PrimaryComponentTick.bCanEverTick = false; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSoldierR::BeginPlay()
{
	Super::BeginPlay();
}

void USkillSoldierR::SkillTriggered()
{
	Super::SkillTriggered();
	
	//애니메이션 재생
	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(OwnerCharacterPC->GetMesh()->GetAnimInstance());
	if (!animInst)
		return;
	
	if (!IsE)
	{
		// 쿨타임
		OwnerCharacterPC->SkillActivating[EAbilityType::SkillR] = true;

		// 애니메이션 재생
		animInst->PlayMontage(EAbilityType::SkillR, ESoldierSkillMontageType::Attack);
		
		//*기능 실현부
		// 마우스 화면 중앙위치 //TODO 필요에 따라 마우스 위치변경 //TODO 마우스 우클릭으로도 fire 가능하게
		int32 screenWidth;
		int32 screenHeight;
		Cast<APlayerController>(OwnerController)->GetViewportSize(screenWidth, screenHeight);
		Cast<APlayerController>(OwnerController)->SetMouseLocation(screenWidth * 0.5f, screenHeight * 0.5f);

		// 화면와이드아웃
		OwnerCharacterPC->MyTargetArmLength = 600;
		OwnerCharacterPC->MyTargetArmLocation = FVector(0, 0, 100);
		OwnerCharacterPC->MyCameraLocation = FVector(0, 0, 100);

		// 컨트롤러 rotation 조정
		// FRotator ThisRotation = PlayerController->GetControlRotation();
		// PlayerController->SetControlRotation(FRotator(0, ThisRotation.Yaw, ThisRotation.Roll));

		//*후행 조건 설정부
		IsE = true;
		OwnerCharacterPC->CanZoom = true;
		OwnerCharacterPC->CanCameraControl = false;
	}
	else if (IsE)
	{
		AfterLogic();
	}
}

void USkillSoldierR::AfterLogic()
{
	//애니메이션 재생?
	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(OwnerCharacterPC->GetMesh()->GetAnimInstance());
	if (!animInst)
		return;
	
	// 쿨타임
	CoolTimeHandler->SetCoolTime(CoolTime);
	OwnerCharacterPC->SkillActivating[EAbilityType::SkillR] = false;

	// 몽타주 정지
	animInst->StopMontage(EAbilityType::SkillR, 0.2f);
		
	//*기능 실현부
	FHitResult hitResult = UtilCollision::GetUnderCursor(GetWorld());
	AActor *hitActor = hitResult.GetActor();
	if (hitActor)
	{
		if(ProjectileClass)
		{
			FTransform spawnTransform( FRotator(0,0, 0), hitResult.Location);
			AProjectileBase *Projectile = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, spawnTransform, GetOwner());
			Projectile->FinishSpawning(spawnTransform);
		}
	}

	// 화면와이드인
	OwnerCharacterPC->MyTargetArmLength = 400.0f;
	OwnerCharacterPC->MyTargetArmLocation = FVector(0, 0, 55);
	OwnerCharacterPC->MyCameraLocation = FVector(0, 0, 55);

	//*후행 조건 설정부
	OwnerCharacterPC->CanZoom = true;
	OwnerCharacterPC->CanCameraControl = true;

	//HandleCombatState();
	OwnerCharacterPC->CanJog = true;

	IsE = false;
}
