// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/EnemyTrainingEnvironment.h"
#include "Kismet/GameplayStatics.h"

//Here we will reward our character for following the path
void UEnemyTrainingEnvironment::GatherAgentReward_Implementation(float& OutReward, const int32 AgentId)
{
	TrainingEnvAgentID = AgentId;
	ACharacter* RewardCharacter = Cast<ACharacter>(GetAgent(AgentId));
	AMLEnemyBase* Enemy = Cast<AMLEnemyBase>(GetAgent(AgentId));
	AWeaponBase* Weapon = Enemy->getWeapon();
	USkeletalMeshComponent* RewardCharMesh = RewardCharacter->GetMesh();
	TrainingEnvSplineComponent = Enemy->GetSplineController()->getSpline();

	float TotalReward = 0.0f;
	AActor* TargetToFollow = nullptr;

	if (bTraining == true)
	{
		TargetToFollow = Enemy->getTrainingTarget();
	}

	else
	{
		TargetToFollow = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
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
		/*if ((RelativeDir.Y > 0 && EnemyTurnValue < -0.1f) || (RelativeDir.Y < 0 && EnemyTurnValue > 0.1f))
		{
			TotalReward -= 2.0f;
			UE_LOG(LogTemp, Error, TEXT("Long way turn penalty"));
		}*/

		//if (FMath::Abs(EnemyTurnValue) > 0.6f && !Enemy->getSeePlayer())
		//{
		//	// The faster they spin, the more it hurts.
		//	TotalReward -= 10.0f;
		//	UE_LOG(LogTemp, Error, TEXT("360 penalty"));
		//}

		//Hitting the player logic
		if (Enemy->getHit() == true)
		{
			// A massive one-time bonus
			TotalReward += 150.0f;

			Enemy->setHit(false);
		}
		
		if (Enemy->getSeePlayer() == true)
		{
			
			//CurrentState = EAgentState::SeeingPlayer;
			Enemy->setCurrentState(EAgentState::SeeingPlayer);
		}

		else
		{ 
			//CurrentState = EAgentState::Patrolling;
			Enemy->setCurrentState(EAgentState::Patrolling);
		}



		if (Enemy->getCurrentState() == EAgentState::Patrolling)
		{
			TotalReward += 2.0f;
			//if (FMath::Abs(EnemyTurnValue) > 0.2f)
			//{
			//	TotalReward -= 1.0f; // Punish 'wiggly' turning 5
			//	UE_LOG(LogTemp, Error, TEXT("Distance penalty"));
			//}

			//if (Enemy->getEnemyShootValue() > 0.1f)
			//{
			//	TotalReward -= 10.0f; // Heavy punishment for shooting on patrol 50
			//	UE_LOG(LogTemp, Error, TEXT("Shot on patrol"));
			//}


			//TotalReward = 0.0f;
			//Following Spline
			//Reward the character for being close to the spline. I am using a gaussian distribution for the reward as to not give them a harsh punishment if they step off the spline.
			//Also this will need to change when I want the enemy to be chasing the player.
			//Max Reward Possible is about 0.7f.
			TotalReward += 2.0f * FMath::Exp(-0.1f * DistanceToPath);
			//TotalReward += 0.175f * FMath::Exp(-0.01f * DistanceToPath);

			if (DistanceToPath > 250.0f && Enemy->FindingTrack == false) // If more than 225 units off the line
			{
				TotalReward -= 15.0f; //50
				//UE_LOG(LogTemp, Error, TEXT("Distance penalty"));
			}

			////Going fast.
			////Max reward possible is 0.4f
			/*float SpeedReward = (NormalizedVelocity * 50.0f) * FMath::Max(0.1f, CharAlignment);
			TotalReward += SpeedReward;*/
			//TotalReward += (0.2f * NormalizedVelocity) * FMath::Max(0.0f, CharAlignment);
			float ForwardMotion = FVector::DotProduct(Enemy->GetActorForwardVector(), Enemy->GetVelocity().GetSafeNormal());
			float SpeedReward = (NormalizedVelocity * 10.0f) * FMath::Max(0.0f, ForwardMotion); //1.5f
			TotalReward += SpeedReward;

			////Facing the correct direction
			////Max reward possible is 1.0f
			CharAlignment = FMath::Clamp(CharAlignment, -1.0f, 1.0f);
			TotalReward += 2.0f * CharAlignment;
			//TotalReward += 0.25f * CharAlignment;

			//if (CharAlignment < 0.8f) // If they are looking more than ~36 degrees away from the path
			//{
			//	// Punish them more the further they look away
			//	// A flat penalty (-10.0) combined with a scaling penalty
			//	TotalReward -= 1.0f + (1.0f - CharAlignment);
			//	UE_LOG(LogTemp, Error, TEXT("Looking away from spline penalty"));
			//}


			if ((CharAlignment < 0.85f && NormalizedVelocity > 0.4f) && Enemy->FindingTrack == false)
			{
				// Punish specifically for 'Full Throttle' during a turn
				TotalReward -= (NormalizedVelocity * 25.0f);
				//UE_LOG(LogTemp, Error, TEXT("Full speed turn penalty"));
				//TotalReward -= 2.0f;
			}

			//TotalReward = 0.0f;

			//if (DistanceToPath > 175.0f) // If more than 225 units off the line
			//{
			//	TotalReward -= 15.0f; //50
			//}
		}

		else if (Enemy->getCurrentState() == EAgentState::SeeingPlayer)
		//if (CurrentState == EAgentState::SeeingPlayer)
		{
			//GLog->Log(TEXT("Seeing player"));
			//TotalReward += 1.0f;
			//UE_LOG(LogTemp, Warning, TEXT("Agent: %d can see the player"), AgentId);
			//We reward the agents proportionally to how much they are facing the player when they see them.
			TotalReward += PlayerAlignment * 1.0f;

			if (PlayerAlignment >= 0.95f) {
				//5.0f
				TotalReward += 2.0f;
				//TotalReward += 10.0f;
			}

			FVector FaceLocation = RewardCharMesh->GetSocketLocation(TEXT("FaceShoot"));
			FVector AimDirection = RewardCharacter->GetControlRotation().Vector();
			FVector MuzzleLocation = Weapon->getMesh()->GetSocketLocation(TEXT("BulletSpawn"));

			FVector TargetLocation = PlayerLoc;
			FVector PointToTargetDir = (TargetLocation - FaceLocation).GetSafeNormal();


			float GunAlignment = FVector::DotProduct(AimDirection, PointToTargetDir);
			GunAlignment = FMath::Clamp(GunAlignment, 0.0f, 1.0f); // We only care about the front 180 degrees

			TotalReward += FMath::Pow(GunAlignment, 2) * 10.0f;

			if (Enemy->getIsAimed())
			{
				// High reward for having the GUN on target. 
				// This is the only one that should trigger the 'Stillness' bonus.
				TotalReward += 40.0f;
				TotalReward += (1.0f - FMath::Abs(EnemyTurnValue)) * 0.5f;
			}

			//Rewards for when the enemy is being precise.
			if ((RelativeDir.Y > 0 && EnemyTurnValue > 0.01f) || (RelativeDir.Y < 0 && EnemyTurnValue < -0.01f))
			{
				// Pay them for moving the joystick the RIGHT way
				TotalReward += 1.0f;
			}

			//Velocity. Punish the enemies for going fast and ignoring the player. The velocity should be 0 when they see the player.
			//I am currently testing this idea. I may want them to move when they see the player later.
			float SpeedPct = RewardCharacter->GetVelocity().Size() / MaxSpeed;
			if (SpeedPct > 0.1f)
			{
				TotalReward -= (SpeedPct * 20.0f);
				UE_LOG(LogTemp, Warning, TEXT("Movement seeing player penalty"));
			}


			//Shooting Logic
			if(Enemy->getEnemyShootValue() > 0.1f)
			{
				if (Enemy->getIsAimed() == true && Enemy->getAmmoPercent() > 0.0f)
				{
					TotalReward += (30.0f * Enemy->getEnemyShootValue());
				}

				else
				{
					//TotalReward -= (20.0f * Enemy->getEnemyShootValue());
					TotalReward -= 0.1f;
					//UE_LOG(LogTemp, Warning, TEXT("Not shooting penalty"));
				}
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
					//TotalReward -= 20.0f;
					TotalReward -= 0.1f;
					//UE_LOG(LogTemp, Warning, TEXT("Reloading when high"));
				}
			}
			

			//If the enemy never reloads punish them.
			if (Enemy->getAmmoPercent() <= 0.0f)
			{
				TotalReward -= 30.0f;
				UE_LOG(LogTemp, Warning, TEXT("Not reloading at all penalty"));
			}


			ELearningAgentsCompletion AgentCompletion;
			GatherAgentCompletion_Implementation(AgentCompletion, AgentId);
			if (AgentCompletion == ELearningAgentsCompletion::Truncation && Enemy->getCurrentState() == EAgentState::SeeingPlayer)
			{
				// A one-time massive reward for successfully holding the focus for 2 seconds
				//20.0f
				TotalReward += 100.0f;
				//TotalReward += 50.0f;
				//UE_LOG(LogTemp, Warning, TEXT("Agent %d WON the episode! +20 Reward"), AgentId);
			}

			
		}

		else if (Enemy->getCurrentState() == EAgentState::Chasing)
		{
			TotalReward += 1.0f; //Base reward for hunting

			TotalReward += 15.0f * FMath::Exp(-0.005f * Enemy->LastKnownLocDist);

			if (Enemy->LastKnownLocDist <= 160.0f)
			{
				TotalReward += 50.0f;
				UE_LOG(LogTemp, Warning, TEXT("Agent %d WON the episode! +50 Reward"), AgentId);
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
	TrainingEnvSplineComponent = RewardCharacter->GetSplineController()->getSpline();
	OutCompletion = ELearningAgentsCompletion::Running;

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

	if (RewardCharacter->getHit() == true)
	{
		OutCompletion = ELearningAgentsCompletion::Truncation;
		UE_LOG(LogTemp, Warning, TEXT("Agent %d WON the episode! It hit!"), AgentId);
		return;
	}

	if (RewardCharacter->getCurrentState() == EAgentState::Patrolling)
	{
		

		//Terminate the episode if the agent moves further than 0.5m away from the spline.
		if (DistanceFromPath > 300.0f && RewardCharacter->FindingTrack == false)
		{
			OutCompletion = ELearningAgentsCompletion::Termination;
			UE_LOG(LogTemp, Error, TEXT("Agent %d Went to far from the path"), AgentId);
		}


		//if (CharAlignment < 0.0f)
		//{
		//	OutCompletion = ELearningAgentsCompletion::Termination;
		//	//UE_LOG(LogTemp, Warning, TEXT("Looked the wrong way"), AgentId);
		//}

		else
		{
			//If none of the conditions are met we keep it running.
			OutCompletion = ELearningAgentsCompletion::Running;
		}
	}

	else if (RewardCharacter->getCurrentState() == EAgentState::SeeingPlayer)
	{
		bool bFacingPlayer;
		bool bStopped;

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
				UE_LOG(LogTemp, Warning, TEXT("Agent %d WON the episode! Timer"), AgentId);
				return;
			}
		}

		else
		{
			RewardCharacter->setSuccessTimer(0.0f);
		}

		//If they lose sight of the player they have failed the episode.
		//float DistanceToPlayer = FVector::Dist(CharLocation, PlayerLoc);
		//if (DistanceToPlayer > 7000.0f) //|| bSeePlayer == false)
		//{
		//	OutCompletion = ELearningAgentsCompletion::Termination;
		//	UE_LOG(LogTemp, Error, TEXT("Agent %d Lost the player"), AgentId);
		//}

	}

	/*else if (RewardCharacter->getCurrentState() == EAgentState::Chasing)
	{
		if (RewardCharacter->LastKnownLocDist <= 150.0f)
		{
			UE_LOG(LogTemp, Warning, TEXT("Agent %d Made it to the players last known location and won the episode"), AgentId);
			OutCompletion = ELearningAgentsCompletion::Truncation;
			return;
		}
	}*/

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
	TrainingEnvSplineComponent = CharAgent->GetSplineController()->getSpline();
	bool bIsSphereVisible = CharAgent->GetSplineController()->getSphereVisible();
	CharAgent->setCurrentState(EAgentState::Patrolling);

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
		float SpawnChance = 1.1f;
		float Roll = FMath::FRand(); // Returns 0.0 to 1.0

		if ((Roll <= SpawnChance) && bIsSphereVisible)
		{

			if (bTraining == true)
			{
				AMyActor* TrainingActor = Cast<AMyActor>(TargetToFollow);
				TrainingActor->setHide(false);
				TrainingActor->setSplineController(CharAgent->GetSplineController());
				

				// Get a random distance along the spline
				float RandomDistance = FMath::FRandRange(0.0f, CharAgent->GetSplineController()->getSpline()->GetSplineLength());
				TrainingActor->setCurrentDistance(RandomDistance);
				FVector RandomLocation = CharAgent->GetSplineController()->getSpline()->GetLocationAtDistanceAlongSpline(RandomDistance, ESplineCoordinateSpace::World);

				// Add a slight offset so the player isn't on the line
				RandomLocation += FVector(FMath::FRandRange(-200.f, 200.f), FMath::FRandRange(-200.f, 200.f), 0.0f);
				RandomLocation.Z = EnemyLoc.Z + 50.0f;

				TrainingActor->SetActorLocation(RandomLocation);


				// Distance in front (e.g., 3 to 7 meters)
				//float ForwardDist = FMath::FRandRange(400.0f, 800.0f); // 4-8 meters ahead
				//float SideDist = FMath::FRandRange(-300.0f, 300.0f);    // 3 meters left or right

				//// 2. Calculate the World Location
				//// We take the agent's position, move forward, then move right (or left if SideDist is negative)
				//FVector SpawnLoc = EnemyLoc + (EnemyFwd * ForwardDist) + (EnemyRight * SideDist);

				//// 3. Match Height
				//// Ensure they spawn at the same level as the agent (plus height adjustment)
				//SpawnLoc.Z = EnemyLoc.Z + 20.0f;

				//// 4. Update the Training Actor
				//if (TrainingActor)
				//{
				//	// Randomize movement direction
				//	float DirectionMultiplier = (FMath::FRand() > 0.5f) ? 1.0f : -1.0f;
				//	TrainingActor->setDirectionMultiplier(DirectionMultiplier);

				//	// Set the location
				//	TrainingActor->SetActorLocation(SpawnLoc);

				//	// Optional: Rotate the sphere to face the agent so it's ready to be 'seen'
				//	FRotator LookAtRot = (EnemyLoc - SpawnLoc).Rotation();
				//	TrainingActor->SetActorRotation(LookAtRot);
				//}
				////TrainingActor->setCurrentDistance(DistanceOnSpline);




				//float InFrontSpawnChance = FMath::FRand();
				//float AngleOffset;

				////Spawns training actor infront pf agent
				//if (InFrontSpawnChance < 0.7f)
				//{
				//	AngleOffset = FMath::FRandRange(-45.0f, 45.0f);
				//}

				////Spawns training actor to the side of the agent
				//else if (InFrontSpawnChance < 0.9f)
				//{
				//	if (FMath::FRand() > 0.5f)
				//	{
				//		AngleOffset = 90.0f;
				//	}

				//	else
				//	{
				//		AngleOffset = -90.0f;
				//	}
				//	//AngleOffset = -90.0f;
				//}

				////Spawns them directly behinde the agent
				//else
				//{
				//	if (FMath::FRand() > 0.5f)
				//	{
				//		AngleOffset = 180.0f;
				//	}

				//	else
				//	{
				//		AngleOffset = -180.0f;
				//	}
				//}

				//float DirectionChance = FMath::FRand();
				//if (DirectionChance > 0.5f)
				//{
				//	TrainingActor->setDirectionMultiplier(-1.0f);
				//}

				//else
				//{
				//	TrainingActor->setDirectionMultiplier(1.0f);
				//}

				//float Dist = FMath::FRandRange(400.0f, 800.0f);
				//FVector SpawnDir = EnemyFwd.RotateAngleAxis(AngleOffset, FVector::UpVector);
				//FVector DesiredLoc = EnemyLoc + (SpawnDir * Dist);
				////DesiredLoc.Z = EnemyLoc.Z + 60.0f;

				//USplineComponent* Spline = CharAgent->GetSplineController()->getSpline();
				//float ClosestKey = Spline->FindInputKeyClosestToWorldLocation(DesiredLoc);
				//float DistanceOnSpline = Spline->GetDistanceAlongSplineAtSplineInputKey(ClosestKey);
				//FVector FinalSpawnLoc = Spline->GetLocationAtDistanceAlongSpline(DistanceOnSpline, ESplineCoordinateSpace::World);
				//FinalSpawnLoc.Z = EnemyLoc.Z + 50.0f;

				//TrainingActor->SetActorLocation(FinalSpawnLoc);
				//TrainingActor->setCurrentDistance(DistanceOnSpline);
				
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

			if (bTraining == true)
			{
				AMyActor* TrainingActor = Cast<AMyActor>(TargetToFollow);
				AActor* Sphere = UGameplayStatics::GetActorOfClass(GetWorld(), ASplineMovementActor::StaticClass());
				if (TrainingActor && Sphere)
				{
					TrainingActor->setCurrentDistance(0.0f);
					TrainingActor->SetActorLocation(Sphere->GetActorLocation());
					TrainingActor->setHide(true);
					//UE_LOG(LogTemp, Log, TEXT("Episode Reset: Player HIDDEN for Agent %d"), AgentId);
				}
				
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
