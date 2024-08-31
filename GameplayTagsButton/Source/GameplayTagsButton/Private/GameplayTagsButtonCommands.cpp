// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayTagsButtonCommands.h"

#define LOCTEXT_NAMESPACE "FGameplayTagsButtonModule"

void FGameplayTagsButtonCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "GameplayTagsButton", "Execute GameplayTagsButton action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
