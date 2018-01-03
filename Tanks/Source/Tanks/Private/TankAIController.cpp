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
void ATankAIController::aimAtCrosshair()
{
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank not contolled by AI"));
		return;
	}

	FVector hitLocation;
	if (getCrosshairHitLocation(hitLocation)) 
	{

	}
	
}
bool ATankAIController::getCrosshairHitLocation(FVector & outHitLocation)
{
	FVector2D crosshairLocationOnScreen = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
	
	crosshairLocationOnScreen.X *= crosshairX;
	crosshairLocationOnScreen.Y *= crosshairY;
	UE_LOG(LogTemp, Warning, TEXT("Crosshair location: %s"), *(crosshairLocationOnScreen.ToString()));
	return true;
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	aimAtCrosshair();
}