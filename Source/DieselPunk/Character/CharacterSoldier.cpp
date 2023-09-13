// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterSoldier.h"
#include "../Logic/PlayerControllerBase.h"

#include <GameFramework/PlayerController.h>
#include <DrawDebugHelpers.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterSoldier)

void ACharacterSoldier::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterSoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (DrawERange)
	{
		//*스킬e 범위 디버그
		DrawDebugSphere(GetWorld(), GetUnderCursorLocation().ImpactPoint, 32, 16, FColor::Red, false, -1.f);
		DrawDebugSphere(GetWorld(), GetUnderCursorLocation().ImpactPoint, 500, 64, FColor::Blue, false, -1.f); // 파란 디버그구
	} 
}

FHitResult ACharacterSoldier::GetUnderCursorLocation()
{
	FHitResult HitResult;
	APlayerController *ownerController = Cast<APlayerControllerBase>(GetController());
	if (ownerController)
	{
		ownerController->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false,
			HitResult);
		return HitResult;
	}
	return HitResult;
}