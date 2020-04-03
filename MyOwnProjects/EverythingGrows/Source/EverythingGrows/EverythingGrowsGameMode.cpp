// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "EverythingGrowsGameMode.h"
#include "EverythingGrowsPlayerController.h"
#include "EverythingGrowsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEverythingGrowsGameMode::AEverythingGrowsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AEverythingGrowsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_Adventurer"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}

	
}