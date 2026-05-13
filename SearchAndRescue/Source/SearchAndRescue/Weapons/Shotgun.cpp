// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/Weapons/Shotgun.h"

AShotgun::AShotgun()
{
	PrimaryActorTick.bCanEverTick = true;

	iCurrentMagCount = 8;
	iCurrentAmmoReserve = 40;
	iMaxMagCount = 8;
	iMaxAmmoReserve = 40;

	Cooldown = 0.50f;
	Range = 2200.0f;
}

void AShotgun::BeginPlay()
{
	Super::BeginPlay();
}

void AShotgun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShotgun::ShotgunFire()
{
	if (iCurrentMagCount > 0 && Cooldown <= 0.0f)
	{
		Fire();
		iCurrentMagCount--;
		Cooldown = 0.50f;
	}
	
}
