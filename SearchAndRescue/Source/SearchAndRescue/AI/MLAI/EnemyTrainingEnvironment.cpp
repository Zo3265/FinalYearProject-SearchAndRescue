// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/EnemyTrainingEnvironment.h"
#include "Kismet/GameplayStatics.h"

//Here we will reward our character for following the path
void UEnemyTrainingEnvironment::GatherAgentReward_Implementation(float& OutReward, const int32 AgentId)
{
	TrainingEnvAgentID = AgentId;
	ACharacter* RewardCharacter = Cast<ACharacter>(GetAgent(AgentId));
	AMLEnemyBase* Enemy = Cast<AMLEnemyBase>(GetAgent(AgentId));

	float TotalReward = 0.0f;
	AActor* TargetToFollow = nullptr;

	if (bTraining == true)
	{
		TargetToFollow = Enemy->getTrainingTarget();
		//Enemy->getWeapon()->getBullet()->setTarget(TargetToFollow);
	}

	else
	{
		TargetToFollow = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		//Enemy->getWeapon()->getBullet()->setTarget(TargetToFollow);
	}

	
	//UE_LOG(LogTemp, Error, TEXT("The value is: %s"), Enemy->getSeePlayer() ? TEXT("true") : TEXT("false"));
	if (RewardCharacter && TrainingEnvSplineComponent)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Test"));
		//====================================================================================================
		// 1.Following the spline reward
		//====================================================================================================
		//Get the location of the character and their closest location to a point on the spline.
		FVector CharLocation = RewardCharacter->GetActorLocation();
		FVector ClosestSplineLocation = TrainingEnvSplineComponent->FindLocationClosestToWorldLocation(CharLocation, ESplineCoordinateSpace::World);
		FTransform ActorTransform = Enemy->GetActorTransform();

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
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		FVector PlayerLoc = TargetToFollow->GetActorLocation();
		FVector PlayerDir = (PlayerLoc - CharLocation).GetSafeNormal();
		FVector RelativeDir = ActorTransform.InverseTransformVectorNoScale(PlayerDir);
		float PlayerAlignment = FVector::DotProduct(CharForward, PlayerDir);
		//UE_LOG(LogTemp, Warning, TEXT("PlayerAlignment: %f"), PlayerAlignment);

		//float RightDot = FVector::DotProduct(Enemy->GetActorRightVector(), PlayerDir);
		float EnemyTurnValue = Enemy->getTurnValue();

		//The enemy is sometimes turning the long way to see the player. We need to punish that.
		if ((RelativeDir.Y > 0 && EnemyTurnValue < -0.1f) || (RelativeDir.Y < 0 && EnemyTurnValue > 0.1f))
		{
			TotalReward -= 75.0f;
		}

		if (FMath::Abs(EnemyTurnValue) > 0.5f && !Enemy->getSeePlayer())
		{
			// The faster they spin, the more it hurts.
			TotalReward -= (FMath::Abs(EnemyTurnValue) * 50.0f);
		}
		
		if (Enemy->getSeePlayer() == true)
		{
			
			CurrentState = EAgentState::SeeingPlayer;
		}

		else
		{ 
			CurrentState = EAgentState::Patrolling;
		}

		//if (CurrentState == EAgentState::Patrolling)
		//{
		//	//TotalReward = 0.0f;
		//	//Following Spline
		//	//Reward the character for being close to the spline. I am using a gaussian distribution for the reward as to not give them a harsh punishment if they step off the spline.
		//	//Also this will need to change when I want the enemy to be chasing the player.
		//	//Max Reward Possible is about 0.7f.
		//	//TotalReward += 0.7f * FMath::Exp(-0.01f * DistanceToPath);
		//	TotalReward += 0.35f * FMath::Exp(-0.01f * DistanceToPath);

		//	////Facing the correct direction
		//	////Max reward possible is 1.0f
		//	//TotalReward += 1.0f * CharAlignment;
		//	TotalReward += 0.5f * CharAlignment;

		//	////Going fast.
		//	////Max reward possible is 0.4f
		//	//TotalReward += (0.4f * NormalizedVelocity) * FMath::Max(0.0f, CharAlignment);
		//	TotalReward += (0.2f * NormalizedVelocity) * FMath::Max(0.0f, CharAlignment);
		//}

		//else if (CurrentState == EAgentState::SeeingPlayer)
		if (CurrentState == EAgentState::SeeingPlayer)
		{
			TotalReward += 1.0f;
			//UE_LOG(LogTemp, Warning, TEXT("Agent: %d can see the player"), AgentId);
			//We reward the agents proportionally to how much they are facing the player when they see them.
			TotalReward += PlayerAlignment * 5.0f;

			//Velocity. Punish the enemies for going fast and ignoring the player. The velocity should be 0 when they see the player.
			//I am currently testing this idea. I may want them to move when they see the player later.
			float SpeedPct = RewardCharacter->GetVelocity().Size() / MaxSpeed;
			if (SpeedPct > 0.01f)
			{
				TotalReward -= (SpeedPct * 30.0f);
			}

			else if (PlayerAlignment >= 0.95f) {
				//5.0f
				//TotalReward += 20.0f;
				TotalReward += 10.0f;
			}

			//Rewards for when the enemy is being precise.
			if (Enemy->getIsAimed())
			{
				TotalReward += (1.0f - FMath::Abs(EnemyTurnValue)) * 2.0f;
			}

			//Shooting Logic
			if(Enemy->getEnemyShootValue() > 0.1f)
			{
				if (PlayerAlignment > 0.8 && Enemy->getIsAimed() == true && Enemy->getAmmoPercent() > 0.0f)
				{
					TotalReward += (20.0f * Enemy->getEnemyShootValue());
				}

				else
				{
					TotalReward -= (5.0f * Enemy->getEnemyShootValue());
				}
			}

			//Hitting the player logic
			if (Enemy->getHit() == true)
			{
				// A massive one-time bonus
				TotalReward += 100.0f;

				Enemy->setHit(false);
			}
			
			
			//Reloading logic
			if (Enemy->getEnemyReloadValue() > 0.5f)
			{
				if (Enemy->getAmmoPercent() < 0.25f)
				{
					TotalReward += 15.0f;
				}

				else
				{
					TotalReward -= 20.0f;
				}
			}
			

			//If the enemy never reloads punish them.
			if (Enemy->getAmmoPercent() <= 0.0f)
			{
				TotalReward -= 30.0f;
			}


			/*if (SpeedPct < 0.01f)
			{
				TotalReward += 2.0f;
			}*/

			ELearningAgentsCompletion AgentCompletion;
			GatherAgentCompletion_Implementation(AgentCompletion, AgentId);
			if (AgentCompletion == ELearningAgentsCompletion::Truncation && CurrentState == EAgentState::SeeingPlayer)
			{
				// A one-time massive reward for successfully holding the focus for 2 seconds
				//20.0f
				//TotalReward += 100.0f;
				TotalReward += 50.0f;
				//UE_LOG(LogTemp, Warning, TEXT("Agent %d WON the episode! +20 Reward"), AgentId);
			}

			
		}
		
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
	AMLEnemyBase* RewardCharacter = Cast<AMLEnemyBase>(GetAgent(AgentId));

	if (RewardCharacter == nullptr || TrainingEnvSplineComponent == nullptr)
	{
		OutCompletion = ELearningAgentsCompletion::Running;
		return;
	}

	AActor* TargetToFollow = nullptr;

	if (bTraining == true)
	{
		TargetToFollow = RewardCharacter->getTrainingTarget();
	}

	else
	{
		TargetToFollow = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
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
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	FVector PlayerLoc = TargetToFollow->GetActorLocation();
	FVector PlayerDir = (PlayerLoc - CharLocation).GetSafeNormal();
	float PlayerAlignment = FVector::DotProduct(CharForward, PlayerDir);

	//if (CurrentState == EAgentState::Patrolling)
	//{
	//	

	//	//Terminate the episode if the agent moves further than 0.5m away from the spline.
	//	if (DistanceFromPath > 25.0f)
	//	{
	//		OutCompletion = ELearningAgentsCompletion::Termination;
	//	}


	//	if (CharAlignment < 0.0f)
	//	{
	//		OutCompletion = ELearningAgentsCompletion::Termination;
	//	}

	//	else
	//	{
	//		//If none of the conditions are met we keep it running.
	//		OutCompletion = ELearningAgentsCompletion::Running;
	//	}
	//}

	//else if (CurrentState == EAgentState::SeeingPlayer)
	if (CurrentState == EAgentState::SeeingPlayer)
	{
		bool bFacingPlayer;
		bool bStopped;

		if (RewardCharacter->getHit() == true)
		{
			OutCompletion = ELearningAgentsCompletion::Truncation;
			return;
		}

		//Check if the enemy is facing the player
		if (PlayerAlignment > 0.95f)
		{
			bFacingPlayer = true;
		}
		
		else
		{
			bFacingPlayer = false;
		}

		//Check if they have stopped moving
		if (RewardCharacter->GetVelocity().Size() < 5.0f)
		{
			bStopped = true;
		}

		else
		{
			bStopped = false;
		}

		if (bFacingPlayer && bStopped)
		{
			RewardCharacter->setSuccessTimer(RewardCharacter->getTimer() + GetWorld()->GetDeltaSeconds());

			//If they look at the player and have stopped moving for more than 2 secconds. They have succeded in their episode.
			if (RewardCharacter->getTimer() > 10.0f)
			{
				OutCompletion = ELearningAgentsCompletion::Truncation;
				return;
			}
		}

		else
		{
			RewardCharacter->setSuccessTimer(0.0f);
		}

		//If they lose sight of the player they have failed the episode.
		float DistanceToPlayer = FVector::Dist(CharLocation, PlayerLoc);
		if (DistanceToPlayer > 3000.0f) //|| bSeePlayer == false)
		{
			OutCompletion = ELearningAgentsCompletion::Termination;
		}

	}

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
	CharAgent->setSuccessTimer(0.0f);
	CharAgent->setHit(false);
	CurrentState = EAgentState::Patrolling;

	AActor* TargetToFollow = nullptr;
	FVector EnemyLoc = CharAgent->GetActorLocation();
	FVector EnemyFwd = CharAgent->GetActorForwardVector();
	FVector EnemyRight = CharAgent->GetActorRightVector();

	if (bTraining == true)
	{
		TargetToFollow = CharAgent->getTrainingTarget();
	}

	else
	{
		TargetToFollow = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	}

	if (CharAgent)
	{
		CharAgent->ResetToRandomPointOnSpline();
	}

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (TargetToFollow && TrainingEnvSplineComponent)
	{
		//0.7f
		float SpawnChance = 0.5f;
		float Roll = FMath::FRand(); // Returns 0.0 to 1.0

		if (Roll <= SpawnChance)
		{

			if (bTraining == true)
			{
				AMyActor* TrainingActor = Cast<AMyActor>(TargetToFollow);
				TrainingActor->setSplineController(CharAgent->GetSplineController());
				

				//// Get a random distance along the spline
				//float RandomDistance = FMath::FRandRange(0.0f, CharAgent->GetSplineController()->getSpline()->GetSplineLength());
				//TrainingActor->setCurrentDistance(RandomDistance);
				//FVector RandomLocation = CharAgent->GetSplineController()->getSpline()->GetLocationAtDistanceAlongSpline(RandomDistance, ESplineCoordinateSpace::World);

				//// Add a slight offset so the player isn't on the line
				//RandomLocation += FVector(FMath::FRandRange(-200.f, 200.f), FMath::FRandRange(-200.f, 200.f), 0.0f);
				//RandomLocation.Z = EnemyLoc.Z + 60.0f;

				//TrainingActor->SetActorLocation(RandomLocation);

				float InFrontSpawnChance = FMath::FRand();
				float AngleOffset;
			
				//Spawns training actor infront pf agent
				if (InFrontSpawnChance < 0.7f)
				{
					AngleOffset = FMath::FRandRange(-45.0f, 45.0f);
				}

				//Spawns training actor to the side of the agent
				else if (InFrontSpawnChance < 0.9f)
				{
					if (FMath::FRand() > 0.5f)
					{
						AngleOffset = 90.0f;
					}

					else
					{
						AngleOffset = -90.0f;
					}
					//AngleOffset = -90.0f;
				}

				//Spawns them directly behinde the agent
				else
				{
					if (FMath::FRand() > 0.5f)
					{
						AngleOffset = 180.0f;
					}

					else
					{
						AngleOffset = -180.0f;
					}
				}

				float DirectionChance = FMath::FRand();
				if (DirectionChance > 0.5f)
				{
					TrainingActor->setDirectionMultiplier(-1.0f);
				}

				else
				{
					TrainingActor->setDirectionMultiplier(1.0f);
				}

				float Dist = FMath::FRandRange(400.0f, 800.0f);
				FVector SpawnDir = EnemyFwd.RotateAngleAxis(AngleOffset, FVector::UpVector);
				FVector DesiredLoc = EnemyLoc + (SpawnDir * Dist);
				DesiredLoc.Z = EnemyLoc.Z + 60.0f;

				// 4. Snap to Spline (using the code we wrote earlier)
				USplineComponent* Spline = CharAgent->GetSplineController()->getSpline();
				float ClosestKey = Spline->FindInputKeyClosestToWorldLocation(DesiredLoc);
				float DistanceOnSpline = Spline->GetDistanceAlongSplineAtSplineInputKey(ClosestKey);

				TrainingActor->SetActorLocation(Spline->GetLocationAtDistanceAlongSpline(DistanceOnSpline, ESplineCoordinateSpace::World));
				TrainingActor->setCurrentDistance(DistanceOnSpline);
				
			}

			else
			{

				// Get a random distance along the spline
				float RandomDistance = FMath::FRandRange(0.0f, CharAgent->GetSplineController()->getSpline()->GetSplineLength());
				FVector RandomLocation = CharAgent->GetSplineController()->getSpline()->GetLocationAtDistanceAlongSpline(RandomDistance, ESplineCoordinateSpace::World);

				// Add a slight offset so the player isn't on the line
				RandomLocation += FVector(FMath::FRandRange(-200.f, 200.f), FMath::FRandRange(-200.f, 200.f), 0.0f);
				RandomLocation.Z = EnemyLoc.Z + 60.0f;

				TargetToFollow->SetActorLocation(RandomLocation);
			}
			

			//// Distance in front (e.g., 3 to 7 meters)
			//float ForwardDist = FMath::FRandRange(300.0f, 700.0f);
			//// Slight side-to-side randomness (e.g., 2 meters left or right)
			//float SideDist = FMath::FRandRange(-200.0f, 200.0f);

			//FVector SpawnLoc = EnemyLoc + (EnemyFwd * ForwardDist) + (CharAgent->GetActorRightVector() * SideDist);

			//// Ensure they aren't spawning inside the floor (match eye height)
			//SpawnLoc.Z = EnemyLoc.Z + 60.0f;

			//// 3. Move the player
			//TargetToFollow->SetActorLocation(SpawnLoc);
		}
		else
		{
			AActor* Sphere;
			Sphere = UGameplayStatics::GetActorOfClass(GetWorld(), ASplineMovementActor::StaticClass());

			if (Sphere != nullptr)
			{
				TargetToFollow->SetActorLocation(Sphere->GetActorLocation());
				//UE_LOG(LogTemp, Log, TEXT("Episode Reset: Player HIDDEN for Agent %d"), AgentId);
			}
		}
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
