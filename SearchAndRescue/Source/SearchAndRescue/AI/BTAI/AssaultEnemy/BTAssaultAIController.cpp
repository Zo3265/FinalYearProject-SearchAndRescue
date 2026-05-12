// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/AssaultEnemy/BTAssaultAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

ABTAssaultAIController::ABTAssaultAIController()
{
	SightConfig->SightRadius = 1200.0f;
	SightConfig->LoseSightRadius = 1300.0f;
	SightConfig->PeripheralVisionAngleDegrees = 80.0f;
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ABTAssaultAIController::OnTargetPerceptionUpdated);
}

void ABTAssaultAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	ControlledPawn = GetPawn();
	AssaultEnemy = Cast<AAssaultEnemy>(ControlledPawn);
}

void ABTAssaultAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ABTAssaultAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AssaultEnemy->getHealth() <= 45.0f)
	{
		this->ClearFocus(EAIFocusPriority::Gameplay);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bLowHealth"), true);
		AssaultEnemy->setSpeed(400.0f);
	}

	if (GetBlackboardComponent()->GetValueAsBool(TEXT("bSeePlayer")) == true)
	{
		lastPlayerLocation = PlayerPawn->GetActorLocation();
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), lastPlayerLocation);
	}

	if ((GetBlackboardComponent()->GetValueAsBool(TEXT("bHavePlayer")) == true && GetBlackboardComponent()->GetValueAsBool(TEXT("bSeePlayer")) == false))
	{
		float distance = FVector::Distance(lastPlayerLocation, ControlledPawn->GetActorLocation());
		//UE_LOG(LogTemp, Warning, TEXT("Distance is: %f"), distance);
		AssaultEnemy->setSpeed(400.0f);
		if (distance <= 70.0f)
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bHavePlayer"), false);
		}

	}

	if (AssaultEnemy->getExplosiveGrenadeAmount() > 0)
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bHasExplosive"), true);
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bHasExplosive"), false);
	}
}

void ABTAssaultAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		//GLog->Log("See player");
		GetBlackboardComponent()->SetValueAsBool(TEXT("bSeePlayer"), true);
		this->SetFocus(PlayerPawn);
		lastPlayerLocation = PlayerPawn->GetActorLocation();
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), lastPlayerLocation);
	}

	else
	{
		//GLog->Log("Lost");
		lastPlayerLocation = PlayerPawn->GetActorLocation();
		GetBlackboardComponent()->SetValueAsBool(TEXT("bSeePlayer"), false);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bHavePlayer"), true);
		this->ClearFocus(EAIFocusPriority::Gameplay);
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), lastPlayerLocation);
	}
}


