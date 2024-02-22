// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterTurret.h"

#include "..\Logic\NPCAIController.h"
#include "../Animation/TurretAnimInstace.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/NavigationManager.h"

#include <Components/SkeletalMeshComponent.h>
#include <Components/StaticMeshComponent.h>



// =============================================================
// 생성자
// =============================================================
ACharacterTurret::ACharacterTurret()
{
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterTurret::BeginPlay()
{
	Super::BeginPlay();
	CharacterType = ECharacterType::Turret;
}

// =============================================================
// 소멸자
// =============================================================
void ACharacterTurret::BeginDestroy()
{
	Super::BeginDestroy();
}

// =============================================================
// Tick
// =============================================================
void ACharacterTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(NPCType == ENPCType::Alliance)
		SetTurretTarget();

	// 애니메이션 타겟 SET
	UTurretAnimInstace* TurretAnimInstace = Cast<UTurretAnimInstace>(GetMesh()->GetAnimInstance());
	if(TurretAnimInstace != nullptr)
		TurretAnimInstace->SetCurTarget(Cast<ACharacterNPC>(Target));
}

void ACharacterTurret::RunAi()
{
	Super::RunAi();
	ANPCAIController* aiController = Cast<ANPCAIController>(GetController());
	if(aiController)
		aiController->RunAi(this, true);
}

// =============================================================
// 터렛의 조건에 따라 타겟을 결정합니다.
// =============================================================
void ACharacterTurret::SetTurretTarget()
{
	// 사정거리 Draw
	if(DebugOnOff)
		DrawDebugSearchArea();
	
	// * 터렛은 현재 목표가 없으면 탐색을 하여, 사거리가 유효한 가장 가까운 적을 목표로 삼는다.
	// * 목표가 사거리에서 벗어나면 목표를 재탐색한다.
	
	//현재 타겟이 유효한가 //유효하지 않다면 탐색 // 유효하다면 타겟 추적
	if(!Target.IsValid())
	{
		//1 기본 탐색 흐름 : 
		//타입 조건에 맞는(Enemy) 액터 어레이 반환(ObjectManager)
		TArray<int32> outActors;
		FObjectManager::GetInstance()->FindActorArrayByPredicate(outActors, [](AActor* InActor)
		{
			if(ACharacterNPC* thisNPC = Cast<ACharacterNPC>(InActor))
				if(thisNPC->GetNPCType() == ENPCType::Enemy)
					return true;
        
			return false;
		});
		//범위 조건에 맞는 액터 어레이 반환
		TWeakObjectPtr<ACharacterTurret> thisPtr = this;
		outActors.RemoveAll([thisPtr](int32 ID)
		{
			if(thisPtr.IsValid())
				return !thisPtr->InValidSearchArea(FObjectManager::GetInstance()->FindActor(ID)->GetActorLocation());
			return true;
		});
		//타겟을 공격할 수 있는 조건(벽에 막히거나)
		//TODO
		if(!bPierceWall)
		{
			outActors.RemoveAll([thisPtr](int32 ID)
			{
				if(thisPtr.IsValid())
					return thisPtr->IsOverWall(FObjectManager::GetInstance()->FindActor(ID)->GetActorLocation());
				return true;
			});
		}
		
		//기준점(대게 this)에 가장 가까운(또는 다른 조건) 액터(또는 어레이) 반환
		TWeakObjectPtr<AActor> tempTarget = Cast<ACharacterNPC>(FObjectManager::GetInstance()->FindActor(
			FObjectManager::GetInstance()->GetNearestACtorByRangeAndIds(GetActorLocation(), outActors)));
		
		//2 타겟 유효성 검사 :
		//현재 타겟이 유효한가
		if(!tempTarget.IsValid())
			return;
		
		//3 타겟 등록(NPC 프롭) : 위 조건에 맞는 타겟 등록
		ChangeTarget(tempTarget);
	}
	else
	{
		// 유효하다면 타겟 추적
		// 타겟이 범위안에 있는지 탐색 // 유효하지 않으면 타겟 초기화
		if(!InValidSearchArea(Target->GetActorLocation()))
		{
			ChangeTarget(nullptr);
			return;
		}
		// 타겟과 포탑 사이에 벽이 있는지 탐색 // 벽이 있으면 타겟 초기화
		if(!bPierceWall)
			if(IsOverWall(Target->GetActorLocation()))
				ChangeTarget(nullptr);
	}
}

// =============================================================
// 포탑의 사각형 탐색범위를 생성합니다. 
// =============================================================
void ACharacterTurret::MakeSearchArea()
{
	float wide = GridSizeHorizontal * FNavigationManager::GridSize;
	FVector firstPoint = GetActorLocation() + (GetActorRightVector() * wide);
	FVector secondPoint = GetActorLocation() + (GetActorRightVector() * wide) + GetActorForwardVector() * GetStat().GetStat(ECharacterStatType::AttackMaxRange);
	FVector thirdPoint = GetActorLocation() + (-1 * GetActorRightVector() * wide) + GetActorForwardVector() * GetStat().GetStat(ECharacterStatType::AttackMaxRange);
	FVector fourthPoint = GetActorLocation() + (-1 * GetActorRightVector() * wide);

	// Set RectanglePoints
	RectanglePoints.Empty();
	RectanglePoints.Add(firstPoint);
	RectanglePoints.Add(secondPoint);
	RectanglePoints.Add(thirdPoint);
	RectanglePoints.Add(fourthPoint);
}

