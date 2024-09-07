#include "Interactor.h"
#include "Interactable.h"
#include "DrawDebugHelpers.h"

UInteractor::UInteractor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInteractor::BeginPlay()
{
	Super::BeginPlay();

    OnComponentBeginOverlap.AddDynamic(this, &UInteractor::OnOverlapBegin);
    OnComponentEndOverlap.AddDynamic(this, &UInteractor::OnOverlapEnd);
}

void UInteractor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor)
    {
        UInteractable* Interactable = Cast<UInteractable>(OtherActor->GetComponentByClass(UInteractable::StaticClass()));
        if (Interactable)
        {
            OverlappingInteractables.AddUnique(Interactable);
        }
    }
}

void UInteractor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor)
    {
        UInteractable* Interactable = Cast<UInteractable>(OtherActor->GetComponentByClass(UInteractable::StaticClass()));
        if (Interactable)
        {
            OverlappingInteractables.RemoveSingle(Interactable);
        }
    }
}

void UInteractor::DrawInteractorSphere()
{
    float DebugRadius = GetScaledSphereRadius();
    FVector WorldPosition = GetComponentLocation();
    DrawDebugSphere(GetWorld(), WorldPosition, DebugRadius, 32, FColor::Green, false, 0.01f, 0, 1);

    for (UInteractable* Interactable : OverlappingInteractables)
    {
        if (Interactable)
        {
            if (GEngine)
            {
                FString DebugMessage = FString::Printf(TEXT("Overlapping with interactable: %s"), *Interactable->GetOwner()->GetName());
                GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, DebugMessage);
            }
                
        }
    }
}

void UInteractor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

#if WITH_EDITOR
    DrawInteractorSphere();
#endif
}