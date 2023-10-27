// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillSpawnTurret.h"
#include "../../Character/CharacterNPC.h"
#include "../../Logic/EnemyAIController.h"

#include <DrawDebugHelpers.h>


USkillSpawnTurret::USkillSpawnTurret() : Super()
{
	PrimaryComponentTick.bCanEverTick = true; // 일단 Tick은 OFF 해두었습니다.
}

void USkillSpawnTurret::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	DrawSupport();
}

void USkillSpawnTurret::SkillStarted()
{
	Super::SkillStarted();

	// 현재는 첫 입력 시 스폰서포트 활성화, 한번 더 입력시 스폰 으로 해놨습니다.
	// 로직은 추후 쉽게 변경가능하므로 일단 이렇게 해놓겠습니다.
	if(bTaskOn == false)
	{
		bDrawSupport = true;
		bTaskOn = true;
	}
	else
	{
		UClass* TurretClass = LoadClass<ACharacterNPC>( NULL, TEXT( "/Script/Engine.Blueprint'/Game/DieselPunk/Blueprints/Characters/BP_Turret.BP_Turret_C'" ));
		FTransform spawnTransform( FRotator::ZeroRotator, UtilCollision::GetUnderCursor().Location);
		if(TurretClass)
		{
			ACharacterNPC* newActor = GetWorld()->SpawnActorDeferred<ACharacterNPC>(TurretClass, spawnTransform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn );
			newActor->AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
			newActor->FinishSpawning(spawnTransform);
		}
		
		bDrawSupport = false;
		bTaskOn = false;
	}
}

// =============================================================
// 스폰 위치를 시각적으로 보여줍니다. // 현재는 DrawDebug로 했습니다.
// 나중에 이펙트로 치환하거나, 스폰할 액터의 메쉬정보를 받아와서 활용하면 될 것 같습니다.
// =============================================================
void USkillSpawnTurret::DrawSupport()
{
	if(bDrawSupport)
		DrawDebugBox(GetWorld(),
			UtilCollision::GetUnderCursor().Location,
			FVector (100,100,200),
			FColor::Red,
			false,
			-1.f);
}

