// Copyright GuardiansW. All Rights Reserved.


#include "InteractiveActor.h"

#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(InteractiveActor)

// =============================================================
// 생성자
// =============================================================
AInteractiveActor::AInteractiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 블락 캡슐 컴포넌트
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->InitCapsuleSize(90.f, 90.f);
	SetRootComponent(CapsuleComponent);

	// 메쉬
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(CapsuleComponent);

	// 오버랩용 캡슐 컴포넌트
	CapsuleComponentInteractive = CreateDefaultSubobject<UCapsuleComponent>(TEXT("OverlapComponent"));
	CapsuleComponentInteractive->InitCapsuleSize(360.f, 360.f);
	// 오버랩 이벤트 바인딩
	CapsuleComponentInteractive->OnComponentBeginOverlap.AddDynamic(this, &AInteractiveActor::BindingDelegate);
	CapsuleComponentInteractive->OnComponentEndOverlap.AddDynamic(this, &AInteractiveActor::RemoveDelegate);
}

// =============================================================
// BeginPlay
// =============================================================
void AInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
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
	//InOtherActor->DelegateInteractTask.BindDynamic(this, &AInteractiveActor::AInteractiveActor::task);
}

// =============================================================
// EndOverlap시 CharacterPC의 DelegateInteractTask에 함수 언바인드 /상호작용 비활성화
// =============================================================
void AInteractiveActor::RemoveDelegate(UPrimitiveComponent* OverlappedComponent, AActor* InOtherActor,
	UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex)
{
	//InOtherActor->DelegateInteractTask.UnBind();
}

// =============================================================
// ChracterPC의 DelegateInteractTask에 바인딩되는 함수
// =============================================================
void AInteractiveActor::task()
{
	
}

