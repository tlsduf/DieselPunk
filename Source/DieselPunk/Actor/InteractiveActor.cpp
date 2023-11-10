// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveActor.h"
#include "../Character/CharacterPC.h"
#include "../UI/HUD/ItemGuideUI.h"

#include <NiagaraFunctionLibrary.h>
#include <NiagaraComponent.h>
#include <Kismet/GameplayStatics.h>

#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/WidgetComponent.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(InteractiveActor)

// =============================================================
// 생성자
// =============================================================
AInteractiveActor::AInteractiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 오버랩 캡슐 컴포넌트
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->InitCapsuleSize(360.f, 360.f);
	SetRootComponent(CapsuleComponent);

	// 메쉬
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(CapsuleComponent);

	// 위젯 컴포넌트 세팅
	WidgetComp = CreateDefaultSubobject< UWidgetComponent >( TEXT( "StatusUI" ) );
	if ( WidgetComp )
	{
		WidgetComp->SetupAttachment( GetRootComponent() );
		WidgetComp->SetCollisionEnabled( ECollisionEnabled::Type::NoCollision );
		WidgetComp->SetGenerateOverlapEvents( false );
		WidgetComp->SetSimulatePhysics( false );
		WidgetComp->SetWidgetSpace( EWidgetSpace::Screen );
	}

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// =============================================================
// 데미지UI 위젯을 생성한다. TODO 받을 위젯을 변경 가능하도록 변경
// =============================================================
void AInteractiveActor::CreateUI()
{
	if( GuideUI.IsValid() )
		return;

	FString inPath = UtilPath::GetUIPath( TEXT("WBP_ItemGuideUI") );
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
	UItemGuideUI* myWidget = Cast<UItemGuideUI>(userWidget);
	if(myWidget)
		myWidget->RemoveFromRoot();
		
	GuideUI = myWidget;

	
	if ( !WidgetComp || !GuideUI.IsValid() )
		return;

	WidgetComp->SetWidget( GuideUI.Get() );
	WidgetComp->SetDrawSize( FVector2D( 250.0f, 80.0f ) );
	GuideUI->SetVisibility(ESlateVisibility::Hidden);
}

// =============================================================
// BeginPlay
// =============================================================
void AInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 오버랩 이벤트 바인딩
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AInteractiveActor::BindingDelegate);
	CapsuleComponent->OnComponentEndOverlap.AddDynamic(this, &AInteractiveActor::RemoveDelegate);

	CreateUI();
}

// =============================================================
// Tick
// =============================================================
void AInteractiveActor::Tick(float InDeltaTime)
{
	Super::Tick(InDeltaTime);
	
}

// =============================================================
// BeginOverlap시 CharacterPC의 DelegateInteractTask에 함수 바인딩 /상호작용 활성화
// =============================================================
void AInteractiveActor::BindingDelegate(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor,
	UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex, bool InbFromSweep, const FHitResult& InSweepResult)
{
	if(Cast<ACharacterPC>(InOtherActor)->DelegateInteractTask.IsBound())
		Cast<ACharacterPC>(InOtherActor)->DelegateInteractTask.Unbind();
	Cast<ACharacterPC>(InOtherActor)->DelegateInteractTask.BindDynamic(this, &AInteractiveActor::task);

	// UI 생성
	if ( WidgetComp && GuideUI.IsValid() )
		GuideUI->SetVisibility(ESlateVisibility::Visible);
}

// =============================================================
// EndOverlap시 CharacterPC의 DelegateInteractTask에 함수 언바인드 /상호작용 비활성화
// =============================================================
void AInteractiveActor::RemoveDelegate(UPrimitiveComponent* OverlappedComponent, AActor* InOtherActor,
	UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex)
{
	if(Cast<ACharacterPC>(InOtherActor)->DelegateInteractTask.IsBound())
		Cast<ACharacterPC>(InOtherActor)->DelegateInteractTask.Unbind();

	// UI 제거
	if ( WidgetComp && GuideUI.IsValid() )
		GuideUI->SetVisibility(ESlateVisibility::Hidden);
}

// =============================================================
// ChracterPC의 DelegateInteractTask에 바인딩되는 함수 // 각종 효과 실행
// =============================================================
void AInteractiveActor::task()
{
	// 이펙트, 사운드 출력
	//if (ActionEffect)

	if (ActionParticle)
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ActionParticle,  GetActorLocation());
	if (ActionSound)
		UGameplayStatics::PlaySoundAtLocation(this, ActionSound, GetActorLocation());
	
	// UI 제거
	if ( WidgetComp && GuideUI.IsValid() )
		GuideUI->SetVisibility(ESlateVisibility::Hidden);
	
	// 액터 파괴
	Destroy();
}

