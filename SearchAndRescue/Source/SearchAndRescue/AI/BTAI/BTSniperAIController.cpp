// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/BTSniperAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

ABTSniperAIController::ABTSniperAIController()
{
	SightConfig->SightRadius = 1400.0f;
	SightConfig->SightRadius = 1800.0f;
	SightConfig->PeripheralVisionAngleDegrees = 50.0f;
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ABTSniperAIController::OnTargetPerceptionUpdated);
}

void ABTSniperAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void ABTSniperAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ABTSniperAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if ((GetBlackboardComponent()->GetValueAsBool(TEXT("bHavePlayer")) == true && GetBlackboardComponent()->GetValueAsBool(TEXT("bSeePlayer")) == false))
	{
		float distance = FVector::Distance(lastPlayerLocation, ControlledPawn->GetActorLocation());
		//UE_LOG(LogTemp, Warning, TEXT("Distance is: %f"), distance);
		if (distance <= 50.0f)
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bHavePlayer"), false);
		}
		
	}
}

void ABTSniperAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bSeePlayer"), true);
		this->SetFocus(PlayerPawn);
		lastPlayerLocation = PlayerPawn->GetActorLocation();
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bSeePlayer"), false);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bHavePlayer"), true);
		this->ClearFocus(EAIFocusPriority::Gameplay);
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), lastPlayerLocation);
	}
}
