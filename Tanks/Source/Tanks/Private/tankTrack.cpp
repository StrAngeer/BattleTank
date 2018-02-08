// Fill out your copyright notice in the Description page of Project Settings.

#include "tankTrack.h"




UtankTrack::UtankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UtankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UtankTrack::OnHit);
}

void UtankTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	driveTrack();
	
	//przeciwdzia³anie œlizganiu siê w bok
	float slippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	FVector correctionAcceleration = -slippageSpeed / GetWorld()->GetDeltaSeconds() * GetRightVector();
	auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	FVector correctionForce = (tankRoot->GetMass() * correctionAcceleration) / 2;
	tankRoot->AddForce(correctionForce);

	currThrottle = 0;

}




void UtankTrack::setThrottle(float throttle)
{
	currThrottle += throttle;
}

void UtankTrack::driveTrack()
{
	FVector forceApplied = GetForwardVector() * currThrottle * maxMovingForce;
	FVector forceLocation = GetComponentLocation();
	UPrimitiveComponent* tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}