// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DieselPunk : ModuleRules
{
	public DieselPunk(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivatePCHHeaderFile = "DieselPunk.h";

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"NavigationSystem", 
			"AIModule", 
			"Niagara", 
			"EnhancedInput" ,
			"GameplayTasks", 
			"UMG", 
			"SlateCore", 
			"Landscape",
			"UnrealEd",
			"EditorSubsystem"
		});
	}
}
