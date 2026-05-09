// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/Weapons/AssaultRifle.h"

// Sets default values
AAssaultRifle::AAssaultRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	iCurrentMagCount = 30;
	iCurrentAmmoReserve = 180;
	iMaxMagCount = 30;
	iMaxAmmoReserve = 180;

	Cooldown = 0.30f;
	Range = 2500.0f;
}

// Called when the game starts or when spawned
void AAssaultRifle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAssaultRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAssaultRifle::AssualtFire()
{
	if (iCurrentMagCount > 0)
	{
			//GLog->Log("Firing");
			Fire();
			//bCanFire = false;
			iCurrentMagCount--;
			Cooldown = 0.30f;
	}
}

