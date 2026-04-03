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
}

void ABTSniperAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bSeePlayer"), true);
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bSeePlayer"), false);
	}
}
