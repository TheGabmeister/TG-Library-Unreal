#include "SoEventSystemBPLibrary.h"
#include "SoGameEvent.h"

USoEventSystemBPLibrary::USoEventSystemBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void USoEventSystemBPLibrary::DispatchEvent(USoGameEvent* DataAsset)
{
    if (DataAsset)
    {
        DataAsset->OnEventDispatched.Broadcast();
    }
}

