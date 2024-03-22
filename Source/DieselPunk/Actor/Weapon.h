// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "../Interface/DpManagementTargetInterFace.h"
#include "Weapon.generated.h"

class ACharacterBase;
class UPlayerSkill;

UCLASS()
class DIESELPUNK_API AWeapon : public AActor, public IDpManagementTargetInterFace
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	ACharacterBase* OwnerCharacter = nullptr;	// 소유자

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY()
	USceneComponent* DefaultSceneRoot = nullptr;
	
	// 마우스 왼쪽 클릭 스킬을 할당받기 위한 유클래스입니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	TSubclassOf<UPlayerSkill> SkillInfo_LM;
	
	// 마우스 오른쪽 클릭 스킬을 할당받기 위한 유클래스입니다.
	UPROPERTY(EditAnywhere, Category = "MYDP_Skill")
	TSubclassOf<UPlayerSkill> SkillInfo_RM;

	UPROPERTY()
	TObjectPtr<UPlayerSkill> Skill_LM;
	
	UPROPERTY()
	TObjectPtr<UPlayerSkill> Skill_RM;
	
public:
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void SetOwnerPlayer(ACharacterBase* InOwner) {OwnerCharacter = InOwner;}
	ACharacterBase* GetOwnerPlayer(){return OwnerCharacter;}

	TObjectPtr<UPlayerSkill> GetSkill_LM(){return Skill_LM;}
	TObjectPtr<UPlayerSkill> GetSkill_RM(){return Skill_RM;}
};
