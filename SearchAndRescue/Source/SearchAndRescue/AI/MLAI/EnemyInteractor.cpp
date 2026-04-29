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

	ObservationMap.Add(TEXT("PlayerLocation"), ULearningAgentsObservations::SpecifyLocationObservation(InObservationSchema));
	ObservationMap.Add(TEXT("PlayerDirection"), ULearningAgentsObservations::SpecifyDirectionObservation(InObservationSchema));

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
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);

	//USplineComponent* SplineComp = OBSActor->FindComponentByClass<USplineComponent>();
	TMap<FName, FLearningAgentsObservationObjectElement> ObservationMap;
	
	if(OBSActor)
	{
		
		FVector ActorLocation = OBSActor->GetActorLocation();
		float InputKey = InteractorSplineComponent->FindInputKeyClosestToWorldLocation(ActorLocation);
		float RawDistance = InteractorSplineComponent->GetDistanceAlongSplineAtSplineInputKey(InputKey);
		FVector PlayerLoc = PlayerPawn->GetActorLocation();
		FVector PlayerDir = (PlayerLoc - ActorLocation).GetSafeNormal();

		//UE_LOG(LogTemp, Warning, TEXT("Agent %d - InputKey: %f"), AgentId, InputKey);

		// Normalise by total length.
		float NormalisedDistance = RawDistance / InteractorSplineComponent->GetSplineLength();

		FTransform Transform = OBSActor->GetActorTransform();

		ObservationMap.Add(TEXT("Location"), ULearningAgentsObservations::MakeLocationAlongSplineObservation(InObservationObject, InteractorSplineComponent, NormalisedDistance, Transform));
		ObservationMap.Add(TEXT("Direction"), ULearningAgentsObservations::MakeDirectionAlongSplineObservation(InObservationObject, InteractorSplineComponent, InputKey, Transform));
		ObservationMap.Add(TEXT("Velocity"), ULearningAgentsObservations::MakeVelocityObservation(InObservationObject, OBSActor->GetVelocity()));
		ObservationMap.Add(TEXT("PlayerLocation"), ULearningAgentsObservations::MakeLocationObservation(InObservationObject,PlayerPawn->GetActorLocation()));
		ObservationMap.Add(TEXT("PlayerDirection"), ULearningAgentsObservations::MakeDirectionObservation(InObservationObject, PlayerDir));

		OutObservationObjectElement = ULearningAgentsObservations::MakeStructObservation(InObservationObject, ObservationMap);
	}

	//else
	//{
	//	ObservationMap.Add(TEXT("Location"), ULearningAgentsObservations::MakeLocationAlongSplineObservation(InObservationObject, InteractorSplineComponent, 0.0f, FTransform::Identity));
	//	ObservationMap.Add(TEXT("Direction"), ULearningAgentsObservations::MakeDirectionAlongSplineObservation(InObservationObject, InteractorSplineComponent, 0.0f, FTransform::Identity));

	//	OutObservationObjectElement = ULearningAgentsObservations::MakeStructObservation(InObservationObject, ObservationMap);
	//}
	
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
	ACharacter* Enemy = Cast<ACharacter>(GetAgent(AgentId));

	if (Enemy)
	{
		TMap<FName, FLearningAgentsActionObjectElement> ActionObjectMap;
		float ForwardValue;
		float TurnValue;
		float TurnSensitivity = 10.0f;
		//FRotator RotationValue;

		////We are retrieving the actions that we are able to do and their values.
		ULearningAgentsActions::GetStructAction(ActionObjectMap, InActionObject, InActionObjectElement);
		ULearningAgentsActions::GetFloatAction(ForwardValue ,InActionObject, ActionObjectMap[TEXT("ForwardInput")]); //Store the value of the Forward input that we retrieved from the struct into a float.
		ULearningAgentsActions::GetFloatAction(TurnValue, InActionObject, ActionObjectMap[TEXT("TurnInput")]);
		//ULearningAgentsActions::GetRotationAction(RotationValue, InActionObject, ActionObjectMap[TEXT("TurnInput")]);

		

		if (ActionObjectMap.Contains(TEXT("ForwardInput")) && ActionObjectMap.Contains(TEXT("TurnInput")))
		{
			ULearningAgentsActions::GetFloatAction(ForwardValue, InActionObject, ActionObjectMap[TEXT("ForwardInput")]);
			ULearningAgentsActions::GetFloatAction(TurnValue, InActionObject, ActionObjectMap[TEXT("TurnInput")]);

			float RotationChange = TurnValue * 1080.0f * GetWorld()->GetDeltaSeconds();
			FRotator CurrentRot = Enemy->GetActorRotation();
			CurrentRot.Yaw += RotationChange;
			//UE_LOG(LogTemp, Warning, TEXT("Agent %d - Forward: %f, Turn: %f"), AgentId, ForwardValue, TurnValue);

			ForwardValue = FMath::Clamp(ForwardValue, 0.0f, 1.0f);
			//TurnValue = FMath::Clamp(TurnValue, -1.0f, 1.0f);

			//Move the character forward and turn them using the character classes regular functions.
			Enemy->AddMovementInput(Enemy->GetActorForwardVector(), ForwardValue);
			//Enemy->AddControllerYawInput(TurnValue);
			Enemy->SetActorRotation(CurrentRot);
		}
		else
		{
			//UE_LOG(LogTemp, Error, TEXT("Agent %d - Actions map missing expected keys!"), AgentId);
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
