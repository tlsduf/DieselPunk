// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "../Actor/DamageUIActor.h"
#include "../Core/DpGameMode.h"
#include "../Manager/ObjectManager.h"
#include "../Core/DPLevelScriptActor.h"

#include <Components/WidgetComponent.h>
#include <Components/StaticMeshComponent.h>

#include "ColorManagement/Public/ColorManagementDefines.h"
#include "Engine/Level.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterBase)


// =============================================================
// Sets default values for this character's properties
// =============================================================
ACharacterBase::ACharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	WidgetComp = CreateDefaultSubobject< UWidgetComponent >( TEXT( "StatusUI" ) );
	if ( WidgetComp )
	{
		WidgetComp->SetupAttachment( GetRootComponent() );
		WidgetComp->SetCollisionEnabled( ECollisionEnabled::Type::NoCollision );
		WidgetComp->SetGenerateOverlapEvents( false );
		WidgetComp->SetSimulatePhysics( false );
		WidgetComp->SetWidgetSpace( EWidgetSpace::Screen );
	}
}


// =============================================================
// Called when the game starts or when spawned
// =============================================================
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if(ObjectId == -1)
		FObjectManager::GetInstance()->AddActor(this);

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
int32 ACharacterBase::GetCharacterStat(ECharacterStatType inStatType)
{
	return Stat.GetStat(inStatType);
}

//================================================================
// 데미지 처리
//================================================================
float ACharacterBase::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser)
{
	float damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	
	// DamageImmunity가 false 일 때 데미지계산 // EventInstigator 가 본인이 아닐 때 데미지 계산
	if (!DamageImmunity && EventInstigator != Controller)
	{
		HandleCombatState();

		//================================================================
		// 1.데미지 계산(공식적용|올림내림)
		damage = (int)(damage + 0.2); // 데미지 소수점 처리 *소수점첫째자리가 0.8 이상이면 올림, 미만시 내림
		damage = FMath::Min(Stat.GetStat(ECharacterStatType::Hp), (int)damage);
		
		_UpdateHp(Stat.GetStat(ECharacterStatType::Hp) - damage, Stat.GetStat(ECharacterStatType::MaxHp));
		Stat.ChangeStat(ECharacterStatType::Hp , -damage);
		CreateDamageActor(damage);
		
		//================================================================
		// 2.애니메이션 플레이 //bool 변수로 0.3초마다 애니메이션 실행
		PlayDamagedAnim();

		//================================================================
		// 3.죽음구현
		if (IsDead())
		{
			auto DamageCauserPlayer = Cast<ACharacterBase>(DamageCauser);
			// 플레이어의 경험치를 1 올림
			DamageCauserPlayer->Stat.ChangeStat(ECharacterStatType::Exp, 1);
			if(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Level) != UtilLevelCal::LevelCal(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Exp)))
				DamageCauserPlayer->Stat.ChangeStat(ECharacterStatType::Level, UtilLevelCal::LevelCal(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Exp)));
			if(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::MaxHp) != UtilLevelCal::MaxHealthCal(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Level)))
				DamageCauserPlayer->Stat.ChangeStat(ECharacterStatType::MaxHp , UtilLevelCal::MaxHealthCal(DamageCauserPlayer->Stat.GetStat(ECharacterStatType::Level)));
			
			Destroy();

			// 레벨관리
			if(ADPLevelScriptActor* level = Cast<ADPLevelScriptActor>(this->GetLevel()->GetLevelScriptActor()))
				level->WaveClearEvent();
		}
		return damage;
	}
	else // DamageImmunity가 true 일 때 Damage = 0
	{
		HandleCombatState();
		damage = 0.f;
		CreateDamageActor(damage);
		PlayDamagedAnim();
		
		return damage;
	}
}

// =============================================================
// Damaged 애니메이션 플레이 //bool 변수로 0.3초마다 애니메이션 실행
// =============================================================
void ACharacterBase::PlayDamagedAnim()
{
	if (CanTakeDamageAnim)
	{
		TakeDamageAnim = true;

		TWeakObjectPtr<ACharacterBase> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimerForNextTick([thisPtr](){
			if(thisPtr.IsValid())
				thisPtr->TakeDamageAnim = false;
			});

		CanTakeDamageAnim = false;
		GetWorld()->GetTimerManager().SetTimer(TakeDamageHandle, [thisPtr](){
			if(thisPtr.IsValid())
				thisPtr->CanTakeDamageAnim = true;
			},0.3f, false);
	}
}


// =============================================================
// 데미지를 입으면 데미지UI액터를 생성합니다.
// =============================================================
void ACharacterBase::CreateDamageActor(float InDamage)
{
	FTransform spawnTransform( FRotator::ZeroRotator, GetActorLocation());
	DamageUIActor = GetWorld()->SpawnActorDeferred<ADamageUIActor>(ADamageUIActor::StaticClass(), spawnTransform, this);
	if(DamageUIActor)
	{
		DamageUIActor->SetDamage(InDamage);
		DamageUIActor->FinishSpawning(spawnTransform);
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

	TWeakObjectPtr<ACharacterBase> thisPtr = this;

	// HPbar 애니메이션
	AnimatorParam HpBarparam;
	HpBarparam.StartValue = curPercent;
	HpBarparam.EndValue = destPercent;
	HpBarparam.DurationTime = 0.6f;
	HpBarparam.AnimType = EAnimType::CubicOut;
	HpBarparam.DurationFunc = [thisPtr](float InCurValue)
	{
		if(thisPtr.IsValid())
			thisPtr->HpPercent = InCurValue;
	};
	HpBarAnimator.SetParam(HpBarparam);
	HpBarAnimator.Start();

	// HPbar 잔상 애니메이션
	AnimatorParam HpBarAfterparam;
	HpBarAfterparam.StartValue = curPercent;
	HpBarAfterparam.EndValue = destPercent;
	HpBarAfterparam.DurationTime = (0.f <= percentAmount && percentAmount < 0.2f) ? 0.6f
								: (0.2f <= percentAmount && percentAmount < 0.4f) ? 0.85f
								:													1.1f;
	HpBarAfterparam.AnimType = EAnimType::CubicIn;
	HpBarAfterparam.DurationFunc = [thisPtr](float InCurValue)
	{
		if(thisPtr.IsValid())
			thisPtr->HpPercentAfterImage = InCurValue;
	};
	HpBarAfterImageAnimator.SetParam(HpBarAfterparam);
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
		TWeakObjectPtr<ACharacterBase> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(TakeDamageHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->InCombat = false;
			},5.0f, false);
	}
	else
	{
		// 타이머가 실행 중이 아니면, 5초 후에 InCombat을 false로 설정합니다.
		TWeakObjectPtr<ACharacterBase> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(TakeDamageHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->InCombat = false;
			},5.0f, false);
	}
}
