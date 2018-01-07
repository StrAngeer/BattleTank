// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




ATank * ATankAIController::GetControlledTank()
{

	return Cast<ATank>(GetPawn());

}

ATank * ATankAIController::GetPlayerTank()
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Getting AI Controlled Tank: %s"), *(GetControlledTank()->GetName()));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Tank not contolled by AI"));

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetControlledTank()->aimAt(GetPlayerTank()->GetActorLocation());
	if (tempForReload >= reloadTime)
	{
		GetControlledTank()->fire();
		tempForReload = 0;
	}
	else
	{
		tempForReload += DeltaTime;
	}
}
