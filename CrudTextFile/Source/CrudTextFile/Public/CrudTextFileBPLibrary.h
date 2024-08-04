#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CrudTextFileBPLibrary.generated.h"

UCLASS()
class UCrudTextFileBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Read Text File", Keywords = "Read text file", ReturnDisplayName = "Contents"), Category = "TG CrudTextFile")
	static FString ReadTextFile(const FString& FilePath);

	// This can also overwrite an existing text file
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Text File", Keywords = "Create text file", ReturnDisplayName = "Success"), Category = "TG CrudTextFile")
	static bool CreateTextFile(const FString& FilePath, const FString& FileContent);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete File", Keywords = "Delete file", ReturnDisplayName = "Success"), Category = "TG CrudTextFile")
	static bool DeleteFile(const FString& FilePath);
};
