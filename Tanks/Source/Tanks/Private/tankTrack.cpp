// Fill out your copyright notice in the Description page of Project Settings.

#include "tankTrack.h"

void UtankTrack::setThrottle(float throttle)
{
	FVector forceApplied = GetForwardVector() * throttle * maxMovingForce;
	FVector forceLocation = GetComponentLocation();
	UPrimitiveComponent* tankRoot = Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}
