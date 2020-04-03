// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EG_WeaponClass.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None,
	Knife,
	Sword,
	Staff,
	Gun
};

UENUM(BlueprintType)
enum class EAttackType : uint8
{
	None,
	ShortRangeWeak,
	ShortRangeStrong,
	LongRangeMagic,
	LongRangeNormal
};

UCLASS()
class EVERYTHINGGROWS_API AEG_WeaponClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEG_WeaponClass();

	UPROPERTY(EditAnywhere, Category="EG_WeaponClass")
	EWeaponType WeaponType;
	UPROPERTY(EditAnywhere, Category="EG_WeaponClass")
	EAttackType AttackType;
	UPROPERTY(EditAnywhere, Category="EG_WeaponClass")
	int32 DamagePoints;
	UPROPERTY(EditAnywhere, Category="EG_WeaponClass")
	bool InInventory;
	UPROPERTY(EditAnywhere, Category="EG_WeaponClass")
	bool IsEquipped;
	UPROPERTY(EditAnywhere, Category="EG_WeaponClass")
	bool IsDiscarded;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
