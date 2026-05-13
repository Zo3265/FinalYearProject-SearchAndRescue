// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SearchAndRescue/AI/BTAI/BTEnemyAIControllerBase.h"
#include "SearchAndRescue/AI/BTAI/ShotgunEnemy/ShotgunEnemy.h"
#include "BTShotgunAIController.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API ABTShotgunAIController : public ABTEnemyAIControllerBase
{
	GENERATED_BODY()
public:
	ABTShotgunAIController();
protected:
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY()
	AShotgunEnemy* ShotgunEnemy;
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	FVector lastPlayerLocation;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
private:
};
