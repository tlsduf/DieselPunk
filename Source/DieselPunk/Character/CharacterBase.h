// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Stat.h"

#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"


class FAnimationHandler;
//class UDecalComponent;
class UWidgetComponent;
class UStatusUIBase;

UCLASS()
class DIESELPUNK_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	//================================================
	// 데미지 UI 액터
	UPROPERTY()
	class ADamageUIActor *DamageUIActor;

	//데미지를 입으면 데미지ui액터를 생성합니다.
	void DisplayDamage(float inDamage);
	//================================================
	
	// Anim Notify가 실행된 SectionName 발송용
	DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateAnimNotify, const EMontageSectionType)
	FDelegateAnimNotify DelegateAnimNotify;
	
	// 바닥 인디케이터 데칼
	UPROPERTY( EditAnywhere )
	UDecalComponent* DecalComp;

	// 위젯 컴포넌트
	UPROPERTY( EditAnywhere )
	UWidgetComponent* WidgetComp;

#if WITH_EDITORONLY_DATA
	// 데칼 확인용 프리뷰 메쉬
	UPROPERTY( EditAnywhere )
	UStaticMeshComponent* PreviewMesh;
#endif
protected:
	TWeakObjectPtr< UStatusUIBase > StatusUI; // 상태 UI 포인터

	FObjId		ObjId;	// 오브젝트 고유 식별자
	FInfoId		InfoId; // Character 테이블 식별자
	FStat		Stats;	// 스텟 정보

	FString		Name;	// 이름
	
	FAnimationHandler*	AnimHandler;	//애니메이션 관리자

public:
	// Sets default values for this character's properties
	ACharacterBase();

	// 데이터 식별자를 통해 초기화한다.
	virtual void Init( FInfoId InInfoId );

	// 캐릭터 사망을 처리한다.
	virtual void Die();

	// 상태 UI 위젯을 생성한다.
	virtual void CreateStatusUI() {};

	// 스텟 설정
	void SetStat( EActorStatType InType, int32 InValue );

	// 스텟 반환
	int32 GetStat( EActorStatType InType ) const;

	// 스텟 전체 정보를 반환한다.
	FORCEINLINE FStat& GetStats() { return Stats; }

	// 오브젝트 식별자를 반환한다.
	FORCEINLINE FObjId GetObjId() const { return ObjId; }

	// 데이터 식별자를 반환한다.
	FORCEINLINE FInfoId GetInfoId() const { return InfoId; }

	// 오브젝트 식별자를 설정한다.
	FORCEINLINE void SetObjId( FObjId InObjId ) { ObjId = InObjId; }

	// 데이터 식별자를 설정한다.
	void SetInfoId( FInfoId InInfoId );

	// AnimInstance에게 Anim Montage Play를 요청합니다. 플레이 시간을 반환합니다.
	float AnimPlayBySectionType(const EMontageSectionType InSectionType) const;
	
	// AnimInstance에서 Notify되면 해당 Notify가 걸린 Montage의 Section Name을 가져옵니다.
	// AnimInstance에서 호출합니다.
	void NotifiedSectionName(const EMontageSectionType InSectionType) const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called before destroying the object.
	virtual void BeginDestroy() override;

public:	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InPlayerInputComponent) override;

private:
	// 스폰 후 최초 값 세팅을 처리한다.
	void _InitValue();
	
};
