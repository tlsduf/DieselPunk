// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNPC.h"
#include "../Skill/SkillBase.h"
#include "../UI/HUD/EnemyStatusUI.h"

#include <Components/WidgetComponent.h>
#include <AIController.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <NavigationSystem.h>
#include <DrawDebugHelpers.h>
#include <Kismet/GameplayStatics.h>

#include "CharacterMonster.h"
#include "Animation/AnimSequence.h"
#include "Components/SkeletalMeshComponent.h"
#include "DieselPunk/Animation/DPAnimInstance.h"
#include "DieselPunk/Component/StatControlComponent.h"
#include "DieselPunk/Data/SearchAreaDataTable.h"
#include "DieselPunk/Manager/DatatableManager.h"
#include "DieselPunk/Skill/SkillNPC/NPCAttack.h"


// =============================================================
// 생성자
// =============================================================
ACharacterNPC::ACharacterNPC()
{
	// AI possess
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// =============================================================
// BeginPlay
// =============================================================
void ACharacterNPC::BeginPlay()
{
	Super::BeginPlay();
	
	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	// Skill Instancing , SKill Stat Initialize

	if(!NPCAttackNames.IsEmpty())
	{
		for(const auto& [key, skillName] : NPCAttackNames)
		{
			UNPCAttack* attack = NewObject<UNPCAttack>(this, skillName);
			attack->RegisterComponent();
			attack->SetNPCSkillName(skillName);
			attack->InitSkill();
			NPCAttacks.Add(key, attack);
		}
		UseableSkills.Reserve(NPCAttacks.Num());
	}
	
	if(StatControlComponent->GetActorNames().IsEmpty())
		return;

	FName name = StatControlComponent->GetActorNames()[0];
	const FSearchAreaDataTable* table = FDataTableManager::GetInstance()->GetData<FSearchAreaDataTable>(EDataTableType::SearchArea, name);
	if(table)
	{
		SearchAreaData.SearchAreaType = table->SearchAreaType;
		SearchAreaData.RectangleWidth = table->RectangleWidth;
		SearchAreaData.ArcAngle = table->ArcAngle;
		SearchAreaData.CircleHeight = table->CircleHeight;
		SearchAreaData.AtkMaxRange = table->AtkMaxRange;
		SearchAreaData.AtkMaxRangeForFly = table->AtkMaxRangeForFly;
		SearchAreaData.AtkMinRange = table->AtkMinRange;
	}
}

// =============================================================
// Tick
// =============================================================
void ACharacterNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if( EnemyStatusUI != nullptr )
	{
		EnemyStatusUI->SetHPPercent(HpPercent);
		EnemyStatusUI->SetHPPercentAfterImage(HpPercentAfterImage);
	}
	
	if(IsDead())
		WidgetComp->bHiddenInGame = 1;

	SetTarget();
	
	FindUseableAbilityType();
}

// =============================================================
// SetupPlayerInputComponent
// =============================================================
void ACharacterNPC::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
}

// =============================================================
// 상태 UI 위젯을 생성한다.
// =============================================================
void ACharacterNPC::CreateStatusUI()
{
	if( EnemyStatusUI.IsValid() )
		return;

	FString inPath = UtilPath::GetUIPath( TEXT("NPC_HpBar") );
	UClass* widgetClass = ConstructorHelpersInternal::FindOrLoadClass( inPath, UUserWidget::StaticClass() );
	if(!widgetClass)
		return;
	
	UUserWidget* userWidget = CreateWidget<UUserWidget>( GetWorld(), widgetClass );
	if ( userWidget )
	{
		userWidget->AddToRoot();

		UUserWidgetBase* userWidgetBase = Cast<UUserWidgetBase>( userWidget );
		if ( userWidgetBase )
			userWidgetBase->OnCreated();
	}
	UEnemyStatusUI* myWidget = Cast<UEnemyStatusUI>(userWidget);
	if(myWidget)
		myWidget->RemoveFromRoot();
		
	EnemyStatusUI = myWidget;

	
	if ( !WidgetComp || !EnemyStatusUI.IsValid() )
		return;

	WidgetComp->SetWidget( EnemyStatusUI.Get() );
	WidgetComp->SetDrawSize( FVector2D( 250.0f, 80.0f ) );
	WidgetComp->bHiddenInGame = 1;
	
	EnemyStatusUI->SetHPPercent(HpPercent);
	EnemyStatusUI->SetHPPercentAfterImage(HpPercentAfterImage);
}

