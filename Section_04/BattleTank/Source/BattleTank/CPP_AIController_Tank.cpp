// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_AIController_Tank.h"

ACPP_Tank* ACPP_AIController_Tank::GetAIControlledTank()
{
	return Cast<ACPP_Tank>(GetPawn());
}

void ACPP_AIController_Tank::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing: %s"), *AIControlledTank->GetName());
	}
}
