#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "WindowsFileDialogBPLibrary.generated.h"

UCLASS()
class UWindowsFileDialogBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open File Dialog", Keywords = "open file dialog", ReturnDisplayName = "Path"), Category = "Windows File Dialog")
	static FString OpenFileDialog(const FString& DefaultPath, const FString& DefaultFileName);
};
