// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/AssaultEnemy/AssaultEnemy.h"

// Sets default values
AAssaultEnemy::AAssaultEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAssaultEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	FActorSpawnParameters SpawnParamaters = FActorSpawnParameters();
	SpawnParamaters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AssaultRifle = GetWorld()->SpawnActor<AAssaultRifle>(AssaultClass, FTransform(), SpawnParamaters);
	Weapon = AssaultRifle;

	if (AssaultRifle != nullptr)
	{
		AssaultRifle->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("AssaultRifleSocket"));
		AssaultRifle->SetOwner(this);
	}

	AnimInstance = GetMesh()->GetAnimInstance();
}

// Called every frame
void AAssaultEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAssaultEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

AAssaultRifle* AAssaultEnemy::getAssaultRifle()
{
	return AssaultRifle;
}

