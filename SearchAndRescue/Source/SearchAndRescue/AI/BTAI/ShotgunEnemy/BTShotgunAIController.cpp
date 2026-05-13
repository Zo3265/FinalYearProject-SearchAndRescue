// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/ShotgunEnemy/BTShotgunAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

ABTShotgunAIController::ABTShotgunAIController()
{
	SightConfig->SightRadius = 1000.0f;
	SightConfig->LoseSightRadius = 1100.0f;
	SightConfig->PeripheralVisionAngleDegrees = 90.0f;
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ABTShotgunAIController::OnTargetPerceptionUpdated);
}

void ABTShotgunAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	ControlledPawn = GetPawn();
	ShotgunEnemy = Cast<AShotgunEnemy>(ControlledPawn);
}

void ABTShotgunAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ABTShotgunAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ShotgunEnemy->getHealth() <= 15.0f)
	{
		this->ClearFocus(EAIFocusPriority::Gameplay);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bLowHealth"), true);
		ShotgunEnemy->setSpeed(400.0f);
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
		ShotgunEnemy->setSpeed(400.0f);
		if (distance <= 70.0f)
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bHavePlayer"), false);
			GetAIPerceptionComponent()->ForgetAll();
		}

	}

	if (ShotgunEnemy->getExplosiveGrenadeAmount() > 0)
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bHasExplosive"), true);
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bHasExplosive"), false);
	}
}

void ABTShotgunAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{

	if (!Actor || Actor != GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		return;
	}
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
