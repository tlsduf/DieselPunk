// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"

#include "../Actor/DamageUIActor.h"

#include <Components/WidgetComponent.h>
#include <Components/StaticMeshComponent.h>


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
}

// =============================================================
// Called to bind functionality to input
// =============================================================
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* InPlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InPlayerInputComponent);
}

// =============================================================
// 데미지를 입으면 데미지UI액터를 생성합니다.
// =============================================================
void ACharacterBase::DisplayDamage(float inDamage)
{
	FTransform SpawnTransform( FRotator::ZeroRotator, GetActorLocation());
	DamageUIActor = GetWorld()->SpawnActorDeferred<ADamageUIActor>(ADamageUIActor::StaticClass(), SpawnTransform, this);
	
	if(DamageUIActor)
	{
		// DamageUIActor->AttachToComponent( GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
		DamageUIActor->SetDamage(inDamage);
		DamageUIActor->FinishSpawning(SpawnTransform);
	}
}