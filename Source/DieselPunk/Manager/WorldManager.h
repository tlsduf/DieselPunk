// Copyright GuardiansW. All Rights Reserved.


#pragma once


#include "../Core/SingletonBase.h"


// 월드 매니저
// 월드 이동 같은 로직 처리를 위해서 만듬
class FWorldManager : public TSingletonBase<FWorldManager>
{
private:

public:
	// 생성자
	FWorldManager();

	// 소멸자
	virtual ~FWorldManager();

	// 초기화
	virtual void InitSingleton() override;

	// 데이터 정리
	virtual void ClearSingleton() override;

	// 월드 이동이 완료되었음을 알린다.
	void OnWorldMoveFinished();
};


GENERATE_SINGLETON_GETTER( WorldManager )
