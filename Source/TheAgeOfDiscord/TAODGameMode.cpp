// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TAODGameMode.h"
#include "TheAgeOfDiscord.h"
#include "TAODGameState.h"
#include "TheAgeOfDiscordCharacter.h"

ATAODGameMode::ATAODGameMode()
{
	GameStateClass = ATAODGameState::StaticClass();
}