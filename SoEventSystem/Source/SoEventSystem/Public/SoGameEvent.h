#pragma once

#include "CoreMinimal.h"
#include "SoDataAsset.h"
#include "SoGameEvent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEventDispatched);

UCLASS(Blueprintable)
class SOEVENTSYSTEM_API USoGameEvent : public USoDataAsset
{
	GENERATED_BODY()
	
public:
	// Event dispatcher
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Events")
	FOnEventDispatched OnEventDispatched;
};