// =============================================================
// inLocation이 유효 범위 안에 있으면 True 반환
// =============================================================
bool ACharacterTurret::InValidSearchArea(FVector inLocation)
{
	if(TurretSearchAreaType == ESearchAreaType::Circle)
	{
		float distance = FVector::Dist(GetActorLocation(), inLocation);
		bool inMaxDistance = distance < GetStat().GetStat(ECharacterStatType::AttackMaxRange);		// 최대거리 안에 위치?
		bool inMinDistance = distance > GetStat().GetStat(ECharacterStatType::AttackMinRange);		//최소거리 밖에 위치?

		float forwardDir = GetActorForwardVector().GetSafeNormal().Rotation().Yaw;
		float toTargetDir = (inLocation - GetActorLocation()).GetSafeNormal().Rotation().Yaw;
		bool inDegree = true; // ( -30 < (forwardDir - toTargetDir) ) && ( (forwardDir - toTargetDir) < 30 );	// 각도 내에 위치?
	
		return inMaxDistance && inMinDistance && inDegree;
	}

	if(TurretSearchAreaType == ESearchAreaType::Rectangle)
		return IsInPolygon(inLocation.X, inLocation.Y);
	
	return false;
}

// =============================================================
// inLocation까지 트레이스를 하여 맵 구성요소(ex 벽)이 있는지 탐색하고, 있으면 true 반환
// =============================================================
bool ACharacterTurret::IsOverWall(FVector inLocation)
{
	//라인트레이싱에 성공했는가
	TArray<FHitResult> hits;
	FVector start = GetActorLocation();
	FVector end = inLocation;

	// 모든 터렛을 IgnoredActor에 등록합니다. // 플레이어를 IgnoredActor에 등록합니다.
	FCollisionQueryParams params;
	TArray<int32> turretsIDs;
	FObjectManager::GetInstance()->FindActorArrayByPredicate(turretsIDs, [](AActor* InActor)
	{
		if(auto turret = Cast<ACharacterTurret>(InActor))
			if(turret->NPCType == ENPCType::Alliance)
				return true;
		return false;
	});
	for(const int32& ID : turretsIDs)
	{
		params.AddIgnoredActor(FObjectManager::GetInstance()->FindActor(ID));
	}
	params.AddIgnoredActor(FObjectManager::GetInstance()->GetPlayer());
	
	bool bIsWorldObject = false;
	//라인트레이스하여 맵 오브젝트가 있는지 확인. 있으면 true
	if(GetWorld()->LineTraceMultiByChannel(hits, start, end, ECollisionChannel::ECC_GameTraceChannel6, params))
	{
		for(const auto& hit : hits)
		{
			if(hit.GetActor()->GetClass()->ImplementsInterface(UDpManagementTargetInterFace::StaticClass()))
				continue;
			bIsWorldObject = true;
		}
	}
	return bIsWorldObject;
}

// =============================================================
// 다각형 내부에 점이 위치하는지 확인합니다. // Point in polygon algorithm
// =============================================================
bool ACharacterTurret::IsInPolygon(double InX, double InY)
{
	if(RectanglePoints.IsEmpty())
		return false;
	
	int cn = 0;    // the crossing number counter
	
	for (int i = 0; i < RectanglePoints.Num(); i++)
	{
		int j = (i + 1) % RectanglePoints.Num();
		if ((( RectanglePoints[i].Y <= InY ) && ( RectanglePoints[j].Y > InY )) || (( RectanglePoints[i].Y > InY ) && ( RectanglePoints[j].Y <=  InY )))
		{
			float vt = (float)(InY  - RectanglePoints[i].Y) / (RectanglePoints[j].Y - RectanglePoints[i].Y);
			if (InX <  RectanglePoints[i].X + vt * ( RectanglePoints[j].X - RectanglePoints[i].X ))
				++cn;
		}
	}
	return ( cn & 1 );    // 0 if even (out), and 1 if  odd (in)
}

// =============================================================
// 사정거리를 그립니다.
// =============================================================
void ACharacterTurret::DrawDebugSearchArea()
{
	if(TurretSearchAreaType == ESearchAreaType::Circle)
	{
		DrawDebugCircle(GetWorld(), GetActorLocation(), GetStat().GetStat(ECharacterStatType::AttackMaxRange), 16, FColor::Red, false, -1, 0, 3, FVector(0,1,0), FVector(1,0,0), true);
		DrawDebugCircle(GetWorld(), GetActorLocation(), GetStat().GetStat(ECharacterStatType::AttackMinRange), 16, FColor::Green, false, -1, 0, 3, FVector(0,1,0), FVector(1,0,0), true);

		/*float dif = GetStat().GetStat(ECharacterStatType::AttackMaxRange) - GetStat().GetStat(ECharacterStatType::AttackMinRange);
		float colorDif = 255 / 4;
		for(int32 i = 1 ; i <= 4 ; i++)
		{
			DrawDebugCircle(GetWorld(), GetActorLocation(), GetStat().GetStat(ECharacterStatType::AttackMaxRange) - (dif * i / 4), 16, FColor(255 - (colorDif * i),colorDif * i,0), false, -1, 0, 3, FVector(0,1,0), FVector(1,0,0), false);
		}*/
	}

	if(TurretSearchAreaType == ESearchAreaType::Rectangle)
	{
		if(RectanglePoints.IsEmpty())
			return;
		for(int i = 0; i < RectanglePoints.Num(); ++i)
		{
			if(i == RectanglePoints.Num() - 1)
				DrawDebugLine( GetWorld(),RectanglePoints[i],RectanglePoints[0],FColor::Red, false, -1, 0, 3);
			else
				DrawDebugLine( GetWorld(),RectanglePoints[i],RectanglePoints[i + 1],FColor::Red, false, -1, 0, 3);
		}
	}
}