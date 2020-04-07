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
	Gun,
	Staff
};

UENUM(BlueprintType)
enum class EAttackType : uint8
{
	None,
	ShortRangeSingle,
	ShortRangeMulti,
	LongRangeSingle,
	LongRangeMulti
};

UCLASS()
class EVERYTHINGGROWS_API AEG_WeaponClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEG_WeaponClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_WeaponClass")
	EWeaponType WeaponType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_WeaponClass")
	EAttackType AttackType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_WeaponClass")
	int32 AttackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_WeaponClass")
	bool InInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_WeaponClass")
	bool IsEquipped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_WeaponClass")
	bool IsDropped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_WeaponClass")
	FVector DropLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_WeaponClass")
	int32 DropIslandIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_WeaponClass")
	int32 CurrentGrowTurn;
	FString WeaponName;

	UFUNCTION(BlueprintCallable)
	EWeaponType GetWeaponType();
	UFUNCTION(BlueprintCallable)
	FString SetWeaponName(bool bPickRandom, FString CustomName, EWeaponType WeaponCategory);
	UFUNCTION(BlueprintCallable)
	FString GetWeaponName();
	UFUNCTION(BlueprintCallable)
	EAttackType SetAttackType(EWeaponType WeaponCategory);
	UFUNCTION(BlueprintCallable)
	EAttackType GetAttackType();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
