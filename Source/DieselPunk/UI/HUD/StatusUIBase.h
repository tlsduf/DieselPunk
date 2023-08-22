// Copyright GuardiansW. All Rights Reserved.


#pragma once


#include "../UserWidgetBase.h"
#include "StatusUIBase.generated.h"


class ACharacterBase;
class UTextBlock;
class UProgressBar;
class UImage;


// 상태 UI 베이스
UCLASS()
class DIESELPUNK_API UStatusUIBase : public UUserWidgetBase
{
	GENERATED_BODY()
	
protected:
	typedef std::function<void( UStatusUIBase&, int64, int64 )> FTR_STAT_FUNC;

protected:
	TWeakObjectPtr< ACharacterBase >      Character;     // 소유 캐릭터
	TMap< EActorStatType, FTR_STAT_FUNC > FtrStatFunc;   // _Set 스텟 함수

	UTextBlock*                           TextName;      // 이름 텍스트 블록
public:
	UProgressBar*                         ProgressBarHP; // HP 바
	UImage*                               ImageIcon;     // 아이콘 이미지

	FInfoId                               InfoId;        // 캐릭터 테이블 식별자
	Animator                              HpAnimator;    // Hp 애니메이션
	int64                                 MaxHp;         // 최대 체력
	int64                                 CurHp;         // 현재 체력

public:
	// 캐릭터 정보를 업데이트한다.
	virtual void UpdateTarget( FInfoId InInfoId );

	// UI를 초기화한다.
	void InitStatus( ACharacterBase* InOwner );

protected:
	// 생성자
	virtual void OnCreated() override;

	// 소멸자
	virtual void BeginDestroy() override;

	// 틱
	virtual void NativeTick( const FGeometry& MyGeometry, float InDeltaTime ) override;

	// 스텟 변화량을 처리한다.
	virtual void OnStatChanged( FObjId InObjId, EActorStatType InStatType, int64 InOldValue, int64 InNewValue );

private:

public:
	// 위젯을 초기화한다.
	void _InitControls();


private:
	// 현재 Hp 변화를 처리한다.
	void _UpdateHp( int64 InCurHp, int64 InMaxHp );

	// Hp 를 설정한다.
	void _SetHp( int64 InOldValue, int64 InNewValue );

	// Max Hp 를 설정한다.
	void _SetMaxHp( int64 InOldValue, int64 InNewValue );
};
