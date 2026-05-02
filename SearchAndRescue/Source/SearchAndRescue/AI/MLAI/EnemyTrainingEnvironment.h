// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "LearningAgentsTrainingEnvironment.h"
#include "GameFramework/Character.h"
#include "SearchAndRescue/AI/MLAI/Enemies/MLEnemyBase.h"
#include "SearchAndRescue/AI/SplineMovementActor.h"
#include "EnemyTrainingEnvironment.generated.h"

UENUM(BlueprintType)
enum class EAgentState : uint8
{
	Patrolling	UMETA(DisplayName = "Patrolling"),
	SeeingPlayer UMETA(DisplayName = "SeePlayer")
};
/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API UEnemyTrainingEnvironment : public ULearningAgentsTrainingEnvironment
{
	GENERATED_BODY()
public:

protected:
	virtual void GatherAgentReward_Implementation(float& OutReward,const int32 AgentId) override;

	virtual void GatherAgentCompletion_Implementation(ELearningAgentsCompletion& OutCompletion, const int32 AgentId) override;

	virtual void ResetAgentEpisode_Implementation(const int32 AgentId) override;

	int32 TrainingEnvAgentID;
	
	bool bSeePlayer = false;
public:
	UPROPERTY(EditAnywhere, Category = "Spline")
	USplineComponent* TrainingEnvSplineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	EAgentState CurrentState = EAgentState::Patrolling;

	void setTrainingEnvAgentID(int32 AgentIDStore);
	int32 getTrainingEnvAgentID();
	UFUNCTION(BlueprintCallable, Category = "Spline")
	void setTrainingEnvSplineComponent(USplineComponent* tempSpline);
	bool bTraining = true;
};
