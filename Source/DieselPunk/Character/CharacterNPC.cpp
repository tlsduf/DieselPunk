// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterNPC.h"
#include "../Skill/PlayerSkill.h"
#include "../Skill/MeleeAttack.h"
#include "../UI/HUD/EnemyStatusUI.h"
#include "../Component/HousingActorComponent.h"

#include <Components/StaticMeshComponent.h>
#include <Kismet/GameplayStatics.h>
#include <Particles/ParticleSystemComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Components/WidgetComponent.h>



ACharacterNPC::ACharacterNPC()
{
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	if ( TurretMesh )
	{
		TurretMesh->SetupAttachment( GetRootComponent() );
		TurretMesh->SetCollisionEnabled( ECollisionEnabled::Type::NoCollision );
		TurretMesh->SetGenerateOverlapEvents( false );
		TurretMesh->SetSimulatePhysics( false );
	}

	TurretTopMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Top Mesh"));
	if ( TurretTopMesh )
	{
		TurretTopMesh->SetupAttachment(TurretMesh);
		TurretTopMesh->SetCollisionEnabled( ECollisionEnabled::Type::NoCollision );
		TurretTopMesh->SetGenerateOverlapEvents( false );
		TurretTopMesh->SetSimulatePhysics( false );
	}
	
	//HousingActorComponent = CreateDefaultSubobject<UHousingActorComponent>(TEXT("Housing Actor Component"));

	// AI possess
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
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
		EnemyStatusUI->SetHPPercent(HpPercent);
		EnemyStatusUI->SetHPPercentAfterImage(HpPercentAfterImage);
		EnemyStatusUI->SetTextStack(SoldierStack);
	}
	if(IsDead())
		WidgetComp->bHiddenInGame = 1;

	if(NPCType == ENPCType::Alliance)
	{
		//TurretTopMesh->SetWolrdRotation();
	}
}

// =============================================================
// 상태 UI 위젯을 생성한다.
// =============================================================
void ACharacterNPC::CreateStatusUI()
{
	if( EnemyStatusUI.IsValid() )
		return;

	FString inPath = FString::Printf(TEXT( "/Script/UMGEditor.WidgetBlueprint'/Game/DieselPunk/UI/Widgets/HUD/NPC_HpBar.NPC_HpBar_C'" ));
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
	// TODO 예외처리해야됨 어떻게? // 블루프린트상 스킬이 할당되어있지 않으면 크래쉬
	auto _MeleeAttack = Cast<UMeleeAttack>(MeleeAttack);
	return _MeleeAttack->Attack();
}

void ACharacterNPC::TempDoMeleeAttack()
{
	// TODO 예외처리해야됨 어떻게? // 블루프린트상 스킬이 할당되어있지 않으면 크래쉬
	auto _MeleeAttack = Cast<UMeleeAttack>(MeleeAttack);
	_MeleeAttack->_Attack();
}

void ACharacterNPC::DoProjectileAttack()
{
	// TODO 예외처리해야됨 어떻게? // 블루프린트상 스킬이 할당되어있지 않으면 크래쉬
	ProjectileAttack->SkillTriggered();

	FVector Location = GetMesh()->GetSocketLocation("Granade_socket");
	if (GrenadeMuzzleEffect)
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), GrenadeMuzzleEffect, Location, GetActorRotation() + FRotator(0, 180, 0));
}
