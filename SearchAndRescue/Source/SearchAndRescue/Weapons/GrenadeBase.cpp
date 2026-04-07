// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/Weapons/GrenadeBase.h"

// Sets default values
AGrenadeBase::AGrenadeBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Mesh Component
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetSimulatePhysics(true);
    SetRootComponent(Mesh);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->InitialSpeed = finitSpeed;
    ProjectileMovement->bShouldBounce = true;
    ProjectileMovement->Bounciness = 0.5;
    ProjectileMovement->ProjectileGravityScale = 1.0;
}

// Called when the game starts or when spawned
void AGrenadeBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGrenadeBase::Explode()
{

}

// Called every frame
void AGrenadeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

