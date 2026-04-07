// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/Weapons/ExplosiveGrenade.h"

AExplosiveGrenade::AExplosiveGrenade()
{
}

void AExplosiveGrenade::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle ExplodeTimer;
	GetWorldTimerManager().SetTimer(ExplodeTimer, this, &AExplosiveGrenade::Explode, fFuseTime, false);
}

void AExplosiveGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AExplosiveGrenade::Explode()
{
	Super::Explode();

	Destroy();
}
