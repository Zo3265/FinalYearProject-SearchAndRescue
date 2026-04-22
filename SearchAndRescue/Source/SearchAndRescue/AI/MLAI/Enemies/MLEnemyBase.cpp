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
			AgentId = tempManager->GetAgentId(this);
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

//To improve training for the patrolling behaviour. We need to reset the enemies to a random point on the spline.
void AMLEnemyBase::ResetToRandomPointOnSpline()
{
	if (EnemySpline != nullptr)
	{
		//Modified version of the code from the learning agents tutorial.
		//Get the total spline length and a random distance along that spline.
		float SplineLength = EnemySpline->getSpline()->GetSplineLength();
		float RandomDistance = FMath::FRandRange(0.0f, SplineLength);

		//Create a new vector and rotator for the location and rotation of the enemy.
		FVector NewLocation = EnemySpline->getSpline()->GetLocationAtDistanceAlongSpline(RandomDistance, ESplineCoordinateSpace::World);
		FRotator NewRotation = EnemySpline->getSpline()->GetRotationAtDistanceAlongSpline(RandomDistance, ESplineCoordinateSpace::World);

		//Teleport enemy to said location with an offset of 50.0f on the Z. Idk why this is but the tutorial has it.
		TeleportTo(NewLocation + FVector(0, 0, 50.f), NewRotation, false, true);

		//Remove all momentum from the character so as to not have any momentum carry over.
		//Rotate the character to face the correct direction
		this->GetCharacterMovement()->StopMovementImmediately();
		this->Controller->SetControlRotation(NewRotation);
	}
}

int32 AMLEnemyBase::getAgentId()
{
	return AgentId;
}

ASplineController* AMLEnemyBase::GetSplineController()
{
	return EnemySpline;
}

// Called to bind functionality to input
void AMLEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

