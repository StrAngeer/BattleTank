// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "tankMovementComponent.generated.h"

class UtankTrack;
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKS_API UtankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Movement)
	void intendToMove(float thro);

	UFUNCTION(BlueprintCallable, Category = Movement)
		void intendToTurn(float thro);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void setTracks(UtankTrack* leftTrack, UtankTrack* rightTrack);
	
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
private:
	UtankTrack* lTrack = nullptr;
	UtankTrack* rTrack = nullptr;

	
};
