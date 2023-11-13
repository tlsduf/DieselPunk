// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "../Actor/DamageUIActor.h"
#include "DieselPunk/Core/DpGameMode.h"

#include <Components/WidgetComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Engine/DamageEvents.h>



#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterBase)


// =============================================================
// Sets default values for this character's properties
// =============================================================
ACharacterBase::ACharacterBase()
{
	WidgetComp = CreateDefaultSubobject< UWidgetComponent >( TEXT( "StatusUI" ) );
	if ( WidgetComp )
	{
		WidgetComp->SetupAttachment( GetRootComponent() );
		WidgetComp->SetCollisionEnabled( ECollisionEnabled::Type::NoCollision );
		WidgetComp->SetGenerateOverlapEvents( false );
		WidgetComp->SetSimulatePhysics( false );
		WidgetComp->SetWidgetSpace( EWidgetSpace::Screen );
	}
	
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// =============================================================
// Called when the game starts or when spawned
// =============================================================
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	CreateStatusUI();
	
	//스탯 초기화
	Stat.Initialize(this, CharacterName);
}

// =============================================================
// Called before destroying the object.
// =============================================================
void ACharacterBase::BeginDestroy()
{
	Stat.Release();
	
	Super::BeginDestroy();
}

// =============================================================
// Called every frame
// =============================================================
void ACharacterBase::Tick(float InDeltaTime)
{
	Super::Tick(InDeltaTime);

	// 체력바 애니메이션 업데이트
	HpBarAnimator.Update(InDeltaTime);
	HpBarAfterImageAnimator.Update(InDeltaTime);
	
	HpPercent = HpBarAnimator.GetCurValue();
	HpPercentAfterImage = HpBarAfterImageAnimator.GetCurValue();
}

// =============================================================
// Called to bind functionality to input
// =============================================================
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* InPlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InPlayerInputComponent);
}

//================================================================
// 블루프린트용 스탯 Getter
//================================================================
int32 ACharacterBase::GetCharacterStat(ECharacterStatType InStatType)
{
	return Stat.GetStat(InStatType);
}

//================================================================
// 데미지 처리
//================================================================
float ACharacterBase::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser)
{
	float damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	// DamageImmunity가 false 일 때 데미지계산
	if (!DamageImmunity && EventInstigator != Controller)
	{
		HandleCombatState();
		//================================================================
		// 1.데미지이벤트 판별
		//================================================================
		
		if (DamageEvent.IsOfType(FPointDamageEvent::ClassID))
		{
			const FPointDamageEvent *PointDamageEvent = static_cast<const FPointDamageEvent *>(&DamageEvent);
			if (0 == (PointDamageEvent->HitInfo.BoneName).Compare(FName(TEXT("Head"))))
			{
				// TODO 부위별 데미지 기능 실현
				damage *= 5;
			}
		}
		else if (DamageEvent.IsOfType(FRadialDamageEvent::ClassID))
		{
			const FRadialDamageEvent *RadialDamageEvent = static_cast<const FRadialDamageEvent *>(&DamageEvent);
		}

		//================================================================
		// 2.데미지 계산(공식적용-올림내림)
		//================================================================
		// TODO 방어력, 공격효과 적용해서 데미지공식 적용하기
		// TODO 효과적용 방식 : 체력비례피해(최대or현재), 고정피해(방어구관통), 지속피해(틱뎀), 방어력감소(영구or시간), 폭발스택
		//Damage = Damage * (100 / (100 + Armor));
		damage = (int)(damage + 0.2); // 데미지 소수점 처리 *소수점첫째자리가 0.8 이상이면 올림, 미만시 내림

		damage = FMath::Min(Stat.GetStat(ECharacterStatType::Hp), (int)damage);
		_UpdateHp(Stat.GetStat(ECharacterStatType::Hp) - damage, Stat.GetStat(ECharacterStatType::MaxHp));
		Stat.ChangeStat(ECharacterStatType::Hp , -damage);
		CreateDamageActor(damage);
		LOG_SCREEN(FColor::Red, TEXT("hp : %d"), Stat.GetStat(ECharacterStatType::Hp));
		
		//================================================================
		// 3.애니메이션 플레이 //bool 변수로 0.3초마다 애니메이션 실행
		//================================================================
		if (CanTakeDamageAnim)
		{
			TakeDamageAnim = true;
			GetWorldTimerManager().SetTimerForNextTick(this, &ACharacterBase::SetTakeDamageAnimFalse);
			CanTakeDamageAnim = false;
			GetWorldTimerManager().SetTimer(TakeDamageHandle, this, &ACharacterBase::SetCanTakeDamageAnimTrue, 0.3f, false);
		}

		//================================================================
		// 4.죽음구현
		//================================================================
		if (IsDead())
		{
			//LOG_SCREEN(TEXT("He Died"));
			ADpGameMode *GameMode = GetWorld()->GetAuthGameMode<ADpGameMode>();
			if (GameMode != nullptr)
			{
				GameMode->PawnKilled(this);
			}
			
			/*
			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision); // 캡슐콜리전 무효
			// 20초 뒤 액터 destroy
			TWeakObjectPtr<ACharacterPC> thisPtr = this;
			GetWorld()->GetTimerManager().SetTimer(
				TakeDamageHandle, [thisPtr]()
				{
					if(thisPtr.IsValid())
						thisPtr->Destroy();
				},
				20.0f, false);
			*/

			auto DamageCauserPlayer = Cast<ACharacterBase>(DamageCauser);
			// 플레이어의 경험치를 1 올림
			DamageCauserPlayer->Stat.ChangeStat(ECharacterStatType::Exp, 1);
			if(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Level) != UtilLevelCal::LevelCal(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Exp)))
				DamageCauserPlayer->Stat.ChangeStat(ECharacterStatType::Level, UtilLevelCal::LevelCal(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Exp)));
			if(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::MaxHp) != UtilLevelCal::MaxHealthCal(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Level)))
				DamageCauserPlayer->Stat.ChangeStat(ECharacterStatType::MaxHp , UtilLevelCal::MaxHealthCal(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Level)));
			
			Destroy();
		}
		
		return damage;
	}
	else // DamageImmunity가 true 일 때 Damage = 0
	{
		HandleCombatState();
		damage = 0.f;
		CreateDamageActor(damage);
		
		// 애니메이션 플레이 //bool 변수로 0.3초마다 애니메이션 실행
		if (CanTakeDamageAnim)
		{
			TakeDamageAnim = true;
			GetWorldTimerManager().SetTimerForNextTick(this, &ACharacterBase::SetTakeDamageAnimFalse);
			CanTakeDamageAnim = false;
			GetWorldTimerManager().SetTimer(TakeDamageHandle, this, &ACharacterBase::SetCanTakeDamageAnimTrue, 0.3f, false);
		}
		return damage;
	}
}

