// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNPC.h"
#include "../Skill/PlayerSkill.h"
#include "../Skill/MeleeAttack.h"
#include "../Manager/UIManager.h"
#include "../UI/HUD/EnemyStatusUI.h"

//#include <Components/InputComponent.h>
#include <Kismet/GameplayStatics.h>
#include <Particles/ParticleSystemComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Components/WidgetComponent.h>


ACharacterNPC::ACharacterNPC()
{
	MeleeAttack = CreateDefaultSubobject<UPlayerSkill>(TEXT("MeleeAttack"));
	ProjectileAttack = CreateDefaultSubobject<UPlayerSkill>(TEXT("ProjectileAttack"));
}

void ACharacterNPC::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if( EnemyStatusUI != nullptr )
	{
		EnemyStatusUI->SetHPPercent(TempPercent);
		EnemyStatusUI->SetHPPercentAfterImage(TempPercentAfterImage);
		EnemyStatusUI->SetTextStack(SoldierStack);
	}
	if(IsDead())
		WidgetComp->bHiddenInGame = 1;
	
}

// =============================================================
// 상태 UI 위젯을 생성한다.
// =============================================================
void ACharacterNPC::CreateStatusUI()
{
	if( EnemyStatusUI.IsValid() )
		return;

	EnemyStatusUI = GetUIManager().CreateUnmanagedUI< UEnemyStatusUI >( TEXT( "HUD/NPC_HpBar" ) );
	if ( !WidgetComp || !EnemyStatusUI.IsValid() )
		return;

	WidgetComp->SetWidget( EnemyStatusUI.Get() );
	WidgetComp->SetDrawSize( FVector2D( 250.0f, 80.0f ) );
	WidgetComp->bHiddenInGame = 1;
	
	//EnemyStatusUI->InitStatus( this );
	EnemyStatusUI->SetHPPercent(TempPercent);
	EnemyStatusUI->SetHPPercentAfterImage(TempPercentAfterImage);
}

void ACharacterNPC::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	//PlayerInputComponent->BindAction("LeftMouse", IE_Pressed, this, &ABaseEnemyCharacter::MeleeAttackHandle);
	//PlayerInputComponent->BindAction("RightMouse", IE_Pressed, this, &ABaseEnemyCharacter::DoProjectileAttack);
}

float ACharacterNPC::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,AActor* DamageCauser)
{
	WidgetComp->bHiddenInGame = 0;
	TWeakObjectPtr<ACharacterNPC> thisPtr = this;
	//SetTimerWithDelegate(EnemyStatusUISetHiddenInGameTHandle, FTimerDelegate::CreateUObject(this, &ACharacterNPC::EnemyStatusUISetHiddenInGame), 10.f, false);
	
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

/*void ACharacterNPC::SetTimerWithDelegate(FTimerHandle& TimerHandle, TBaseDelegate<void> ObjectDelegate, float Time,
	bool bLoop)
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, ObjectDelegate, Time, bLoop);
}*/

void ACharacterNPC::EnemyStatusUISetHiddenInGame()
{
	WidgetComp->bHiddenInGame = 1;
}

float ACharacterNPC::DoMeleeAttack()
{
	auto _MeleeAttack = Cast<UMeleeAttack>(MeleeAttack);
	return _MeleeAttack->Attack();
}

void ACharacterNPC::TempDoMeleeAttack()
{
	auto _MeleeAttack = Cast<UMeleeAttack>(MeleeAttack);
	_MeleeAttack->_Attack();
}

void ACharacterNPC::DoProjectileAttack()
{
	ProjectileAttack->SkillTriggered();

	FVector Location = GetMesh()->GetSocketLocation("Granade_socket");
	if (GrenadeMuzzleEffect)
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), GrenadeMuzzleEffect, Location, GetActorRotation() + FRotator(0, 180, 0));
}
