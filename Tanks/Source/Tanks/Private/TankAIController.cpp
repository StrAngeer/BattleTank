// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"



APawn * ATankAIController::GetPlayerTank()
{
	return GetWorld()->GetFirstPlayerController()->GetPawn();
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!ensure(GetPlayerTank() && GetPawn()))return;

	auto aimingComp = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(aimingComp))return;

	aimingComp->aimAt(GetPlayerTank()->GetActorLocation());

	if (tempForReload >= reloadTime)
	{
		//GetControlledTank()->fire();
		tempForReload = 0;
	}
	else
	{
		tempForReload += DeltaTime;
	}

	MoveToActor(GetPlayerTank(), acceptanceRadius);
}


