// Copyright Epic Games, Inc. All Rights Reserved.

#include "SingletonBase.h"
 
template<typename Type>
Type* TSingletonBase<Type>::Instance = nullptr;

template<typename Type>
TSingletonBase<Type>::TSingletonBase()
{
	Instance = static_cast<Type*>(this);
}

template<typename Type>
TSingletonBase<Type>::~TSingletonBase()
{
	Instance = nullptr;
}

template<typename Type>
typename TSingletonBase<Type>::ReturnType TSingletonBase<Type>::CreateInstance()
{
	if(!Instance)
		Instance = new Type();

	return Instance;
}

template<typename Type>
Type& TSingletonBase<Type>::GetInstance()
{
	return *Instance;
}

template<typename Type>
Type* TSingletonBase<Type>::GetInstancePtr()
{
	return Instance;
}

template<typename Type>
void TSingletonBase<Type>::ReleasePtr()
{
	if(Instance)
		delete Instance;

	Instance = nullptr;
}

template<typename Type>
bool TSingletonBase<Type>::IsValid()
{
	return Instance != nullptr;
}