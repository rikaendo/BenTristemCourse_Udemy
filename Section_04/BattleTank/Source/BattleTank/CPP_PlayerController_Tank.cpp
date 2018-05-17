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

void ACPP_PlayerController_Tank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}



ACPP_Tank* ACPP_PlayerController_Tank::GetControlledTank() const
{
	return Cast<ACPP_Tank>(GetPawn());
}

void ACPP_PlayerController_Tank::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; //Out parameter
	if (GetSightRayHitLocation(OutHitLocation))//Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *OutHitLocation.ToString());
		//TODO tell controlled tank to aim at this point
	}
}

//Get world location of linetrace through crosshair, true if it hits landscape
bool ACPP_PlayerController_Tank::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);


	//deproject screen position to world direction
	//linetrace along that direction
	
	/* FVector LineTraceStart = AimPoint from PlayerUI
	FVector LineTraceEnd = LineTraceStart + Rotation * Length
	GetWorld()->LineTraceSingleByObjectType(){}*/
	return true;
}