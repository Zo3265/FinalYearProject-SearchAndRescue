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
	ObservationMap.Add(TEXT("SawPlayer"), ULearningAgentsObservations::SpecifyBoolObservation(InObservationSchema));
	//One observation will be the location along the spline which will be used to make the enemy patrol.
	ObservationMap.Add(TEXT("Location"), ULearningAgentsObservations::SpecifyLocationAlongSplineObservation(InObservationSchema));

	//Another will be the direction along the spline.
	ObservationMap.Add(TEXT("Direction"), ULearningAgentsObservations::SpecifyDirectionAlongSplineObservation(InObservationSchema));

	//We need a velocity observation to tell the enemy to increase its distance along the spline and reward it for doing so.
	ObservationMap.Add(TEXT("Velocity"), ULearningAgentsObservations::SpecifyVelocityObservation(InObservationSchema));
	ObservationMap.Add(TEXT("LookAhead"), ULearningAgentsObservations::SpecifyDirectionObservation(InObservationSchema));

	//Observations needed to see the player
	ObservationMap.Add(TEXT("PlayerLastKnownLocation"), ULearningAgentsObservations::SpecifyLocationObservation(InObservationSchema));
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
	InteractorSplineComponent = Enemy->GetSplineController()->getSpline();
	ACharacter* EnemyChar = Cast<ACharacter>(Enemy);
	USkeletalMeshComponent* EnemyMesh = EnemyChar->GetMesh();

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

		float DistanceToTarget = FVector::Dist(ActorLocation, PlayerLoc);
		bool bInRange = DistanceToTarget < 1500.0f;

		float VisionDot = FVector::DotProduct(ActorForward, PlayerDir);
		bool bInVisionCone = VisionDot > 0.707f;

		bool bHasLineOfSight = false;
		FColor FinalLineColor = FColor::White; // Default to white (out of range/cone)

		if (bInRange && bInVisionCone)
		{
			FHitResult Hit;
			FCollisionQueryParams Params;
			Params.AddIgnoredActor(Enemy);
			Params.AddIgnoredActor(Weapon);

			TArray<UPrimitiveComponent*> AttachedComponents;
			Enemy->GetComponents(AttachedComponents);
			for (UPrimitiveComponent* Comp : AttachedComponents)
			{
				Params.AddIgnoredComponent(Comp);
			}

			// Perform Trace
			bool bBlocked = GetWorld()->LineTraceSingleByChannel(Hit, ActorLocation + FVector(0, 0, 60), PlayerLoc, ECC_Visibility, Params);

			// Initial LOS logic
			bHasLineOfSight = !TargetToFollow->IsHidden() && (!bBlocked || (Hit.GetActor() == TargetToFollow));

			// Height Check Override
			if (PlayerLoc.Z < (ActorLocation.Z - 50.0f) && VisionDot > 0.9f)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Red, FString::Printf(TEXT("Height override.")));
				bHasLineOfSight = false;
			}

			//DEBUG LOGIC
			// Green = Perfect (In cone, in range, clear shot)
			// Blue = Target is under the floor (Height Check caught it)
			// Red  = Blocked by wall/floor
			

			
		}

		if (bHasLineOfSight)
		{
			// If we see them, reset the timer to max
			Enemy->VisionTimer = Enemy->VisionRetentionDuration;
			Enemy->setSeePlayer(true);
			Enemy->setSawPlayer(true);
			Enemy->PlayerLastKnownLocation = PlayerLoc;
			Enemy->setCurrentState(EAgentState::SeeingPlayer);
		}
		else
		{
			// If we DON'T see them, count down
			if (Enemy->VisionTimer > 0.0f)
			{
				Enemy->VisionTimer -= GetWorld()->GetDeltaSeconds();
				Enemy->setSeePlayer(true); // Still "True" because of the buffer!
				Enemy->setCurrentState(EAgentState::SeeingPlayer);
			}
			else
			{
				Enemy->setSeePlayer(false); // Finally "False" after 0.5s
				Enemy->setCurrentState(EAgentState::Patrolling);
			}
		}


		//if (bHasLineOfSight) {
		//	FinalLineColor = FColor::Green;
		//}
		//else if (PlayerLoc.Z < (ActorLocation.Z - 50.0f)) {
		//	FinalLineColor = FColor::Blue;
		//}
		//else {
		//	FinalLineColor = FColor::Red;
		//}

		//DrawDebugLine(
		//	GetWorld(),
		//	ActorLocation + FVector(0, 0, 60),
		//	PlayerLoc,
		//	FinalLineColor,
		//	false,
		//	0.1f,
		//	0,
		//	2.0f
		//);

		//Chasing the player when losing line of sight logic
		if (Enemy->getCurrentState() != EAgentState::SeeingPlayer)
		{
			if (Enemy->getSeePlayer() == false && Enemy->getSawPlayer() == true && Enemy->FindingTrack == false)
			{
				//UE_LOG(LogTemp, Error, TEXT("Agend %d: Chasing Player"), AgentId);
				Enemy->setCurrentState(EAgentState::Chasing);
				//Enemy->LastKnownLocDist = FVector::Dist(ActorLocation, Enemy->PlayerLastKnownLocation);
				//UE_LOG(LogTemp, Error, TEXT("Last Known location: %s"), *Enemy->PlayerLastKnownLocation.ToString());
				//UE_LOG(LogTemp, Error, TEXT("Last Known location distance: %f"), Enemy->LastKnownLocDist);

				/*if (Enemy->LastKnownLocDist <= 100.0f)
				{
					UE_LOG(LogTemp, Error, TEXT("Agend %d: Couldn't find the player again"), AgentId);
					Enemy->FindingTrack = true;
					Enemy->setCurrentState(EAgentState::Patrolling);
				}*/
			}

			else
			{
				Enemy->setCurrentState(EAgentState::Patrolling);
			}
		}
		

		

		if (EnemyMesh)
		{
			//Same code as the one from my weapon base class. We are just checking to make sure the socket that spawns the bullets is aligned with the player.
			FVector FaceLocation = EnemyMesh->GetSocketLocation(TEXT("FaceShoot"));
			FVector AimDirection = EnemyChar->GetControlRotation().Vector();
			FVector MuzzleLocation = Weapon->getMesh()->GetSocketLocation(TEXT("BulletSpawn"));

			FVector TargetLocation = TargetToFollow->GetActorLocation();
			FVector PointToTargetDir = (TargetLocation - FaceLocation).GetSafeNormal();

			//The actual alignment check
			float GunDot = FVector::DotProduct(AimDirection, PointToTargetDir);
			bool bGunAligned = false;

			if (GunDot > 0.99f)
			{
				bGunAligned = true;
			}


			bool bHasClearShot = false;
			FHitResult AimHit;
			FColor AimLineColour = FColor::White;

			if (bInRange && bGunAligned)
			{
				FCollisionQueryParams Params;
				Params.AddIgnoredActor(Enemy);
				Params.AddIgnoredActor(Weapon);

				bool bBlocked = GetWorld()->LineTraceSingleByChannel(AimHit, MuzzleLocation, TargetLocation, ECC_Visibility, Params);
				bHasClearShot = !TargetToFollow->IsHidden() && (!bBlocked || (AimHit.GetActor() == TargetToFollow));

				if (bHasClearShot)
				{
					AimLineColour = FColor::Green;
					Enemy->setIsAimed(true);
				}
				else
				{
					AimLineColour = FColor::Red;
					Enemy->setIsAimed(false);
				}

				// Draw the line from the MUZZLE to the TARGET to visualize the actual bullet trajectory
				
			}

			else
			{
				Enemy->setIsAimed(false);
			}

			DrawDebugLine(GetWorld(), MuzzleLocation, TargetLocation, AimLineColour, false, 0.1f, 0, 4.0f);
		}
		


		//I want the enemies to lead their shots so we need to know the players speed and direction.
		//Similar math as before but with velocities instead.
		FVector RelativeWorldVelocity = PlayerVelocity - ActorVelocity; //The velocity of the player relative to the enemy in world space.
		FVector RelativeLocalVelocity = ActorTransform.InverseTransformVectorNoScale(RelativeWorldVelocity); //Converted to local space in order for the agents to know if the player is left or right relative to them.

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
			NormalisedDistance = 0.0f;
			LocalFutureDir = FVector(1, 0, 0);
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
		ObservationMap.Add(TEXT("PlayerLastKnownLocation"), ULearningAgentsObservations::MakeLocationObservation(InObservationObject, Enemy->PlayerLastKnownLocation));
		ObservationMap.Add(TEXT("PlayerDirection"), ULearningAgentsObservations::MakeDirectionObservation(InObservationObject, ObservationDir));
		ObservationMap.Add(TEXT("IsPlayerSeen"), ULearningAgentsObservations::MakeBoolObservation(InObservationObject, Enemy->getSeePlayer()));
		ObservationMap.Add(TEXT("SawPlayer"), ULearningAgentsObservations::MakeBoolObservation(InObservationObject, Enemy->getSawPlayer()));

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
	InteractorSplineComponent = Enemy->GetSplineController()->getSpline();
	AWeaponBase* Weapon = Enemy->getWeapon();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	float DeltaTime = GetWorld()->GetDeltaSeconds();

	if (Enemy)
	{
		TMap<FName, FLearningAgentsActionObjectElement> ActionObjectMap;
		float ForwardValue;
		float TurnValue;
		float TurnSensitivity = 1024.0f;
		float ShootValue;
		float ReloadValue;
		bool bShooting = false;
		bool bReloading = false;

		/*if (Enemy->getCurrentState() == EAgentState::Patrolling)
		{
			UE_LOG(LogTemp, Warning, TEXT("Patrolling"));
		}

		else if (Enemy->getCurrentState() == EAgentState::SeeingPlayer)
		{
			UE_LOG(LogTemp, Warning, TEXT("SeeingPlayer"));
		}

		else if (Enemy->getCurrentState() == EAgentState::Chasing)
		{
			UE_LOG(LogTemp, Warning, TEXT("Chasing"));
		}*/

		////We are retrieving the actions that we are able to do and their values.
		ULearningAgentsActions::GetStructAction(ActionObjectMap, InActionObject, InActionObjectElement);
		ULearningAgentsActions::GetFloatAction(ForwardValue ,InActionObject, ActionObjectMap[TEXT("ForwardInput")]); //Store the value of the Forward input that we retrieved from the struct into a float.
		ULearningAgentsActions::GetFloatAction(TurnValue, InActionObject, ActionObjectMap[TEXT("TurnInput")]);
		ULearningAgentsActions::GetFloatAction(ShootValue, InActionObject, ActionObjectMap[TEXT("ShootAction")]);
		ULearningAgentsActions::GetFloatAction(ReloadValue, InActionObject, ActionObjectMap[TEXT("ReloadAction")]);
		
		//UE_LOG(LogTemp, Warning, TEXT("Turn value: %f"), TurnValue);
		//TurnValue = FMath::Clamp(TurnValue, -1.0f, 1.0f);
		Enemy->setTurnValue(TurnValue);
		float RotationChange = TurnValue * TurnSensitivity * GetWorld()->GetDeltaSeconds();
		FRotator CurrentRot = Enemy->GetActorRotation();
		FRotator TargetRot = CurrentRot;
		TargetRot.Yaw += RotationChange;
		TargetRot.Normalize();
		FRotator SmoothedRotation = FMath::RInterpConstantTo(CurrentRot, TargetRot, GetWorld()->GetDeltaSeconds(), TurnSensitivity);
		//Enemy->SetActorRotation(TargetRot);

		ShootValue = FMath::Clamp(ShootValue, 0.0f, 1.0f);
		ReloadValue = FMath::Clamp(ReloadValue, 0.0f, 1.0f);
		
		Enemy->setEnemyShootValue(ShootValue);
		Enemy->setEnemyReloadValue(ReloadValue);

		if (Weapon->getCurrentAmmoReserve() <= 0)
		{
			Weapon->setCurrentAmmoReserve(999);
		}

		

		
		if (ActionObjectMap.Contains(TEXT("ReloadAction")) && ActionObjectMap.Contains(TEXT("ShootAction")))
		{
			if (ShootValue >= 0.45f)
			{
				bShooting = true;
			}

			if (ReloadValue >= 0.45f)
			{
				bReloading = true;
			}
		}

		else
		{
			UE_LOG(LogTemp, Error, TEXT("Actions dont exist"));
		}

		float FinalTurnInput = TurnValue;
		float FinalForwardInput = ForwardValue; // Keep the brain's forward intent

		if (Enemy->getCurrentState() == EAgentState::SeeingPlayer)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Seeing player"));
			// 1. COMBAT AUTO-PILOT
			// Force Stop
			Enemy->GetMovementComponent()->StopMovementImmediately();
			Enemy->GetCharacterMovement()->Velocity = FVector::ZeroVector;
			FinalForwardInput = 0.0f;

			//100% AUTO PILOT
			// Calculate Perfect Aim
			FVector MuzzleLoc = Weapon->getMesh()->GetSocketLocation(TEXT("BulletSpawn"));
			FVector TargetLoc; 
			if (bTraining)
			{
				TargetLoc = Enemy->getTrainingTarget()->GetActorLocation();
			} 

			else
			{
				TargetLoc = PlayerPawn->GetActorLocation();
			}
			FRotator AimRot = (TargetLoc - MuzzleLoc).Rotation();

			
			// Smoothly rotate toward target
			//FRotator CurrentRotShoot = Enemy->GetActorRotation();
			//FRotator NewRot = FMath::RInterpTo(CurrentRotShoot, AimRot, GetWorld()->GetDeltaSeconds(), 50.0f);

			//NewRot.Pitch = 0.0f; // Keep actor upright
			//NewRot.Roll = 0.0f;
			//Enemy->SetActorRotation(NewRot);



			float BrainYawChange = TurnValue * TurnSensitivity * DeltaTime;
			FRotator BrainTargetRot = Enemy->GetActorRotation();
			BrainTargetRot.Yaw += BrainYawChange;





			// WEANING MIXTURE: Blend the rotations 50/50
			// 0.0 = Pure Brain, 1.0 = Pure Auto-Pilot math
			FRotator BlendedRot = FMath::Lerp(BrainTargetRot, AimRot, 0.5f);

			// Apply via Interp to keep it clean, but much slower (strength reduced to 4.0f)
			FRotator CurrentRotShoot = Enemy->GetActorRotation();
			FRotator NewRot = FMath::RInterpTo(CurrentRotShoot, BlendedRot, DeltaTime, 40.0f);

			NewRot.Pitch = 0.0f;
			NewRot.Roll = 0.0f;
			Enemy->SetActorRotation(NewRot);

			// If we are perfectly aimed, force the shoot value to 1.0
			/*if (Enemy->getIsAimed()) { 
				ShootValue = 1.0f; 
			}
			*/

			//NO ASISTANCE
			/*float BrainYawChange = FinalTurnInput * TurnSensitivity * DeltaTime;
			CurrentRot = Enemy->GetActorRotation();
			CurrentRot.Yaw = FRotator::NormalizeAxis(CurrentRot.Yaw + BrainYawChange);
			Enemy->SetActorRotation(CurrentRot);*/
		}

		else if (Enemy->getCurrentState() == EAgentState::Chasing)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Chasing player"));
			FVector SearchTarget = Enemy->PlayerLastKnownLocation;
			FVector CurrentLoc = Enemy->GetActorLocation();

			// 2. Proximity and Direction Calculation
			float DistanceToTarget = FVector::Dist(CurrentLoc, SearchTarget);
			FVector MoveDirection = (SearchTarget - CurrentLoc).GetSafeNormal();
			FRotator FaceTargetRot = MoveDirection.Rotation();




			// 3. FULL OVERRIDE ROTATION (No Weaning / No Brain Input)
			// We use a high Interp speed (25.0f) to snap their heading directly to the memory vector
			CurrentRot = Enemy->GetActorRotation();
			FRotator NewRot = FMath::RInterpTo(CurrentRot, FaceTargetRot, GetWorld()->GetDeltaSeconds(), 25.0f);

			NewRot.Pitch = 0.0f; // Keep the character capsule strictly vertical
			NewRot.Roll = 0.0f;
			Enemy->SetActorRotation(NewRot);

			//// 4. FULL OVERRIDE THROTTLE
			//// Smooth deceleration as they get close so they don't slide past the finish line
			//float ArrivalBrake = FMath::Clamp(DistanceToTarget / 150.0f, 0.0f, 1.0f);

			//// Force them to sprint (1.0f) when far, scaling down smoothly down to 0.0f at the target
			//FinalForwardInput = 1.0f * ArrivalBrake;

			//// Apply the physical forward movement input
			//Enemy->AddMovementInput(Enemy->GetActorForwardVector(), FinalForwardInput);


			//float BrainYawChange = TurnValue * TurnSensitivity * DeltaTime;
			//FRotator BrainTargetRot = Enemy->GetActorRotation();
			//BrainTargetRot.Yaw += BrainYawChange;

			//// Mix the targets 50/50: 0.5 = Brain, 0.5 = Perfect Auto-Pilot math
			//FRotator BlendedRot = FMath::Lerp(BrainTargetRot, FaceTargetRot, 0.5f);

			//// Apply via Interp but drop the strength from 25.0f to 4.0f so it is a "gentle guide"
			//CurrentRot = Enemy->GetActorRotation();
			//FRotator NewRot = FMath::RInterpTo(CurrentRot, BlendedRot, DeltaTime, 4.0f);

			//NewRot.Pitch = 0.0f; // Keep the character capsule strictly vertical
			//NewRot.Roll = 0.0f;
			//Enemy->SetActorRotation(NewRot);

			//// --- 4. BLENDED THROTTLE WEANING ---
			//// Smooth deceleration curve remains to protect from physics overshooting
			//float ArrivalBrake = FMath::Clamp(DistanceToTarget / 150.0f, 0.0f, 1.0f);

			//// Instead of forcing 1.0f, we now let the brain press the gas (ForwardValue) 
			//// but scale it by the ArrivalBrake so they still slow down at the finish line.
			//// We clamp it to Max(0.0f) to prevent them from throwing it into reverse during a hunt.
			//FinalForwardInput = FMath::Max(0.0f, ForwardValue) * ArrivalBrake;

			//// Apply the physical forward movement input
			//Enemy->AddMovementInput(Enemy->GetActorForwardVector(), FinalForwardInput);

			if (DistanceToTarget <= 100.0f)
			{
				Enemy->GetMovementComponent()->StopMovementImmediately();
				Enemy->GetCharacterMovement()->Velocity = FVector::ZeroVector;
				Enemy->FindingTrack = true;
				Enemy->setCurrentState(EAgentState::Patrolling);
			}

			else if (DistanceToTarget >= 2500.0f)
			{
				Enemy->FindingTrack = true;
				Enemy->setCurrentState(EAgentState::Patrolling);
			}

			//NO ASSISSTANCE
			float ArrivalBrake = FMath::Clamp(DistanceToTarget / 150.0f, 0.0f, 1.0f);

			// Turn control is 100% driven by the brain
			/*float BrainYawChange = FinalTurnInput * TurnSensitivity * DeltaTime;
			CurrentRot = Enemy->GetActorRotation();
			CurrentRot.Yaw = FRotator::NormalizeAxis(CurrentRot.Yaw + BrainYawChange);
			Enemy->SetActorRotation(CurrentRot);*/

			// Gas control is 100% driven by the brain, scaled only by the physical arrival brake
			FinalForwardInput = FMath::Max(0.0f, FinalForwardInput) * ArrivalBrake;
			Enemy->AddMovementInput(Enemy->GetActorForwardVector(), FinalForwardInput);
		}

		else if(Enemy->getCurrentState() == EAgentState::Patrolling)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Following path"));
			//// 2. PATROL AUTO-PILOT
			USplineComponent* Spline = InteractorSplineComponent;
			float ClosestKey = Spline->FindInputKeyClosestToWorldLocation(Enemy->GetActorLocation());
			FVector ClosestSplineLocation = Spline->FindLocationClosestToWorldLocation(Enemy->GetActorLocation(), ESplineCoordinateSpace::World);
			FVector PathDir = Spline->GetDirectionAtSplineInputKey(ClosestKey, ESplineCoordinateSpace::World);
			FRotator IdealRot = PathDir.Rotation();
			float DistanceToPath = FVector::Dist(Enemy->GetActorLocation(), ClosestSplineLocation);


			if (Enemy->FindingTrack == true)
			{
				UE_LOG(LogTemp, Warning, TEXT("Agent %d: Returning to path"), AgentId);
				FVector ReturnDir = (ClosestSplineLocation - Enemy->GetActorLocation()).GetSafeNormal();
				FRotator ReturnRot = ReturnDir.Rotation();

				CurrentRot = Enemy->GetActorRotation();
				FRotator NewRot = FMath::RInterpTo(CurrentRot, ReturnRot, DeltaTime, 15.0f); // High strength to snap back
				NewRot.Pitch = 0.0f;
				NewRot.Roll = 0.0f;
				Enemy->SetActorRotation(NewRot);
				

				// Force a stable forward speed to get them home quickly
				FinalForwardInput = 1.0f;
				Enemy->AddMovementInput(Enemy->GetActorForwardVector(), FinalForwardInput);

				if (DistanceToPath <= 100.0f)
				{
					UE_LOG(LogTemp, Warning, TEXT("Agent %d: Made it back to the path"), AgentId);
					Enemy->FindingTrack = false;
					Enemy->setSawPlayer(false);
				}
			}
			


			///*AUTO PILOT
			//Smoothly rotate to follow the track
			//FRotator CurrentRotPatrol = Enemy->GetActorRotation();
			//FRotator NewRot = FMath::RInterpTo(CurrentRotPatrol, IdealRot, GetWorld()->GetDeltaSeconds(), 10.0f);

			//NewRot.Pitch = 0.0f;
			//NewRot.Roll = 0.0f;
			//Enemy->SetActorRotation(NewRot);

			// Use the brain's forward value (or force 1.0 to get them moving)
			//FinalForwardInput = FMath::Max(0.5f, ForwardValue);

			// 3. APPLY PHYSICAL MOVEMENT
			//Enemy->AddMovementInput(Enemy->GetActorForwardVector(), FinalForwardInput);*/



			////50/50 TRAINING
			//// Calculate what the BRAIN wants to do on the path
			//float BrainYawChange = TurnValue * TurnSensitivity * DeltaTime;
			//FRotator BrainTargetRot = Enemy->GetActorRotation();
			//BrainTargetRot.Yaw += BrainYawChange;

			//// WEANING MIXTURE: 50% Brain target, 50% Spline target
			//FRotator BlendedRot = FMath::Lerp(BrainTargetRot, IdealRot, 0.5f);

			//FRotator CurrentRotPatrol = Enemy->GetActorRotation();
			//FRotator NewRot = FMath::RInterpTo(CurrentRotPatrol, BlendedRot, DeltaTime, 2.0f); // Softened to 2.0f

			//NewRot.Pitch = 0.0f;
			//NewRot.Roll = 0.0f;
			//Enemy->SetActorRotation(NewRot);

			//// Forward movement weaning: Let the brain control the gas fully now
			//FinalForwardInput = FMath::Max(0.0f, ForwardValue);
			//Enemy->AddMovementInput(Enemy->GetActorForwardVector(), FinalForwardInput);

			else
			{
				//NO ASSISSTANCE
				//UE_LOG(LogTemp, Warning, TEXT("Agent %d: Standard patrolling"), AgentId);

				FRotator CurrentRotPatrol = Enemy->GetActorRotation();
				FRotator NewRot = FMath::RInterpTo(CurrentRotPatrol, IdealRot, GetWorld()->GetDeltaSeconds(), 10.0f);

				NewRot.Pitch = 0.0f;
				NewRot.Roll = 0.0f;
				Enemy->SetActorRotation(NewRot);

				// Gas control is 100% driven by the brain. Forward-only clamp remains to block reverse exploits.
				FinalForwardInput = FMath::Max(0.0f, FinalForwardInput);
				Enemy->AddMovementInput(Enemy->GetActorForwardVector(), FinalForwardInput);
			}
			
		}


		if (ShootValue >= 0.45f && Enemy->getIsAimed())
		{
			if (ASniperRifle* Sniper = Cast<ASniperRifle>(Weapon))
			{
				Sniper->SniperFire();

			}
		}
		
		if (ReloadValue >= 0.45f && Weapon->getReloading() == false)
		{
			Weapon->Reload();
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
