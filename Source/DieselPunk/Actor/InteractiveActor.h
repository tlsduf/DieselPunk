// Copyright GuardiansW. All Rights Reserved.

#pragma once

#include <GameFramework/Actor.h>
#include "InteractiveActor.generated.h"



UCLASS()
class DIESELPUNK_API AInteractiveActor : public AActor
{
	GENERATED_BODY()

	// 블록용 캡슐 컴포넌트
	UPROPERTY(EditAnywhere)
	class UCapsuleComponent* CapsuleComponent;

	// 오버랩용 캡슐 컴포넌트
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponentInteractive;

	/** The main skeletal mesh associated with this Character (optional sub-object). */
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;
	
	class UWidgetComponent* WidgetComp;			// 상호작용 안내 UI
	//TWeakObjectPtr< UGuideUI > GuideUI;		// 상호작용 UI 포인터
	
public:	
	// Sets default values for this actor's properties
	AInteractiveActor();

protected:
	/** Overridable native event for when play begins for this actor. */
	virtual void BeginPlay()override;
	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;

	// BeginOverlap시 CharacterPC의 DelegateInteractTask에 함수 바인딩 /상호작용 활성화
	void BindingDelegate(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult);
	
	// EndOverlap시 CharacterPC의 DelegateInteractTask에 함수 언바인드 /상호작용 비활성화
	void RemoveDelegate(UPrimitiveComponent* OverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex);

	// DelegateInteractTask에 바인딩되는 함수
	virtual void task();
};

