// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EG_WeaponClass.h"
#include "EG_EnemyClass.generated.h"

UENUM(BlueprintType)
enum class EDifficulty : uint8
{
	Easy,
	Medium,
	Hard
};

UCLASS()
class EVERYTHINGGROWS_API AEG_EnemyClass : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEG_EnemyClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	FVector SpawnLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	int32 SpawnedIslandIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	bool bIsBoss;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	EAttackType EnemyType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	EDifficulty EnemyDifficulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	int32 MaxEggTurns;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	int32 CurrentEggTurn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	bool bIsHatched;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	int32 CurrentGrowTurn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	bool bReadyForCombat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	int32 MaxHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	int32 CurrentHP;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EG_EnemyClass")
	int32 AttackDamage;
	bool bIsDead;


	UFUNCTION(BlueprintCallable)
	void SetEnemyType(EWeaponType WeaponCategory);
	UFUNCTION(BlueprintCallable)
	void SetMaxEggTurns(EDifficulty Difficulty);
	UFUNCTION(BlueprintCallable)
	void SetCurrentGrowTurn(int32 CurrentTurn);
	UFUNCTION(BlueprintCallable)
	void SetMaxHP(bool bBoss, EDifficulty Difficulty);
	UFUNCTION(BlueprintCallable)
	void SetAttackDamage(bool bMakeCustom, int32 CustomDamage, EAttackType AttackRangeType, EDifficulty Difficulty);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
