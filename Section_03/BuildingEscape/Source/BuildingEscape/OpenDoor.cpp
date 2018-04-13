// Copyright Rika Nishikawa 2018.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	//Poll the trigger volume
	//if the Actor that opens is in the volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}
	
}


void UOpenDoor::OpenDoor()
{
	//find the owning actor
	AActor* Owner = GetOwner();

	//create rotator
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);

	//set rotation
	Owner->SetActorRotation(NewRotation);
}
