// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include <GameFramework/Actor.h>
#include "InteractiveActor.generated.h"

class UWidgetComponent;
class UItemGuideUI;

UCLASS()
class DIESELPUNK_API AInteractiveActor : public AActor
{
	GENERATED_BODY()

protected:
	
	// 블록용 캡슐 컴포넌트
	UPROPERTY(EditAnywhere)
	class UCapsuleComponent* CapsuleComponent;

	/** The main skeletal mesh associated with this Character (optional sub-object). */
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;
	
	// 위젯 컴포넌트
	UPROPERTY( EditAnywhere )
	UWidgetComponent* WidgetComp;				// 상호작용 안내 UI

	UPROPERTY()
	TWeakObjectPtr< UItemGuideUI > GuideUI;		// 상호작용 UI 포인터
	
	// 상호작용 이펙트 파티클
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	UParticleSystem *ActionParticle;

	// 상호작용 이펙트 나이아가라
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	TSoftObjectPtr<class UNiagaraSystem> ActionEffect = nullptr;

	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	FVector HitEffectScale = FVector(1);

	// 상호작용 사운드
	UPROPERTY(EditAnywhere, Category = "MyCustomCategory")
	USoundBase *ActionSound;

public:	
	// Sets default values for this actor's properties
	AInteractiveActor();

	// UI 위젯을 생성한다.
	void CreateUI();
	
protected:
	/** Overridable native event for when play begins for this actor. */
	virtual void BeginPlay()override;
	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;

	// BeginOverlap시 CharacterPC의 DelegateInteractTask에 함수 바인딩 /상호작용 활성화
	UFUNCTION()
	void BindingDelegate(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex,
		bool InbFromSweep, const FHitResult & InSweepResult);
	
	// EndOverlap시 CharacterPC의 DelegateInteractTask에 함수 언바인드 /상호작용 비활성화
	UFUNCTION()
	void RemoveDelegate(UPrimitiveComponent* OverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComp, int32 InOtherBodyIndex);

	//================================================================
	// DelegateInteractTask에 바인딩되는 예시함수 ( 새로운 기능이 필요한 경우 함수를 만들어서 바인딩 )

	// ChracterPC의 DelegateInteractTask에 바인딩되는 함수 // 각종 효과 실행
	UFUNCTION()
	virtual void task();
};

