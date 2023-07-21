// Copyright GuardiansW. All Rights Reserved.
//
// 애니메이션 처리 클래스


#pragma once

#include <Components/SkeletalMeshComponent.h>

//데이터 에셋으로 처리할 예정입니다.
struct FAnimationBase
{
	UAnimationAsset*		AnimToPlay;	//재생할 애니메이션 에셋
	bool					Looping;	//반복할 지
	int32					LoopCount;	//몇 번 반복할 지
};

class ACharacterBase;
class FAnimationHandler
{
private:
	FAnimationBase							AnimBase;			//재생할 애니메이션 정보
	TWeakObjectPtr<ACharacterBase>			Owner;				//핸들러를 들고있는 캐릭터
	TWeakObjectPtr<USkeletalMeshComponent>	SkelMesh;			//캐릭터의 스켈레탈 메쉬 컴포넌트
	EAnimationMode::Type					PreviousAnimType;	//이전에 애니메이션 타입

	FTimerDelegate			TimerDelegate;		//타이머 델리게이트
	FTimerHandle			TimerHandle;		//타이머 핸들
public:
	FAnimationHandler() = delete;
	FAnimationHandler(const FAnimationHandler& InOther) = delete;
	FAnimationHandler& operator=(const FAnimationHandler& InRhs) = delete;
public:
	//생성자
	FAnimationHandler(ACharacterBase* InOwner);
	//소멸자
	~FAnimationHandler();
public:
	//애니메이션 재생
	void PlayAnimation(FAnimationBase InAnimBase);
	//애니메이션 종료 시 콜백함수
	void OnAnimationTimerDone();
};