// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/EnemyInteractor.h"
#include "Components/SplineComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

//Specifying which observation for the enemies to make
void UEnemyInteractor::SpecifyAgentObservation_Implementation(FLearningAgentsObservationSchemaElement& OutObservationSchemaElement, ULearningAgentsObservationSchema* InObservationSchema)
{
	//Super::SpecifyAgentObservation_Implementation(OutObservationSchemaElement, InObservationSchema);

	//UE_LOG(LogTemp, Error, TEXT("Specifying OBS"));
	//Map to store the observations
	TMap<FName, FLearningAgentsObservationSchemaElement> ObservationMap;
	
	ObservationMap.Add(TEXT("IsPlayerSeen"), ULearningAgentsObservations::SpecifyBoolObservation(InObservationSchema));
	//One observation will be the location along the spline which will be used to make the enemy patrol.
	ObservationMap.Add(TEXT("Location"), ULearningAgentsObservations::SpecifyLocationAlongSplineObservation(InObservationSchema));

	//Another will be the direction along the spline.
	ObservationMap.Add(TEXT("Direction"), ULearningAgentsObservations::SpecifyDirectionAlongSplineObservation(InObservationSchema));

	//We need a velocity observation to tell the enemy to increase its distance along the spline and reward it for doing so.
	ObservationMap.Add(TEXT("Velocity"), ULearningAgentsObservations::SpecifyVelocityObservation(InObservationSchema));
	ObservationMap.Add(TEXT("LookAhead"), ULearningAgentsObservations::SpecifyDirectionObservation(InObservationSchema));

	//Observations needed to see the player
	//ObservationMap.Add(TEXT("PlayerLocation"), ULearningAgentsObservations::SpecifyLocationObservation(InObservationSchema));
	ObservationMap.Add(TEXT("PlayerDirection"), ULearningAgentsObservations::SpecifyDirectionObservation(InObservationSchema));
	

	//Observations to help the enemies actually shoot the player
	ObservationMap.Add(TEXT("WeaponCoolDown"), ULearningAgentsObservations::SpecifyFloatObservation(InObservationSchema)); //The rate of fire for the weapon
	ObservationMap.Add(TEXT("IsAimedAtTarget"), ULearningAgentsObservations::SpecifyBoolObservation(InObservationSchema)); //If the gun is actually lined up with the player
	ObservationMap.Add(TEXT("TargetRelativeDirection"), ULearningAgentsObservations::SpecifyDirectionObservation(InObservationSchema)); //The direction the player is moving in.
	ObservationMap.Add(TEXT("TargetRelativeSpeed"), ULearningAgentsObservations::SpecifyFloatObservation(InObservationSchema)); //How fast they are moving in said direction. This and the previous observation are supposed to be one. We cant use a velocity observation here because that is made for the agents velocity.
	ObservationMap.Add(TEXT("AmmoPercentage"), ULearningAgentsObservations::SpecifyFloatObservation(InObservationSchema));
	ObservationMap.Add(TEXT("DoesNeedToReload"), ULearningAgentsObservations::SpecifyBoolObservation(InObservationSchema));
	

	//Combine the data. This function concatenates all these sub-observations into a struct. We can do this as many times as needed.
	OutObservationSchemaElement = ULearningAgentsObservations::SpecifyStructObservation(InObservationSchema, ObservationMap);
	
}

