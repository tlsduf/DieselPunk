// Fill out your copyright notice in the Description page of Project Settings.

#include "MokoshMeleeAttack.h"
#include "..\..\Character\CharacterNPC.h"
#include "../../Animation/TurretAnimInstace.h"

#include <Kismet/GameplayStatics.h>
#include <Components/SkeletalMeshComponent.h>

#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "DieselPunk/Component/StatControlComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


UMokoshMeleeAttack::UMokoshMeleeAttack() : Super()
{
	SkillRangeType = ESkillDistanceType::MeleeAttack;
}

void UMokoshMeleeAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UMokoshMeleeAttack::AbilityStart(AActor* InTarget)
{
	Super::AbilityStart(InTarget);
	
	if(InTarget == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("타겟정보 NULL"));
		return;
	}
	
	auto ownerPawn = Cast<ACharacterBase>(OwnerCharacter);
	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance()))	
		animInst->AttackSign(EAbilityType::MouseLM);
}

void UMokoshMeleeAttack::AbilityShot(double InDamageCoefficient, AActor* InTarget)
{
	Super::AbilityShot(InDamageCoefficient, InTarget);

	if(InTarget == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("타겟정보 NULL"));
		return;
	}

	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);
	
	// Shot Effect
	FEffectTransform shotET;
	shotET.Location = ShotEffectTransform.Location + ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
	shotET.Rotation = ShotEffectTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket");
	shotET.Scale = ShotEffectTransform.Scale;
	if (N_ShotEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_ShotEffect, shotET);
	if (ShotEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), ShotEffect, shotET);

	//타겟 타입 검색
	TArray<ECharacterType> targetTypes;
	if(ownerPawn->GetCharacterType() == ECharacterType::Monster)
	{
		targetTypes.Add(ECharacterType::Player);
		targetTypes.Add(ECharacterType::Turret);
		targetTypes.Add(ECharacterType::Installation);
	}
	else if(ownerPawn->GetCharacterType() == ECharacterType::Player || ownerPawn->GetCharacterType() == ECharacterType::Turret)
	{
		targetTypes.Add(ECharacterType::Monster);
	}

	FVector ownerLoc = ownerPawn->GetActorLocation();
	FQuat ownerQuat = ownerPawn->GetActorQuat();
	//충돌체크
	if(SkillHittingRange == ESearchAreaType::Circle)
	{
		TArray<FOverlapResult> results;
		if(GetWorld()->OverlapMultiByChannel(results, ownerLoc, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(MaxRange)))
		{
			TArray<FOverlapResult> filterResults = results.FilterByPredicate([targetTypes](const FOverlapResult& result)
			{
				if(ACharacterBase* charBase = Cast<ACharacterBase>(result.GetActor()))
					return targetTypes.Find(charBase->GetCharacterType()) != INDEX_NONE;
				return false;
			});

			for(const FOverlapResult& result : filterResults)
			{
				UGameplayStatics::ApplyDamage(result.GetActor(), Damage * InDamageCoefficient, OwnerController, ownerPawn, nullptr);
				// Hit Effect
				FEffectTransform hitET;
				hitET.Location = HitEffectFTransform.Location + result.GetActor()->GetActorLocation();
				hitET.Rotation = HitEffectFTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
				hitET.Scale = HitEffectFTransform.Scale;
				if (N_HitEffect)
					UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitET);
				if (HitEffect)
					UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitET);

				//밀치기
				UCharacterMovementComponent* movementComponent = Cast<UCharacterMovementComponent>(Cast<ACharacterBase>(result.GetActor())->GetMovementComponent());
				if(RadialImpulse && movementComponent)
				{
					movementComponent->AddRadialImpulse(ownerPawn->GetActorLocation(), MaxRange, RadialImpulseStrength, RIF_Constant, true);
				}

				//버프
				UStatControlComponent* statComponent = Cast<UStatControlComponent>(Cast<ACharacterBase>(result.GetActor())->GetStatControlComponent());
				if(statComponent)
				{
					for(const FName& buff : Buffs)
					{
						statComponent->AddBuff(buff);
					}
				}
			}
		}
		DrawDebugSphere(GetWorld(), ownerLoc, MaxRange, 12, FColor::Cyan, false, 2, 0, 3);
	}
	else if(SkillHittingRange == ESearchAreaType::Rectangle)
	{
		TArray<FOverlapResult> results;
		if(GetWorld()->OverlapMultiByChannel(results, ownerLoc, ownerQuat, ECC_WorldStatic, FCollisionShape::MakeBox(RectangleRangeInfo.BoxExtend / 2.f)))
		{
			TArray<FOverlapResult> filterResults = results.FilterByPredicate([targetTypes](const FOverlapResult& result)
			{
				if(ACharacterBase* charBase = Cast<ACharacterBase>(result.GetActor()))
					return targetTypes.Find(charBase->GetCharacterType()) != INDEX_NONE;
				return false;
			});

			for(const FOverlapResult& result : filterResults)
			{
				UGameplayStatics::ApplyDamage(result.GetActor(), Damage * InDamageCoefficient, OwnerController, ownerPawn, nullptr);
				// Hit Effect
				FEffectTransform hitET;
				hitET.Location = HitEffectFTransform.Location + result.GetActor()->GetActorLocation();
				hitET.Rotation = HitEffectFTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
				hitET.Scale = HitEffectFTransform.Scale;
				if (N_HitEffect)
					UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitET);
				if (HitEffect)
					UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitET);

				//밀치기
				UCharacterMovementComponent* movementComponent = Cast<UCharacterMovementComponent>(Cast<ACharacterBase>(result.GetActor())->GetMovementComponent());
				if(RadialImpulse && movementComponent)
				{
					movementComponent->AddRadialImpulse(ownerPawn->GetActorLocation(), MaxRange, RadialImpulseStrength, RIF_Constant, true);
				}

				//버프
				UStatControlComponent* statComponent = Cast<UStatControlComponent>(Cast<ACharacterBase>(result.GetActor())->GetStatControlComponent());
				if(statComponent)
				{
					for(const FName& buff : Buffs)
					{
						statComponent->AddBuff(buff);
					}
				}
			}
		}
		DrawDebugBox(GetWorld(), ownerLoc, RectangleRangeInfo.BoxExtend / 2.f, FColor::Cyan, false, 2, 0, 3);
	}
	else if(SkillHittingRange == ESearchAreaType::Arc)
	{
		TArray<FOverlapResult> results;
		if(GetWorld()->OverlapMultiByChannel(results, ownerLoc, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(MaxRange)))
		{
			FVector ownerForwardVector = ownerPawn->GetActorForwardVector();
			float angle = ArcRangeInfo.Angle;
			TArray<FOverlapResult> filterResults = results.FilterByPredicate([targetTypes, ownerLoc, ownerForwardVector, angle](const FOverlapResult& result)
			{
				bool istargetType = false;
				bool isRange = false;
				if(ACharacterBase* charBase = Cast<ACharacterBase>(result.GetActor()))
					istargetType = targetTypes.Find(charBase->GetCharacterType()) != INDEX_NONE;

				FVector ownerToTarget = result.GetActor()->GetActorLocation() - ownerLoc;
				ownerToTarget.Normalize();

				isRange = FVector::DotProduct(ownerToTarget, ownerForwardVector) >= FMath::Cos(FMath::DegreesToRadians(angle / 2.f));
				
				return istargetType && isRange;
			});

			for(const FOverlapResult& result : filterResults)
			{
				UGameplayStatics::ApplyDamage(result.GetActor(), Damage * InDamageCoefficient, OwnerController, ownerPawn, nullptr);
				// Hit Effect
				FEffectTransform hitET;
				hitET.Location = HitEffectFTransform.Location + result.GetActor()->GetActorLocation();
				hitET.Rotation = HitEffectFTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
				hitET.Scale = HitEffectFTransform.Scale;
				if (N_HitEffect)
					UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitET);
				if (HitEffect)
					UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitET);

				//밀치기
				UCharacterMovementComponent* movementComponent = Cast<UCharacterMovementComponent>(Cast<ACharacterBase>(result.GetActor())->GetMovementComponent());
				if(RadialImpulse && movementComponent)
				{
					movementComponent->AddRadialImpulse(ownerPawn->GetActorLocation(), MaxRange, RadialImpulseStrength, RIF_Constant, true);
				}

				//버프
				UStatControlComponent* statComponent = Cast<UStatControlComponent>(Cast<ACharacterBase>(result.GetActor())->GetStatControlComponent());
				if(statComponent)
				{
					for(const FName& buff : Buffs)
					{
						statComponent->AddBuff(buff);
					}
				}
			}
		}
		DrawDebugCone(GetWorld()
			, ownerLoc
			, ownerPawn->GetActorForwardVector()
			, MaxRange
			, FMath::DegreesToRadians(ArcRangeInfo.Angle)
			, FMath::DegreesToRadians(ArcRangeInfo.Angle)
			, 12, FColor::Cyan, false, 2, 0, 3);
	}

	
	UGameplayStatics::ApplyDamage(InTarget, Damage, OwnerController, ownerPawn, nullptr);
}
