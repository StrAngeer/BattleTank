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

void ATankPlayerController::aimAtCrosshair()
{
	if (!GetControlledTank())
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tank not contolled by Player"));
		return;
	}

	FVector hitLocation;
	if (getCrosshairHitLocation(hitLocation))
	{
		GetControlledTank()->aimAt(hitLocation);
	}

}
bool ATankPlayerController::getCrosshairHitLocation(FVector & outHitLocation)
{
	int32 vSizeX, vSizeY;
	GetViewportSize(vSizeX, vSizeY);
	FVector2D crosshairLocationOnScreen = FVector2D(vSizeX*crosshairX, vSizeY*crosshairY);
	
	FVector uselessLocation, worldDirection;
	if (DeprojectScreenPositionToWorld(crosshairLocationOnScreen.X, crosshairLocationOnScreen.Y, uselessLocation, worldDirection))
	{

		FHitResult hitResult;
		auto startLocation = PlayerCameraManager->GetCameraLocation();
		auto endLocation = startLocation + worldDirection * hitRange;
		if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility))
		{
			outHitLocation = hitResult.Location;
			
			return true;
		}
		outHitLocation = { 0,0,0 };
		
	}
	
	return false;
}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	aimAtCrosshair();
}