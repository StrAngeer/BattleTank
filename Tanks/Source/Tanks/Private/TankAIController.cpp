// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.h"



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

	aimingComp->fire();

	MoveToActor(GetPlayerTank(), acceptanceRadius);
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto possessedTank = Cast<ATank>(InPawn);
		if (!ensure(possessedTank)) { return; }
		possessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::onPosessedTankDeath);

	}
}

void ATankAIController::onPosessedTankDeath()
{
	
	if (GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}


