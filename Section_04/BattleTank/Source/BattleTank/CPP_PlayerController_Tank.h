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
	void Tick(float DeltaTime) override;
	
	void BeginPlay() override;

private:	
	ACPP_Tank* GetControlledTank() const;

	bool GetSightRayHitLocation() const;

	//start the tank moving the barrel so that a shot would hit where the crosshair intersects
	void AimTowardsCrossHair();

	//returns OUT parameter, true if hits landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;	
	
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
