// Fill out your copyright notice in the Description page of Project Settings.


#include "../Actor/PathRouter.h"
#include "../Manager/ObjectManager.h"

#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <DrawDebugHelpers.h>


// =============================================================
// 생성자
// =============================================================
APathRouter::APathRouter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRoot);
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(SceneRoot);
	BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxComponent->PrimaryComponentTick.bCanEverTick = false;

	// StaticMesh Set // 스태틱메쉬 설정
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SceneRoot);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->PrimaryComponentTick.bCanEverTick = false;
}

// =============================================================
// BeginPlay
// =============================================================
void APathRouter::BeginPlay()
{
	Super::BeginPlay();

	if(ObjectId == -1)
		FObjectManager::GetInstance()->AddActor(this);
	
	// 스플라인 디버그라인
	if(DebugOnOff)
	{

	}
}

// =============================================================
// Called change info in editor
// =============================================================
void APathRouter::OnConstruction(const FTransform& InTransform)
{
	Super::OnConstruction(InTransform);
}

// =============================================================
// 스플라인 포인트를 기반으로 직사각형의 점을 PolygonPoints에 담습니다.
// =============================================================
void APathRouter::MakeRectangleBySplinePoints()
{
	FVector firstPoint, secondPoint, thirdPoint, fourthPoint;

	FVector scale = GetActorScale3D();
	double BoxScale = 150;
	firstPoint = BoxComponent->Bounds.Origin
	+ GetActorRotation().Vector().GetSafeNormal() * 30 * scale.X
	+ (GetActorRotation() + FRotator(0,-90,0)).Clamp().Vector().GetSafeNormal() * BoxScale * scale.Y;
	secondPoint = BoxComponent->Bounds.Origin
	+ GetActorRotation().Vector().GetSafeNormal() * 30 * scale.X
	+ (GetActorRotation() + FRotator(0,90,0)).Vector().GetSafeNormal() * BoxScale * scale.Y;
	thirdPoint = BoxComponent->Bounds.Origin
	- GetActorRotation().Vector().GetSafeNormal() * 30 * scale.X
	+ (GetActorRotation() + FRotator(0,90,0)).Vector().GetSafeNormal() * BoxScale * scale.Y;
	fourthPoint = BoxComponent->Bounds.Origin
	- GetActorRotation().Vector().GetSafeNormal() * 30 * scale.X
	+ (GetActorRotation() + FRotator(0,-90,0)).Vector().GetSafeNormal() * BoxScale * scale.Y;
	
	// Set PolygonPoints on Spline
	RectanglePoints.Empty();
	RectanglePoints.Add(firstPoint);
	RectanglePoints.Add(secondPoint);
	RectanglePoints.Add(thirdPoint);
	RectanglePoints.Add(fourthPoint);

	// Draw Debug
	if(DebugOnOff)
	{
		DrawDebugCylinder(GetWorld(), firstPoint, fourthPoint, 10, 4, FColor::Blue, true, -1, 0, 5);
		DrawDebugCylinder(GetWorld(), secondPoint, thirdPoint, 10, 4, FColor::Red, true, -1, 0, 5);
		DrawDebugLine(GetWorld(), firstPoint, (firstPoint + secondPoint)/2 + (GetActorRotation().Vector().GetSafeNormal() * 150), FColor::Green, true, -1, 0, 5);
		DrawDebugLine(GetWorld(), secondPoint, (firstPoint + secondPoint)/2 + (GetActorRotation().Vector().GetSafeNormal() * 150), FColor::Green, true, -1, 0, 5);
		//DrawDebugCone(GetWorld(), (firstPoint + secondPoint)/2 + (GetActorRotation().Vector().GetSafeNormal() * 150), -GetActorRotation().Vector().GetSafeNormal(), 150, FMath::DegreesToRadians(20.f), FMath::DegreesToRadians(20.f), 16, FColor::Green, true, 0, 0, 5);
	
		for(int i = 0; i < RectanglePoints.Num(); ++i)
		{
			if(i == RectanglePoints.Num() - 1)
				DrawDebugLine( GetWorld(),RectanglePoints[i],RectanglePoints[0],FColor::Green, true, -1, 0, 5);
			else
				DrawDebugLine( GetWorld(),RectanglePoints[i],RectanglePoints[i + 1],FColor::Green, true, -1, 0, 5);
		}
	}
}

// =============================================================
// 연결된 PathRouter를 모두 등록합니다.
// =============================================================
void APathRouter::RegistPathRouter(TMap<int32, TObjectPtr<APathRouter>>& inPathRouterNodes, int32& inPathRouterNodeNum)
{
	PathRouterNum = inPathRouterNodeNum;			// 현 라우터의 번호를 맵에 등록된 key값으로 업데이트 해줍니다.
	
	if(DebugOnOff)
		DrawDebugString(GetWorld(), GetActorLocation() + FVector(0,0,30), FString::FromInt(PathRouterNum), nullptr, FColor::Green, -1);
	
	// 연결된 PathRouter가 있다면
	if(NextPathRouter)
	{
		// 무한 재귀가 일어나는지 검사 
		bool isInfiniteRecursion = false;
		for(auto& pathRouter : inPathRouterNodes)
		{
			if(pathRouter.Value == NextPathRouter)
				isInfiniteRecursion = true;
		}
		// 상위에 등록된 값과 NextPathRouter 이 같다면 여기서 진행을 멈춤 
		if(isInfiniteRecursion)
		{
			LOG_SCREEN(FColor::Red, TEXT("Warning : 'PathRouter %d' 에 의해 무한 재귀합니다. 'PathRouter %d' 로 이어집니다."), GetPathRouterNumber(), NextPathRouter->GetPathRouterNumber())
			return;
		}
		
		inPathRouterNodeNum++;							// 노드번호를 늘림
		inPathRouterNodes.Add(inPathRouterNodeNum, NextPathRouter);		// 다음 pathRouter 등록
		NextPathRouter->RegistPathRouter(inPathRouterNodes, inPathRouterNodeNum);		// 재귀함수 실행
	}
}

// =============================================================
// 투영값을 통해 위치를 반환합니다.
// =============================================================
FVector APathRouter::MakeGoalLocByProportion(FVector2D inProportion)
{
	// 스플라인의 점으로 직사각형을 생성합니다.
	MakeRectangleBySplinePoints();
	
	// 가로 세로 비례값을 통해 위치를 투영
	FVector targetLoc = RectanglePoints[0];
	targetLoc = targetLoc
	+ ( inProportion.X * (RectanglePoints[1] - RectanglePoints[0]).GetSafeNormal() * FVector::Dist(RectanglePoints[1], RectanglePoints[0]) )
	+ ( inProportion.Y * (RectanglePoints[3] - RectanglePoints[0]).GetSafeNormal() * FVector::Dist(RectanglePoints[3], RectanglePoints[0]) );

	return targetLoc;
}
