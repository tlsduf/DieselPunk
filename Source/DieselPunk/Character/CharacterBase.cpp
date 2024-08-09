// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "CharacterTurret.h"
#include "../Actor/DamageUIActor.h"
#include "../Core/DpGameMode.h"
#include "../Manager/ObjectManager.h"
#include "../Core/DPLevelScriptActor.h"
#include "../Component/StatControlComponent.h"

#include <Components/WidgetComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/CapsuleComponent.h>
#include <Engine/Level.h>
#include <Kismet/GameplayStatics.h>

#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "ColorManagement/Public/ColorManagementDefines.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


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

	StatControlComponent = CreateDefaultSubobject<UStatControlComponent>(TEXT("StatControlComponent"));
}


// =============================================================
// Called when the game starts or when spawned
// =============================================================
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	CreateTime = FDateTime::Now();

	if(ObjectId == -1)
		FObjectManager::GetInstance()->AddActor(this);

	CreateStatusUI();
	// 트레이스 반응 설정 // ECC_GameTraceChannel6는 플레이어, 아군, 적군 이 서로를 탐지할 때 사용합니다.
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_DP_CharacterMultiTrace, ECollisionResponse::ECR_Block);
}

// =============================================================
// Called before destroying the object.
// =============================================================
void ACharacterBase::BeginDestroy()
{
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

void ACharacterBase::InitCollisionResponseToChannel()
{
	
}

// [Stat] 스탯을 변화합니다. 인게임에서 진행도중 스탯을 변경하려면 이 함수를 사용하세요. Stat[InStatType] = Stat[InStatType] + InValue; 로 적용됩니다.
void ACharacterBase::ChangeStat(ECharacterStatType InStatType, int32 InValue)
{
	int32 value = StatControlComponent->GetStat(InStatType) + InValue;
	StatControlComponent->SetStat(InStatType, value);
}

//================================================================
// 블루프린트용 스탯 Getter
//================================================================
int32 ACharacterBase::GetStat(ECharacterStatType InStatType)
{
	return StatControlComponent->GetStat(InStatType);
}

//================================================================
// 데미지 처리
//================================================================
float ACharacterBase::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser)
{
	float damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	//데미지 면역
	if(DamageImmunity)
	{
		HandleCombatState();
		damage = 0.f;
		CreateDamageActor(damage);
		return damage;
	}
	//EventInstigator 가 본인일 때
	if(EventInstigator == Controller)
	{
		damage = 0.f;
		return damage;
	}
	
	HandleCombatState();	// 전투상태 돌입
	//================================================================
	// 1.데미지 계산(공식적용|올림내림)
	damage = (int)(damage + 0.2); // 데미지 소수점 처리 *소수점첫째자리가 0.8 이상이면 올림, 미만시 내림
	damage = FMath::Min(GetStat(ECharacterStatType::Hp), (int)damage);
		
	_UpdateHp(GetStat(ECharacterStatType::Hp) - damage, GetStat(ECharacterStatType::MaxHp));
		
	CreateDamageActor(damage);
		
	//================================================================
	// 2.애니메이션 플레이 //bool 변수로 0.3초마다 애니메이션 실행
	PlayDamagedAnim();

	//================================================================
	// 3.죽음구현
	if (GetStat(ECharacterStatType::Hp) - damage <= 0)
	{
		if(auto NPC = Cast<ACharacterNPC>(this))
		{
			// 몬스터 처치 시 여러 기능을 실행
			if(NPC->GetNPCType() == ENPCType::Enemy)
			{
				// 플레이어에게 코스트를 지급합니다.
				ACharacterPC* playerPawn = Cast<ACharacterPC>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
				if (playerPawn != nullptr)
					playerPawn->ChangeStat(ECharacterStatType::Cost, GetStat(ECharacterStatType::Cost));
					
				auto DamageCauserPlayer = Cast<ACharacterBase>(DamageCauser);
				// 플레이어의 경험치를 1 올림
				if(Cast<ACharacterPC>(DamageCauser))
				{
					DamageCauserPlayer->ChangeStat(ECharacterStatType::Exp, 1);
					if(DamageCauserPlayer->GetStat(ECharacterStatType::Level) != UtilLevelCal::LevelCalc(DamageCauserPlayer->GetStat(ECharacterStatType::Exp)))
						DamageCauserPlayer->ChangeStat(ECharacterStatType::Level, UtilLevelCal::LevelCalc(DamageCauserPlayer->GetStat(ECharacterStatType::Exp)));
					if(DamageCauserPlayer->GetStat(ECharacterStatType::MaxHp) != UtilLevelCal::MaxHealthCalc(DamageCauserPlayer->GetStat(ECharacterStatType::Level)))
						DamageCauserPlayer->ChangeStat(ECharacterStatType::MaxHp , UtilLevelCal::MaxHealthCalc(DamageCauserPlayer->GetStat(ECharacterStatType::Level)));
				}
			}
		}
		if(auto turret = Cast<ACharacterTurret>(this))
		{
			//포탑 파괴 이벤트
		}
		//아래 주석처리한 Destroy와 레벨관리는 UStatControlComponent/SetStatDelegateFunction.163(2024.7.2)로 옮겼습니다.
		//Destroy();
		// 레벨관리
		//if(ADPLevelScriptActor* level = Cast<ADPLevelScriptActor>(this->GetLevel()->GetLevelScriptActor()))
		//  level->CheckWaveCleared();
	}
	ChangeStat(ECharacterStatType::Hp , -damage);
	
	//랙돌 Impulse
	if(GetStat(ECharacterStatType::Hp) <= 0)
		RagdollImpulse(DamageAmount, EventInstigator, DamageCauser);
	
	return damage;
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
	float curPercent = ( float )GetStat(ECharacterStatType::Hp) / ( float )GetStat(ECharacterStatType::MaxHp);
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
	return GetStat(ECharacterStatType::Hp) <= 0;
}

