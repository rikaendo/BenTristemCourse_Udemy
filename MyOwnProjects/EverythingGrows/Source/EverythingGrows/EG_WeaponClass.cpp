// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
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

EWeaponType AEG_WeaponClass::GetWeaponType()
{
	return WeaponType;
}

FString AEG_WeaponClass::SetWeaponName(bool bPickRandom, FString CustomName, EWeaponType WeaponCategory)
{
	FString PickedName;
	uint8 RandIndex = FMath::RandRange(0, 4);

	TArray<FString> KnifeNames
	{
		(TEXT("Butter Knife")),
		(TEXT("Pen Knife")),
		(TEXT("Kitchen Knife")),
		(TEXT("Serrated Knife")),
		(TEXT("Butcher Knife"))
	};

	TArray<FString> SwordNames
	{
		(TEXT("Toy Sword")),
		(TEXT("Wood Sword")),
		(TEXT("Broken Sword")),
		(TEXT("Bent Sword")),
		(TEXT("Single-edged Sword"))
	};

	TArray<FString> StaffNames
	{
		(TEXT("Wooden Staff")),
		(TEXT("Rune Staff")),
		(TEXT("Summon Staff")),
		(TEXT("Stone Staff")),
		(TEXT("Dark Staff"))
	};

	TArray<FString> GunNames
	{
		(TEXT("Water Gun")),
		(TEXT("Paint Gun")),
		(TEXT("Staple Gun")),
		(TEXT("Derringer")),
		(TEXT("BB Gun"))
	};
	
	if (bPickRandom == true)
	{
		switch (WeaponCategory)
		{
		case EWeaponType::Knife:
			PickedName = KnifeNames[RandIndex];
			break;

		case EWeaponType::Sword:
			PickedName = SwordNames[RandIndex];
			break;

		case EWeaponType::Staff:
			PickedName = StaffNames[RandIndex];
			break;

		case EWeaponType::Gun:
			PickedName = GunNames[RandIndex];
			break;
		
		default:
			PickedName = (TEXT("none"));
			break;
		}
	}
	else
	{
		PickedName = CustomName;
	}

	return PickedName;
}

FString AEG_WeaponClass::GetWeaponName()
{
	return WeaponName;
}