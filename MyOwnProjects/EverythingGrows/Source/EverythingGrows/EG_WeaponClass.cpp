// Fill out your copyright notice in the Description page of Project Settings.


#include "EG_WeaponClass.h"

// Sets default values
AEG_WeaponClass::AEG_WeaponClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEG_WeaponClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEG_WeaponClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
