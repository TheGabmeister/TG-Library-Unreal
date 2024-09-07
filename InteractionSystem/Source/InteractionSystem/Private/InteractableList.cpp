#include "InteractableList.h"

void UInteractableList::AddInteractable(UInteractable* Interactable)
{
    if (Interactable && !Interactables.Contains(Interactable))
    {
        Interactables.Add(Interactable);
    }
}

void UInteractableList::RemoveInteractable(UInteractable* Interactable)
{
    Interactables.RemoveSingle(Interactable);
}

bool UInteractableList::ContainsInteractable(UInteractable* Interactable)
{
    return Interactables.Contains(Interactable);
}