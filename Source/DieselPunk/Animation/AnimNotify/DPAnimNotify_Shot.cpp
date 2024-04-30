// Fill out your copyright notice in the Description page of Project Settings.


#include "DPAnimNotify_Shot.h"

#include "../../Component/DecoratorComponent.h"
#include "../../GameInstanceSubSystem/SoundManagementGss.h"
#include <Components/SkeletalMeshComponent.h>
#include <GameFramework/Character.h>

void UDPAnimNotify_Shot::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	UWorld* world = MeshComp->GetWorld();
	if(world == nullptr)
		return;

	UGameInstance* instance = world->GetGameInstance();
	if(instance == nullptr)
		return;
	
	if(ACharacter* character = Cast<ACharacter>(MeshComp->GetOwner()))
	{
		UActorComponent* comp = character->GetComponentByClass(UDecoratorComponent::StaticClass());
		if(UDecoratorComponent* decorator = Cast<UDecoratorComponent>(comp))
		{
			decorator->StartEffect(EEffectPlayType::Shot, FName(TEXT("Grenade_socket")));
		}
	}
}
