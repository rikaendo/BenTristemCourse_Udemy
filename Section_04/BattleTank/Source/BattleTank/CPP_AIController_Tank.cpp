// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_AIController_Tank.h"
#include "GameFramework/Actor.h"

ACPP_Tank* ACPP_AIController_Tank::GetAIControlledTank() const
{
	return Cast<ACPP_Tank>(GetPawn());
}

ACPP_Tank* ACPP_AIController_Tank::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn){ return nullptr; }
	return Cast<ACPP_Tank>(PlayerPawn);
}

void ACPP_AIController_Tank::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller can't find Player Tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player: %s"), *GetPlayerTank()->GetName());
	}
}
