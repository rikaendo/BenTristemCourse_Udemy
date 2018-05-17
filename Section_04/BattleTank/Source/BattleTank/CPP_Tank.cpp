// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Tank.h"


// Sets default values
ACPP_Tank::ACPP_Tank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Tank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Tank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Tank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_Tank::AimAt(FVector HitLocation)
{
	auto OurTankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s"), *OurTankName, *HitLocation.ToString());
}

