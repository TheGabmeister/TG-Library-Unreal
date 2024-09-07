#pragma once
#include "CoreMinimal.h"
#include "Interactable.h"
#include "InteractableList.generated.h"

UCLASS(Blueprintable)
class INTERACTIONSYSTEM_API UInteractableList : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite)
    TArray<UInteractable*> Interactables;

    UFUNCTION(BlueprintCallable)
    void AddInteractable(UInteractable* Interactable);

    UFUNCTION(BlueprintCallable)
    void RemoveInteractable(UInteractable* Interactable);

    UFUNCTION(BlueprintCallable)
    bool ContainsInteractable(UInteractable* Interactable);
};