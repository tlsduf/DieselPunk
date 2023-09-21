// Copyright GuardiansW. All Rights Reserved.

#pragma once

#include <GameFramework/Actor.h>
#include "InteractiveActor.generated.h"



UCLASS()
class DIESELPUNK_API AInteractiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractiveActor();

protected:
	/** Overridable native event for when play begins for this actor. */
	virtual void BeginPlay()override;
	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;
};
