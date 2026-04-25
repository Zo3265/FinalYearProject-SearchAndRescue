// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/EnemyTrainingEnvironment.h"

//Here we will reward our character for following the path
void UEnemyTrainingEnvironment::GatherAgentReward_Implementation(float& OutReward, const int32 AgentId)
{
	TrainingEnvAgentID = AgentId;
	ACharacter* RewardCharacter = Cast<ACharacter>(GetAgent(AgentId));

	float TotalReward = 0.0f;

	if (RewardCharacter && TrainingEnvSplineComponent)
	{
		//====================================================================================================
		// 1.Following the spline reward
		//====================================================================================================
		//Get the location of the character and their closest location to a point on the spline.
		FVector CharLocation = RewardCharacter->GetActorLocation();
		FVector ClosestSplineLocation = TrainingEnvSplineComponent->FindLocationClosestToWorldLocation(CharLocation, ESplineCoordinateSpace::World);

		float DistanceToPath = FVector::Dist(CharLocation, ClosestSplineLocation); //Find the distance between the characters location and the point on the spline.

		//====================================================================================================
		// 2.Going around the spline the correct way reward
		//====================================================================================================
		//Here we are rewarding the enemy for going the correct way along the spline so as to not have any walking backwards.
		FVector CharVelocity = RewardCharacter->GetVelocity();
		FVector SplineDirection = TrainingEnvSplineComponent->FindDirectionClosestToWorldLocation(CharLocation, ESplineCoordinateSpace::World);
		float VelocityAlongSpline = FVector::DotProduct(CharVelocity, SplineDirection);

		//Make sure to reward the character for moving at a percentage of its top speed.
		float MaxSpeed = RewardCharacter->GetCharacterMovement()->MaxWalkSpeed;
		float NormalizedVelocity = VelocityAlongSpline / MaxSpeed; //Normalise the velocity to ensure it is -1.0 to 1.0.

		//====================================================================================================
		// 3.Facing the correct way whilst following the spline reward
		//====================================================================================================
		FVector CharForward = RewardCharacter->GetActorForwardVector();
		float InputKey = TrainingEnvSplineComponent->FindInputKeyClosestToWorldLocation(CharLocation);
		FVector SplineForwardVec = TrainingEnvSplineComponent->GetDirectionAtSplineInputKey(InputKey, ESplineCoordinateSpace::World);

		//-1.0f to 1.0f
		float CharAlignment = FVector::DotProduct(CharForward, SplineForwardVec);

		//Following Spline
		//Reward the character for being close to the spline. I am using a gaussian distribution for the reward as to not give them a harsh punishment if they step off the spline.
		//Also this will need to change when I want the enemy to be chasing the player.
		//Max Reward Possible is about 1.0f.
		TotalReward += 0.7f * FMath::Exp(-0.01f * DistanceToPath);

		//Facing the correct direction
		//Max reward possible is 
		TotalReward += 1.0f * CharAlignment;

		//Going fast.
		//Max reward possible is 
		TotalReward += (0.4f * NormalizedVelocity) * FMath::Max(0.0f, CharAlignment);

		
	}

	OutReward = TotalReward;
}

//Here we put the logic for when our agent completes its tasks.
void UEnemyTrainingEnvironment::GatherAgentCompletion_Implementation(ELearningAgentsCompletion& OutCompletion, const int32 AgentId)
{
	//We want to check how far the agent is from the spline. Then terminate or truncate the episode based on how far it is.
	//Will change this later when more advanced behaviour is required.
	TrainingEnvAgentID = AgentId;
	ACharacter* RewardCharacter = Cast<ACharacter>(GetAgent(AgentId));

	if (RewardCharacter == nullptr || TrainingEnvSplineComponent == nullptr)
	{
		OutCompletion = ELearningAgentsCompletion::Running;
		return;
	}

	//Smae logic as before.
	FVector CharLocation = RewardCharacter->GetActorLocation();
	FVector ClosestSplineLocation = TrainingEnvSplineComponent->FindLocationClosestToWorldLocation(CharLocation, ESplineCoordinateSpace::World);
	float DistanceFromPath = FVector::Dist(CharLocation, ClosestSplineLocation);

	//Terminate the episode if the agent moves further than 0.5m away from the spline.
	if (DistanceFromPath > 50.0f)
	{
		OutCompletion = ELearningAgentsCompletion::Termination;
	}

	//Find the current distance between our character and the spline.
	//float CurrentDistance = TrainingEnvSplineComponent->GetDistanceAlongSplineAtSplineInputKey(TrainingEnvSplineComponent->FindInputKeyClosestToWorldLocation(CharLocation));

	//We want to truncate the episode if the agent reaches the end of the spline.
	/*else if (TrainingEnvSplineComponent->GetDistanceAlongSplineAtSplineInputKey(TrainingEnvSplineComponent->FindInputKeyClosestToWorldLocation(CharLocation)) >= (TrainingEnvSplineComponent->GetSplineLength() - 100.0f))
	{
		OutCompletion = ELearningAgentsCompletion::Truncation;
	}*/

	FVector CharForward = RewardCharacter->GetActorForwardVector();
	float InputKey = TrainingEnvSplineComponent->FindInputKeyClosestToWorldLocation(CharLocation);
	FVector SplineForwardVec = TrainingEnvSplineComponent->GetDirectionAtSplineInputKey(InputKey, ESplineCoordinateSpace::World);

	//-1.0f to 1.0f
	float CharAlignment = FVector::DotProduct(CharForward, SplineForwardVec);

	if (CharAlignment < 0.0f)
	{
		OutCompletion = ELearningAgentsCompletion::Termination;
	}

	else
	{
		//If none of the conditions are met we keep it running.
		OutCompletion = ELearningAgentsCompletion::Running;
	}


	
	
}

void UEnemyTrainingEnvironment::ResetAgentEpisode_Implementation(const int32 AgentId)
{
	TrainingEnvAgentID = AgentId;
	AMLEnemyBase* CharAgent = Cast<AMLEnemyBase>(GetAgent(AgentId));

	if (CharAgent)
	{
		CharAgent->ResetToRandomPointOnSpline();
	}
}

void UEnemyTrainingEnvironment::setTrainingEnvAgentID(int32 AgentIDStore)
{
	TrainingEnvAgentID = AgentIDStore;
}

int32 UEnemyTrainingEnvironment::getTrainingEnvAgentID()
{
	return TrainingEnvAgentID;
}

void UEnemyTrainingEnvironment::setTrainingEnvSplineComponent(USplineComponent* tempSpline)
{
	TrainingEnvSplineComponent = tempSpline;
}
