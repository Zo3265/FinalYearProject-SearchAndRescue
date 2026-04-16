// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LearningAgentsInteractor.h"
#include "EnemyInteractor.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API UEnemyInteractor : public ULearningAgentsInteractor
{
	GENERATED_BODY()
public:

protected:
	//Specify the observations the agent will use.
	virtual void SpecifyAgentObservation_Implementation(FLearningAgentsObservationSchemaElement& OutObservationSchemaElement, ULearningAgentsObservationSchema* InObservationSchema) override;

	//Gather the agent observations
	virtual void GatherAgentObservation_Implementation(FLearningAgentsObservationObjectElement& OutObservationObjectElement, ULearningAgentsObservationObject* InObservationObject, const int32 AgentId) override;

	//Specifying the actions an agent can carry out.
	virtual void SpecifyAgentAction_Implementation(FLearningAgentsActionSchemaElement& OutActionSchemaElement, ULearningAgentsActionSchema* InActionSchema) override;

	virtual void PerformAgentAction_Implementation(const ULearningAgentsActionObject* InActionObject, const FLearningAgentsActionObjectElement& InActionObjectElement, const int32 AgentId) override;
public:
	UPROPERTY(EditAnywhere, Category = "Spline")
	USplineComponent* InteractorSplineComponent;
};
