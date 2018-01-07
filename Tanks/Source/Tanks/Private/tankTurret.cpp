// Fill out your copyright notice in the Description page of Project Settings.

#include "tankTurret.h"


void UtankTurret::rotate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp(relativeSpeed, -1.f, 1.f);
	float rotationChange = relativeSpeed * maxRotationSpeed * GetWorld()->DeltaTimeSeconds;
	float finalRotation = RelativeRotation.Yaw + rotationChange;
	SetRelativeRotation(FRotator(0, finalRotation, 0));
}

