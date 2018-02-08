// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("projectile Movement"));
	projectileMovement->bAutoActivate = false;

	collisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("collision mesh"));
	SetRootComponent(collisionMesh);
	collisionMesh->SetNotifyRigidBodyCollision(true);

	launchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("launch blast"));
	launchBlast->AttachTo(RootComponent);

	impactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("impact blast"));
	impactBlast->AttachTo(launchBlast);
	impactBlast->bAutoActivate = false;

	explosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("explosion force"));
	explosionForce->bAutoActivate = false;
	explosionForce->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	collisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	impactBlast->Deactivate();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::launchProjectile(float speed)
{
	projectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	projectileMovement->Activate();
}

void AProjectile::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	launchBlast->Deactivate();
	impactBlast->Activate();
	explosionForce->FireImpulse();
}

