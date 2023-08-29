// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNPC.h"
#include "../Skill/PlayerSkill.h"
#include "../Skill/MeleeAttack.h"

#include <Components/InputComponent.h>

#include <TimerManager.h>
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
}

// =============================================================
// 상태 UI 위젯을 생성한다.
// =============================================================
void ACharacterNPC::CreateStatusUI()
{
	/*if( StatusUI.IsValid() )
		return;

	StatusUI = GetUIManager().CreateUnmanagedUI< UStatusUIBase >( TEXT( "HUD/NPC_HpBar" ) );
	if ( !WidgetComp || !StatusUI.IsValid() )
		return;

	WidgetComp->SetWidget( StatusUI.Get() );
	WidgetComp->SetDrawSize( FVector2D( 250.0f, 80.0f ) );

	StatusUI->InitStatus( this );*/
}

void ACharacterNPC::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	//PlayerInputComponent->BindAction("LeftMouse", IE_Pressed, this, &ABaseEnemyCharacter::MeleeAttackHandle);
	//PlayerInputComponent->BindAction("RightMouse", IE_Pressed, this, &ABaseEnemyCharacter::DoProjectileAttack);
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
	if (GranadeMuzzleEffect)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), GranadeMuzzleEffect, Location, GetActorRotation() + FRotator(0, 180, 0));
	}
}
