// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchAndRescue/AI/SplineController.h"
#include "MyActor.generated.h"

UCLASS()
class SEARCHANDRESCUE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	ASplineController* SplineController;
	float CurrentDistance;
	float Speed = 250.0f;
	
	
	FVector Location;
	float DirectionMultiplier;
	bool bHide = false;
	UStaticMeshComponent* Mesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void setSplineController(ASplineController* SplineStore);
	ASplineController* getSplineController();
	void setCurrentDistance(float fStore);
	float getCurrentDistance();
	void setSpeed(float fStore);
	float getSpeed();
	void setLocation(FVector Store);
	void setDirectionMultiplier(float fStore);
	void setHide(bool bStore);
	FVector getLocation();
	UStaticMeshComponent* getSphereMesh();
	float AgeTimer;
	bool IsHidden = false;
	float MaxLife = 5.0f;
};
