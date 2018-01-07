// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "tankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKS_API UtankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void rotate(float relativeSpeed);

	UPROPERTY(EditAnywhere)
		float maxRotationSpeed = 50;
	
	
};