//================================================================
// 데미지를 받을 때, 데미지 받는 애니메이션 출력을 위한 함수. TakeDamage에서 호출합니다. ABP에서 활용됩니다.
//================================================================
void ACharacterBase::SetTakeDamageAnimFalse()
{
	TakeDamageAnim = false;
}
void ACharacterBase::SetCanTakeDamageAnimTrue()
{
	CanTakeDamageAnim = true;
}

// =============================================================
// 데미지를 입으면 데미지UI액터를 생성합니다.
// =============================================================
void ACharacterBase::CreateDamageActor(float InDamage)
{
	FTransform SpawnTransform( FRotator::ZeroRotator, GetActorLocation());
	DamageUIActor = GetWorld()->SpawnActorDeferred<ADamageUIActor>(ADamageUIActor::StaticClass(), SpawnTransform, this);
	
	if(DamageUIActor)
	{
		// DamageUIActor->AttachToComponent( GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
		DamageUIActor->SetDamage(InDamage);
		DamageUIActor->FinishSpawning(SpawnTransform);
	}
}

//================================================================
// 체력 변화를 애니메이팅합니다.
//================================================================
void ACharacterBase::_UpdateHp(int InCurHp, int InMaxHp)
{
	// 현재 체력 퍼센트
	float curPercent = ( float )Stat.GetStat(ECharacterStatType::Hp) / ( float )Stat.GetStat(ECharacterStatType::MaxHp);
	curPercent = FMath::Clamp( curPercent, 0.f, 1.f );

	// 목표 체력 퍼센트
	float destPercent = ( float )InCurHp / ( float )InMaxHp;
	destPercent = FMath::Clamp( destPercent, 0.f, 1.f );

	// 퍼센트차이
	float percentAmount = curPercent - destPercent;

	HpBarAnimator.SetParam(curPercent, destPercent, 0.6f, EAnimType::CubicOut);
	HpBarAnimator.Start();

	HpBarAfterImageAnimator.SetParam(curPercent, destPercent,
		(0.f <= percentAmount && percentAmount < 0.2f) ? 0.6f
				: (0.2f <= percentAmount && percentAmount < 0.4f) ? 0.85f
				:													1.1f,
	EAnimType::CubicIn);
	HpBarAfterImageAnimator.Start();
}

//================================================================
// 체력이 0이하일 때, 1 반환
//================================================================
bool ACharacterBase::IsDead()
{
	return Stat.GetStat(ECharacterStatType::Hp) <= 0;
}


//================================================================
// 전투상태 핸들링 함수 // 전투상태 돌입 5초 후, 전투상태 자동 해제. // 해제 전 갱신 시, 5초갱신.
//================================================================
void ACharacterBase::HandleCombatState()
{
	// InCombat을 true로 설정합니다.
	InCombat = true;

	// 만약 타이머가 이미 실행 중이면, 타이머를 초기화하고 재설정합니다.
	if (GetWorldTimerManager().IsTimerActive(CombatStateTHandle))
	{
		GetWorldTimerManager().ClearTimer(CombatStateTHandle);
		GetWorldTimerManager().SetTimer(CombatStateTHandle, this, &ACharacterBase::SetInCombatFalse, 5.f, false);
	}
	else
	{
		// 타이머가 실행 중이 아니면, 5초 후에 InCombat을 false로 설정합니다.
		GetWorldTimerManager().SetTimer(CombatStateTHandle, this, &ACharacterBase::SetInCombatFalse, 5.f, false);
	}
	
	/*TWeakObjectPtr<ACharacterBase> thisPtr = this;
	GetWorld()->GetTimerManager().SetTimer(
		CombatStateTHandle, [thisPtr]()
		{
			if(thisPtr.IsValid())
				thisPtr->InCombat = false;
		},
		5.0f, false);*/
}
void ACharacterBase::SetInCombatFalse()
{
	InCombat = false;
}
