// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "../Interface/DpManagementTargetInterFace.h"
#include "CharacterBase.generated.h"

class UWidgetComponent;
class UStatusUIBase;
class UStatControlComponent;

UCLASS()
class DIESELPUNK_API ACharacterBase : public ACharacter, public IDpManagementTargetInterFace
{
	GENERATED_BODY()

protected:
	/////////////////////////////////////////////////////////////////////
	// for Character info Management //
	UPROPERTY(EditDefaultsOnly, Category="MYDP")
	UStatControlComponent* StatControlComponent;
	
	FDateTime CreateTime;

	//캐릭터 정보를 가져오기 위한 이름
	UPROPERTY(EditDefaultsOnly, Category = "MYDP")
	FString CharacterName = "";

	ECharacterType CharacterType = ECharacterType::None;
	
	/////////////////////////////////////////////////////////////////////
	// for UI //

	// 위젯 컴포넌트
	UPROPERTY( EditAnywhere )
	UWidgetComponent* WidgetComp;			
	
	UPROPERTY()
	class ADamageUIActor *DamageUIActor;	// 데미지 UI 액터


	float HpPercent = 1;					// 체력바 퍼센테이지

	float HpPercentAfterImage = 1;			// 체력바잔상 퍼센테이지

	/////////////////////////////////////////////////////////////////////
	// for Animation //
	
	// 데미지 받는 애니메이션 출력을 위한 ABP에서 활용되는 변수입니다.
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool TakeDamageAnim = false;			

	bool CanTakeDamageAnim = true;
	FTimerHandle TakeDamageHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="MYDP_Animation")
	TObjectPtr<UAnimMontage> StatusEffectAnimMontage = nullptr;

	/////////////////////////////////////////////////////////////////////
	// for State //
	
	// InCombat이 True 면 전투상태
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool InCombat = false;					

	FTimerHandle CombatStateTHandle;		// 전투상태 진입 5초 후, 비전투상태로 회귀

	/////////////////////////////////////////////////////////////////////
	// for Utility //

	// DamageImmunity 가 True 면 데미지를 안 입게 했습니다. TakeDamage 함수에서 활용합니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Combat")
	bool DamageImmunity = false;			

	// 디버그on/off
	UPROPERTY(EditAnywhere, Category = "MYDP_Util")
	bool DebugOnOff = false;

	bool CanMove = true;
	bool CanAttack = true;
	bool CanSkill = true;
	
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
	// Basic Setting //
protected:
	virtual void InitCollisionResponseToChannel();
public:
	//virtual void ChangeCollisionResponseToChannel();
	
	/////////////////////////////////////////////////////////////////////
	// for Character info Management //

	// [Stat] 스탯을 가져옵니다.
	UStatControlComponent* GetStatControlComponent() { return StatControlComponent; }

	// [Stat] 스탯을 변화합니다. 인게임에서 진행도중 스탯을 변경하려면 이 함수를 사용하세요. Stat[InStatType] = Stat[InStatType] + InValue; 로 적용됩니다.
	void ChangeStat(ECharacterStatType InStatType, int32 InValue);
	
	// [Stat] 블루프린트용 스탯 Getter
	UFUNCTION(BlueprintPure)
	int32 GetStat(ECharacterStatType InStatType);

	// 데미지 처리
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	void DestroyByObjectManager();
	
	/////////////////////////////////////////////////////////////////////
	// for UI // Animation //

	// 랙돌 Impulse
	void RagdollImpulse(float DamageAmount, AController *EventInstigator, AActor *DamageCauser);
	
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
	bool IsDead() {return GetStat(ECharacterStatType::Hp) <= 0;};

	float PlayCharacterStatusEffectAnimMontage(float InPlayRate, const FName& InSectionName);
	virtual void _OnInterruptSkillAnimation(){}
	void StopCharacterStatusEffectAnimMontage(float InBlendOutTime);

	
	/////////////////////////////////////////////////////////////////////
	// for State //
	
	// 전투상태 핸들링 함수 // 전투상태 돌입 5초 후, 전투상태 자동 해제. // 해제 전 갱신 시, 5초갱신.
	void HandleCombatState();

public:
	/////////////////////////////////////////////////////////////////////
	// Getter, Setter //
	const FDateTime& GetCreateTime() const {return CreateTime;}

	const FString& GetCharacterName() const {return CharacterName;}

	const ECharacterType& GetCharacterType() const {return CharacterType;}

	bool GetInCombat() const { return InCombat; }
	void SetInCombat(bool inBool) { InCombat = inBool; }

	bool GetDebugOnOff() const { return DebugOnOff; }
	
	virtual void SetBuffStatusEffectRoleType(EBuffStatusEffectRoleType InBuffStatusEffectRolType, bool InCan);

	void SetCanMove(bool InCanMove){CanMove = InCanMove;}
	bool GetCanMove(){return CanMove;}

	void SetCanAttack(bool InCanAttack){CanAttack = InCanAttack;}
	bool GetCanAttack(){return CanAttack;}

	void SetCanSkill(bool InCanSkill){CanSkill = InCanSkill;}
	bool GetCanSkill(){return CanSkill;}

	virtual FVector GetGrenadeSocketLocation(const FName& InSocketName);
	virtual FRotator GetGrenadeSocketRotation(const FName& InSocketName);

	/////////////////////////////////////////////////////////////////////
	// Skill //
	virtual void AbilityShot(double InDamageCoefficient){}
};
