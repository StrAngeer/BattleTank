// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"
#include "TankAimingComponent.h"

ATank * ATankPlayerController::GetControlledTank()
{
	
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto aimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	foundAimingComp(aimingComponent);
	
}

void ATankPlayerController::aimAtCrosshair()
{
	if (!ensure(GetControlledTank())){return;}

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