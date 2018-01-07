// Fill out your copyright notice in the Description page of Project Settings.

#include "tankBarrel.h"

void UtankBarrel::elevate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp(relativeSpeed, -1.f, 1.f);
	float elevationChange = relativeSpeed * maxRotateSpeed * GetWorld()->DeltaTimeSeconds;
	float finalElevation = RelativeRotation.Pitch + elevationChange;

	finalElevation = FMath::Clamp(finalElevation, minElevation, maxElevation);
	SetRelativeRotation(FRotator(finalElevation, 0, 0));
	
}
