// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class TheAgeOfDiscordServerTarget : TargetRules
{
	public TheAgeOfDiscordServerTarget(TargetInfo Target) : base(Target)
    {
		Type = TargetType.Server;
        bUsesSteam = false;

        ExtraModuleNames.Add("TheAgeOfDiscord");
    }
}