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
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void aimAt(FVector target, float launchSpeed);
	void setBarrelAndTurret(UtankBarrel* Barrel, UtankTurret* Turret);
	

private:
	UtankBarrel* barrel = nullptr;
	UtankTurret* turret = nullptr;
	void moveBarrel(FVector aimDir);
	void moveTurret(FVector aimDir);

	EFiringState firingState = EFiringState::reloading;
};
