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
		//GLog->Log("Has Child Actors");
		SphereStore = ChildActor->GetChildActor();
		SphereStore->SetActorTransform(splineController->getSpline()->GetComponentTransform());

		StartTime = GetWorld()->GetTimeSeconds();
		Count = GetWorld()->GetTimeSeconds();
	}

	//Set the speed of the character proportional to the splines length. Except a little slower so we don't get jittery movement. 
	float Speed = splineController->getSpline()->GetSplineLength() / splineController->getTotalPathTimeController();
	GetCharacterMovement()->MaxWalkSpeed = Speed - 20.0f;
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SphereStore != NULL)
	{
		//How long the current spline has been going for.
		float CurrentSplineTime = (Count - StartTime) / splineController->getTotalPathTimeController();
		//UE_LOG(LogTemp, Warning, TEXT("Spline Time is: %f"), CurrentSplineTime);
		//UE_LOG(LogTemp, Warning, TEXT("Count is: %f"), Count);

		//Need to reset count so that we keep following the loop.
		if (Count >= splineController->getTotalPathTimeController())
		{
			//GLog->Log("Spline is Ended");
			Count = StartTime;
		}

		//Find the distance we are along the spline.
		float Distance = splineController->getSpline()->GetSplineLength() * CurrentSplineTime;

		//Translate that distance into world space. Then move the sphere to it,
		FVector Position = splineController->getSpline()->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		SphereStore->SetActorLocation(Position);

		//Rotate the sphere in world space.
		FVector Direction = splineController->getSpline()->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
		SphereStore->SetActorRotation(Rotator);

		Count += 1.0f * DeltaTime;
	}
	
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

