// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SearchAndRescue/AI/BTAI/BTEnemyAIControllerBase.h"
#include "SearchAndRescue/AI/BTAI/AssaultEnemy/AssaultEnemy.h"
#include "BTAssaultAIController.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API ABTAssaultAIController : public ABTEnemyAIControllerBase
{
	GENERATED_BODY()
public:
	ABTAssaultAIController();
protected:
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY()
	AAssaultEnemy* AssaultEnemy;
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	FVector lastPlayerLocation;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
private:
};
