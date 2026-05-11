// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/HostageChar.h"

// Sets default values
AHostageChar::AHostageChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHostageChar::BeginPlay()
{
	Super::BeginPlay();
	
	AnimInstance = GetMesh()->GetAnimInstance();
}

void AHostageChar::playActivationMontage()
{
	if (AnimInstance != nullptr && !bActivated)
	{
		AnimInstance->Montage_Play(ActivationMontage);
	}
}

// Called every frame
void AHostageChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHostageChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AHostageChar::takeDamage(float fDamageStore)
{
	fHealth -= fDamageStore;
}

void AHostageChar::setActivated(bool bStore)
{
	bActivated = bStore;
}

bool AHostageChar::getActivated()
{
	return bActivated;
}

