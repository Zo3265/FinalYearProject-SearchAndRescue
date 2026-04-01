// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SearchAndRescue/AI/BTAI/EnemyBase.h"
#include "SearchAndRescue/AI/SplineMovementActor.h"
#include "BTEnemyAIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API ABTEnemyAIControllerBase : public AAIController
{
	GENERATED_BODY()
public:
protected:

	virtual void OnPossess(APawn* InPawn) override;
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	APawn* ControlledPawn;
	UPROPERTY()
	UChildActorComponent* ChildActor;
	UPROPERTY()
	AActor* SphereStore;

	UPROPERTY()
	AEnemyBase* Enemy;
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

	APlayerController* PlayerController; 
};
