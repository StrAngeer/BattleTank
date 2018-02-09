// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


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
	
	
	APawn* GetPlayerTank();


protected:
	UPROPERTY(EditAnywhere)
	float acceptanceRadius = 30.f;

	

private:
	float reloadTime = 3;
	float tempForReload = 0;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void onPosessedTankDeath();
};
