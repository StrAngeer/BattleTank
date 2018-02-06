// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Engine.h"
#include "tankBarrel.h"
#include "tankTurret.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::BeginPlay()
{
	lastFireTime = FPlatformTime::Seconds();
	firingState = EFiringState::reloading;
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if ((FPlatformTime::Seconds() - lastFireTime) > reloadTimeS)
	{
		firingState = EFiringState::locked;
	}
	else
		firingState = EFiringState::reloading;
}



void UTankAimingComponent::aimAt(FVector target)
{
	if (!ensure(barrel && turret))
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

void UTankAimingComponent::fire()
{

	//UE_LOG(LogTemp, Warning, TEXT("Firing"));
	//bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > reloadTimeS;
	if (!ensure(barrel && projectileBP))return;


	if (firingState != EFiringState::reloading)
	{
		auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBP, barrel->GetSocketLocation(FName("BulletSocket")), barrel->GetSocketRotation(FName("BulletSocket")));
		projectile->launchProjectile(launchSpeed);
		lastFireTime = FPlatformTime::Seconds();
	}
	
}

