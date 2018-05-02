// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing Pressure Plate"), *GetOwner()->GetName()) 
	}
	DoorOriginalRotation = GetOwner()->GetActorRotation();
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

//Poll the trigger volume
	/*if (!bDoorIsOpen)
	{
		if (GetTotalMassOfActorsOnPlate() > TriggerMass)//TODO make into TWO parameters, one for inner door and one for outer door
		{
			OnOpen.Broadcast();
			bDoorIsOpen = true;
		}
	}
	else
	{
		if (GetTotalMassOfActorsOnPlate() < TriggerMass)
		{
			OnClose.Broadcast();
			bDoorIsOpen = false;
		}
	}*/


	if (GetTotalMassOfActorsOnPlate() > TriggerMass)//TODO make into TWO parameters, one for inner door and one for outer door
	{
		if (!bDoorIsOpen)
		{
			OnOpen.Broadcast();
			bDoorIsOpen = true;
		}
	}
	else
	{
		if (bDoorIsOpen)
		{
			OnClose.Broadcast();
			bDoorIsOpen = false;
		}
	}
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.0f;

//Find all overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	
//Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
	}

	return TotalMass;
}
