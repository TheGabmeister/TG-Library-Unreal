#include "CrudTextFileBPLibrary.h"
#include "CrudTextFile.h"

UCrudTextFileBPLibrary::UCrudTextFileBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FString UCrudTextFileBPLibrary::ReadTextFile(const FString& FilePath)
{
	FString FileContent;
	if (FFileHelper::LoadFileToString(FileContent, *FilePath))
	{
		return FileContent;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load file: %s"), *FilePath);
		return FString();
	}
}

bool UCrudTextFileBPLibrary::CreateTextFile(const FString& FilePath, const FString& FileContent)
{
	return FFileHelper::SaveStringToFile(FileContent, *FilePath);
}

bool UCrudTextFileBPLibrary::DeleteFile(const FString& FilePath)
{
	return IFileManager::Get().Delete(*FilePath, false, true, true);
}
