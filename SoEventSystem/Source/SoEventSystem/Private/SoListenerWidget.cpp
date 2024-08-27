#include "SoListenerWidget.h"
#include "SoGameEvent.h"

void USoListenerWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (GameEvent)
    {
        GameEvent->OnEventDispatched.AddUniqueDynamic(this, &USoListenerWidget::OnEventDispatched);
    }
}

void USoListenerWidget::NativeDestruct()
{
    Super::NativeDestruct();

    if (GameEvent)
    {
        GameEvent->OnEventDispatched.RemoveDynamic(this, &USoListenerWidget::OnEventDispatched);
    }
}

void USoListenerWidget::OnEventDispatched()
{
    OnEventInvoked.Broadcast();
}
