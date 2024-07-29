// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterInstallation.h"

#include <Components/SphereComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Kismet/GameplayStatics.h>

// =============================================================
// 생성자
// =============================================================
ACharacterInstallation::ACharacterInstallation()
{
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetMesh());

	Sphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Sphere->SetCollisionObjectType(ECC_WorldDynamic);
	Sphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterInstallation::BeginPlay()
{
	Super::BeginPlay();
	CharacterType = ECharacterType::Installation;
	Sphere->SetSphereRadius(0.f);
}

// =============================================================
// 소멸자
// =============================================================
void ACharacterInstallation::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// Tick
// =============================================================
void ACharacterInstallation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CachedCharacters.RemoveAll([](const FCachedCharacter& character)
	{
		return !character.Character.IsValid();
	});

	TimeCount += DeltaTime;
	if(TimeCount >= 1.f)
	{
		TimeCount -= 1.f;
		StartEffect(EEffectPlayType::Tick, Sphere->GetComponentTransform());
	}
}

void ACharacterInstallation::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	for(const FCachedCharacter& character : CachedCharacters)
	{
		for(const TPair<ECharacterStatType, int32>& value : character.StatValue)
			character.Character->ChangeStat(value.Key, -value.Value);
		StartEffect(EEffectPlayType::End, character.Character->GetActorTransform());
	}
	CachedCharacters.Empty();
}

void ACharacterInstallation::RunAi()
{
	Super::RunAi();
	
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Sphere->SetCollisionResponseToChannel(ECC_DP_Player, ECR_Overlap);
	Sphere->SetCollisionResponseToChannel(ECC_DP_Enemy, ECR_Overlap);
	Sphere->SetCollisionResponseToChannel(ECC_DP_ProjectileEnemy, ECR_Overlap);
	Sphere->SetCollisionResponseToChannel(ECC_DP_CharacterMultiTrace, ECR_Block);
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACharacterInstallation::BeginOverlapEvent);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ACharacterInstallation::EndOverlapEvent);
	Sphere->SetSphereRadius(Range);

	StartEffect(EEffectPlayType::Start, Sphere->GetComponentTransform());
}

void ACharacterInstallation::BeginOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor,
                                               UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult& InSweepResult)
{
	TWeakObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(InOtherActor);
	if(character == nullptr)
		return;

	if(character->GetCharacterType() != TargetType)
		return;

	FCachedCharacter cCharacter;
	cCharacter.Character = character;

	Buff(cCharacter);
	CachedCharacters.Add(cCharacter);
}

void ACharacterInstallation::EndOverlapEvent(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor,
	UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex)
{
	if(!Restore)
		return;

	FCachedCharacter* findCharacter = CachedCharacters.FindByPredicate([&InOtherActor](const FCachedCharacter& character)
	{
		return character.Character.IsValid() && character.Character == InOtherActor;
	});

	if(findCharacter == nullptr)
		return;

	for(const TPair<ECharacterStatType, int32>& value : findCharacter->StatValue)
		findCharacter->Character->ChangeStat(value.Key, -value.Value);
	StartEffect(EEffectPlayType::End, findCharacter->Character->GetActorTransform());

	CachedCharacters.RemoveAll([&InOtherActor](const FCachedCharacter& character)
	{
		return character.Character == InOtherActor;
	});

}

void ACharacterInstallation::Buff(FCachedCharacter& InOutCharacter)
{
	if(!InOutCharacter.Character.IsValid())
		return;

	//스탯 적용
	for(const TPair<ECharacterStatType, int32>& value : CharacterStatValue)
	{
		InOutCharacter.Character->ChangeStat(value.Key, value.Value);
		InOutCharacter.StatValue.FindOrAdd(value.Key) += value.Value;
	}

	//적용 이펙트 재생
	StartEffect(EEffectPlayType::Hit, InOutCharacter.Character->GetActorTransform());
}

void ACharacterInstallation::StartEffect(EEffectPlayType InEffectPlayType, FTransform InTransform)
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