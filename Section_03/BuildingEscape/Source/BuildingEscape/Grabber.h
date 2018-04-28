// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//How far the player can reach, in cm
	float Reach = 100.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	///Ray-cast and grab what's in reach
	void Grab();

	///called when grab key is released
	void Release();

	///find attached physics handle
	void FindPhysicsHandleComponent();

	///setup (assumed) attached input component
	void SetupInputComponent();

	///return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	///gets start of reach line, Player's view point transforms
	FTransform GetLineTraceStart();

	///Gets Line trace end point from Player view point location and rotation with specified reach
	FVector GetLineTraceEnd();
};
