// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SearchAndRescue/AI/BTAI/BTEnemyAIControllerBase.h"
#include "SearchAndRescue/AI/BTAI/SniperEnemy.h"
#include "BTSniperAIController.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API ABTSniperAIController : public ABTEnemyAIControllerBase
{
	GENERATED_BODY()
	
public:
	ABTSniperAIController();
protected:
	virtual void OnPossess(APawn* InPawn) override;
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
private:
};
