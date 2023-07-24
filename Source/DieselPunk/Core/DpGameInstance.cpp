// Fill out your copyright notice in the Description page of Project Settings.

#include "DpGameInstance.h"
#include "DpGameDelegate.h"
#include "../Manager/ObjectManager.h"
#include "../Manager/DataTableManager.h"
#include "../Manager/UIManager.h"
#include "../Manager/WorldManager.h"

#include <TimerManager.h>
#include <Modules/ModuleManager.h>
#include <PropertyEditorModule.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(DpGameInstance)


UDpGameInstance::UDpGameInstance()
{
    static const FName PropertyEditor("PropertyEditor");
    FPropertyEditorModule &PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PropertyEditor);

#define LOCTEXT_NAMESPACE "PropertySection"
    TSharedRef<FPropertySection> Section1 = PropertyModule.FindOrCreateSection("MyRoguelikeCharacter", "CustomSection", LOCTEXT("CustomSection", "CustomSection"));
    Section1->AddCategory("Defensive");
    Section1->AddCategory("Debug");
    Section1->AddCategory("BaseMovement");
    Section1->AddCategory("CombatProp");
    Section1->AddCategory("Skill");

    TSharedRef<FPropertySection> Section2 = PropertyModule.FindOrCreateSection("BasePlayerCharacter", "CustomSection", LOCTEXT("CustomSection", "CustomSection"));
    Section2->AddCategory("ThisMovement");
    Section2->AddCategory("LM");
    Section2->AddCategory("skill Q");
    Section2->AddCategory("skill E");
    Section2->AddCategory("skill R");

    // 아래 카테고리들은 대충 뭉뚱그려서 관리 할 카테고리들입니다. (따로 관리하기에는 너무 종류가 많고 이름도 다 다름)
    // - 몬스터
    TSharedRef<FPropertySection> SectionA1 = PropertyModule.FindOrCreateSection("BaseEnemyCharacter", "CustomSection", LOCTEXT("CustomSection", "CustomSection"));
    SectionA1->AddCategory("MyCustomCategory");
    // - 스킬액터
    TSharedRef<FPropertySection> SectionB1 = PropertyModule.FindOrCreateSection("ApplyRadialDamage", "CustomSection", LOCTEXT("CustomSection", "CustomSection"));
    SectionB1->AddCategory("MyCustomCategory");
    TSharedRef<FPropertySection> SectionB2 = PropertyModule.FindOrCreateSection("BaseHitscan", "CustomSection", LOCTEXT("CustomSection", "CustomSection"));
    SectionB2->AddCategory("MyCustomCategory");
    TSharedRef<FPropertySection> SectionB3 = PropertyModule.FindOrCreateSection("ProjectileBase", "CustomSection", LOCTEXT("CustomSection", "CustomSection"));
    SectionB3->AddCategory("MyCustomCategory");
    // - 스킬로직
    TSharedRef<FPropertySection> SectionC1 = PropertyModule.FindOrCreateSection("SkillGunnerQ", "CustomSection", LOCTEXT("CustomSection", "CustomSection"));
    SectionC1->AddCategory("MyCustomCategory");
#undef LOCTEXT_NAMESPACE
}

UDpGameInstance::~UDpGameInstance()
{
}

// =============================================================
// 게임이 시작될 때마다 호출됨 ( 에디터의 경우 시작 버튼을 눌렀을 때 )
// 에디터 시작시 호출되지 않는다
// =============================================================
void UDpGameInstance::Init()
{
    Super::Init();

    InitSingletons();

    // 여기서 바로 WorldMoveFinished 를 호출하면 UI가 정상적으로 안떠서 1틱 늦게 호출
    // 추후 다른곳에 적용될 수 있음
    GetTimerManager().SetTimerForNextTick( [] () 
    {
        GetWorldManager().OnWorldMoveFinished();
    } );
}

// =============================================================
// 게임이 종료될 때마다 호출됨 ( 에디터의 경우 종료 버튼을 눌렀을 때 )
// 에디터 종료시 호출되지 않는다
// =============================================================
void UDpGameInstance::Shutdown()
{
    Clear();

    Super::Shutdown();
}

// =============================================================
// 게임이 종료될 때의 정리되어야 할 데이터들을 처리한다.
// =============================================================
void UDpGameInstance::Clear()
{
    FDpGameDelegate::Get().Clear();

    ClearSingletons();
}

// =============================================================
// 싱글톤 매니저들을 초기화한다.
// =============================================================
void UDpGameInstance::InitSingletons()
{
    SL.InitSingletons();
}

// =============================================================
// 싱글톤 매니저들의 데이터를 정리한다.
// =============================================================
void UDpGameInstance::ClearSingletons()
{
    SL.ClearSingletons();
}

// =============================================================
// 싱글톤 매니저들을 등록한다.
// =============================================================
void UDpGameInstance::RegisterSingleton()
{
    // 사용하는 싱글톤들은 이곳에 등록해주세요

    REGISTER_SINGLETON( FObjectManager );
    REGISTER_SINGLETON( FDataTableManager );
    REGISTER_SINGLETON( FUIManager );
    REGISTER_SINGLETON( FWorldManager );
}