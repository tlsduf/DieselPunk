// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

template<typename T>
class FState
{
public:
	virtual void Enter(T*) = 0;
	virtual void Execute(T*) = 0;
	virtual void Exit(T*) = 0;
	virtual ~FState() {}
};