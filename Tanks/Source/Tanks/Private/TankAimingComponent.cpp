// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Engine.h"
#include "tankBarrel.h"
#include "tankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::aimAt(FVector target, float launchSpeed)
{
	if (!barrel || !turret)
		return;
	FVector outLaunchVel;
	FVector startLocation = barrel->GetSocketLocation(FName("BulletSocket"));
	UGameplayStatics::SuggestProjectileVelocity(this, outLaunchVel, startLocation, target, launchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);

	auto aimDirection = outLaunchVel.GetSafeNormal();
	moveBarrel(aimDirection);
	moveTurret(aimDirection);
	//UE_LOG(LogTemp, Warning, TEXT("aiming at: %s"), *aimDirection.ToString());
	//auto thisTankName = GetOwner()->GetName();
	//auto barrelLocation = barrel->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s from: %s"), *thisTankName, *(target.ToString()), *barrelLocation.ToString());
}



void UTankAimingComponent::setBarrelAndTurret(UtankBarrel * Barrel, UtankTurret * Turret)
{
	barrel = Barrel;
	turret = Turret;
}

void UTankAimingComponent::moveBarrel(FVector aimDir)
{
	
	auto deltaRotator = aimDir.Rotation() - barrel->GetForwardVector().Rotation();
	
	barrel->elevate(deltaRotator.Pitch);
	
}

void UTankAimingComponent::moveTurret(FVector aimDir)
{
	FRotator rotationChange = aimDir.Rotation() - turret->GetForwardVector().Rotation();
	//UE_LOG(LogTemp, Warning, TEXT("rotation change: %f"), rotationChange.Yaw);
	if (rotationChange.Yaw > 180)
		rotationChange.Yaw -= 360;
	if (rotationChange.Yaw < -180)
		rotationChange.Yaw += 360;
	turret->rotate(rotationChange.Yaw);
	// zrob tankTurret class
}

