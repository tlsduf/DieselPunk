// Fill out your copyright notice in the Description page of Project Settings.


#include "HousingActorComponent.h"

#include "../Character/CharacterPc.h"
#include "../Manager/ObjectManager.h"

#include <Camera/CameraComponent.h>
#include <DrawDebugHelpers.h>
#include <GameFramework/PlayerController.h>

#include "Components/PrimitiveComponent.h"


// Sets default values for this component's properties
UHousingActorComponent::UHousingActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Range = 10000;
	GridSize = 100;
}


// Called when the game starts
void UHousingActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
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
		//그리드에 맞춘 위치 탐색
		int x,y,z;
		x = static_cast<int>(hit.Location.X) / GridSize;
		y = static_cast<int>(hit.Location.Y) / GridSize;
		z = static_cast<int>(hit.Location.Z) / GridSize;
		FVector newLocation(x,y,z);
		newLocation *= GridSize;

		FHitResult NewLocationHitResult;
		//그리드에 맞춰 액터 위치 설정
		GetOwner()->SetActorLocation(newLocation,false, &NewLocationHitResult);

		//디버그 렌더를 위한 로케이션
		FVector boxLocation = GetOwner()->GetActorLocation();
		FVector boxGridSize = {1,1,1};//GetOwner()->GetGridSize();
		FVector boxExtend = (boxGridSize * GridSize / 2);
		boxLocation.Z += boxExtend.Z;

		DrawDebugBox(GetWorld(), boxLocation, boxExtend, (IsArrangeTurret() ? FColor::Cyan : FColor::Red), false, -1.f);
	}
}

bool UHousingActorComponent::IsArrangeTurret()
{
	TArray<FOverlapResult> hitResult;
	FVector location = GetOwner()->GetActorLocation();
	FVector gridSize = {3,3,3};//GetOwner()->GetGridSize();
	FVector boxHalfExtend = (gridSize * GridSize / 2) - 0.25;
	location.Z += boxHalfExtend.Z;
	
	return !GetOwner()->GetWorld()->OverlapMultiByChannel(hitResult, location, FQuat::Identity, ECC_WorldStatic,FCollisionShape::MakeBox(boxHalfExtend));
}

void UHousingActorComponent::CompleteHousingTurret()
{
	if(IsArrangeTurret())
		SetComponentTickEnabled(false);
}

