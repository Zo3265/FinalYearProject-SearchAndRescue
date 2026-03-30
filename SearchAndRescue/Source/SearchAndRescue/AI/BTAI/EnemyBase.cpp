// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/EnemyBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	//Get the first child actor attached to this.
	//Should be the splineMovementActor
	UChildActorComponent* ChildActor = this->GetComponentByClass<UChildActorComponent>();

	if (ChildActor)
	{
		GLog->Log("Has Child Actors");
		SphereStore = ChildActor->GetChildActor();
		SphereStore->SetActorTransform(splineController->getSpline()->GetComponentTransform());

		StartTime = GetWorld()->GetTimeSeconds();
		Count = GetWorld()->GetTimeSeconds();
	}
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//How long the current spline has been going for.
	float fCurrentSplineTime = (Count - StartTime) / splineController->getTotalPathTimeController();

	//Find the distance we are along the spline
	float fDistance = splineController->getSpline()->GetSplineLength();

	//Translate that distance into world space. Then move the sphere to it.
	FVector fvPosition = splineController->getSpline()->GetLocationAtDistanceAlongSpline(fDistance, ESplineCoordinateSpace::World);
	SphereStore->SetActorLocation(fvPosition);

	//Rotate the cube in world space.
	FVector Direction = splineController->getSpline()->GetDirectionAtDistanceAlongSpline(fDistance, ESplineCoordinateSpace::World);
	FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
	SphereStore->SetActorRotation(Rotator);

	Count += 1.0f * DeltaTime;
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

