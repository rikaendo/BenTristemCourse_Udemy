// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_PlayerController_Tank.h"
#include "CPP_Tank.h"
#include "GameFramework/Actor.h"


void ACPP_PlayerController_Tank::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *ControlledTank->GetName());
	}
	
}

ACPP_Tank* ACPP_PlayerController_Tank::GetControlledTank() const
{
	return Cast<ACPP_Tank>(GetPawn());
}
