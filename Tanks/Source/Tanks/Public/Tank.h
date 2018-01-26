// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UtankBarrel;
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

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	
	

public:	
	// Called every frame
	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	

	UPROPERTY(EditAnywhere, Category = Firing)
		float launchSpeed = 10000;
	UFUNCTION(BlueprintCallable, Category = Firing)
		void fire();
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> projectileBP;

private:
	UtankBarrel* barrel = nullptr;
	
};
