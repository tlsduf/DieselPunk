// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Stat/Stat.h"
#include "CharacterBase.generated.h"

class UWidgetComponent;
class UStatusUIBase;

UCLASS()
class DIESELPUNK_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

protected:
	/////////////////////////////////////////////////////////////////////
	// for Character info Management //
	
	int32 ObjectId = -1;			//오브젝트 ID
	FStat Stat;						//스탯
	
	FDateTime CreateTime;
	
	UPROPERTY(EditDefaultsOnly, Category = "MYDP")
	FString CharacterName = "";		//캐릭터 정보를 가져오기 위한 이름
	
	/////////////////////////////////////////////////////////////////////
	// for UI //
	
	UPROPERTY( EditAnywhere )
	UWidgetComponent* WidgetComp;			// 위젯 컴포넌트
	
	UPROPERTY()
	class ADamageUIActor *DamageUIActor;	// 데미지 UI 액터

	Animator HpBarAnimator;					// 체력바 애니메이터
	float HpPercent = 1;					// 체력바 퍼센테이지
	Animator HpBarAfterImageAnimator;		// 체력바잔상 애니메이터
	float HpPercentAfterImage = 1;			// 체력바잔상 퍼센테이지

	/////////////////////////////////////////////////////////////////////
	// for Animation //
	
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool TakeDamageAnim = false;			// 데미지 받는 애니메이션 출력을 위한 ABP에서 활용되는 변수입니다.

	bool CanTakeDamageAnim = true;
	FTimerHandle TakeDamageHandle;

	/////////////////////////////////////////////////////////////////////
	// for State //

public:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool InCombat = false;					// InCombat이 True 면 전투상태

	FTimerHandle CombatStateTHandle;		// 전투상태 진입 5초 후, 비전투상태로 회귀

	/////////////////////////////////////////////////////////////////////
	// for Utility //
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool DamageImmunity = false;			// DamageImmunity 가 True 면 데미지를 안 입게 했습니다. TakeDamage 함수에서 활용합니다.
	
	UPROPERTY(EditAnywhere, Category = "MYDP_Util")
	bool DebugOnOff = false;				// 디버그on/off
	
public:
	//생성자
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called before destroying the object.
	virtual void BeginDestroy() override;
	
	virtual void CreateStatusUI() {};
public:	
	// Called every frame
	virtual void Tick(float InDeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InPlayerInputComponent) override;

	
	/////////////////////////////////////////////////////////////////////
	// for Character info Management //
	
	const int32 GetObjectId() const { return ObjectId; }

	void SetObjectId(int32 InObjectId) { ObjectId = InObjectId; }

	// [Stat] 스탯을 가져옵니다.
	FStat& GetStat() { return Stat; }

	// [Stat] 스탯을 변화합니다. 인게임에서 진행도중 스탯을 변경하려면 이 함수를 사용하세요. Stat[InStatType] = Stat[InStatType] + InValue; 로 적용됩니다.
	void ChangeStat(ECharacterStatType InStatType, int32 InValue);
	
	// [Stat] 블루프린트용 스탯 Getter
	UFUNCTION(BlueprintPure)
	int32 GetCharacterStat(ECharacterStatType inStatType);

	// 데미지 처리
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	
	/////////////////////////////////////////////////////////////////////
	// for UI // Animation //

	// Damaged 애니메이션 플레이 //bool 변수로 0.3초마다 애니메이션 실행
	void PlayDamagedAnim();
	
	// 데미지를 입으면 데미지ui액터를 생성합니다.
	void CreateDamageActor(float InDamage);

	// 체력 퍼센테이지 반환 애니메이팅
	void _UpdateHp(int InCurHp, int InMaxHp);
	
	// 체력 퍼센트를 반환합니다.
	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const {return HpPercent;}

	// 체력잔상 퍼센트를 반환합니다.
	UFUNCTION(BlueprintPure)
	float GetHealthPercentAfterImage() const {return HpPercentAfterImage;}

	// 체력이 0이하일 때, true 반환
	UFUNCTION(BlueprintPure)
	bool IsDead();

	
	/////////////////////////////////////////////////////////////////////
	// for State //
	
	// 전투상태 핸들링 함수 // 전투상태 돌입 5초 후, 전투상태 자동 해제. // 해제 전 갱신 시, 5초갱신.
	void HandleCombatState();

	const FDateTime& GetCreateTime() const {return CreateTime;}

	const FString& GetCharacterName() const {return CharacterName;}
};
