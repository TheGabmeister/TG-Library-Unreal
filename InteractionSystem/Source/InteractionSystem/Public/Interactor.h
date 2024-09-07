#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Interactor.generated.h"

class USphereComponent;
class UInteractable;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIONSYSTEM_API UInteractor : public USphereComponent
{
	GENERATED_BODY()

public:	

	UInteractor();

private:
	
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void DrawInteractorSphere();

	UPROPERTY(VisibleAnywhere)
	TArray<UInteractable*> OverlappingInteractables;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
