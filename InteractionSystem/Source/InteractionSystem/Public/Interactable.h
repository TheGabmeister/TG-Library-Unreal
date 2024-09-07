#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Interactable.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIONSYSTEM_API UInteractable : public USphereComponent
{
	GENERATED_BODY()

public:	
	
	UInteractable();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
