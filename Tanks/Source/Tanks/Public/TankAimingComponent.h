// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM(BlueprintType)
enum class EFiringState : uint8
{
	reloading,
	aiming,
	locked
};

class UtankBarrel;
class UtankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	
	
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState firingState = EFiringState::reloading;

public:	
	
	void aimAt(FVector target, float launchSpeed);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setBarrelAndTurret(UtankBarrel* Barrel, UtankTurret* Turret);
	

private:
	UtankBarrel* barrel = nullptr;
	UtankTurret* turret = nullptr;
	void moveBarrel(FVector aimDir);
	void moveTurret(FVector aimDir);

	
};
