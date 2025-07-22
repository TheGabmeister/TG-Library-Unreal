#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SimpleEventSystem.generated.h"

#define ADD_EVENT(EventName) \
UPROPERTY(BlueprintAssignable, Category = "Simple Event System") F##EventName EventName; \
UFUNCTION(BlueprintCallable, Category = "Simple Event System") void Broadcast##EventName() { EventName.Broadcast(); }

#define ADD_EVENT_OneParam(EventName, ParamType, ParamName) \
UPROPERTY(BlueprintAssignable, Category = "Simple Event System") F##EventName EventName; \
UFUNCTION(BlueprintCallable, Category = "Simple Event System") void Broadcast##EventName(ParamType ParamName) { EventName.Broadcast(ParamName); }





UCLASS()
class SIMPLEEVENTS_API USimpleEventSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStarted);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemCollected, int32, Value);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDied);
	
public:
	
	ADD_EVENT_OneParam(OnItemCollected, int32, Value);
	ADD_EVENT(OnPlayerDied);
	ADD_EVENT(OnGameStarted);
};

#undef ADD_EVENT
#undef ADD_EVENT_OneParam
