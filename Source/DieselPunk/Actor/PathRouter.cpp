// Fill out your copyright notice in the Description page of Project Settings.


#include "../Actor/PathRouter.h"
#include "../Manager/ObjectManager.h"

#include <Components/SplineComponent.h>
#include <DrawDebugHelpers.h>


// =============================================================
// 생성자
// =============================================================
APathRouter::APathRouter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SetRootComponent(SplineComponent);
	SplineComponent->SetClosedLoop(true);
	SplineComponent->PrimaryComponentTick.bCanEverTick = false;
}

// =============================================================
// BeginPlay
// =============================================================
void APathRouter::BeginPlay()
{
	Super::BeginPlay();

	if(ObjectId == -1)
		FObjectManager::GetInstance()->AddActor(this);

	// 스플라인으로 직사각형을 생성합니다.
	MakeRectangleBySplinePoints();
	
	// 스플라인 디버그라인
	if(bDrawDebug)
	{

	}
}

// =============================================================
// Called change info in editor
// =============================================================
void APathRouter::OnConstruction(const FTransform& InTransform)
{
	Super::OnConstruction(InTransform);

	// Set All Spline Point Type "Linear"
	for(int i = 0; i < SplineComponent->GetNumberOfSplinePoints(); ++i)
		SplineComponent->SetSplinePointType(i, ESplinePointType::Linear, true);
}

// =============================================================
// Called every frame
// =============================================================
void APathRouter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APathRouter::MakeRectangleBySplinePoints()
{
	if(SplineComponent->GetNumberOfSplinePoints() < 3)
		return;

	FVector firstPoint, secondPoint, thirdPoint, fourthPoint;
	
	firstPoint = SplineComponent->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::World);
	secondPoint = SplineComponent->GetLocationAtSplinePoint(1, ESplineCoordinateSpace::World);
	secondPoint = FVector(secondPoint.X, secondPoint.Y, firstPoint.Z);
	FVector heightPoint = SplineComponent->GetLocationAtSplinePoint(2, ESplineCoordinateSpace::World);
	heightPoint = FVector(heightPoint.X, heightPoint.Y, firstPoint.Z);

	FVector ZupFirstPoint = firstPoint + FVector(0,0,100);
	// 법선벡터
	FVector norm = ((firstPoint - ZupFirstPoint).Cross(secondPoint - ZupFirstPoint)).GetSafeNormal();

	// Get distance between (firstPoint-secondPoint)Line and heightPoint
	double a = firstPoint.Y - secondPoint.Y;
	double b = secondPoint.X - firstPoint.X;
	double c = firstPoint.X * secondPoint.Y - secondPoint.X * firstPoint.Y;
	float dist = abs((a * heightPoint.X) + (b * heightPoint.Y) + c) / sqrt((a * a) + (b * b));

	thirdPoint = secondPoint + (norm * dist);
	fourthPoint = firstPoint + (norm * dist);
	
	// Set PolygonPoints on Spline
	RectanglePoints.Empty();
	RectanglePoints.Add(firstPoint);
	RectanglePoints.Add(secondPoint);
	RectanglePoints.Add(thirdPoint);
	RectanglePoints.Add(fourthPoint);

	// Draw Debug
	DrawDebugCylinder(GetWorld(), firstPoint, fourthPoint, 10, 4, FColor::Blue, true, -1, 0, 5);
	DrawDebugCylinder(GetWorld(), secondPoint, thirdPoint, 10, 4, FColor::Red, true, -1, 0, 5);
	DrawDebugLine(GetWorld(), firstPoint, (firstPoint + secondPoint)/2 + (-norm * 150), FColor::Green, true, -1, 0, 5);
	DrawDebugLine(GetWorld(), secondPoint, (firstPoint + secondPoint)/2 + (-norm * 150), FColor::Green, true, -1, 0, 5);
	//DrawDebugCone(GetWorld(), (firstPoint + secondPoint)/2 + (-norm * 150), norm, 150, FMath::DegreesToRadians(20.f), FMath::DegreesToRadians(20.f), 16, FColor::Green, true, 0, 0, 5);
	
	for(int i = 0; i < RectanglePoints.Num(); ++i)
	{
		if(i == RectanglePoints.Num() - 1)
			DrawDebugLine( GetWorld(),RectanglePoints[i],RectanglePoints[0],FColor::Green, true, -1, 0, 5);
		else
			DrawDebugLine( GetWorld(),RectanglePoints[i],RectanglePoints[i + 1],FColor::Green, true, -1, 0, 5);
	}
}
