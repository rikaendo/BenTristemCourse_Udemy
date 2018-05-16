// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_Tank.h"
#include "CPP_PlayerController_Tank.generated.h" //must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ACPP_PlayerController_Tank : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACPP_Tank* GetControlledTank() const;
	
	void BeginPlay() override;
};
