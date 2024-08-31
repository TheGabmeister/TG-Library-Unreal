#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "GameplayTagsButtonStyle.h"

class FGameplayTagsButtonCommands : public TCommands<FGameplayTagsButtonCommands>
{
public:

	FGameplayTagsButtonCommands()
		: TCommands<FGameplayTagsButtonCommands>(TEXT("GameplayTagsButton"), NSLOCTEXT("Contexts", "GameplayTagsButton", "GameplayTagsButton Plugin"), NAME_None, FGameplayTagsButtonStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
