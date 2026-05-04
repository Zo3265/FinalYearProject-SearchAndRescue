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
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SplineController)
	{
		CurrentDistance = (Speed * GetWorld()->GetDeltaSeconds()) + CurrentDistance;
		CurrentDistance = FMath::Fmod(CurrentDistance, SplineController->getSpline()->GetSplineLength());
		Location = SplineController->getSpline()->GetLocationAtDistanceAlongSpline(CurrentDistance, ESplineCoordinateSpace::World);
		Location.Z += (0, 0, 120);
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

FVector AMyActor::getLocation()
{
	return Location;
}