float ACharacterBase::PlayCharacterStatusEffectAnimMontage(float InPlayRate, const FName& InSectionName)
{
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if(animInstance == nullptr || StatusEffectAnimMontage == nullptr)
		return -1.f;

	if(InSectionName == NAME_None || !StatusEffectAnimMontage->IsValidSectionName(InSectionName))
		return -1.f;

	_OnInterruptSkillAnimation();
	
	UAnimMontage* curMontage = animInstance->GetCurrentActiveMontage();
	if(curMontage != StatusEffectAnimMontage || curMontage->RateScale != InPlayRate)
		if(animInstance->Montage_Play(StatusEffectAnimMontage, InPlayRate, EMontagePlayReturnType::Duration) <= 0.f)
			return -1.f;

	animInstance->Montage_JumpToSection(InSectionName);
	
	int32 index = StatusEffectAnimMontage->GetSectionIndex(InSectionName);
	return StatusEffectAnimMontage->GetSectionLength(index) / InPlayRate;
}

void ACharacterBase::StopCharacterStatusEffectAnimMontage(float InBlendOutTime)
{
	UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
	if(animInstance == nullptr || StatusEffectAnimMontage == nullptr)
		return;

	if(animInstance->Montage_IsPlaying(StatusEffectAnimMontage))
		animInstance->Montage_Stop(InBlendOutTime, StatusEffectAnimMontage);
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
		GetWorld()->GetTimerManager().SetTimer(CombatStateTHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->InCombat = false;
			},5.0f, false);
	}
	else
	{
		// 타이머가 실행 중이 아니면, 5초 후에 InCombat을 false로 설정합니다.
		TWeakObjectPtr<ACharacterBase> thisPtr = this;
		GetWorld()->GetTimerManager().SetTimer(CombatStateTHandle, [thisPtr](){
				if(thisPtr.IsValid())
					thisPtr->InCombat = false;
			},5.0f, false);
	}
}

void ACharacterBase::SetBuffStatusEffectRoleType(EBuffStatusEffectRoleType InBuffStatusEffectRolType, bool InCan)
{
	if(InBuffStatusEffectRolType < EBuffStatusEffectRoleType::Move || InBuffStatusEffectRolType >= EBuffStatusEffectRoleType::Max)
		return;

	if(InBuffStatusEffectRolType == EBuffStatusEffectRoleType::Move)
		CanMove = InCan;
	else if(InBuffStatusEffectRolType == EBuffStatusEffectRoleType::Attack)
		CanAttack = InCan;
	else if(InBuffStatusEffectRolType == EBuffStatusEffectRoleType::Skill)
		CanSkill = InCan;
}

void ACharacterBase::RagdollImpulse(float DamageAmount, AController *EventInstigator, AActor *DamageCauser)
{
	//플레이어와 몬스터일 경우에만 Impulse
	if(CharacterType == ECharacterType::None || CharacterType == ECharacterType::Turret || CharacterType == ECharacterType::Installation)
		return;
	
	if(DamageCauser == nullptr)
	{
		//DamageCauser == nullptr << 액터를 이용한 공격이 아니다
		FVector impulse = FVector( GetActorLocation() - EventInstigator->GetCharacter()->GetActorLocation() ).GetSafeNormal();
		impulse = impulse * 5000;
		GetMesh()->AddImpulse(impulse, NAME_None ,true);
	}
	else
	{
		//DamageCause /= nullptr << 투사체나 액터를 이용한 공격
		FVector impulse = FVector( GetActorLocation() - DamageCauser->GetActorLocation() ).GetSafeNormal();
		impulse = impulse * 5000;
		GetMesh()->AddImpulse(impulse, NAME_None ,true);
	}
}