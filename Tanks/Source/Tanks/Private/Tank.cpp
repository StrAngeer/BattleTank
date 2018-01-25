// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "tankBarrel.h"
#include "Engine/World.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
}

// Called when the game starts or when spawned


// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	aimingComp = FindComponentByClass<UTankAimingComponent>();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::aimAt(FVector hitLocation)
{
	if (!ensure(aimingComp))return;
	aimingComp->aimAt(hitLocation, launchSpeed);

}



void ATank::fire()
{

	//UE_LOG(LogTemp, Warning, TEXT("Firing"));

	if (!ensure(barrel))return;

	auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBP, barrel->GetSocketLocation(FName("BulletSocket")), barrel->GetSocketRotation(FName("BulletSocket")));
	projectile->launchProjectile(launchSpeed);
}

