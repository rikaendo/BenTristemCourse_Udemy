// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOpenDoorParams, float, OpenAngle, FRotator, DoorOriginalRotation);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

	UPROPERTY(BlueprintAssignable)
	FOpenDoorParams DoorParams;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Door Parameters")
	float OpenAngle;
	
	UPROPERTY(BlueprintReadWrite, Category = "Door Parameters")
	FRotator DoorOriginalRotation;

private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.0f;

	//float LastDoorOpenTime;

	AActor* Owner = nullptr;

	float GetTotalMassOfActorsOnPlate();

	bool bDoorIsOpen = false;
};