// =============================================================
// UI 컨트롤 하기 위한 오버라이드
// =============================================================
float ACharacterNPC::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,AActor* DamageCauser)
{
	HandleStatusUI();
	
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

// =============================================================
// UI 타이머 컨트롤
// =============================================================
void ACharacterNPC::HandleStatusUI()
{
	WidgetComp->bHiddenInGame = 0;

	// 만약 타이머가 이미 실행 중이면, 타이머를 초기화하고 재설정합니다.
	if (GetWorldTimerManager().IsTimerActive(EnemyStatusUITHandle))
	{
		GetWorldTimerManager().ClearTimer(EnemyStatusUITHandle);
		TWeakObjectPtr<ACharacterNPC> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(EnemyStatusUITHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->WidgetComp->bHiddenInGame = 1;
			},10.0f, false);
	}
	else
	{
		// 타이머가 실행 중이 아니면, 10초 후에 EnemyStatusUI를 화면에서 제거합니다.(SetHidden)
		TWeakObjectPtr<ACharacterNPC> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(EnemyStatusUITHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->WidgetComp->bHiddenInGame = 1;
			},10.0f, false);
	}
}

void ACharacterNPC::FindUseableAbilityType()
{
	UseableSkills.Empty();
	
	//for(const auto& [key, skill] : NPCSkills)
	//{
	//	if(skill->IsUseableSkill(Target))
	//		UseableSkills.Add(key);
	//}

	for(const auto& [key, attack] : NPCAttacks)
	{
		if(attack->IsUseableSkill(Target))
			UseableSkills.Add(key);
	}
}

