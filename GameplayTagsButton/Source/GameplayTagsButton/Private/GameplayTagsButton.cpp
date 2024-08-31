// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayTagsButton.h"
#include "GameplayTagsButtonStyle.h"
#include "GameplayTagsButtonCommands.h"
#include "ToolMenus.h"
#include "SGameplayTagPicker.h"

static const FName GameplayTagsButtonTabName("GameplayTagsButton");

#define LOCTEXT_NAMESPACE "FGameplayTagsButtonModule"

void FGameplayTagsButtonModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FGameplayTagsButtonStyle::Initialize();
	FGameplayTagsButtonStyle::ReloadTextures();

	FGameplayTagsButtonCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FGameplayTagsButtonCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FGameplayTagsButtonModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FGameplayTagsButtonModule::RegisterMenus));
}

void FGameplayTagsButtonModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FGameplayTagsButtonStyle::Shutdown();

	FGameplayTagsButtonCommands::Unregister();
}

void FGameplayTagsButtonModule::PluginButtonClicked()
{
	FGameplayTagManagerWindowArgs Args;
	Args.bRestrictedTags = false;
	UE::GameplayTags::Editor::OpenGameplayTagManager(Args);
}

void FGameplayTagsButtonModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FGameplayTagsButtonCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FGameplayTagsButtonCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGameplayTagsButtonModule, GameplayTagsButton)