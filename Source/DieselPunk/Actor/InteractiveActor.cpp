// Copyright GuardiansW. All Rights Reserved.


#include "InteractiveActor.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(InteractiveActor)

// =============================================================
// 생성자
// =============================================================
AInteractiveActor::AInteractiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// =============================================================
// BeginPlay
// =============================================================
void AInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// =============================================================
// Tick
// =============================================================
void AInteractiveActor::Tick(float InDeltaTime)
{
	Super::Tick(InDeltaTime);
	
}

