// Fill out your copyright notice in the Description page of Project Settings.


#include "DPAnimNotify_Shot.h"

#include "../../Component/DecoratorComponent.h"
#include "../../GameInstanceSubSystem/SoundManagementGss.h"
#include "../../Character/CharacterBase.h"
#include <Components/SkeletalMeshComponent.h>

#include "DieselPunk/Animation/DPAnimInstance.h"
#include "DieselPunk/Character/CharacterPC.h"
#include "DieselPunk/Skill/SkillSoldier/SkillSoldierLM.h"

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
	
	if(ACharacterBase* character = Cast<ACharacterBase>(MeshComp->GetOwner()))
	{
		UActorComponent* comp = character->GetComponentByClass(UDecoratorComponent::StaticClass());
		if(UDecoratorComponent* decorator = Cast<UDecoratorComponent>(comp))
		{
			decorator->StartEffect(EEffectPlayType::Shot, FName(TEXT("Grenade_socket")));
		}
		//if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(MeshComp->GetAnimInstance()))
		//{
		//	ACharacterPC* pc = Cast<ACharacterPC>(character);
		//	if(!pc || !Cast<USkillSoldierLM>(pc->GetCurrentCachedSkill()))
		//		animInst->AttackEndSign();
		//}
		character->AbilityShot();
	}
}