//Gathering observations that we specified.
void UEnemyInteractor::GatherAgentObservation_Implementation(FLearningAgentsObservationObjectElement& OutObservationObjectElement, ULearningAgentsObservationObject* InObservationObject, const int32 AgentId)
{
	//Super::GatherAgentObservation_Implementation(OutObservationObjectElement, InObservationObject, AgentId);

	//Get the agent that is making the observations.
	setInteractorAgentID(AgentId);
	UObject* OBSAgent = GetAgent(AgentId);

	//Get the actual actor
	AMLEnemyBase* Enemy = Cast<AMLEnemyBase>(OBSAgent);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	AWeaponBase* Weapon = Enemy->getWeapon();

	//USplineComponent* SplineComp = Enemy->FindComponentByClass<USplineComponent>();
	TMap<FName, FLearningAgentsObservationObjectElement> ObservationMap;
	
	AActor* TargetToFollow = nullptr;
	if(Enemy)
	{
		if (bTraining == true)
		{
			TargetToFollow = Enemy->getTrainingTarget();
		}

		else
		{
			TargetToFollow = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		}


		FVector ActorLocation = Enemy->GetActorLocation();
		FVector ActorForward = Enemy->GetActorForwardVector();
		FVector ActorVelocity = Enemy->GetVelocity();

		float InputKey = InteractorSplineComponent->FindInputKeyClosestToWorldLocation(ActorLocation);
		float RawDistance = InteractorSplineComponent->GetDistanceAlongSplineAtSplineInputKey(InputKey);

		float NormalisedDistance = RawDistance / InteractorSplineComponent->GetSplineLength();
		FTransform ActorTransform = Enemy->GetActorTransform();

		//Looking 500 units ahead of the agents position to help them make turns.
		float FutureDistance = FMath::Fmod(RawDistance + 250.0f, InteractorSplineComponent->GetSplineLength());
		FVector FutureDir = InteractorSplineComponent->GetDirectionAtDistanceAlongSpline(FutureDistance, ESplineCoordinateSpace::World);
		FVector LocalFutureDir = ActorTransform.InverseTransformVectorNoScale(FutureDir);

		FVector PlayerLoc = TargetToFollow->GetActorLocation();
		FVector PlayerVelocity = TargetToFollow->GetVelocity();
		FVector PlayerDir = (PlayerLoc - ActorLocation).GetSafeNormal();
		FVector RelativeDir = ActorTransform.InverseTransformVectorNoScale(PlayerDir);

		float PlayerAlignment = FVector::DotProduct(ActorForward, PlayerDir);
		//UE_LOG(LogTemp, Warning, TEXT("PlayerAlignment: %f"), PlayerAlignment);

		//Here we are trying to spot the player
		//According to Gemini this value means that the agents have a 45 degree fov.
		if (PlayerAlignment >= 0.707f)
		{
			//UE_LOG(LogTemp, Error, TEXT("Player Aligned"));
			//Setting up a raycast so that the agents cant see through walls
			FHitResult HitResult;
			FCollisionQueryParams CollisionParams;
			CollisionParams.AddIgnoredActor(Enemy);

			bool bHit = GetWorld()->LineTraceSingleByChannel(
				HitResult,
				ActorLocation + FVector(0, 0, 60),
				PlayerLoc + FVector(0, 0, 60),
				ECC_Visibility,
				CollisionParams
			);

			/*UE_LOG(LogTemp, Warning, TEXT("bHit: %s"), bHit ? TEXT("true") : TEXT("false"));
			bool bCanSee = (!bHit || (HitResult.GetActor() == TargetToFollow));
			UE_LOG(LogTemp, Error, TEXT("bCanSee: %s"), bCanSee ? TEXT("true") : TEXT("false"));*/

			/*if (bHit && HitResult.GetActor()) {
				UE_LOG(LogTemp, Warning, TEXT("Agent %d hit: %s instead of target!"),
					AgentId, *HitResult.GetActor()->GetName());
			}*/
			if (!bHit || (HitResult.GetActor() == TargetToFollow))
			{
				Enemy->setSeePlayer(true);
				//UE_LOG(LogTemp, Error, TEXT("Agent:%d can see the player with PlayerAlignment: %f"), AgentId, PlayerAlignment);
			}

			else
			{
				Enemy->setSeePlayer(false);
			}
			//UE_LOG(LogTemp, Warning, TEXT("The value is: %s"), Enemy->getSeePlayer() ? TEXT("true") : TEXT("false"));

		}

		else
		{
			Enemy->setSeePlayer(false);
		}


		//We need another line of sight check that we can use to see if the muzzle of our gun is actually pointing at the player.
		//I am going to use another line trace for this but one with a range that will be decided by the type of weapon.
		FVector MuzzleLocation = Weapon->getMesh()->GetSocketLocation("BulletSpawn");
		FVector MuzzleForward = Weapon->getMesh()->GetSocketRotation("BulletSpawn").Vector();
		FVector TraceEnd = MuzzleLocation + (MuzzleForward * Weapon->getRange());

		//DrawDebugLine(
		//	GetWorld(),
		//	MuzzleLocation,
		//	TraceEnd,
		//	FColor::Red, // Color of the line
		//	false,       // Whether the line is persistent (stays forever)
		//	0.1f,        // Lifetime in seconds (0.1f is good for every-frame updates)
		//	0,           // Depth priority
		//	2.0f         // Thickness of the line
		//);

		FHitResult AimHit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(Enemy);
		Params.AddIgnoredActor(Weapon);

		bool bAimHit = GetWorld()->LineTraceSingleByChannel(
			AimHit,
			MuzzleLocation,
			TraceEnd,
			ECC_Visibility,
			Params
		);
		//UE_LOG(LogTemp, Warning, TEXT("AimHit is: %s"), bAimHit ? TEXT("true") : TEXT("false"));
		//UE_LOG(LogTemp, Warning, TEXT("AimHit Target is: %s"), AimHit.GetActor()->IsA(AMyActor::StaticClass()) ? TEXT("true") : TEXT("false"));

		/*if (AimHit.GetActor())
		{
			UE_LOG(LogTemp, Warning, TEXT("Trace hit: %s"), *AimHit.GetActor()->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Trace hit NOTHING"));
		}*/

		if (bAimHit == true && AimHit.GetActor() == TargetToFollow)
		{
			Enemy->setIsAimed(true);
		}

		else
		{
			Enemy->setIsAimed(false);
		}

		//I want the enemies to lead their shots so we need to know the players speed and direction.
		//Similar math as before but with velocities instead.
		FVector RelativeWorldVelocity = PlayerVelocity - ActorVelocity; //The velocity of the player relative to the enemy in world space.
		FVector RelativeLocalVelocity = ActorTransform.InverseTransformVectorNoScale(RelativeWorldVelocity); //Converted to local space in order for the agents to know if the player isleft or right relative to them.

		float RelativeMoveSpeed = RelativeLocalVelocity.Size();
		float NormalizedMoveSpeed = FMath::Clamp(RelativeMoveSpeed / 600.0f, 0.0f, 1.0f);
		FVector RelativeMoveDirection = RelativeLocalVelocity.GetSafeNormal();

		//We need to make the enemy reload for this we need to know the ammo count and if we need to reload.
		float AmmoPercent = (float)Weapon->getCurrentMagCount() / (float)Weapon->getMaxMagCount();
		Enemy->setAmmoPercent(AmmoPercent);
		//UE_LOG(LogTemp, Warning, TEXT("Current Mag Count: %i"), Weapon->getCurrentMagCount());
		//UE_LOG(LogTemp, Warning, TEXT("Max Mag Count: %i"), Weapon->getMaxMagCount());
		
		bool bNeedToReload;
		if (Weapon->getCurrentMagCount() <= 0)
		{
			bNeedToReload = true;
		}

		else
		{
			bNeedToReload = false;
		}

		FVector ObservationDir;
		if (Enemy->getSeePlayer())
		{
			ObservationDir = RelativeDir;
		}
		else
		{
			ObservationDir = FVector(1.0f, 0.0f, 0.0f);

			RelativeMoveDirection = FVector(0.0f, 0.0f, 0.0f); // Use zero here for movement
			NormalizedMoveSpeed = 0.0f;
			bNeedToReload = false;
			Enemy->setIsAimed(false);
		}

		
		//Spline following observations
		ObservationMap.Add(TEXT("Location"), ULearningAgentsObservations::MakeLocationAlongSplineObservation(InObservationObject, InteractorSplineComponent, NormalisedDistance, ActorTransform));
		ObservationMap.Add(TEXT("Direction"), ULearningAgentsObservations::MakeDirectionAlongSplineObservation(InObservationObject, InteractorSplineComponent, InputKey, ActorTransform));
		ObservationMap.Add(TEXT("Velocity"), ULearningAgentsObservations::MakeVelocityObservation(InObservationObject, Enemy->GetVelocity()));
		ObservationMap.Add(TEXT("LookAhead"), ULearningAgentsObservations::MakeDirectionObservation(InObservationObject, LocalFutureDir));
	
		//Player seeing observations
		ObservationMap.Add(TEXT("PlayerDirection"), ULearningAgentsObservations::MakeDirectionObservation(InObservationObject, ObservationDir));
		ObservationMap.Add(TEXT("IsPlayerSeen"), ULearningAgentsObservations::MakeBoolObservation(InObservationObject, Enemy->getSeePlayer()));

		//Firing weapons observations
		ObservationMap.Add(TEXT("WeaponCooldown"), ULearningAgentsObservations::MakeFloatObservation(InObservationObject, Weapon->getCoolDown()));
		ObservationMap.Add(TEXT("IsAimedAtTarget"), ULearningAgentsObservations::MakeBoolObservation(InObservationObject, Enemy->getIsAimed()));
		ObservationMap.Add(TEXT("TargetRelativeDirection"), ULearningAgentsObservations::MakeDirectionObservation(InObservationObject, RelativeMoveDirection));
		ObservationMap.Add(TEXT("TargetRelativeSpeed"), ULearningAgentsObservations::MakeFloatObservation(InObservationObject, NormalizedMoveSpeed));
		ObservationMap.Add(TEXT("AmmoPercentage"), ULearningAgentsObservations::MakeFloatObservation(InObservationObject, Enemy->getAmmoPercent()));
		ObservationMap.Add(TEXT("DoesNeedToReload"), ULearningAgentsObservations::MakeBoolObservation(InObservationObject, bNeedToReload));

		OutObservationObjectElement = ULearningAgentsObservations::MakeStructObservation(InObservationObject, ObservationMap);
	}
	
}

