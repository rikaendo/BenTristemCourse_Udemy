// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPP_Tank.h"
#include "CPP_AIController_Tank.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ACPP_AIController_Tank : public AAIController
{
	GENERATED_BODY()
	
public:
	ACPP_Tank * GetAIControlledTank();
	
	void BeginPlay() override;
};
