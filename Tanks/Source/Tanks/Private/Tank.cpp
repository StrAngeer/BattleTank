// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
}

// Called when the game starts or when spawned


float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 damageToApply = FMath::Clamp<int32>(DamageAmount, 0, currHP);
	if (currHP > 0)
	{
		currHP -= damageToApply;
	}
	else
	{
		OnDeath.Broadcast();
	}

	return damageToApply;

}

float ATank::getHPpercent() const
{
	return (float)currHP / (float)startingHP;
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}





