/* Copyright (C) Eternal Monke Games - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
* Written by Mansoor Pathiyanthra <codehawk64@gmail.com , mansoor@eternalmonke.com>, 2021
*/

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "UnrealWidget.h"
#include "IAnimNodeEditMode.h"
#include "BonePose.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"

class FCanvas;
class FEditorViewportClient;
class FPrimitiveDrawInterface;
class USkeletalMeshComponent;
struct FViewportClick;
struct FBoneDragonSocketTarget;


template <class PoseType> struct FCSPose;


//#include "AnimNodeEditMode.h"
//#include "CoreMinimal.h"
//#include "UnrealWidget.h"
//#include "AnimNode_DragonControlBase.h"
//#include "AnimGraphNode_DragonControlBase.h"
//#include "DragonControlBaseEditMode.generated.h"

/*
//UCLASS()
class DRAGONIKPLUGINEDITOR_API FDragonControlBaseEditMode : public IAnimNodeEditMode
{
public:
	
};
*/

class FCanvas;

class FEditorViewportClient;

class FPrimitiveDrawInterface;

class USkeletalMeshComponent;

struct FViewportClick;



struct DRAGONIKPLUGINEDITOR_API DragonControlBaseEditModes
{
	const static FEditorModeID DragonControlBase;

//	const static FEditorModeID DragonFootSolver;

};



class DRAGONIKPLUGINEDITOR_API FDragonControlBaseEditMode : public IAnimNodeEditMode

{

public:

	FDragonControlBaseEditMode();


	/** IAnimNodeEditMode interface */
	virtual ECoordSystem GetWidgetCoordinateSystem() const override;
	virtual UE::Widget::EWidgetMode GetWidgetMode() const override;
	virtual UE::Widget::EWidgetMode ChangeToNextWidgetMode(UE::Widget::EWidgetMode CurWidgetMode) override;
	virtual bool SetWidgetMode(UE::Widget::EWidgetMode InWidgetMode) override;
	virtual FName GetSelectedBone() const override;
	virtual void DoTranslation(FVector& InTranslation) override;
	virtual void DoRotation(FRotator& InRotation) override;
	virtual void DoScale(FVector& InScale) override;
	virtual void EnterMode(class UAnimGraphNode_Base* InEditorNode, struct FAnimNode_Base* InRuntimeNode) override;
	virtual void ExitMode() override;
	virtual bool SupportsPoseWatch() override { return false; };

	/** IPersonaEditMode interface */
	virtual bool GetCameraTarget(FSphere& OutTarget) const override;
	virtual class IPersonaPreviewScene& GetAnimPreviewScene() const override;
	virtual void GetOnScreenDebugInfo(TArray<FText>& OutDebugInfo) const override;

	/** FEdMode interface */
	virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	virtual void DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport, const FSceneView* View, FCanvas* Canvas) override;
	virtual bool HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy, const FViewportClick& Click) override;
	virtual FVector GetWidgetLocation() const override;
	virtual bool StartTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport) override;
	virtual bool EndTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport) override;
	virtual bool InputKey(FEditorViewportClient* InViewportClient, FViewport* InViewport, FKey InKey, EInputEvent InEvent) override;
	virtual bool InputDelta(FEditorViewportClient* InViewportClient, FViewport* InViewport, FVector& InDrag, FRotator& InRot, FVector& InScale) override;
	virtual bool GetCustomDrawingCoordinateSystem(FMatrix& InMatrix, void* InData) override;
	virtual bool GetCustomInputCoordinateSystem(FMatrix& InMatrix, void* InData) override;
	virtual bool ShouldDrawWidget() const override;
	virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
	virtual void Exit() override;

	virtual void RegisterPoseWatchedNode(UAnimGraphNode_Base* InEditorNode, FAnimNode_Base* InRuntimeNode);

	struct EditorRuntimeNodePair
	{
		EditorRuntimeNodePair(UAnimGraphNode_Base* InEditorAnimNode, FAnimNode_Base* InRuntimeAnimNode)
			: EditorAnimNode(InEditorAnimNode)
			, RuntimeAnimNode(InRuntimeAnimNode)
		{}

		/** The node we are operating on */
		UAnimGraphNode_Base* EditorAnimNode;

		/** The runtime node in the preview scene */
		FAnimNode_Base* RuntimeAnimNode;
	};

protected:
	// local conversion functions for drawing
	static void ConvertToComponentSpaceTransform(const USkeletalMeshComponent* SkelComp, const FTransform& InTransform, FTransform& OutCSTransform, int32 BoneIndex, EBoneControlSpace Space);
	static void ConvertToBoneSpaceTransform(const USkeletalMeshComponent* SkelComp, const FTransform& InCSTransform, FTransform& OutBSTransform, int32 BoneIndex, EBoneControlSpace Space);
	// convert drag vector in component space to bone space 
	static FVector ConvertCSVectorToBoneSpace(const USkeletalMeshComponent* SkelComp, FVector& InCSVector, FCSPose<FCompactHeapPose>& MeshBases, const FName& BoneName, const EBoneControlSpace Space);
	static FVector ConvertCSVectorToBoneSpace(const USkeletalMeshComponent* SkelComp, FVector& InCSVector, FCSPose<FCompactHeapPose>& MeshBases, const FBoneSocketTarget& InTarget, const EBoneControlSpace Space);
	// convert rotator in component space to bone space 
	static FQuat ConvertCSRotationToBoneSpace(const USkeletalMeshComponent* SkelComp, FRotator& InCSRotator, FCSPose<FCompactHeapPose>& MeshBases, const FName& BoneName, const EBoneControlSpace Space);
	// convert widget location according to bone control space
	static FVector ConvertWidgetLocation(const USkeletalMeshComponent* InSkelComp, FCSPose<FCompactHeapPose>& InMeshBases, const FName& BoneName, const FVector& InLocation, const EBoneControlSpace Space);
	static FVector ConvertWidgetLocation(const USkeletalMeshComponent* InSkelComp, FCSPose<FCompactHeapPose>& InMeshBases, const FBoneSocketTarget& Target, const FVector& InLocation, const EBoneControlSpace Space);

	virtual UAnimGraphNode_Base* GetActiveWidgetAnimNode() const; // Return the editor node associated with the selected widget. All widget operations are performed on this node.
	virtual FAnimNode_Base* GetActiveWidgetRuntimeAnimNode() const; // Return the runtime node associated with the selected widget. All widget operations are performed on this node.

	const bool IsManipulatingWidget() const { return bManipulating; }

	TArray< EditorRuntimeNodePair > SelectedAnimNodes;	// Selected Anim Graph Nodes
	TArray< EditorRuntimeNodePair > PoseWatchedAnimNodes; 	// Pose Watched Anim Graph Nodes. 

private:
	bool bManipulating;

	bool bInTransaction;

};

