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
	
	//One observation will be the location along the spline which will be used to make the enemy patrol.
	ObservationMap.Add(TEXT("Location"), ULearningAgentsObservations::SpecifyLocationAlongSplineObservation(InObservationSchema));

	//Another will be the direction along the spline.
	ObservationMap.Add(TEXT("Direction"), ULearningAgentsObservations::SpecifyDirectionAlongSplineObservation(InObservationSchema));

	//We need a velocity observation to tell the enemy to increase its distance along the spline and reward it for doing so.
	ObservationMap.Add(TEXT("Velocity"), ULearningAgentsObservations::SpecifyVelocityObservation(InObservationSchema));

	//ObservationMap.Add(TEXT("PlayerLocation"), ULearningAgentsObservations::SpecifyLocationObservation(InObservationSchema));
	ObservationMap.Add(TEXT("PlayerDirection"), ULearningAgentsObservations::SpecifyDirectionObservation(InObservationSchema));
	ObservationMap.Add(TEXT("IsPlayerSeen"), ULearningAgentsObservations::SpecifyBoolObservation(InObservationSchema));

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
	AActor* OBSActor = Cast<AActor>(OBSAgent);
	AMLEnemyBase* Enemy = Cast<AMLEnemyBase>(OBSAgent);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);

	//USplineComponent* SplineComp = OBSActor->FindComponentByClass<USplineComponent>();
	TMap<FName, FLearningAgentsObservationObjectElement> ObservationMap;
	AActor* TargetToFollow = nullptr;
	
	if(OBSActor)
	{
		if (bTraining == true)
		{
			TargetToFollow = Enemy->getTrainingTarget();
		}

		else
		{
			TargetToFollow = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		}


		FVector ActorLocation = OBSActor->GetActorLocation();
		FVector ActorForward = OBSActor->GetActorForwardVector();

		float InputKey = InteractorSplineComponent->FindInputKeyClosestToWorldLocation(ActorLocation);
		float RawDistance = InteractorSplineComponent->GetDistanceAlongSplineAtSplineInputKey(InputKey);

		float NormalisedDistance = RawDistance / InteractorSplineComponent->GetSplineLength();
		FTransform ActorTransform = OBSActor->GetActorTransform();

		FVector PlayerLoc = TargetToFollow->GetActorLocation();
		FVector PlayerDir = (PlayerLoc - ActorLocation).GetSafeNormal();
		FVector RelativeDir = ActorTransform.InverseTransformVectorNoScale(PlayerDir);
		float PlayerAlignment = FVector::DotProduct(ActorForward, PlayerDir);
		//UE_LOG(LogTemp, Warning, TEXT("PlayerAlignment: %f"), PlayerAlignment);

		//According to Gemini this value means that the agents have a 45 degree fov.
		//if (PlayerAlignment >= 0.707f)
		//{

		//	//Setting up a raycast so that the agents cant see through walls
		//	FHitResult HitResult;
		//	FCollisionQueryParams CollisionParams;
		//	CollisionParams.AddIgnoredActor(OBSActor);

		//	bool bHit = GetWorld()->LineTraceSingleByChannel(
		//		HitResult,
		//		ActorLocation + FVector(0, 0, 60),
		//		PlayerLoc,
		//		ECC_Visibility,
		//		CollisionParams
		//	);

		//	if (!bHit || (HitResult.GetActor() == UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
		//	{
		//		Enemy->setSeePlayer(true);
		//		//UE_LOG(LogTemp, Warning, TEXT("Agent:%d can see the player with PlayerAlignment: %f"), AgentId, PlayerAlignment);
		//	}

		//	else
		//	{
		//		Enemy->setSeePlayer(false);
		//	}

		//}

		//else
		//{
		//	Enemy->setSeePlayer(false);
		//}
		
		ObservationMap.Add(TEXT("Location"), ULearningAgentsObservations::MakeLocationAlongSplineObservation(InObservationObject, InteractorSplineComponent, NormalisedDistance, ActorTransform));
		ObservationMap.Add(TEXT("Direction"), ULearningAgentsObservations::MakeDirectionAlongSplineObservation(InObservationObject, InteractorSplineComponent, InputKey, ActorTransform));
		ObservationMap.Add(TEXT("Velocity"), ULearningAgentsObservations::MakeVelocityObservation(InObservationObject, OBSActor->GetVelocity()));
		//ObservationMap.Add(TEXT("PlayerLocation"), ULearningAgentsObservations::MakeLocationObservation(InObservationObject,PlayerPawn->GetActorLocation()));
		ObservationMap.Add(TEXT("PlayerDirection"), ULearningAgentsObservations::MakeDirectionObservation(InObservationObject, RelativeDir));
		ObservationMap.Add(TEXT("IsPlayerSeen"), ULearningAgentsObservations::MakeBoolObservation(InObservationObject, Enemy->getSeePlayer()));

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

	OutActionSchemaElement = ULearningAgentsActions::SpecifyStructAction(InActionSchema, ActionMap);
}

void UEnemyInteractor::PerformAgentAction_Implementation(const ULearningAgentsActionObject* InActionObject, const FLearningAgentsActionObjectElement& InActionObjectElement, const int32 AgentId)
{
	setInteractorAgentID(AgentId);
	AMLEnemyBase* Enemy = Cast<AMLEnemyBase>(GetAgent(AgentId));

	if (Enemy)
	{
		TMap<FName, FLearningAgentsActionObjectElement> ActionObjectMap;
		float ForwardValue;
		float TurnValue;
		float TurnSensitivity = 360.0f;
		//FRotator RotationValue;

		////We are retrieving the actions that we are able to do and their values.
		ULearningAgentsActions::GetStructAction(ActionObjectMap, InActionObject, InActionObjectElement);
		ULearningAgentsActions::GetFloatAction(ForwardValue ,InActionObject, ActionObjectMap[TEXT("ForwardInput")]); //Store the value of the Forward input that we retrieved from the struct into a float.
		ULearningAgentsActions::GetFloatAction(TurnValue, InActionObject, ActionObjectMap[TEXT("TurnInput")]);

		float RotationChange = TurnValue * TurnSensitivity * GetWorld()->GetDeltaSeconds();
		FRotator CurrentRot = Enemy->GetActorRotation();
		CurrentRot.Yaw += RotationChange;
		Enemy->SetActorRotation(CurrentRot);


		/*if (Enemy->getSeePlayer() && FMath::Abs(ForwardValue) < 0.1f)
		{
			Enemy->GetMovementComponent()->StopMovementImmediately();
		}
		else
		{*/
			//UE_LOG(LogTemp, Warning, TEXT("Agent %d - Forward: %f, Turn: %f"), AgentId, ForwardValue, TurnValue);

			//ForwardValue = FMath::Clamp(ForwardValue, 0.0f, 1.0f);
			//TurnValue = FMath::Clamp(TurnValue, -1.0f, 1.0f);

			//Move the character forward and turn them using the character classes regular functions.
			Enemy->AddMovementInput(Enemy->GetActorForwardVector(), ForwardValue);
			
		//}
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
