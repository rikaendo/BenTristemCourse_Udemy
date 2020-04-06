// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Growable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGrowable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class EVERYTHINGGROWS_API IGrowable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Growth")
	void Grow(bool bInInventory, int32 LevelMaxGrow, int32 PlayerCurrentGrow);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Growth")
	void StopGrow();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Growth")
	void ResetGrow();

};
