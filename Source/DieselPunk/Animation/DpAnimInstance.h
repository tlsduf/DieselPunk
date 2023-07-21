// Copyright GuardiansW. All Rights Reserved.

#pragma once

#include <Animation/AnimInstance.h>
#include "DpAnimInstance.generated.h"

/**
 * 폰의 정보를 받아 애님 그래프가 참조할 데이터를 제공합니다.
 * 현재는 몬스터 애님인스턴스만을 담당합니다. 추후에 캐릭터 전반을 담당할 수도 있습니다.
 */
UCLASS()
class DIESELPUNK_API UDpAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
private:
	// 캐릭터가 사용할 애님 몽타주
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UAnimMontage> AnimMontage;
	
	// 캐릭터 스피드
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CharacterSpeed;

	// 데미지를 입을 시 본을 회전시킬 방향
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	FRotator RotateDamaged;

	// 본 회전 블렌딩 알파
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float Alpha;

	//알파 값을 애니메이팅 합니다.
	Animator AlphaAnimator;
public:
	// 생성자
	UDpAnimInstance();
	// 틱마다 호출되는 함수, 스피드를 계산한다.
	virtual void NativeUpdateAnimation(float InDeltaSeconds) override;
	// 몽타주를 재생합니다.
	float PlayMontage(EMontageSectionType InSectionType, float InPlayRate = 1.f);
	// 몽타주 재생을 정지합니다.
	void StopMontage(float InBlendOutTime);
	// 몽타주 재생을 일시 정지합니다.
	void PauseMontage();
	// 몽타주를 다시 재생합니다.
	void ResumeMontage();
	// Spine 본의 Rotator를 회전합니다.
	void RotateSpine(FRotator InRotate, float InDuration);

private:
	// Notify가 되면 Character Base에 섹션 네임을 넘겨줍니다.
	UFUNCTION()
	void AnimNotify_NotifyToCharacter() const;
};
