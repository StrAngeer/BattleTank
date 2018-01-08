// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "tankMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TANKS_API UtankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = Movement)
		void intendToMove(float thro);
	
	
};
