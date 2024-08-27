#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SoListenerComponent.generated.h"

class USoGameEvent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSoComponentEventHandler);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOEVENTSYSTEM_API USoListenerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USoListenerComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SO Event System")
	USoGameEvent* GameEvent;

	UPROPERTY(BlueprintAssignable, Category = "SO Event System")
	FSoComponentEventHandler OnEventInvoked;

protected:
	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	
	UFUNCTION()
	void OnEventDispatched();
};
