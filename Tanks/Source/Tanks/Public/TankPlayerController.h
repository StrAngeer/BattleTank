// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


/**
 * 
 */




UCLASS()
class TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	
protected:
	
	

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void foundAimingComp(UTankAimingComponent* aimCompRef);

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	
	void aimAtCrosshair();
	bool getCrosshairHitLocation(FVector& outHitLocation);

	UPROPERTY(EditAnywhere)
		float crosshairX = 0.5;

	UPROPERTY(EditAnywhere)
		float crosshairY = 0.33333;
	
	UPROPERTY(EditAnywhere)
		float hitRange = 1000000.f;
private:
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void onPosessedTankDeath();
};
