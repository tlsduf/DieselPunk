// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "State.h"

template <typename T>
class FStateMachine
{
private:
	FState<T>*	CurrentState;
	T*			Owner;

public:
	FStateMachine(T* InOwner, FState<T>* InState = nullptr)
		: Owner(InOwner), CurrentState(InState)
	{
		if(CurrentState != nullptr)
			CurrentState->Enter(Owner);
	}
	void Update() {CurrentState->Execute(Owner);}
	void ChangeState(FState<T>* InState)
	{
		if(CurrentState != InState)
		{
			CurrentState->Exit(Owner);
			CurrentState = InState;
			CurrentState->Enter(Owner);
		}
	}
	FState<T>*	GetCurrentState() {return CurrentState;}
	//SetCurrentState는 초기화 시에만 사용합니다. 게임 도중에는 ChangeState를 통해 상태를 변화시킵니다.
	void		SetCurrentState(FState<T>* InState)
	{
		if(CurrentState == nullptr)
		{
			CurrentState = InState;
			CurrentState->Enter(Owner);
		}
	}
};