// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/EnemyTrainingEnvironment.h"

//Here we will reward our character for following the path
void UEnemyTrainingEnvironment::GatherAgentReward_Implementation(float& OutReward, const int32 AgentId)
{
	ACharacter* RewardCharacter = Cast<ACharacter>(GetAgent(AgentId));

	float TotalReward = 0.0f;

	if (RewardCharacter && TrainingEnvSplineComponent)
	{
		//Get the location of the character and their closest location to a point on the spline.
		FVector CharLocation = RewardCharacter->GetActorLocation();
		FVector ClosestSplineLocation = TrainingEnvSplineComponent->FindLocationClosestToWorldLocation(CharLocation, ESplineCoordinateSpace::World);

		float DistanceToPath = FVector::Dist(CharLocation, ClosestSplineLocation); //Find the distance between the characters location and the point on the spline.

		//Reward the character for being close to the spline. I am using a range of 0 to 1 currently but 1 to 10 might be a bit more appropriate.
		//Also this will need to change when I want the enemy to be chasing the player.
		TotalReward += FMath::Exp(-0.01f * DistanceToPath);
	}

	OutReward = TotalReward;
}

//Here we put the logic for when our agent completes its tasks.
void UEnemyTrainingEnvironment::GatherAgentCompletion_Implementation(ELearningAgentsCompletion& OutCompletion, const int32 AgentId)
{
	//We want to check how far the agent is from the spline. Then terminate or truncate the episode based on how far it is.
	//Will change this later when more advanced behaviour is required.
	ACharacter* RewardCharacter = Cast<ACharacter>(GetAgent(AgentId));

	//Smae logic as before.
	FVector CharLocation = RewardCharacter->GetActorLocation();
	FVector ClosestSplineLocation = TrainingEnvSplineComponent->FindLocationClosestToWorldLocation(CharLocation, ESplineCoordinateSpace::World);
	float DistanceFromPath = FVector::Dist(CharLocation, ClosestSplineLocation);

	//Terminate the episode if the agent moves further than 5m away from the spline.
	if (DistanceFromPath > 500.0f)
	{
		OutCompletion = ELearningAgentsCompletion::Termination;
	}

	//Find the current distance between our character and the spline.
	float CurrentDistance = TrainingEnvSplineComponent->GetDistanceAlongSplineAtSplineInputKey(TrainingEnvSplineComponent->FindInputKeyClosestToWorldLocation(CharLocation));

	//We want to truncate the episode if the agent reaches the end of the spline.
	if (CurrentDistance >= (TrainingEnvSplineComponent->GetSplineLength() - 100.0f))
	{
		OutCompletion = ELearningAgentsCompletion::Truncation;
	}

	//If none of the conditions are met we keep it running.
	OutCompletion = ELearningAgentsCompletion::Running;
}
