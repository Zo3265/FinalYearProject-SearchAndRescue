// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/EnemyInteractor.h"
#include "Components/SplineComponent.h"

//Specifying which observation for the enemies to make
void UEnemyInteractor::SpecifyAgentObservation_Implementation(FLearningAgentsObservationSchemaElement& OutObservationSchemaElement, ULearningAgentsObservationSchema* InObservationSchema)
{
	Super::SpecifyAgentObservation_Implementation(OutObservationSchemaElement, InObservationSchema);

	//Map to store the observations
	TMap<FName, FLearningAgentsObservationSchemaElement> ObservationMap;
	
	//One observation will be the location along the spline which will be used to make the enemy patrol.
	ObservationMap.Add(TEXT("Location"), ULearningAgentsObservations::SpecifyLocationAlongSplineObservation(InObservationSchema));

	//Another will be the direction along the spline.
	ObservationMap.Add(TEXT("Direction"), ULearningAgentsObservations::SpecifyDirectionAlongSplineObservation(InObservationSchema));

	//Combine the data. This function concatenates all these sub-observations into a struct. We can do this as many times as needed.
	OutObservationSchemaElement = ULearningAgentsObservations::SpecifyStructObservation(InObservationSchema, ObservationMap);
	
}

//Gathering observations that we specified.
void UEnemyInteractor::GatherAgentObservation_Implementation(FLearningAgentsObservationObjectElement& OutObservationObjectElement, ULearningAgentsObservationObject* InObservationObject, const int32 AgentId)
{
	Super::GatherAgentObservation_Implementation(OutObservationObjectElement, InObservationObject, AgentId);

	//Get the agent that is making the observations.
	UObject* OBSAgent = GetAgent(AgentId);

	//Get the actual actor
	AActor* OBSActor = Cast<AActor>(OBSAgent);

	//USplineComponent* SplineComp = OBSActor->FindComponentByClass<USplineComponent>();
	
	if(OBSActor)
	{
		TMap<FName, FLearningAgentsObservationObjectElement> ObservationMap;
		FVector ActorLocation = OBSActor->GetActorLocation();
		float InputKey = InteractorSplineComponent->FindInputKeyClosestToWorldLocation(ActorLocation);
		float RawDistance = InteractorSplineComponent->GetDistanceAlongSplineAtSplineInputKey(InputKey);

		// Normalise by total length.
		float NormalisedDistance = RawDistance / InteractorSplineComponent->GetSplineLength();

		FTransform Transform = OBSActor->GetActorTransform();

		ObservationMap.Add(TEXT("Location"), ULearningAgentsObservations::MakeLocationAlongSplineObservation(InObservationObject, InteractorSplineComponent, NormalisedDistance, Transform));

		ObservationMap.Add(TEXT("Direction"), ULearningAgentsObservations::MakeDirectionAlongSplineObservation(InObservationObject, InteractorSplineComponent, NormalisedDistance, Transform));

		OutObservationObjectElement = ULearningAgentsObservations::MakeStructObservation(InObservationObject, ObservationMap);
	}
	
}
