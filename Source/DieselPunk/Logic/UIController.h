// Copyright Epic Games, Inc. All Rights Reserved.


#pragma once


class UUserWidgetBase;


// UI 컨트롤러
// UI를 닫을때 이전 페이지가 있었다면 이전 페이지로 복귀할수있는 구조를 만드려하는데 그냥 UIManager 로 통합될 예정
// 추후에 UI Depth 가 생기면 그때가서 구현해두겠습니당
class FUIController
{
private:
	typedef TArray<UUserWidgetBase*> FUIStack; // UI 스택

private:
	FUIStack UIStack; // UI 스택

public:
	// 생성자
	FUIController();

	// 소멸자
	~FUIController();

	// 새로운 UI를 Push 한다.
	void Push( UUserWidgetBase* InUserWidget );

	// 최상단 UI를 Pop 한다
	UUserWidgetBase* Pop();
};
