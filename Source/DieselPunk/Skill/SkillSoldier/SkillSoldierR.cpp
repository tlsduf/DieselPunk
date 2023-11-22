// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSoldierR.h"
#include "../../Actor\ProjectileBase.h"
#include "../../Character/CharacterPC.h"
#include "../../Logic/PlayerControllerBase.h"
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
	
	auto ownerPawn = Cast<ACharacterPC>(OwnerCharacter);
	
	//애니메이션 재생?
	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance());
	if (!animInst)
		return;
	
	if (!IsE)
	{

		// 쿨타임!!!!!!!!!!!!!!!!!!
		ownerPawn->SkillActivating[EAbilityType::SkillR] = true;
		
		animInst->PlayMontage(EAbilityType::SkillR, ESoldierSkillMontageType::Attack);
		
		//*기능 실현부
		// 마우스 화면 중앙위치 //TODO 필요에 따라 마우스 위치변경 //TODO 마우스 우클릭으로도 fire 가능하게
		int32 ScreenWidth;
		int32 ScreenHeight;
		Cast<APlayerController>(OwnerController)->GetViewportSize(ScreenWidth, ScreenHeight);
		Cast<APlayerController>(OwnerController)->SetMouseLocation(ScreenWidth * 0.5f, ScreenHeight * 0.5f);

		// 화면와이드아웃
		ownerPawn->MyTargetArmLength = 600;
		ownerPawn->MyTargetArmLocation = FVector(0, 0, 100);
		ownerPawn->MyCameraLocation = FVector(0, 0, 100);

		// 컨트롤러 rotation 조정
		// FRotator ThisRotation = PlayerController->GetControlRotation();
		// PlayerController->SetControlRotation(FRotator(0, ThisRotation.Yaw, ThisRotation.Roll));

		//*후행 조건 설정부
		IsE = true;
		ownerPawn->CanZoom = true;
		ownerPawn->CanCameraControl = false;
	}
	else if (IsE) //*선행 조건 설정부
	{

		/*// 쿨타임 감소
		float CoolDown = 0.5 * ownerPawn->PCSkillManager.SoldierSkillRUpgradeType[ESoldierSkillRUpgradeType::CoolDown];
		// 쿨타임!!!!!!!!!!!!!!!!!!
		CoolTimeHandler->SetCoolTime(CoolTime - CoolDown);
		ownerPawn->SkillActivating[EAbilityType::SkillR] = false;

		// 몽타주 정지
		animInst->StopMontage(EAbilityType::SkillR, 0.2f);
		
		//*기능 실현부
		FHitResult HitResult = UtilCollision::GetUnderCursor();
		AActor *HitActor = HitResult.GetActor();
		if (HitActor)
		{
			if(ProjectileClass)
			{
				FTransform SpawnTransform( FRotator(0,0, 0), HitResult.Location);
				Projectile = DpGetWorld()->SpawnActorDeferred<ASoldierProjectile>(ProjectileClass, SpawnTransform, GetOwner());

				Projectile->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillRUpgradeType[ESoldierSkillRUpgradeType::CoolDown];
				Projectile->Stack = 15;
				Projectile->AttackRadius += 30 * ownerPawn->PCSkillManager.SoldierSkillRUpgradeType[ESoldierSkillRUpgradeType::WideRange];
				
				Projectile->FinishSpawning(SpawnTransform);
			}
			if (PinPointHitEffect)
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PinPointHitEffect, HitResult.Location);
		}

		// 화면와이드인
		ownerPawn->MyTargetArmLength = 400.0f;
		ownerPawn->MyTargetArmLocation = FVector(0, 0, 55);
		ownerPawn->MyCameraLocation = FVector(0, 0, 55);

		//*후행 조건 설정부
		ownerPawn->CanZoom = true;
		ownerPawn->CanCameraControl = true;
		ownerPawn->DrawERange = false;

		//HandleCombatState();
		ownerPawn->CanJog = true;

		IsE = false;*/
	}
}

void USkillSoldierR::AfterLogic()
{
	auto ownerPawn = Cast<ACharacterPC>(OwnerCharacter);
	
	//애니메이션 재생?
	USoldierAnimInstance* animInst = Cast<USoldierAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance());
	if (!animInst)
		return;
	
	// 쿨타임 감소
	float CoolDown = 0.5 * ownerPawn->PCSkillManager.SoldierSkillRUpgradeType[ESoldierSkillRUpgradeType::CoolDown];
	// 쿨타임!!!!!!!!!!!!!!!!!!
	CoolTimeHandler->SetCoolTime(CoolTime - CoolDown);
	ownerPawn->SkillActivating[EAbilityType::SkillR] = false;

	// 몽타주 정지
	animInst->StopMontage(EAbilityType::SkillR, 0.2f);
		
	//*기능 실현부
	FHitResult HitResult = UtilCollision::GetUnderCursor();
	AActor *HitActor = HitResult.GetActor();
	if (HitActor)
	{
		if(ProjectileClass)
		{
			FTransform SpawnTransform( FRotator(0,0, 0), HitResult.Location);
			Projectile = GetWorld()->SpawnActorDeferred<AProjectileBase>(ProjectileClass, SpawnTransform, GetOwner());

			Projectile->Damage += 10 * ownerPawn->PCSkillManager.SoldierSkillRUpgradeType[ESoldierSkillRUpgradeType::CoolDown];
			Projectile->AttackRadius += 30 * ownerPawn->PCSkillManager.SoldierSkillRUpgradeType[ESoldierSkillRUpgradeType::WideRange];
				
			Projectile->FinishSpawning(SpawnTransform);
		}
		if (PinPointHitEffect)
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PinPointHitEffect, HitResult.Location);
	}

	// 화면와이드인
	ownerPawn->MyTargetArmLength = 400.0f;
	ownerPawn->MyTargetArmLocation = FVector(0, 0, 55);
	ownerPawn->MyCameraLocation = FVector(0, 0, 55);

	//*후행 조건 설정부
	ownerPawn->CanZoom = true;
	ownerPawn->CanCameraControl = true;

	//HandleCombatState();
	ownerPawn->CanJog = true;

	IsE = false;
}
