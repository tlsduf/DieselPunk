// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCAttack.h"
#include "..\..\Character\CharacterNPC.h"
#include "../../Util/SplineConstructor.h"
#include "../../Animation/TurretAnimInstace.h"

#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>
#include <DrawDebugHelpers.h>

#include "Components/CapsuleComponent.h"
#include "DieselPunk/Actor/ParabolaSkillActorBase.h"
#include "DieselPunk/Actor/ProjectileSkillActorBase.h"
#include "DieselPunk/Actor/StraightSkillActorBase.h"
#include "DieselPunk/Actor/ThrowableActor.h"
#include "DieselPunk/Character/CharacterMonster.h"
#include "DieselPunk/Component/StatControlComponent.h"
#include "DieselPunk/Data/NPCSkillDataTable.h"
#include "DieselPunk/Data/ProjectileSkillActorDataTable.h"
#include "DieselPunk/Manager/DatatableManager.h"
#include "DieselPunk/Manager/ObjectManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


UNPCAttack::UNPCAttack() : Super()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UNPCAttack::BeginPlay()
{
	Super::BeginPlay();
}

void UNPCAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(SnipingStart)
	{
		ACharacterMonster* monster = Cast<ACharacterMonster>(OwnerCharacter);
		if(monster)
		{
			if(!monster->GetAttackTarget().IsValid() || CurrentTarget != monster->GetAttackTarget())
			{
				if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(monster->GetMesh()->GetAnimInstance()))
					animInst->AttackEndSign();
				SnipingStart = false;
				CurrentTarget = monster->GetAttackTarget().IsValid() ? monster->GetAttackTarget() : nullptr;

				return;
			}
			DrawDebugLine(GetWorld(), monster->GetMesh()->GetSocketLocation(TEXT("Grenade_socket")), monster->GetAttackTarget()->GetActorLocation(), FColor::Red);
		}
	}
}

void UNPCAttack::AbilityStart(AActor* InTarget)
{
	Super::AbilityStart(InTarget);

	if(ProjectileType != EProjectileType::SuicideBomb && InTarget == nullptr)
	{
		LOG_SCREEN(FColor::Red, TEXT("타겟정보 NULL"));
		return;
	}
	
	auto ownerPawn = Cast<ACharacterBase>(OwnerCharacter);
	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(ownerPawn->GetMesh()->GetAnimInstance()))	
		animInst->AttackSign(EAbilityType::MouseLM);
	LOG_SCREEN(FColor::White, TEXT("를 사용합니다."))

	if(ProjectileType == EProjectileType::Throwing)
	{
		FSpawnParam param;
		param.Location = FVector::ZeroVector;
		param.Rotation = FRotator::ZeroRotator;
		param.CallBackSpawn = nullptr;
		ThrowActorId = FObjectManager::GetInstance()->CreateActor<AActor>(ThrowingActorClass, param, ownerPawn);
		AActor* throwActor = FObjectManager::GetInstance()->FindActor(ThrowActorId);
		IThrowableInterface* throwInterface = Cast<IThrowableInterface>(throwActor);
		if(throwInterface)
			throwInterface->ThrowReady(OwnerCharacter);
		AThrowableActor* throwableActor = Cast<AThrowableActor>(throwActor);
		if(throwableActor)
			throwableActor->SetDamage(Damage);
		throwActor->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("ThrowingActorSocket"));
	}
	else if(ProjectileType == EProjectileType::SuicideBomb)
	{
		AbilityShot(1.f, InTarget);
	}
	else if(ProjectileType == EProjectileType::Sniping)
	{
		SnipingStart = true;
		CurrentTarget = InTarget;
	}
}

