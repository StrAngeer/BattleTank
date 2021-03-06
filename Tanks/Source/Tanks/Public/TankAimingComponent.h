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
	locked,
	outOfAmmo
};

class UtankBarrel;
class UtankTurret;
class AProjectile;

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
	
	void aimAt(FVector target);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setBarrelAndTurret(UtankBarrel* Barrel, UtankTurret* Turret);
	
	


	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Firing)
	int getRoundsLeft();

	UPROPERTY(EditAnywhere, Category = Firing)
		float launchSpeed = 10000;
	UFUNCTION(BlueprintCallable, Category = Firing)
		void fire();
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> projectileBP;



private:
	

	UtankBarrel* barrel = nullptr;
	UtankTurret* turret = nullptr;
	void moveBarrel(FVector aimDir);
	void moveTurret(FVector aimDir);

	float reloadTimeS = 3;
	float lastFireTime=0;

	UPROPERTY(EditAnywhere, Category = Firing)
	int32 roundsLeft = 5;

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};
