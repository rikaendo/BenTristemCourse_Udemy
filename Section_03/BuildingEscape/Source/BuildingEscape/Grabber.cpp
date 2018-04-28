// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandleComponent();
	SetupInputComponent();
}

//Find the physics handle component from parent actor
void UGrabber::FindPhysicsHandleComponent()
{
	///look for attached physics handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Physics Handle not found on: %s"), *GetOwner()->GetName())
	}
}

//Find the input component from parent actor
//Assign pressed input to GRAB, released input to RELEASE
void UGrabber::SetupInputComponent()
{
	///look for attached input component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Input Component not found on: %s"), *GetOwner()->GetName())
	}
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//If physics handle is attached
	if (PhysicsHandle->GrabbedComponent)
	{
		//move the object that we're holding
		PhysicsHandle->SetTargetLocation(GetLineTraceEnd());
	}		
}

//Get Line trace start location, rotation
FTransform UGrabber::GetLineTraceStart()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	FVector ScaleOne(1.f, 1.f, 1.f);
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint
	(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	FTransform PlayerViewPoint(PlayerViewPointRotation, PlayerViewPointLocation, ScaleOne);

	return FTransform(PlayerViewPoint);
}

//Get Line trace end vector, using start location, rotation, and Reach variable
FVector UGrabber::GetLineTraceEnd()
{
	FVector PlayerViewPointLocation = GetLineTraceStart().GetLocation();
	FRotator PlayerViewPointRotation = GetLineTraceStart().GetRotation().Rotator();
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}

//Run Line Trace single by object type on Physics Body objects, returns hit result
const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
///Line-trace out to reach distance
	FHitResult HitResult;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType
	(
		OUT HitResult,
		GetLineTraceStart().GetLocation(),
		GetLineTraceEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	return HitResult;
}

//Takes hit results and grabs hit component
void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab pressed"))
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

///If we hit something then attach a physics handle
	if (ActorHit)
	{
		//attach physics handle
		PhysicsHandle->GrabComponentAtLocationWithRotation
		(
			ComponentToGrab,
			NAME_None,
			ComponentToGrab->GetOwner()->GetActorLocation(),
			ComponentToGrab->GetOwner()->GetActorRotation()
		); 
	}
}

//Releases component
void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab released"))
	//release physics handle
	PhysicsHandle->ReleaseComponent();
}
