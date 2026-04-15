// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/Enemies/MLEnemyBase.h"

// Sets default values
AMLEnemyBase::AMLEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMLEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> FoundActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("LearningAgentsManager"), FoundActor);

	for(AActor* temp : FoundActor)
	{
		ULearningAgentsManager* tempManager = temp->FindComponentByClass<ULearningAgentsManager>();

		if(tempManager != nullptr)
		{
			tempManager->AddAgent(this);
			bFoundManager = true;
		}
	}

	if (bFoundManager == false)
	{
		GLog->Log("Could not find manager");
	}
}

// Called every frame
void AMLEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AMLEnemyBase::getExplosiveGrenadeAmount()
{
	return iExplosiveGrenadeAmount;
}

int AMLEnemyBase::getFlashGrenadeAmount()
{
	return iFlashGrenadeAmount;
}

float AMLEnemyBase::getHealth()
{
	return fHealth;
}

void AMLEnemyBase::setSpeed(float fSpeedStore)
{
	GetCharacterMovement()->MaxWalkSpeed = fSpeedStore;
}

float AMLEnemyBase::getDefaultSpeed()
{
	return fDefaultSpeed;
}

void AMLEnemyBase::takeDamage(float fDamageStore)
{
	fHealth -= fDamageStore;
}

// Called to bind functionality to input
void AMLEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

