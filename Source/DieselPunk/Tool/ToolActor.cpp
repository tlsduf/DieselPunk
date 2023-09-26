// Fill out your copyright notice in the Description page of Project Settings.


#include "ToolActor.h"
#include "ToolEditorSubsystem.h"

#include <Editor.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(ToolActor)

// Sets default values
AToolActor::AToolActor()
{
}

void AToolActor::OnConstruction(const FTransform& InTransform)
{
	Super::OnConstruction(InTransform);
	UToolEditorSubsystem* toolSubsystem = GEditor->GetEditorSubsystem<UToolEditorSubsystem>();
	if(nullptr != toolSubsystem && nullptr == toolSubsystem->FindToolActor(this))
	{
		ToolId = toolSubsystem->GeneratorToolId();
		toolSubsystem->AddToolActor(ToolId, this);
	}
}

// Called when the game starts or when spawned
void AToolActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AToolActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}