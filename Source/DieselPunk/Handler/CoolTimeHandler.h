// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
/**
 * TimerManager를 이용한 쿨타임 관리 클래스입니다.
 */
struct FTimerHandle;

class FCoolTimeHandler
{
private:
	// Timer 관련 작업을 수행하기 위한 핸들러 입니다.
	FTimerHandle CoolTimeHandle;

	// 람다 사용시 가비지 컬렉팅 대기중인지 확인하기 위한 Owner Ptr 입니다
	TWeakObjectPtr<UObject> Owner;
public:
	// 타이머가 완료 될 시 브로드캐스트 해 줄 Delegate입니다.
	DECLARE_MULTICAST_DELEGATE(FDelegateCoolTimeOver)
	FDelegateCoolTimeOver DelegateCoolTimeOver;
	
	// 기본 생성자는 사용하지 않습니다.
	FCoolTimeHandler() = delete;

	// 생성자
	FCoolTimeHandler(UObject* InOwner);
	
	// 소멸자
	~FCoolTimeHandler() = default;
	
	// 지정된 초 만큼 쿨타임을 걸고 성공 여부를 반환합니다.
	void SetCoolTime(const float InCoolTime);

	// 남은 쿨타임을 반환합니다. 쿨타임이 걸려 있지 않으면 0.f를 반환합니다.
	float GetCoolTime() const;

	// 쿨타임을 감소시킵니다.
	void ReduceCoolTime(const float InReduceTime);

	// 걸려있는 쿨타임을 해제 합니다.
	void ClearCoolTime();

private:
	// 쿹타임 오버시 브로드캐스트 해 줄 함수입니다.
	void _CoolTimeOver() const;
};
