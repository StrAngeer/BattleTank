// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UtankBarrel;
class Utankturret;
class AProjectile;

UCLASS()
class TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UTankAimingComponent* aimingComp = nullptr;

public:	
	// Called every frame
	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void aimAt(FVector hitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void setBarrelAndTurret(UtankBarrel* Barrel, UtankTurret* Turret);

	UPROPERTY(EditAnywhere, Category = Firing)
		float launchSpeed = 10000;
	UFUNCTION(BlueprintCallable, Category = Firing)
		void fire();
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> projectileBP;

private:
	UtankBarrel* barrel = nullptr;
	
};