// =============================================================
// 포탑의 사각형 탐색범위를 생성합니다. 
// =============================================================
void ACharacterNPC::MakeSearchArea()
{
	if(SearchAreaData.SearchAreaType != ESearchAreaType::Rectangle)
		return;
	
	FVector firstPoint = GetActorLocation() + (GetActorRightVector() * SearchAreaData.RectangleWidth * 0.5f);
	FVector secondPoint = GetActorLocation() + (GetActorRightVector() * SearchAreaData.RectangleWidth * 0.5f) + GetActorForwardVector() * GetStat(ECharacterStatType::AtkMaxRange);
	FVector thirdPoint = GetActorLocation() + (-1 * GetActorRightVector() * SearchAreaData.RectangleWidth * 0.5f) + GetActorForwardVector() * GetStat(ECharacterStatType::AtkMaxRange);
	FVector fourthPoint = GetActorLocation() + (-1 * GetActorRightVector() * SearchAreaData.RectangleWidth * 0.5f);

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
bool ACharacterNPC::InValidSearchArea(FVector InLocation)
{
	if(SearchAreaData.SearchAreaType == ESearchAreaType::Circle)
	{
		FVector ownerLoc = GetActorLocation();
		ownerLoc.Z = 0.f;
		FVector inLoc = InLocation;
		inLoc.Z = 0.f;
		
		float distance = FVector::Dist(ownerLoc, inLoc);
		bool inMaxDistance = distance <= GetStat(ECharacterStatType::AtkMaxRange);		// 최대거리 안에 위치?
		bool inMinDistance = distance >= GetStat(ECharacterStatType::AtkMinRange);		// 최소거리 밖에 위치?
		bool inMaxHeight = InLocation.Z <= GetActorLocation().Z + SearchAreaData.CircleHeight * 0.5f;
		bool inMinHeight = InLocation.Z >= GetActorLocation().Z - SearchAreaData.CircleHeight * 0.5f;
	
		return inMaxDistance && inMinDistance && inMaxHeight && inMinHeight;
	}
	else if(SearchAreaData.SearchAreaType == ESearchAreaType::Rectangle)
	{
		return IsInPolygon(InLocation.X, InLocation.Y);
	}
	else if(SearchAreaData.SearchAreaType == ESearchAreaType::Arc)
	{
		float distance = FVector::Distance(GetActorLocation(), InLocation);

		OriginForwardVector.Normalize();
		FVector targetDir = InLocation - GetActorLocation();
		targetDir.Normalize();
		double dot = FVector::DotProduct(OriginForwardVector, targetDir);

		return distance < GetStat(ECharacterStatType::AtkMaxRange)
			&& distance > GetStat(ECharacterStatType::AtkMinRange)
			&& dot > FMath::Cos(FMath::DegreesToRadians(SearchAreaData.ArcAngle * 0.5));
	}
	
	return false;
}


// =============================================================
// 다각형 내부에 점이 위치하는지 확인합니다. // Point in polygon algorithm
// =============================================================
bool ACharacterNPC::IsInPolygon(double InX, double InY)
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
void ACharacterNPC::DrawDebugSearchArea()
{
	if(SearchAreaData.SearchAreaType == ESearchAreaType::Circle)
	{
		DrawDebugCircle(GetWorld(), GetActorLocation(), GetStat(ECharacterStatType::AtkMaxRange), 16, FColor::Red, false, -1, 0, 3, FVector(0,1,0), FVector(1,0,0), true);
		DrawDebugCircle(GetWorld(), GetActorLocation(), GetStat(ECharacterStatType::AtkMinRange), 16, FColor::Green, false, -1, 0, 3, FVector(0,1,0), FVector(1,0,0), true);

		/*float dif = GetStat().GetStat(ECharacterStatType::AttackMaxRange) - GetStat().GetStat(ECharacterStatType::AttackMinRange);
		float colorDif = 255 / 4;
		for(int32 i = 1 ; i <= 4 ; i++)
		{
			DrawDebugCircle(GetWorld(), GetActorLocation(), GetStat().GetStat(ECharacterStatType::AttackMaxRange) - (dif * i / 4), 16, FColor(255 - (colorDif * i),colorDif * i,0), false, -1, 0, 3, FVector(0,1,0), FVector(1,0,0), false);
		}*/
	}
	else if(SearchAreaData.SearchAreaType == ESearchAreaType::Rectangle)
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
	else if(SearchAreaData.SearchAreaType == ESearchAreaType::Arc)
	{
		FRotator right = OriginForwardVector.Rotation() + FRotator(0.0, SearchAreaData.ArcAngle * 0.5, 0.0);
		FRotator left = OriginForwardVector.Rotation() + FRotator(0.0, SearchAreaData.ArcAngle * -0.5, 0.0);
		DrawDebugLine(GetWorld(),
			GetActorLocation() + left.Vector() * GetStat(ECharacterStatType::AtkMinRange),
			GetActorLocation() + left.Vector() * GetStat(ECharacterStatType::AtkMaxRange),
			FColor::Red, false, -1, 0, 3);

		
		DrawDebugLine(GetWorld(),
			GetActorLocation() + right.Vector() * GetStat(ECharacterStatType::AtkMinRange),
			GetActorLocation() + right.Vector() * GetStat(ECharacterStatType::AtkMaxRange),
			FColor::Red, false, -1, 0, 3);

		DrawDebugCircleArc(GetWorld(),
			GetActorLocation(),
			GetStat(ECharacterStatType::AtkMinRange),
			OriginForwardVector,
			FMath::DegreesToRadians(SearchAreaData.ArcAngle * 0.5),
			12, FColor::Red, false, -1, 0, 3);
		
		DrawDebugCircleArc(GetWorld(),
			GetActorLocation(),
			GetStat(ECharacterStatType::AtkMaxRange),
			OriginForwardVector,
			FMath::DegreesToRadians(SearchAreaData.ArcAngle * 0.5),
			12, FColor::Red, false, -1, 0, 3);
	}
}

// =============================================================
// 몬스터 스킬
// =============================================================

void ACharacterNPC::InitSkill()
{
	if(!NPCAttacks.IsEmpty())
		for(const auto& [key, attack] : NPCAttacks)
			attack->InitSkill();
}

// =============================================================
// 타겟을 업데이트하고, 업데이트 조건에 따라 함수를 실행합니다.
// =============================================================
void ACharacterNPC::ChangeTarget(TWeakObjectPtr<AActor> inTarget)
{
	if(inTarget == Target)
		return;

	// 타겟이 플레이어에서 다른 타겟으로 업데이트 되면 경로재설정
	if(Target == Player)
		if(inTarget != Player)
			if(Cast<ACharacterMonster>(this))
				Cast<ACharacterMonster>(this)->UpdateSplinePath();
	
	Target = inTarget;
}

const UAnimSequence* ACharacterNPC::GetNPCAttackAnimation(EAbilityType InAbilityType)
{
	UAnimSequence** animSequencePtr = NPCAttackAnimations.Find(InAbilityType);
	if(animSequencePtr)
		return *animSequencePtr;

	return nullptr;
}

//스폰 애니메이션을 실행하고 애니메이션의 길이를 반환합니다. 애니메이션이 없을 경우 0을 반환합니다.
float ACharacterNPC::PlaySpawnAnim()
{
	if(SpawnAnimation == nullptr)
		return 0.f;

	USkeletalMeshComponent* mesh = GetMesh();
	if(mesh == nullptr)
		return 0.f;

	mesh->PlayAnimation(SpawnAnimation, false);

	return SpawnAnimation->GetPlayLength();
}

void ACharacterNPC::DoNPCSkill(EAbilityType InAbilityType)
{
	//TObjectPtr<USkillBase>* skill = NPCSkills.Find(InAbilityType);
	//if(skill && *skill && CanAttack)
	//{
	//	(*skill)->AbilityStart(Target.Get());
	//	CurrentUseAbilityType = InAbilityType;
	//	if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(GetMesh()->GetAnimInstance()))	
	//		animInst->AttackSign(InAbilityType);
	//}

	TObjectPtr<UNPCAttack>* attack = NPCAttacks.Find(InAbilityType);
	if(attack && *attack && CanAttack)
	{
		(*attack)->AbilityStart(Target.Get());
		CurrentUseAbilityType = InAbilityType;
		if(UDPAnimInstance* animInst = Cast<UDPAnimInstance>(GetMesh()->GetAnimInstance()))	
			animInst->AttackSign(InAbilityType);
	}
}

void ACharacterNPC::AbilityShot(double InDamageCoefficient)
{
	Super::AbilityShot(InDamageCoefficient);

	if(CurrentUseAbilityType != EAbilityType::None)
	{
		TObjectPtr<UNPCAttack>* attack = NPCAttacks.Find(CurrentUseAbilityType);
		if(attack && *attack)
		{
			(*attack)->AbilityShot(InDamageCoefficient, Target.Get());
			CurrentUseAbilityType = EAbilityType::None;
		}
	}
}

EAbilityType ACharacterNPC::GetTopPriorityUseableSkill()
{
	TArray<EAbilityType> melee;
	TArray<EAbilityType> ranged;
    
	for(const EAbilityType& useableSkill : GetUseableSkills())
	{
		const UNPCAttack* attack = GetNPCAttack(useableSkill);
		if(attack->GetSkillDistanceType() == ESkillDistanceType::MeleeAttack)
			melee.Add(useableSkill);
		else if(attack->GetSkillDistanceType() == ESkillDistanceType::RangedAttack)
			ranged.Add(useableSkill);
	}

	if(!melee.IsEmpty())
	{
		int32 random = FMath::RandRange(0, melee.Num() - 1);
		return melee[random];
	}
	else
	{
		if(!ranged.IsEmpty())
		{
			int32 random = FMath::RandRange(0, ranged.Num() - 1);
			return ranged[random];
		}
		else
		{
			return EAbilityType::None;
		}
	}
	return EAbilityType::None;
}

bool ACharacterNPC::IsAllParabolaAttack()
{
	for(const auto& [key, value] : NPCAttacks)
	{
		if(value->GetProjectileType() != EProjectileType::Parabola)
			return false;
	}
	return true;
}

const UNPCAttack* ACharacterNPC::GetNPCAttack(EAbilityType InAbilityType)
{
	TObjectPtr<UNPCAttack>* attackPtr = NPCAttacks.Find(InAbilityType);
	if(attackPtr)
		return *attackPtr;

	return nullptr;
}