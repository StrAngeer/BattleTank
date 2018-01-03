// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class TANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	ATank* GetControlledTank();
	ATank* GetPlayerTank();
	virtual void BeginPlay() override;
	void aimAtCrosshair();
	bool getCrosshairHitLocation(FVector& outHitLocation);

	UPROPERTY(EditAnywhere)
		float crosshairX = 0.5;
	
	UPROPERTY(EditAnywhere)
		float crosshairY = 0.33333;
};
