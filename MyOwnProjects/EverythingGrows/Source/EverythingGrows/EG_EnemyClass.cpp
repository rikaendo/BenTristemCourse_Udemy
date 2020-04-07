// Fill out your copyright notice in the Description page of Project Settings.


#include "EG_EnemyClass.h"

// Sets default values
AEG_EnemyClass::AEG_EnemyClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEG_EnemyClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEG_EnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEG_EnemyClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEG_EnemyClass::SetEnemyType(EWeaponType WeaponCategory)
{
	switch (WeaponCategory)
	{
	case EWeaponType::Knife :
		EnemyType = EAttackType::ShortRangeSingle;
		break;

	case EWeaponType::Sword :
		EnemyType = EAttackType::ShortRangeMulti;
		break;

	case EWeaponType::Gun:
		EnemyType = EAttackType::LongRangeSingle;
		break;	

	case EWeaponType::Staff :
		EnemyType = EAttackType::LongRangeMulti;
		break;
	
	default:
		EnemyType = EAttackType::None;
		break;
	}
	return;
}

void AEG_EnemyClass::SetMaxEggTurns(EDifficulty Difficulty)
{
	switch(Difficulty)
	{
	case EDifficulty::Easy :
		MaxEggTurns = 3;
		break;

	case EDifficulty::Medium :
		MaxEggTurns = 2;
		break;

	case EDifficulty::Hard :
		MaxEggTurns = 1;
		break;

	default:
		MaxEggTurns = 3;
		break;
	}
	return;
}

void AEG_EnemyClass::SetMaxGrowTurns(EDifficulty Difficulty)
{
	switch(Difficulty)
	{
	case EDifficulty::Easy :
		MaxGrowTurns = 3;
		break;

	case EDifficulty::Medium :
		MaxGrowTurns = 2;
		break;

	case EDifficulty::Hard :
		MaxGrowTurns = 1;
		break;

	default:
		MaxGrowTurns = 3;
		break;
	}
	return;
}

void AEG_EnemyClass::SetCurrentGrowTurn(int32 CurrentTurn)
{
	CurrentGrowTurn = CurrentTurn; //may change later to calculate based off of island index and which one the egg hatched at
	return;
}

void AEG_EnemyClass::SetMaxHP(bool bBoss, EDifficulty Difficulty)
{
	if (bBoss == true)
	{
		switch(Difficulty)
		{
		case EDifficulty::Easy :
			MaxHP = 5;
			break;

		case EDifficulty::Medium :
			MaxHP = 6;
			break;

		case EDifficulty::Hard :
			MaxHP = 7;
			break;

		default:
			MaxHP = 5;
			break;
		}
	}	 
	else
	{
		switch(Difficulty)
		{
		case EDifficulty::Easy :
			MaxHP = 3;
			break;

		case EDifficulty::Medium :
			MaxHP = 4;
			break;

		case EDifficulty::Hard :
			MaxHP = 5;
			break;

		default:
			MaxHP = 3;
			break;
		}
	}
	return;
}

void AEG_EnemyClass::SetAttackDamage(bool bMakeCustom, int32 CustomDamage, EAttackType AttackRangeType, EDifficulty Difficulty)
{
	if (bMakeCustom == true)
	{
		AttackDamage = CustomDamage;
	}
	else
	{
		switch (Difficulty)
		{
		case EDifficulty::Easy :
			switch (AttackRangeType)
			{
				case EAttackType::ShortRangeSingle :
				AttackDamage = 1;
				break;

				case EAttackType::ShortRangeMulti :
				AttackDamage = 2;
				break;

				case EAttackType::LongRangeSingle :
				AttackDamage = 1;
				break;

				case EAttackType::LongRangeMulti :
				AttackDamage = 2;
				break;

				default:
				AttackDamage = 1;
				break;
			}
			break;

		case EDifficulty::Medium :
			switch (AttackRangeType)
			{
				case EAttackType::ShortRangeSingle :
				AttackDamage = 2;
				break;

				case EAttackType::ShortRangeMulti :
				AttackDamage = 3;
				break;

				case EAttackType::LongRangeSingle :
				AttackDamage = 2;
				break;

				case EAttackType::LongRangeMulti :
				AttackDamage = 3;
				break;

				default:
				AttackDamage = 2;
				break;
			}
			break;

		case EDifficulty::Hard :
			switch (AttackRangeType)
			{
				case EAttackType::ShortRangeSingle :
				AttackDamage = 3;
				break;

				case EAttackType::ShortRangeMulti :
				AttackDamage = 4;
				break;

				case EAttackType::LongRangeSingle :
				AttackDamage = 3;
				break;

				case EAttackType::LongRangeMulti :
				AttackDamage = 4;
				break;

				default:
				AttackDamage = 3;
				break;
			}
			break;

		default: 
			switch (AttackRangeType)
			{
				case EAttackType::ShortRangeSingle :
				AttackDamage = 1;
				break;

				case EAttackType::ShortRangeMulti :
				AttackDamage = 2;
				break;

				case EAttackType::LongRangeSingle :
				AttackDamage = 1;
				break;

				case EAttackType::LongRangeMulti :
				AttackDamage = 2;
				break;

				default:
				AttackDamage = 1;
				break;
			}
			break;
		}
	}
	return;
}