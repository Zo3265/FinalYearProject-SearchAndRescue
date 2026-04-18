// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "LearningAgentsTrainingEnvironment.h"
#include "GameFramework/Character.h"
#include "SearchAndRescue/AI/MLAI/Enemies/MLEnemyBase.h"
#include "EnemyTrainingEnvironment.generated.h"

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
public:
	UPROPERTY(EditAnywhere, Category = "Spline")
	USplineComponent* TrainingEnvSplineComponent;
};