//This where we specify which actions our NPC is able to do.
void UEnemyInteractor::SpecifyAgentAction_Implementation(FLearningAgentsActionSchemaElement& OutActionSchemaElement, ULearningAgentsActionSchema* InActionSchema)
{
	//UE_LOG(LogTemp, Error, TEXT("Specifying Agent"));
	TMap<FName, FLearningAgentsActionSchemaElement> ActionMap;

	//Forward input is a float action with 0.0f to 1.0f.
	//For the time being the NPC can only run forward.
	ActionMap.Add(TEXT("ForwardInput"), ULearningAgentsActions::SpecifyFloatAction(InActionSchema));

	//Turn input is -1.0f to 1.0f; -ve is left +ve is right.
	ActionMap.Add(TEXT("TurnInput"), ULearningAgentsActions::SpecifyFloatAction(InActionSchema));

	TArray<float> PriorProbabilities;
	ActionMap.Add(TEXT("ShootAction"), ULearningAgentsActions::SpecifyFloatAction(InActionSchema));
	ActionMap.Add(TEXT("ReloadAction"), ULearningAgentsActions::SpecifyFloatAction(InActionSchema));

	OutActionSchemaElement = ULearningAgentsActions::SpecifyStructAction(InActionSchema, ActionMap);
}

void UEnemyInteractor::PerformAgentAction_Implementation(const ULearningAgentsActionObject* InActionObject, const FLearningAgentsActionObjectElement& InActionObjectElement, const int32 AgentId)
{
	setInteractorAgentID(AgentId);
	AMLEnemyBase* Enemy = Cast<AMLEnemyBase>(GetAgent(AgentId));
	AWeaponBase* Weapon = Enemy->getWeapon();

	if (Enemy)
	{
		TMap<FName, FLearningAgentsActionObjectElement> ActionObjectMap;
		float ForwardValue;
		float TurnValue;
		float TurnSensitivity = 720.0f;
		float ShootValue;
		float ReloadValue;
		bool bShooting = false;
		bool bReloading = false;

		
		////We are retrieving the actions that we are able to do and their values.
		ULearningAgentsActions::GetStructAction(ActionObjectMap, InActionObject, InActionObjectElement);
		ULearningAgentsActions::GetFloatAction(ForwardValue ,InActionObject, ActionObjectMap[TEXT("ForwardInput")]); //Store the value of the Forward input that we retrieved from the struct into a float.
		ULearningAgentsActions::GetFloatAction(TurnValue, InActionObject, ActionObjectMap[TEXT("TurnInput")]);
		ULearningAgentsActions::GetFloatAction(ShootValue, InActionObject, ActionObjectMap[TEXT("ShootAction")]);
		ULearningAgentsActions::GetFloatAction(ReloadValue, InActionObject, ActionObjectMap[TEXT("ReloadAction")]);
		
		//UE_LOG(LogTemp, Warning, TEXT("Turn value: %f"), TurnValue);
		Enemy->setTurnValue(TurnValue);
		float RotationChange = TurnValue * TurnSensitivity * GetWorld()->GetDeltaSeconds();
		FRotator CurrentRot = Enemy->GetActorRotation();
		FRotator TargetRot = CurrentRot;
		TargetRot.Yaw += RotationChange;
		TargetRot.Normalize();
		FRotator SmoothedRotation = FMath::RInterpConstantTo(CurrentRot, TargetRot, GetWorld()->GetDeltaSeconds(), TurnSensitivity);
		Enemy->SetActorRotation(TargetRot);
		Enemy->setEnemyShootValue(ShootValue);
		Enemy->setEnemyReloadValue(ReloadValue);

		if (Weapon->getCurrentAmmoReserve() <= 0)
		{
			// You can even 'teleport' ammo into their inventory here
			Weapon->setCurrentAmmoReserve(999);
		}

		

		
		if (ActionObjectMap.Contains(TEXT("ReloadAction")) && ActionObjectMap.Contains(TEXT("ShootAction")))
		{
			if (ShootValue > 0.5f)
			{
				bShooting = true;
			}

			if (ReloadValue > 0.5f)
			{
				bReloading = true;
			}
		}

		else
		{
			UE_LOG(LogTemp, Error, TEXT("Actions dont exist"));
		}
		
		if (Enemy->getSeePlayer() || Enemy->GetVelocity().Size() > 10.0f)
		{
			Enemy->setIdleTimer(0.0f);
		}
		else
		{
			// If they are standing still and see nothing, increase the timer
			float CurrentTime = Enemy->getIdleTimer();
			Enemy->setIdleTimer(CurrentTime + GetWorld()->GetDeltaSeconds());
		}


		if (Enemy->getSeePlayer())
		{
			

			if (bShooting == true)
			{
				if (ASniperRifle* Sniper = Cast<ASniperRifle>(Weapon))
				{
					if(Sniper->getCoolDown() <= 0.0f) { Sniper->SniperFire(); }
					
				}
			}

			if (bReloading == true && Weapon->getReloading() == false)
			{
				Weapon->Reload();
			}
			//UE_LOG(LogTemp, Warning, TEXT("Turn Value: %f"), TurnValue);
			
		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("Agent %d - Forward: %f, Turn: %f"), AgentId, ForwardValue, TurnValue);
			ForwardValue = FMath::Max(0.0f, 1.0f);
			
			USplineComponent* Spline = InteractorSplineComponent;

			// 2. Find where THIS agent is on the spline right now
			FVector MyLocation = Enemy->GetActorLocation();
			float ClosestKey = Spline->FindInputKeyClosestToWorldLocation(MyLocation);

			// 3. Get the direction the track is going at THIS specific spot
			FVector TargetDirection = Spline->GetDirectionAtSplineInputKey(ClosestKey, ESplineCoordinateSpace::World);

			// 4. Convert that direction into a Rotator
			TargetRot = TargetDirection.Rotation();

			// 5. Apply the rotation smoothly
			CurrentRot = Enemy->GetActorRotation();
			FRotator NewRot = FMath::RInterpTo(CurrentRot, TargetRot, GetWorld()->GetDeltaSeconds(), 10.0f);

			// Only change the Yaw (don't tilt them up or down)
			NewRot.Pitch = 0.0f;
			NewRot.Roll = 0.0f;

			Enemy->SetActorRotation(NewRot);

			//Move the character forward and turn them using the character classes regular functions.
			Enemy->AddMovementInput(Enemy->GetActorForwardVector(), ForwardValue);
			
		}
	}
}

void UEnemyInteractor::setInteractorSplineComponent(USplineComponent* tempSpline)
{
	InteractorSplineComponent = tempSpline;
}

void UEnemyInteractor::setInteractorAgentID(int32 AgentIDStore)
{
	InteractorAgentID = AgentIDStore;
}

int32 UEnemyInteractor::getInteractorAgentID()
{
	return InteractorAgentID;
}
