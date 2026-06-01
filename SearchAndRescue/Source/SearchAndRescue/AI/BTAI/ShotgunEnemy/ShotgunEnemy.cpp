// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/ShotgunEnemy/ShotgunEnemy.h"

// Sets default values
AShotgunEnemy::AShotgunEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShotgunEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	//Shotgun spawning logic
	FActorSpawnParameters SpawnParamaters = FActorSpawnParameters();
	SpawnParamaters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Shotgun = GetWorld()->SpawnActor<AShotgun>(ShotgunClass, FTransform(), SpawnParamaters);
	Weapon = Shotgun;

	if (Shotgun != nullptr)
	{
		Shotgun->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("ShotgunSocket"));
		Shotgun->SetOwner(this);
	}

	AnimInstance = GetMesh()->GetAnimInstance();
}

// Called every frame
void AShotgunEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShotgunEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

AShotgun* AShotgunEnemy::getShotgun()
{
	return Shotgun;
}

