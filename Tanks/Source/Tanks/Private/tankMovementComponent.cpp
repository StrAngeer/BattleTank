// Fill out your copyright notice in the Description page of Project Settings.

#include "tankMovementComponent.h"
#include "tankTrack.h"

void UtankMovementComponent::intendToMove(float thro)
{
	lTrack->setThrottle(thro);
	rTrack->setThrottle(thro);
}

void UtankMovementComponent::intendToTurn(float thro)
{
	lTrack->setThrottle(-thro);
	rTrack->setThrottle(thro);
}

void UtankMovementComponent::setTracks(UtankTrack * leftTrack, UtankTrack * rightTrack)
{
	lTrack = leftTrack;
	rTrack = rightTrack;
}

void UtankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	FVector currentDirection = GetOwner()->GetActorForwardVector();
	FVector intendedDirection = MoveVelocity.GetSafeNormal();
	float forwardThrow = FVector::DotProduct(currentDirection, intendedDirection);
	intendToMove(forwardThrow);
	FVector rightThrow = FVector::CrossProduct(currentDirection, intendedDirection);
	intendToTurn(rightThrow.Z);

}
