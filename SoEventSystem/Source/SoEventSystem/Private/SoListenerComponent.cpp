#include "SoListenerComponent.h"
#include "SoGameEvent.h"

USoListenerComponent::USoListenerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USoListenerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GameEvent)
	{
		GameEvent->OnEventDispatched.AddUniqueDynamic(this, &USoListenerComponent::OnEventDispatched);
	}
}

void USoListenerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GameEvent)
	{
		GameEvent->OnEventDispatched.RemoveDynamic(this, &USoListenerComponent::OnEventDispatched);
	}
}

void USoListenerComponent::OnEventDispatched()
{
	OnEventInvoked.Broadcast();
}