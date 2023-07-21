// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "../Data/Info/CharacterInfo.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/UIManager.h"
#include "../Util/UtilEnum.h"
#include "../UI/HUD/StatusUIBase.h"
//#include "../Handler/BuffHandler.h"
#include "../Handler/AnimationHandler.h"
#include "..\Animation\DpAnimInstance.h"

#include <Components/DecalComponent.h>
#include <Components/WidgetComponent.h>

#include "Components/StaticMeshComponent.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterBase)


// =============================================================
// Sets default values for this character's properties
// =============================================================
ACharacterBase::ACharacterBase()
	:
	ObjId( G_InvalidObjId ),
	InfoId( G_InvalidInfoId )
{
	DecalComp = CreateDefaultSubobject< UDecalComponent >( TEXT( "Indicator" ) );
	if ( DecalComp )
	{
		DecalComp->SetupAttachment( GetRootComponent() );
		DecalComp->SetVisibility( false );
		DecalComp->SetWorldScale3D( FVector( 0.5f, 0.5f, 0.5f ) );

		DecalComp->DecalSize = FVector( 256.f, 256.f, 256.f );
		DecalComp->PrimaryComponentTick.bCanEverTick = false;
	}

#if WITH_EDITORONLY_DATA
	PreviewMesh = CreateDefaultSubobject< UStaticMeshComponent >( TEXT( "PreviewMesh" ) );
	if ( PreviewMesh )
	{
		PreviewMesh->SetupAttachment( GetRootComponent() );
		PreviewMesh->SetHiddenInGame( true );

		PreviewMesh->PrimaryComponentTick.bCanEverTick = false;
	}
#endif

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

	Stats.Initialize( this );
}

// =============================================================
// 데이터 식별자를 통해 초기화한다.
// =============================================================
void ACharacterBase::Init( FInfoId InInfoId )
{
	_InitValue();

	CreateStatusUI();
}

// =============================================================
// 캐릭터 사망을 처리한다.
// 
// 필요한 애니메이션 처리, 값 정리 등을 이곳에서 처리
// =============================================================
void ACharacterBase::Die()
{

	GetObjectManager().DestroyActor( ObjId );
}

// =============================================================
// 스텟 설정
// =============================================================
void ACharacterBase::SetStat( EActorStatType InType, int32 InValue )
{
	Stats.Set( InType, InValue );
}

// =============================================================
// 데이터 식별자를 설정한다.
// =============================================================
void ACharacterBase::SetInfoId( FInfoId InInfoId )
{
	// 이게 런타임중에 바뀔수 있어야 하는지..?
	// BP 에 고정해서 쓰는 방법도 고민
	InfoId = InInfoId;
}

// =============================================================
// AnimInstance에게 Anim Montage Play를 요청합니다.
// =============================================================
float ACharacterBase::AnimPlayBySectionType(const EMontageSectionType InSectionType) const
{
	if(UDpAnimInstance* animInstance = Cast<UDpAnimInstance>(GetMesh()->GetAnimInstance()))
	{
		return animInstance->PlayMontage(InSectionType);
	}
	return 0.f;
}

// =============================================================
// AnimInstance에서 Notify되면 해당 Notify가 걸린 Montage의 Section Type을 가져옵니다.
// AnimInstance에서 호출합니다.
// =============================================================
void ACharacterBase::NotifiedSectionName(const EMontageSectionType InSectionType) const
{
	if(DelegateAnimNotify.IsBound())
		DelegateAnimNotify.Broadcast(InSectionType);
}

// =============================================================
// 스텟 반환
// =============================================================
int32 ACharacterBase::GetStat( EActorStatType InType ) const
{
	return Stats.Get( InType );
}

// =============================================================
// Called when the game starts or when spawned
// =============================================================
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	Init( InfoId );
	AnimHandler = new FAnimationHandler(this);
}

// =============================================================
// Called before destroying the object.
// =============================================================
void ACharacterBase::BeginDestroy()
{
	if ( StatusUI.IsValid() )
		GetUIManager().RemoveImmediatelyUI( StatusUI.Get() );
	
	DpDelete( AnimHandler );

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
// 스폰 후 최초 값 세팅을 처리한다.
// =============================================================
void ACharacterBase::_InitValue()
{
	FCharacterInfoPtr info( InfoId );
	if ( !info ) return;

	for ( EActorStatType type : ENUM_RANGE( EActorStatType ) )
	{
		SetStat( type, info->GetValueByStatType( type ) );
	}
}