// 설정된 Transform으로 투사체를 생성합니다.
void UNPCAttack::AbilityShot(double InDamageCoefficient, AActor* InTarget)
{
	Super::AbilityShot(InDamageCoefficient, InTarget);
	
	if(ProjectileType != EProjectileType::SuicideBomb && InTarget == nullptr)
		return;
	
	auto ownerPawn = Cast<ACharacterNPC>(OwnerCharacter);
	if(!ownerPawn)
		return;
	
	if(ProjectileType == EProjectileType::TargetAttack)
	{
		TArray<FHitResult> results;
		if(ownerPawn->GetCharacterType() == ECharacterType::Player || ownerPawn->GetCharacterType() == ECharacterType::Turret)
		{
			GetWorld()->LineTraceMultiByChannel(results, ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket"), InTarget->GetActorLocation()
			, ECC_DP_PlayerChannel);
		}
		else if(ownerPawn->GetCharacterType() == ECharacterType::Monster)
		{
			GetWorld()->LineTraceMultiByChannel(results, ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket"), InTarget->GetActorLocation()
			, ECC_DP_EnemyChannel);
		}

		if(!results.IsEmpty())
		{
			for(const FHitResult& hitResult : results)
			{
				if(hitResult.GetActor() == InTarget)
				{
					FEffectTransform hitET;
					hitET.Location = HitEffectTransform.Location + hitResult.Location;
					hitET.Rotation = HitEffectTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
					hitET.Scale = HitEffectTransform.Scale;
					if (N_HitEffect)
						UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitET);
					if (HitEffect)
						UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitET);
				}
			}
		}
		UGameplayStatics::ApplyDamage(InTarget, Damage * InDamageCoefficient, OwnerController, nullptr, nullptr);
	}
	else if(ProjectileType == EProjectileType::Straight)
	{
		FSpawnParam param;
		param.Location = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
		param.Rotation = ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket");

		TWeakObjectPtr<UNPCAttack> thisPtr = this;
		float damage = Damage;
		float maxRange = MaxRange;
		FName projectileName = ProjectileName;
		param.CallBackSpawn = [thisPtr, damage, maxRange, projectileName](AActor* InActor)
		{
			if(thisPtr.IsValid())
			{
				AStraightSkillActorBase* straight = Cast<AStraightSkillActorBase>(InActor);
				straight->SetDamage(damage);
				straight->SetMaxRange(maxRange);
				straight->SetProjectileSkillActorName(projectileName);
			}
		};
		const FProjectileSkillActorDataTable* table = FDataTableManager::GetInstance()->GetData<FProjectileSkillActorDataTable>(EDataTableType::ProjectileSkillActor, projectileName.ToString());
		if(table)
			FObjectManager::GetInstance()->CreateActor<AProjectileSkillActorBase>(table->ProjectileSkillActorClass, param, ownerPawn);
	}
	else if(ProjectileType == EProjectileType::Parabola)
	{
		FSpawnParam param;
		param.Location = ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket");
		param.Rotation = ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket");

		TWeakObjectPtr<UNPCAttack> thisPtr = this;
		TWeakObjectPtr<AActor> targetPtr = InTarget;
		FName projectileName = ProjectileName;
		float damage = Damage;
		float maxRange = MaxRange;
		int32 minRange = 0;
		ACharacterNPC* npc = Cast<ACharacterNPC>(OwnerCharacter);
		int32 shellFall = OwnerCharacter->GetStat(ECharacterStatType::ShellFall);
		if(npc)
			minRange = npc->GetSearchAreaData().AtkMinRange;
		param.CallBackSpawn = [thisPtr, damage, maxRange, targetPtr, projectileName, minRange, shellFall](AActor* InActor)
		{
			if(thisPtr.IsValid() && targetPtr.IsValid())
			{
				AParabolaSkillActorBase* parabola = Cast<AParabolaSkillActorBase>(InActor);
				parabola->SetDamage(damage);
				parabola->SetMaxRange(maxRange);
				parabola->SetGoalLocation(targetPtr->GetActorLocation());
				parabola->SetProjectileSkillActorName(projectileName);
				parabola->SetMinRange(minRange);
				parabola->SetShellFall(shellFall);
			}
		};
		const FProjectileSkillActorDataTable* table = FDataTableManager::GetInstance()->GetData<FProjectileSkillActorDataTable>(EDataTableType::ProjectileSkillActor, projectileName.ToString());
		if(table)
			FObjectManager::GetInstance()->CreateActor<AProjectileSkillActorBase>(table->ProjectileSkillActorClass, param, ownerPawn);
	}
	else if(ProjectileType == EProjectileType::Throwing)
	{
		if(MaxRange <= 0)
		{
			LOG_SCREEN(FColor::Red, TEXT("액터: %s의 ThrowingAttack: %s의 MaxRange가 0보다 작습니다."), *OwnerCharacter->GetName(), *GetName())
			return;
		}

		if(!FObjectManager::IsValidId(ThrowActorId))
			return;
		
		FVector startLocation = ownerPawn->GetMesh()->GetSocketLocation(TEXT("ThrowingActorSocket"));
		FVector goalLocation = InTarget->GetActorLocation();
		FVector outVelocity = FVector::ZeroVector;
		//if(UGameplayStatics::SuggestProjectileVelocity(this, outVelocity, startLocation, goalLocation, InitSpeed, HighArc, 0, GetWorld()->GetGravityZ(), ESuggestProjVelocityTraceOption::DoNotTrace))
		if(UGameplayStatics::SuggestProjectileVelocity_CustomArc(this, outVelocity, startLocation, goalLocation, GetWorld()->GetGravityZ(), ArcValue))
		{
			float flightTime = FVector::Distance(startLocation, goalLocation) * MaxFlightTime / MaxRange;
			FPredictProjectilePathParams predictParams(20.f, startLocation, outVelocity, flightTime);
			predictParams.DrawDebugTime = flightTime;
			predictParams.DrawDebugType = EDrawDebugTrace::Type::ForDuration;
			predictParams.OverrideGravityZ = GetWorld()->GetGravityZ();
			FPredictProjectilePathResult result;
			UGameplayStatics::PredictProjectilePath(this, predictParams, result);
	
			if(AActor* throwActor = FObjectManager::GetInstance()->FindActor(ThrowActorId))
			{
				throwActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				
				IThrowableInterface* throwInterface = Cast<IThrowableInterface>(throwActor);
				if(!throwInterface)
					return;
	
				throwInterface->ThrowExecute(OwnerCharacter);
					
				UActorComponent* actorComp = throwActor->GetComponentByClass(UMovementComponent::StaticClass());
				if(UCharacterMovementComponent* charMovementComp = Cast<UCharacterMovementComponent>(actorComp))
				{
					TWeakObjectPtr<UCharacterMovementComponent> moveCompPtr = charMovementComp;
					throwActor->GetWorldTimerManager().SetTimerForNextTick([moveCompPtr, outVelocity]()
					{
						if(moveCompPtr.IsValid())
							moveCompPtr->AddImpulse(outVelocity);
					});
				}
				else if(UProjectileMovementComponent* projMovementComp = Cast<UProjectileMovementComponent>(actorComp))
				{
					TWeakObjectPtr<UProjectileMovementComponent> moveCompPtr = projMovementComp;
					throwActor->GetWorldTimerManager().SetTimerForNextTick([moveCompPtr, outVelocity]()
					{
						if(moveCompPtr.IsValid())
							moveCompPtr->Velocity += outVelocity;
					});
				}
			}
		}
	}
	else if(ProjectileType == EProjectileType::SuicideBomb)
	{
		FCollisionQueryParams param;
		param.AddIgnoredActor(ownerPawn);
		TArray<FOverlapResult> overlapResults;
		if(GetWorld()->OverlapMultiByChannel(overlapResults, ownerPawn->GetActorLocation(), FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(SuicideBombRadius), param))
		{
			for(const FOverlapResult& result : overlapResults)
			{
				ACharacterBase* charBase = Cast<ACharacterBase>(result.GetActor());
				if(!charBase)
					continue;
			
				if(ownerPawn->GetCharacterType() == ECharacterType::Player || ownerPawn->GetCharacterType() == ECharacterType::Turret)
				{
					if(charBase->GetCharacterType() == ECharacterType::Monster)
						UGameplayStatics::ApplyDamage(charBase, Damage * InDamageCoefficient, OwnerController, nullptr, nullptr);
				}
				else if(ownerPawn->GetCharacterType() == ECharacterType::Monster)
				{
					if(charBase->GetCharacterType() == ECharacterType::Player
					|| charBase->GetCharacterType() == ECharacterType::Turret
					|| charBase->GetCharacterType() == ECharacterType::Installation)
						UGameplayStatics::ApplyDamage(charBase, Damage * InDamageCoefficient, OwnerController, nullptr, nullptr);
				}
			}
		}
		DrawDebugSphere(GetWorld(), ownerPawn->GetActorLocation(), SuicideBombRadius, 12, FColor::Red, false, 3, 0, 2);
		ownerPawn->GetStatControlComponent()->SetStat(ECharacterStatType::Hp, 0);
	}
	else if(ProjectileType == EProjectileType::Melee)
	{
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
					UGameplayStatics::ApplyDamage(result.GetActor(), Damage * InDamageCoefficient, OwnerController, nullptr, nullptr);
					// Hit Effect
					FEffectTransform hitET;
					hitET.Location = HitEffectTransform.Location + result.GetActor()->GetActorLocation();
					hitET.Rotation = HitEffectTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
					hitET.Scale = HitEffectTransform.Scale;
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
			if(GetWorld()->OverlapMultiByChannel(results, ownerLoc, ownerQuat, ECC_WorldStatic, FCollisionShape::MakeBox(RectangleBoxExtend / 2.f)))
			{
				TArray<FOverlapResult> filterResults = results.FilterByPredicate([targetTypes](const FOverlapResult& result)
				{
					if(ACharacterBase* charBase = Cast<ACharacterBase>(result.GetActor()))
						return targetTypes.Find(charBase->GetCharacterType()) != INDEX_NONE;
					return false;
				});
	
				for(const FOverlapResult& result : filterResults)
				{
					UGameplayStatics::ApplyDamage(result.GetActor(), Damage * InDamageCoefficient, OwnerController, nullptr, nullptr);
					// Hit Effect
					FEffectTransform hitET;
					hitET.Location = HitEffectTransform.Location + result.GetActor()->GetActorLocation();
					hitET.Rotation = HitEffectTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
					hitET.Scale = HitEffectTransform.Scale;
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
			DrawDebugBox(GetWorld(), ownerLoc, RectangleBoxExtend / 2.f, FColor::Cyan, false, 2, 0, 3);
		}
		else if(SkillHittingRange == ESearchAreaType::Arc)
		{
			TArray<FOverlapResult> results;
			if(GetWorld()->OverlapMultiByChannel(results, ownerLoc, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(MaxRange)))
			{
				FVector ownerForwardVector = ownerPawn->GetActorForwardVector();
				float angle = ArcAngle;
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
					UGameplayStatics::ApplyDamage(result.GetActor(), Damage * InDamageCoefficient, OwnerController, nullptr, nullptr);
					// Hit Effect
					FEffectTransform hitET;
					hitET.Location = HitEffectTransform.Location + result.GetActor()->GetActorLocation();
					hitET.Rotation = HitEffectTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
					hitET.Scale = HitEffectTransform.Scale;
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
				, FMath::DegreesToRadians(ArcAngle)
				, FMath::DegreesToRadians(ArcAngle)
				, 12, FColor::Cyan, false, 2, 0, 3);
		}
	
		
		UGameplayStatics::ApplyDamage(InTarget, Damage, OwnerController, nullptr, nullptr);
	}
	else if(ProjectileType == EProjectileType::Sniping)
	{
		TArray<FHitResult> results;
		if(ownerPawn->GetCharacterType() == ECharacterType::Player || ownerPawn->GetCharacterType() == ECharacterType::Turret)
		{
			GetWorld()->LineTraceMultiByChannel(results, ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket"), InTarget->GetActorLocation()
			, ECC_DP_PlayerChannel);
		}
		else if(ownerPawn->GetCharacterType() == ECharacterType::Monster)
		{
			GetWorld()->LineTraceMultiByChannel(results, ownerPawn->GetMesh()->GetSocketLocation("Grenade_socket"), InTarget->GetActorLocation()
			, ECC_DP_EnemyChannel);
		}

		if(!results.IsEmpty())
		{
			for(const FHitResult& hitResult : results)
			{
				if(hitResult.GetActor() == InTarget)
				{
					FEffectTransform hitET;
					hitET.Location = HitEffectTransform.Location + hitResult.Location;
					hitET.Rotation = HitEffectTransform.Rotation + ownerPawn->GetMesh()->GetSocketRotation("Grenade_socket").GetInverse();
					hitET.Scale = HitEffectTransform.Scale;
					if (N_HitEffect)
						UtilEffect::SpawnNiagaraEffect(GetWorld(), N_HitEffect, hitET);
					if (HitEffect)
						UtilEffect::SpawnParticleEffect(GetWorld(), HitEffect, hitET);
					UGameplayStatics::ApplyDamage(InTarget, Damage * InDamageCoefficient, OwnerController, nullptr, nullptr);
					return;
				}
			}
		}
		SnipingStart = false;
		CurrentTarget = nullptr;
	}
}

