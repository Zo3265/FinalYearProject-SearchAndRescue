// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/EnemyTrainingEnvironment.h"
#include "Kismet/GameplayStatics.h"

//Here we will reward our character for following the path
void UEnemyTrainingEnvironment::GatherAgentReward_Implementation(float& OutReward, const int32 AgentId)
{
	TrainingEnvAgentID = AgentId;
	ACharacter* RewardCharacter = Cast<ACharacter>(GetAgent(AgentId));

	float TotalReward = 0.0f;
	

	if (RewardCharacter && TrainingEnvSplineComponent)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Test"));
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

		//====================================================================================================
		// 4.Checking to see if the agent can see the player.
		//====================================================================================================
		APlayerController* PlayerChar = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		APawn* PlayerPawn = PlayerChar->GetPawn();
		FVector PlayerLoc = PlayerPawn->GetActorLocation();
		FVector PlayerDir = (PlayerLoc - CharLocation).GetSafeNormal();
		float PlayerAlignment = FVector::DotProduct(CharForward, PlayerDir);
		//UE_LOG(LogTemp, Warning, TEXT("PlayerAlignment: %f"), PlayerAlignment);

		//According to Gemini this value means that the agents have a 45 degree fov.
		//if (PlayerAlignment >= 0.707)
		//{
		//	//Setting up a raycast so that the agents cant see through walls
		//	FHitResult HitResult;
		//	FCollisionQueryParams CollisionParams;
		//	CollisionParams.AddIgnoredActor(RewardCharacter);

		//	bool bHit = GetWorld()->LineTraceSingleByChannel(
		//		HitResult,
		//		CharLocation + FVector(0, 0, 60),
		//		PlayerLoc,
		//		ECC_Visibility,
		//		CollisionParams
		//	);

		//	if (!bHit || (HitResult.GetActor() == Player))
		//	{
		//		bSeePlayer = true;
		//	}

		//	else
		//	{
		//		bSeePlayer = false;
		//	}

		//	
		//}

		if (bSeePlayer == true)
		{
			
			CurrentState = EAgentState::SeeingPlayer;
		}

		else
		{ 
			CurrentState = EAgentState::Patrolling;
		}

		if (CurrentState == EAgentState::Patrolling)
		{
			//Following Spline
			//Reward the character for being close to the spline. I am using a gaussian distribution for the reward as to not give them a harsh punishment if they step off the spline.
			//Also this will need to change when I want the enemy to be chasing the player.
			//Max Reward Possible is about 0.7f.
			TotalReward += 0.7f * FMath::Exp(-0.01f * DistanceToPath);

			//Facing the correct direction
			//Max reward possible is 1.0f
			TotalReward += 1.0f * CharAlignment;

			//Going fast.
			//Max reward possible is 0.4f
			TotalReward += (0.4f * NormalizedVelocity) * FMath::Max(0.0f, CharAlignment);
		}

		//else if (CurrentState == EAgentState::SeeingPlayer)
		//{
		//	TotalReward = 0.0f;

		//	//We now need to punish the enemy for following the spline.
		//	float SplineFollowing = 0.7f * FMath::Exp(-0.01f * DistanceToPath);
		//	TotalReward -= SplineFollowing;

		//	float SplineAlignment = 1.0f * CharAlignment;
		//	TotalReward -= SplineAlignment;

		//	if (NormalizedVelocity > 0.05f)
		//	{
		//		float SplineVelocity = (4.0f * NormalizedVelocity);
		//		TotalReward -= SplineVelocity;
		//	}
		//	

		//	//We reward the agents proportionally to how much they are facing the player when they see them.
		//	TotalReward += FMath::Max(0.0f, PlayerAlignment) * 5.0f;

		//	//Velocity. Punish the enemies for going fast and ignoring the player. The velocity should be 0 when they see the player.
		//	//I am currently testing this idea. I may want them to move when they see the player later.
		//	float SpeedPct = RewardCharacter->GetVelocity().Size() / MaxSpeed;
		//	if (SpeedPct > 0.01f)
		//	{
		//		TotalReward -= (SpeedPct * 3.0f);
		//	}

		//	else
		//	{
		//		
		//		TotalReward += 5.0f;
		//		
		//		
		//	}
		//	
		//}
		
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("Null"));
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

	//Logic for patrolling behaviour same as the rewards function.
	FVector CharLocation = RewardCharacter->GetActorLocation();
	FVector ClosestSplineLocation = TrainingEnvSplineComponent->FindLocationClosestToWorldLocation(CharLocation, ESplineCoordinateSpace::World);
	float DistanceFromPath = FVector::Dist(CharLocation, ClosestSplineLocation);

	FVector CharForward = RewardCharacter->GetActorForwardVector();
	float InputKey = TrainingEnvSplineComponent->FindInputKeyClosestToWorldLocation(CharLocation);
	FVector SplineForwardVec = TrainingEnvSplineComponent->GetDirectionAtSplineInputKey(InputKey, ESplineCoordinateSpace::World);

	//-1.0f to 1.0f
	float CharAlignment = FVector::DotProduct(CharForward, SplineForwardVec);

	//Logic for the seeingPlayer state. Same as reward function
	APlayerController* PlayerChar = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APawn* PlayerPawn = PlayerChar->GetPawn();
	FVector PlayerLoc = PlayerPawn->GetActorLocation();
	FVector PlayerDir = (PlayerLoc - CharLocation).GetSafeNormal();
	float PlayerAlignment = FVector::DotProduct(CharForward, PlayerDir);

	if (CurrentState == EAgentState::Patrolling)
	{
		

		//Terminate the episode if the agent moves further than 0.5m away from the spline.
		if (DistanceFromPath > 50.0f)
		{
			OutCompletion = ELearningAgentsCompletion::Termination;
		}


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

	//else if (CurrentState == EAgentState::SeeingPlayer)
	//{
	//	bool bFacingPlayer;
	//	bool bStopped;

	//	//Check if the enemy is facing the player
	//	if (PlayerAlignment > 0.95f)
	//	{
	//		bFacingPlayer = true;
	//	}
	//	
	//	else
	//	{
	//		bFacingPlayer = false;
	//	}

	//	//Check if they have stopped moving
	//	if (RewardCharacter->GetVelocity().Size() < 10.0f)
	//	{
	//		bStopped = true;
	//	}

	//	else
	//	{
	//		bStopped = false;
	//	}

	//	if (bFacingPlayer && bStopped)
	//	{
	//		SuccessTimer += GetWorld()->GetDeltaSeconds();

	//		//If they look at the player and have stopped moving for more than 2 secconds. They have succeded in their episode.
	//		if (SuccessTimer > 2.0f)
	//		{
	//			OutCompletion = ELearningAgentsCompletion::Truncation;
	//			return;
	//		}
	//	}

	//	else
	//	{
	//		SuccessTimer = 0.0f;
	//	}

	//	//If they lose sight of the player they have failed the episode.
	//	float DistanceToPlayer = FVector::Dist(CharLocation, PlayerLoc);
	//	if (DistanceToPlayer > 2000.0f || bSeePlayer == false)
	//	{
	//		OutCompletion = ELearningAgentsCompletion::Termination;
	//	}

	//	else
	//	{
	//		OutCompletion = ELearningAgentsCompletion::Running;
	//	}
	//}

	else
	{
		OutCompletion = ELearningAgentsCompletion::Running;
	}
	
}

void UEnemyTrainingEnvironment::ResetAgentEpisode_Implementation(const int32 AgentId)
{
	TrainingEnvAgentID = AgentId;
	AMLEnemyBase* CharAgent = Cast<AMLEnemyBase>(GetAgent(AgentId));
	bSeePlayer = false;
	SuccessTimer = 0.0f;
	CurrentState = EAgentState::Patrolling;

	if (CharAgent)
	{
		CharAgent->ResetToRandomPointOnSpline();
	}

	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//if (PlayerPawn && TrainingEnvSplineComponent)
	//{
	//	// Get a random distance along the spline
	//	float RandomDistance = FMath::FRandRange(0.0f, TrainingEnvSplineComponent->GetSplineLength());
	//	FVector RandomLocation = TrainingEnvSplineComponent->GetLocationAtDistanceAlongSpline(RandomDistance, ESplineCoordinateSpace::World);

	//	// Add a slight offset so the player isn't on the line
	//	RandomLocation += FVector(FMath::FRandRange(-200.f, 200.f), FMath::FRandRange(-200.f, 200.f), 0.0f);

	//	PlayerPawn->SetActorLocation(RandomLocation);
	//}
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
