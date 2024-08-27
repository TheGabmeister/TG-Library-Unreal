#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SoListenerWidget.generated.h"

class USoGameEvent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSoWidgetEventHandler);

UCLASS()
class SOEVENTSYSTEM_API USoListenerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SO Event System")
	USoGameEvent* GameEvent;

	UPROPERTY(BlueprintAssignable, Category = "SO Event System")
	FSoWidgetEventHandler OnEventInvoked;

protected:
	virtual void NativeConstruct();
	virtual void NativeDestruct();

	UFUNCTION()
	void OnEventDispatched();
};
