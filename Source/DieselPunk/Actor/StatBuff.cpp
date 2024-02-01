// Fill out your copyright notice in the Description page of Project Settings.

#include "StatBuff.h"
#include "../Manager/ObjectManager.h"

#include <Components/StaticMeshComponent.h>
#include <Kismet/GameplayStatics.h>

#include "DieselPunk/Character/CharacterPC.h"


// =============================================================
// 생성자
// =============================================================
AStatBuff::AStatBuff()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// StaticMesh Set // 스태틱메쉬 설정
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	SetRootComponent(Mesh);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
}

// =============================================================
// BeginPlay
// =============================================================
void AStatBuff::BeginPlay()
{
	Super::BeginPlay();

	TickMaxCount = static_cast<int32>(MaxTime / TickTime);

	// Effect
	TWeakObjectPtr<AStatBuff> thisPtr = this;
	GetWorldTimerManager().SetTimerForNextTick([thisPtr]()
	{
		if(!thisPtr.IsValid())
			return;
		thisPtr->StartEffect(EEffectPlayType::Start, thisPtr->GetActorTransform());

		thisPtr->Buff();
		
	});
}

void AStatBuff::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	StartEffect(EEffectPlayType::End, GetActorTransform());
}

// =============================================================
// Tick
// =============================================================
void AStatBuff::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeCount += DeltaTime;

	if(TimeCount >= TickTime)
	{
		TimeCount -= TickTime;
		Buff();

		if(TickCount == TickMaxCount)
		{
			//다음 틱 삭제
			TWeakObjectPtr<AStatBuff> thisPtr = this;
			GetWorld()->GetTimerManager().SetTimerForNextTick([thisPtr]()
			{
				if(thisPtr.IsValid())
					FObjectManager::GetInstance()->DestroyActor(thisPtr.Get());
			});
		}
	}
}

TArray<int32> AStatBuff::FindBuffTarget()
{
	TArray<int32> targets;

	//대상 찾기
	FVector location = GetActorLocation();
	float range = AttackRange;
	ECharacterType type = TargetType;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(targets, [&location, &range, &type](AActor* target)
	{
		if(Cast<ACharacterBase>(target) == nullptr)
			return false;

		float dist = FVector::Distance(target->GetActorLocation(), location);
		
		return (Cast<ACharacterBase>(target)->GetCharacterType() == type) && (range >= dist);
	});
	
	if(targets.IsEmpty())
		return targets;

	//가까운 순으로 정렬
	targets.Sort([&location](int32 lhs, int32 rhs)
	{
		return FVector::Distance(FObjectManager::GetInstance()->FindActor(lhs)->GetActorLocation(), location)
		< FVector::Distance(FObjectManager::GetInstance()->FindActor(rhs)->GetActorLocation(), location);
	});


	if(Count < 1)
		return targets;

	TArray<int32> outTargets;
	for(int i = 0; i < Count; ++i)
		outTargets.Add(targets[i]);

	return outTargets;
}

void AStatBuff::StartEffect(EEffectPlayType InEffectPlayType, FTransform InTransform)
{
	for(const FEffectData& effect : Effects)
	{
		if(effect.EffectPlayType != InEffectPlayType)
			continue;

		FEffectTransform transform;
		transform.Location = InTransform.GetLocation();
		transform.Rotation = InTransform.GetRotation().Rotator();
		transform.Scale = InTransform.GetScale3D();
		
		if (effect.N_Effect)
			UtilEffect::SpawnNiagaraEffect(GetWorld(), effect.N_Effect, transform);
		if (effect.Effect)
			UtilEffect::SpawnParticleEffect(GetWorld(), effect.Effect, transform);
		if (effect.Sound)
			UGameplayStatics::PlaySoundAtLocation(this, effect.Sound, GetActorLocation());
	}
}

void AStatBuff::Buff()
{
	TArray<int32> targets = FindBuffTarget();

	if(DebugOnOff)
	{
		if(targets.IsEmpty())
			DrawDebugSphere(GetWorld(), GetActorLocation(), AttackRange, 10, FColor::Red, false, 1, 0, 5);
		else
			DrawDebugSphere(GetWorld(), GetActorLocation(), AttackRange, 10, FColor::Green, false, 1, 0, 5);
	}

	for(const int32& targetId : targets)
	{
		ACharacterBase* target = Cast<ACharacterBase>(FObjectManager::GetInstance()->FindActor(targetId));
		if(target == nullptr)
		{
			LOG_SCREEN(FColor::Red, TEXT("캐릭터베이스가 아닌데 캐릭터베이스로 인식함. 큰문제 야기 가능"))
			return;
		}

		//스탯 적용
		target->ChangeStat(CharacterStatType, Value);
		DrawDebugPoint(GetWorld(), target->GetActorLocation(), 100, FColor::Cyan, false, 1, 0);

		//적용 이펙트 재생
		StartEffect(EEffectPlayType::Hit, target->GetActorTransform());
	}
	//틱 이펙트 재생
	StartEffect(EEffectPlayType::Tick, GetActorTransform());

	++TickCount;
}
