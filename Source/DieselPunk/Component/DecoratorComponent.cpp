// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoratorComponent.h"

#include <Components/SkeletalMeshComponent.h>

// Sets default values for this component's properties
UDecoratorComponent::UDecoratorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UDecoratorComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	if(!Owner.IsValid())
		return;

	StartEffect(EEffectPlayType::Spawn);
}

void UDecoratorComponent::StartEffect(EEffectPlayType InEffectPlayType, FName InBoneName)
{
	for(const FEffectData& effect : EffectDatas)
	{
		if(effect.EffectPlayType != InEffectPlayType)
			continue;

		if(effect.bAttach)
		{
			if(InBoneName != "" && effect.AttachBoneName != InBoneName)
				continue;
			
			TArray<USkeletalMeshComponent*> comp;
			Owner->GetComponents<USkeletalMeshComponent>(comp);

			USkeletalMeshComponent* mesh = nullptr;

			for(int i = 0; i < comp.Num(); ++i)
			{
				TArray<FName> names;
				comp[i]->GetBoneNames(names);

				for(const FName& name : names)
				{
					if(name == effect.AttachBoneName)
					{
						mesh = comp[i];
						break;
					}
				}
			}

			if(mesh == nullptr)
				return;

			FEffectTransform transform;
			transform.Location =  effect.Offset.GetLocation();
			transform.Rotation = effect.Offset.GetRotation().Rotator();
			transform.Scale = effect.Offset.GetScale3D();
		
			if (effect.N_Effect)
				UtilEffect::SpawnNiagaraEffectAttached(effect.N_Effect, mesh, effect.AttachBoneName, transform);
			if (effect.Effect)
				UtilEffect::SpawnParticleEffectAttached(effect.Effect, mesh, effect.AttachBoneName, transform);
			if (effect.Sound)
				UtilEffect::SpawnSoundBase(this, effect.Sound, Owner->GetActorLocation() + effect.Offset.GetLocation());
		}
		else
		{
			if(effect.AttachBoneName == "")
			{
				FEffectTransform transform;
				transform.Location = Owner->GetActorLocation() + effect.Offset.GetLocation();
				transform.Rotation = Owner->GetActorRotation() + effect.Offset.GetRotation().Rotator();
				transform.Scale = Owner->GetActorScale() * effect.Offset.GetScale3D();
		
				if (effect.N_Effect)
					UtilEffect::SpawnNiagaraEffect(GetWorld(), effect.N_Effect, transform);
				if (effect.Effect)
					UtilEffect::SpawnParticleEffect(GetWorld(), effect.Effect, transform);
				if (effect.Sound)
					UtilEffect::SpawnSoundBase(this, effect.Sound, Owner->GetActorLocation() + effect.Offset.GetLocation());
			}
			else
			{
				if(effect.AttachBoneName != InBoneName)
					continue;
				TArray<USkeletalMeshComponent*> comp;
				Owner->GetComponents<USkeletalMeshComponent>(comp);

				USkeletalMeshComponent* mesh = nullptr;

				for(int i = 0; i < comp.Num(); ++i)
				{
					TArray<FName> names;
					comp[i]->GetBoneNames(names);
					names.Append(comp[i]->GetAllSocketNames());
					

					auto boneIndex = names.Find(effect.AttachBoneName);
					if(boneIndex != INDEX_NONE)
					{
						mesh = comp[i];
						break;
					}
				}

				if(mesh == nullptr)
				{
					LOG_SCREEN(FColor::Red, TEXT("%s에 해당하는 소켓/본이 없습니다."), *effect.AttachBoneName.ToString())
					return;
				}

				FEffectTransform transform;
				
				TArray<FName> boneNames;
				mesh->GetBoneNames(boneNames);
				
				if(boneNames.Find(effect.AttachBoneName) != INDEX_NONE)
					transform.Location = mesh->GetBoneLocation(effect.AttachBoneName, EBoneSpaces::WorldSpace);
				else if(mesh->GetAllSocketNames().Find(effect.AttachBoneName) != INDEX_NONE)
					transform.Location = mesh->GetSocketLocation(effect.AttachBoneName);
				
				transform.Rotation = Owner->GetActorRotation();
				transform.Scale = Owner->GetActorScale();

				transform.Location += effect.Offset.GetLocation();
				transform.Rotation += effect.Offset.GetRotation().Rotator();
				transform.Scale *= effect.Offset.GetScale3D();
		
				if (effect.N_Effect)
					UtilEffect::SpawnNiagaraEffect(GetWorld(), effect.N_Effect, transform);
				if (effect.Effect)
					UtilEffect::SpawnParticleEffect(GetWorld(), effect.Effect, transform);
				if (effect.Sound)
					UtilEffect::SpawnSoundBase(this, effect.Sound, Owner->GetActorLocation() + effect.Offset.GetLocation());
			}
		}
	}
}

// Called every frame
void UDecoratorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDecoratorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	StartEffect(EEffectPlayType::Death);
}

void UDecoratorComponent::PlayWalkEffect(FName InBoneName)
{
	StartEffect(EEffectPlayType::Walk, InBoneName);
}

