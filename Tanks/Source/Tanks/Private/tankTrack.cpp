// Fill out your copyright notice in the Description page of Project Settings.

#include "tankTrack.h"




UtankTrack::UtankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UtankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float slippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	FVector correctionAcceleration = -slippageSpeed / DeltaTime * GetRightVector();

	auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	FVector correctionForce = (tankRoot->GetMass() * correctionAcceleration)/2;

	//tankRoot->AddForce(correctionForce);
	
}

void UtankTrack::setThrottle(float throttle)
{
	FVector forceApplied = GetForwardVector() * throttle * maxMovingForce;
	FVector forceLocation = GetComponentLocation();
	UPrimitiveComponent* tankRoot = Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}
