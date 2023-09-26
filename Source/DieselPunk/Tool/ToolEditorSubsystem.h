// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <EditorSubsystem.h>
#include "ToolEditorSubsystem.generated.h"


class AToolActor;
class USkeletalMesh;
struct FCharacterInfo;
/**
 * 
 */
UCLASS()
class DIESELPUNK_API UToolEditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()
private:
	TMap<FToolId,TWeakObjectPtr<AToolActor>>	ToolActors;		//툴 오브젝트
	TIdGenerator<FToolId>						IdGenerator;	//툴 오브젝트 고유 아이디 생성기
	TMap<FInfoId, FCharacterInfo*>				CharacterInfos;	//툴 미리보기용 메시 출력을 위한 캐릭터 인포
public:
	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() override;

	// 데이터 테이블, 에셋등의 변경으로 리빌드가 필요할 경우 호출합니다.
	UFUNCTION(BlueprintCallable)
	void Rebuild();

	// 툴 오브젝트 고유 아이디를 반환한다.
	FORCEINLINE FToolId GeneratorToolId() { return IdGenerator++; }

	// 툴 액터를 추가한다.
	void AddToolActor(FToolId InToolId, TWeakObjectPtr<AToolActor> InToolActor);

	// 툴 액터를 찾는다.
	AToolActor* FindToolActor(FToolId InId);
	AToolActor* FindToolActor(TWeakObjectPtr<AToolActor> InToolActor);

	// CharacterInfo의 스켈레탈 메시를 가져옵니다.
	USkeletalMesh* GetSkeletalMesh(FInfoId InId);
protected:
	// ToolActors에 Non Valid한 액터를 삭제합니다.
	void RemoveNonValidToolActors();
	
	// 데이터 테이블을 리빌드 합니다.
	void _RebuildInfo();
};
