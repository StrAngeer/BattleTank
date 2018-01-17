// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "tankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKS_API UtankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Movement)
	void setThrottle(float throttle);

private:
	UPROPERTY(EditDefaultsOnly)
		float maxMovingForce = 800000;//w njutonach, a tak du¿o bo to czo³g 40 ton

	
	
	
};
