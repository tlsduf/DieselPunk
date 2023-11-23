// Fill out your copyright notice in the Description page of Project Settings.


#include "CoolTimeHandler.h"
#include <Kismet/GameplayStatics.h>


// =============================================================
//  생성자
// =============================================================
FCoolTimeHandler::FCoolTimeHandler(UObject* InOwner) : CoolTimeHandle(FTimerHandle())
{
	Owner = InOwner;
}

// =============================================================
//  지정된 초 만큼 쿨타임을 걸고 성공 여부를 반환합니다.
// =============================================================
void FCoolTimeHandler::SetCoolTime(const float InCoolTime)
{
	FWorldContext* world = GEngine->GetWorldContextFromGameViewport( GEngine->GameViewport );
	if ( !world )
		return ;
	
	if(UGameInstance* gameInstance = UGameplayStatics::GetGameInstance( world->World() ))
	{
		TWeakObjectPtr<UObject> owner = Owner;
		
		gameInstance->GetTimerManager().SetTimer(CoolTimeHandle, [this, owner]
		{
			if(owner.IsValid()) // owner가 가비지 컬렉팅 대상이 아닐때만 실행합니다.
			{
				_CoolTimeOver();
			}
		}, InCoolTime, false);
	}
}

// =============================================================
// 남은 쿨타임을 반환합니다. 쿨타임이 걸려 있지 않으면 0.f를 반환합니다.
// =============================================================
float FCoolTimeHandler::GetCoolTime() const
{
	FWorldContext* world = GEngine->GetWorldContextFromGameViewport( GEngine->GameViewport );
	if ( !world )
		return 0.f;
	
	if(UGameInstance* gameInstance = UGameplayStatics::GetGameInstance( world->World() ))
	{
		if(gameInstance->GetTimerManager().IsTimerActive(CoolTimeHandle))
		{
			return gameInstance->GetTimerManager().GetTimerRemaining(CoolTimeHandle);
		}
	}

	return 0.f;
}

// =============================================================
// 쿨타임을 감소시킵니다.
// 내부적으로 현재 남은 시간 - 감소 시킬 시간을 계산 후 새로운 타이머로 대치하는 식입니다.
// =============================================================
void FCoolTimeHandler::ReduceCoolTime(const float InReduceTime)
{
	SetCoolTime(GetCoolTime() - InReduceTime);
}

// =============================================================
// 걸려있는 쿨타임을 해제 합니다.
// =============================================================
void FCoolTimeHandler::ClearCoolTime()
{
	FWorldContext* world = GEngine->GetWorldContextFromGameViewport( GEngine->GameViewport );
	if ( !world )
		return ;
	
	if(UGameInstance* gameInstance =UGameplayStatics::GetGameInstance( world->World() ))
	{
		if(gameInstance->GetTimerManager().IsTimerActive(CoolTimeHandle))
		{
			return gameInstance->GetTimerManager().ClearTimer(CoolTimeHandle);
		}
	}
}

// =============================================================
// 쿹타임 오버시 브로드캐스트 해 줄 함수입니다.
// =============================================================
void FCoolTimeHandler::_CoolTimeOver() const
{
	if(DelegateCoolTimeOver.IsBound())
	{
		DelegateCoolTimeOver.Broadcast();
	}
}
