// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimationHandler.h"

#include "../Character/CharacterBase.h"

FAnimationHandler::FAnimationHandler(ACharacterBase* InOwner)
	: Owner(InOwner)
{
	if (!Owner.IsValid())
	{
		WARN_LOG(TEXT("FAnimationHandler::FAnimationHandler Failed! : Owner가 없습니다."));
		return;
	}
	SkelMesh = Owner->GetMesh();
	if (!SkelMesh.IsValid())
	{
		WARN_LOG(TEXT("FAnimationHandler::FAnimationHandler Failed! : Owner에 SkeletalMeshComponent가 없습니다."));
		return;
	}

	TimerDelegate = FTimerDelegate::CreateRaw(this, &FAnimationHandler::OnAnimationTimerDone);
	PreviousAnimType = EAnimationMode::AnimationBlueprint;
}

FAnimationHandler::~FAnimationHandler()
{
}

//애니메이션 재생
void FAnimationHandler::PlayAnimation(FAnimationBase InAnimBase)
{
	if (!Owner.IsValid() || !SkelMesh.IsValid())
	{
		WARN_LOG(TEXT("FAnimationHandler::PlayAnimation Failed! : Owner, SkeletalMeshComponent가 없습니다."));
		return;
	}

	//이전에 등록한 콜백함수가 있다면 지우고 초기화 해줍니다.
	if(AnimBase.AnimToPlay && TimerHandle.IsValid())
		DpGetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	if (SkelMesh.IsValid() && PreviousAnimType == EAnimationMode::AnimationBlueprint)
		SkelMesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	//타이머 핸들을 초기화합니다.
	TimerHandle.Invalidate();

	AnimBase = InAnimBase;
	PreviousAnimType = SkelMesh->GetAnimationMode();

	SkelMesh->PlayAnimation(AnimBase.AnimToPlay, AnimBase.Looping);
	const float FinishDelay = AnimBase.Looping ? AnimBase.AnimToPlay->GetPlayLength() * AnimBase.LoopCount : AnimBase.AnimToPlay->GetPlayLength();
	
	//콜백함수를 등록합니다.
	DpGetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, FinishDelay, AnimBase.Looping);
}

//애니메이션 종료 시 콜백함수
void FAnimationHandler::OnAnimationTimerDone()
{
	if (AnimBase.Looping)
		SkelMesh->Stop();
	if (SkelMesh.IsValid() && PreviousAnimType == EAnimationMode::AnimationBlueprint)
		SkelMesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);
}
