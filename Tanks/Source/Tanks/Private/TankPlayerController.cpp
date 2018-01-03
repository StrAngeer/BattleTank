// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControlledTank()
{
	
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Getting Player Controlled Tank: %s"), *(GetControlledTank()->GetName()));
	}else
		UE_LOG(LogTemp, Warning, TEXT("No Tank is controled by player"));

}
