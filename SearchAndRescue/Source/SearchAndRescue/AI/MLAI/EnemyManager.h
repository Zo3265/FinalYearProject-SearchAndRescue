// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchAndRescue/AI/MLAI/Enemies/MLEnemyBase.h"
#include "Components/SplineComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SearchAndRescue/AI/MLAI/EnemyInteractor.h"
#include "EnemyManager.generated.h"

UCLASS()
class SEARCHANDRESCUE_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TMap<int32, USplineComponent*> AgentToSplineMap;
	UEnemyInteractor* EnemyInteractorRef;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
