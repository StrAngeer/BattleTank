// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "tankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKS_API UtankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		void elevate(float relativeSpeed);

		UPROPERTY(EditAnywhere)
			float maxRotateSpeed = 15;
		UPROPERTY(EditAnywhere)
			float maxElevation = 20;
		UPROPERTY(EditAnywhere)
			float minElevation = -5;
	
	
};