void UNPCAttack::PlayEffect(const FName& InAttachSocketName)
{
	FEffectTransform effectTransform = ShotEffectTransform;
	effectTransform.Location += OwnerCharacter->GetMesh()->GetSocketLocation(InAttachSocketName);
	effectTransform.Rotation += OwnerCharacter->GetMesh()->GetSocketRotation(InAttachSocketName);
	
	if (N_ShotEffect)
		UtilEffect::SpawnNiagaraEffect(GetWorld(), N_ShotEffect, effectTransform);
	if (ShotEffect)
		UtilEffect::SpawnParticleEffect(GetWorld(), ShotEffect, effectTransform);
	if (ShotSound)
		UGameplayStatics::PlaySoundAtLocation(this, ShotSound, OwnerCharacter->GetMesh()->GetSocketLocation(InAttachSocketName));
}

void UNPCAttack::SetNPCSkillName(const FName& InNPCSkillName)
{
	NPCSkillName = InNPCSkillName;
	if(NPCSkillName == NAME_None)
		return;
	
	const FNPCSkillDataTable* data = FDataTableManager::GetInstance()->GetData<FNPCSkillDataTable>(EDataTableType::NPCSkill, NPCSkillName.ToString());
	if(!data)
		return;

	SkillRangeType = data->SkillRangeType;
	CoolDown = data->CoolDown;
	AtkCoefficient = data->SkillCoefficient;
	ProjectileType = data->ProjectileType;
	MaxRange = data->MaxRange;
	
	ProjectileName = data->ProjectileName;

	ThrowingActorClass = data->ThrowingSkillData.ThrowingActorClass;
	MaxFlightTime = data->ThrowingSkillData.MaxFlightTime;
	ArcValue = data->ThrowingSkillData.ArcValue;
	
	SuicideBombRadius = data->SuicideBombRadius;

	SkillHittingRange = data->MeleeAttackData.SkillHittingRange;
	RectangleBoxExtend = data->MeleeAttackData.RectangleRangeData.BoxExtend;
	ArcAngle = data->MeleeAttackData.ArcRangeData.Angle;
	RadialImpulse = data->MeleeAttackData.RadialImpulse;
	RadialImpulseStrength = data->MeleeAttackData.RadialImpulseStrength;
	Buffs = data->MeleeAttackData.Buffs;
	
	N_ShotEffect = data->N_ShotEffect;
	ShotEffect = data->ShotEffect;
	ShotEffectTransform = data->ShotEffectTransform;
	ShotSound = data->ShotSound;

	N_HitEffect = data->N_HitEffect;
	HitEffect = data->HitEffect;
	HitEffectTransform = data->HitEffectTransform;
	HitSound = data->HitSound;
}
