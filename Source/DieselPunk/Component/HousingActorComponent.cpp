// Fill out your copyright notice in the Description page of Project Settings.


#include "HousingActorComponent.h"

#include "../Character/CharacterPc.h"
#include "../Character/CharacterHousing.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/NavigationManager.h"

#include <DrawDebugHelpers.h>
#include <GameFramework/PlayerController.h>
#include <Components/CapsuleComponent.h>

// Sets default values for this component's properties
UHousingActorComponent::UHousingActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Range = 10000;
}


// Called when the game starts
void UHousingActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UHousingActorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	FNavigationManager::GetInstance()->RestoreNavNodeByDestructedTurret(NavIndex);
	Super::EndPlay(EndPlayReason);
}


// Called every frame
void UHousingActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	//바라보고 있는 위치 찾기
	FHitResult hit;

	//월드 획득
	FWorldContext* world = GEngine->GetWorldContextFromGameViewport( GEngine->GameViewport );
	if ( !world )
		return;

	ACharacterPC* charPc = FObjectManager::GetInstance()->GetPlayer(); 
	if(charPc == nullptr)
		return;

	AController* controller = charPc->GetController();
	if(controller == nullptr)
		return;

	APlayerController* playerController = Cast<APlayerController>(controller);

	//뷰 사이즈 획득
	int32 viewX, viewY;
	playerController->GetViewportSize(viewX, viewY);

	viewX /= 2;
	viewY /= 2;

	FRotator cameraRotation = playerController->PlayerCameraManager->GetCameraRotation();
	FVector cameraDirection = cameraRotation.Vector().GetSafeNormal();

	//스크린 스페이스 위치와 카메라 디렉션을 바탕으로 트레이싱 Start, End 획득
	FVector traceStartLocation, traceEndLocation;
	playerController->DeprojectScreenPositionToWorld(viewX, viewY, traceStartLocation, cameraDirection);
	traceEndLocation = traceStartLocation + Range * cameraDirection;

	//플레이어 충돌범위 제외
	FCollisionQueryParams params;
	params.AddIgnoredActor(charPc);
	params.AddIgnoredActor(GetOwner());

	//라인 충돌
	bool hasHit = world->World()->LineTraceSingleByChannel(
		hit,
		traceStartLocation,
		traceEndLocation,
		ECollisionChannel::ECC_WorldStatic,
		params);

	//바닥과 충돌 됐다면
	if(hasHit)
	{
		int32 turretGridSize = Cast<ACharacterHousing>(GetOwner())->GetGridSize();
		//그리드에 맞춘 위치 탐색
		FVector newLocation;
		if(turretGridSize & 1)
			newLocation = FVector(floor(hit.Location.X / FNavigationManager::GridSize), (floor(hit.Location.Y / FNavigationManager::GridSize)), 0.0);
		else
			newLocation = FVector(round(hit.Location.X / FNavigationManager::GridSize), (round(hit.Location.Y / FNavigationManager::GridSize)), 0.0);
		newLocation *= FNavigationManager::GridSize;
		
		if(turretGridSize & 1)
			newLocation += FVector(FNavigationManager::GridSize / 2);
		
		newLocation.Z = hit.Location.Z + Cast<ACharacter>(GetOwner())->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

		FHitResult NewLocationHitResult;
		//그리드에 맞춰 액터 위치 설정
		GetOwner()->SetActorLocation(newLocation,false, &NewLocationHitResult);

		//디버그 렌더를 위한 로케이션
		FVector boxLocation = GetOwner()->GetActorLocation();
		FVector boxGridSize = FVector(turretGridSize);
		FVector boxExtend = (boxGridSize * FNavigationManager::GridSize / 2);
		boxExtend.Z = Cast<ACharacter>(GetOwner())->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
		//boxLocation.Z += boxExtend.Z;
		DrawDebugBox(world->World(), boxLocation, boxExtend, FColor::Red, false, -1 , 0, 2);

		//설치가 가능하면 시안 색으로 머터리얼 변경
		ACharacterHousing* owner = Cast<ACharacterHousing>(GetOwner());
		owner->ChangeHousingMaterialParameterChange(IsArrangeTurret());
	}
}

bool UHousingActorComponent::IsArrangeTurret()
{
	ACharacterHousing* owner = Cast<ACharacterHousing>(GetOwner());
	if(owner == nullptr)
		return false;

	TArray<FOverlapResult> hitResult;
	FVector location = owner->GetActorLocation();
	double gridSize = owner->GetGridSize();
	FVector grid = {gridSize, gridSize, gridSize};
	FVector boxHalfExtend = (grid * FNavigationManager::GridSize / 2) - 0.25;
	location.Z += boxHalfExtend.Z;

	//플레이어 충돌범위 제외
	FCollisionQueryParams params;
	params.AddIgnoredActor(owner);
	
	return !GetOwner()->GetWorld()->OverlapMultiByChannel(hitResult, location, FQuat::Identity, ECC_WorldStatic,FCollisionShape::MakeBox(boxHalfExtend), params) &&
		FNavigationManager::GetInstance()->IsPlacementTurret(GetOwner()->GetActorLocation(), owner->GetGridSize());
}

bool UHousingActorComponent::CompleteHousingTurret()
{
	ACharacterHousing* owner = Cast<ACharacterHousing>(GetOwner());
	if(owner == nullptr)
		return false;

	TArray<FOverlapResult> hitResult;
	FVector location = owner->GetActorLocation();
	double gridSize = owner->GetGridSize();
	FVector grid = {gridSize, gridSize, gridSize};
	FVector boxHalfExtend = (grid * FNavigationManager::GridSize / 2) - 0.25;
	location.Z += boxHalfExtend.Z;

	//플레이어 충돌범위 제외
	FCollisionQueryParams params;
	params.AddIgnoredActor(owner);

	if(GetOwner()->GetWorld()->OverlapMultiByChannel(hitResult, location, FQuat::Identity, ECC_WorldStatic,FCollisionShape::MakeBox(boxHalfExtend), params))
		return false;
	
	location = owner->GetActorLocation();
	if(FNavigationManager::GetInstance()->PlacementTurret(location, owner->GetGridSize(), NavIndex, GetOwner()))
	{
		location.Z += owner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
		GetOwner()->SetActorLocation(location);
		SetComponentTickEnabled(false);
		return true;
	}
	return false;
}

