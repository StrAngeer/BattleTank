// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

class AProjectile;


UCLASS()
class TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	virtual float TakeDamage(float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		AController * EventInstigator,
		AActor * DamageCauser) override;

	UFUNCTION(BlueprintPure, Category = "HP")
		float getHPpercent() const;

	FTankDelegate OnDeath;

protected:
	// Called when the game starts or when spawned

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Setup")
	int32 startingHP = 100;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 currHP = startingHP;

	
	
	

public:	
	// Called every frame
	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

private:

	
};
