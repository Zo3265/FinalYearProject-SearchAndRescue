// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/TrainingActor/MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	float Random = FMath::FRand();

	if (Random > 0.5f)
	{
		DirectionMultiplier = -1.0f;
	}

	else
	{
		DirectionMultiplier = 1.0f;
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SplineController)
	{
		CurrentDistance = (Speed * GetWorld()->GetDeltaSeconds() * DirectionMultiplier) + CurrentDistance;
		CurrentDistance = FMath::Fmod(CurrentDistance, SplineController->getSpline()->GetSplineLength());
		if (CurrentDistance < 0.0f)
		{
			CurrentDistance += SplineController->getSpline()->GetSplineLength();
		}
		Location = SplineController->getSpline()->GetLocationAtDistanceAlongSpline(CurrentDistance, ESplineCoordinateSpace::World);
		Location.Z += 120;
		this->SetActorLocation(Location);
	}
	
}

void AMyActor::setSplineController(ASplineController* SplineStore)
{
	SplineController = SplineStore;
}

ASplineController* AMyActor::getSplineController()
{
	return SplineController;
}

void AMyActor::setCurrentDistance(float fStore)
{
	CurrentDistance = fStore;
}

float AMyActor::getCurrentDistance()
{
	return CurrentDistance;
}

void AMyActor::setSpeed(float fStore)
{
	Speed = fStore;
}

float AMyActor::getSpeed()
{
	return Speed;
}

void AMyActor::setLocation(FVector Store)
{
	Location = Store;
}

void AMyActor::setDirectionMultiplier(float fStore)
{
	DirectionMultiplier = fStore;
}

FVector AMyActor::getLocation()
{
	return Location;
}

