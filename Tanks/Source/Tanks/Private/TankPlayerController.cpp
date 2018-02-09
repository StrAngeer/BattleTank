// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto aimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(aimingComponent))return;
	foundAimingComp(aimingComponent);
	
}

void ATankPlayerController::aimAtCrosshair()
{
	if (!GetPawn())return;
	auto aimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(aimingComponent))return;

	FVector hitLocation;
	if (getCrosshairHitLocation(hitLocation))
	{
		aimingComponent->aimAt(hitLocation);
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
void ATankPlayerController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto possessedTank = Cast<ATank>(InPawn);
		if (!ensure(possessedTank)) { return; }
		possessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::onPosessedTankDeath);

	}
}
void ATankPlayerController::onPosessedTankDeath()
{
	StartSpectatingOnly();
}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	aimAtCrosshair();
}