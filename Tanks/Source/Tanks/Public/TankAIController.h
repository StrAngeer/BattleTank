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
	
	ATank* GetControlledTank();
	ATank* GetPlayerTank();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	float reloadTime = 3;
	float tempForReload = 0;
	
};
