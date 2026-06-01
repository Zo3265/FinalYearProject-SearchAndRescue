// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/SniperEnemy.h"

ASniperEnemy::ASniperEnemy()
{

}

void ASniperEnemy::BeginPlay()
{
	Super::BeginPlay();

	//Spawning logic for the sniper rifle.
	FActorSpawnParameters SpawnParamaters = FActorSpawnParameters();
	SpawnParamaters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SniperRifle = GetWorld()->SpawnActor<ASniperRifle>(SniperClass, FTransform(), SpawnParamaters);
	Weapon = SniperRifle;

	if (SniperRifle != nullptr)
	{
		SniperRifle->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("GunPoint"));
		SniperRifle->SetOwner(this);
	}

	AnimInstance = GetMesh()->GetAnimInstance();

}

void ASniperEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ASniperRifle* ASniperEnemy::getRifle()
{
	return SniperRifle;
}


