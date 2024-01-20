// Copyright AvnishGameDev 2024.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "%PLUGIN_NAME%BPLibrary.generated.h"

UCLASS()
class U%PLUGIN_NAME%BPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Show Android Toast", Keywords = "android template show toast"), Category = "%PLUGIN_NAME%")
	static void Android_ShowToast(const FString& Message);
};
