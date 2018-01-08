// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "tankMovementComponent.h"
#include "tankBarrel.h"
#include "tankTurret.h"
#include "Engine/World.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	aimingComp = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	movementComp = CreateDefaultSubobject<UtankMovementComponent>(FName("Movement Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::aimAt(FVector hitLocation)
{
	aimingComp->aimAt(hitLocation, launchSpeed);

}

void ATank::setBarrelAndTurret(UtankBarrel* Barrel, UtankTurret* Turret)
{
	aimingComp->setBarrelAndTurret(Barrel, Turret);
	barrel = Barrel;
}

void ATank::fire()
{

	//UE_LOG(LogTemp, Warning, TEXT("Firing"));

	if (!barrel)return;

	auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBP, barrel->GetSocketLocation(FName("BulletSocket")), barrel->GetSocketRotation(FName("BulletSocket")));
	projectile->launchProjectile(launchSpeed);
}

