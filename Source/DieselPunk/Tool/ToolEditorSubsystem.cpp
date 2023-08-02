// Copyright GuardiansW. All Rights Reserved.


#include "ToolEditorSubsystem.h"
#include "ToolActor.h"
#include "../Data/Info/CharacterInfo.h"

#include <Engine/SkeletalMesh.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(ToolEditorSubsystem)

/** Implement this for initialization of instances of the system */
void UToolEditorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	IdGenerator = { 10000, 1000000 };
	_RebuildInfo();

}

/** Implement this for deinitialization of instances of the system */
void UToolEditorSubsystem::Deinitialize()
{
	Super::Deinitialize();

	IdGenerator.Reset();
	ToolActors.Empty();
}

// 데이터 테이블, 에셋등의 변경으로 리빌드가 필요할 경우 호출합니다.
void UToolEditorSubsystem::Rebuild()
{
	RemoveNonValidToolActors();
	
	_RebuildInfo();
	for(const auto& [id, toolActor] : ToolActors)
		if(toolActor.IsValid())
			toolActor->Rebuild();
}

// 툴 액터를 추가한다.
void UToolEditorSubsystem::AddToolActor(FToolId InToolId, TWeakObjectPtr<AToolActor> InToolActor)
{
	if(!InToolActor.IsValid())
		return;
	
	ToolActors.Add(InToolId, InToolActor);
	RemoveNonValidToolActors();
}

// 툴 액터를 ToolId로 찾는다.
AToolActor* UToolEditorSubsystem::FindToolActor(FToolId InId)
{
	return ToolActors.Find(InId)->Get();
}

// 툴 액터를 ToolActor로 찾는다.
AToolActor* UToolEditorSubsystem::FindToolActor(TWeakObjectPtr<AToolActor> InToolActor)
{
	for(auto& [id , toolActor] : ToolActors)
	{
		if(toolActor == InToolActor)
			return toolActor.Get();
	}
	return nullptr;
}

// CharacterInfo의 스켈레탈 메시를 가져옵니다.
USkeletalMesh* UToolEditorSubsystem::GetSkeletalMesh(FInfoId InId)
{
	FCharacterInfo** infoPtr = CharacterInfos.Find(InId);
	if(nullptr == infoPtr)
		return nullptr;

	FCharacterInfo* info = *infoPtr;

	return LoadSoftObject<USkeletalMesh>(info->SkeletalMesh);
}

// ToolActors에 Non Valid한 액터를 삭제합니다.
void UToolEditorSubsystem::RemoveNonValidToolActors()
{
	for(TMap<FToolId, TWeakObjectPtr<AToolActor>>::TIterator iterToolActor{ToolActors.CreateIterator()}; iterToolActor; ++iterToolActor)
	{
		if(!iterToolActor->Value.IsValid())
			iterToolActor.RemoveCurrent();
	}
}

// 데이터 테이블을 리빌드 합니다.
void UToolEditorSubsystem::_RebuildInfo()
{
	CharacterInfos.Empty();
	
	UDataTable* data = LoadObject<UDataTable>(nullptr, TEXT( "/Script/Engine.DataTable'/Game/DieselPunk/Data/DataTable/DT_Character.DT_Character'" ));
	if(nullptr == data)
	{
		WARN_LOG( TEXT( "Load DT_Character Is Fail" ));
		return;
	}

	for(const auto& [rowName, value] : data->GetRowMap())
	{
		if(FCharacterInfo* info = (FCharacterInfo*)(value))
		{
			// InfoId == 0 인지 체크
			if (!ensureMsgf(info->InfoId != G_InvalidInfoId, TEXT("InfoId (%d) Is Invalid Value at DT_Character"), info->InfoId))
				continue;

			// InfoId 중복 체크
			if (!ensureMsgf(!CharacterInfos.Find(info->InfoId), TEXT("Duplication InfoId : %d at DT_Character") , info->InfoId))
				continue;

			CharacterInfos.Add(info->InfoId, info);
		}
	}
}
