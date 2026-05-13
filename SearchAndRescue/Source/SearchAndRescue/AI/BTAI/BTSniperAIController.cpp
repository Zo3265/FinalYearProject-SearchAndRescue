// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/BTSniperAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

ABTSniperAIController::ABTSniperAIController()
{
	SightConfig->SightRadius = 1500.0f;
	SightConfig->LoseSightRadius = 1600.0f;
	SightConfig->PeripheralVisionAngleDegrees = 60.0f;
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ABTSniperAIController::OnTargetPerceptionUpdated);
}

void ABTSniperAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ControlledPawn = GetPawn();
	SniperEnemy = Cast<ASniperEnemy>(ControlledPawn);
}

void ABTSniperAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ABTSniperAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SniperEnemy->getHealth() <= 20.0f)
	{
		this->ClearFocus(EAIFocusPriority::Gameplay);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bLowHealth"), true);
		SniperEnemy->setSpeed(400.0f);
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
		SniperEnemy->setSpeed(400.0f);
		if (distance <= 50.0f)
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bHavePlayer"), false);
			GetAIPerceptionComponent()->ForgetAll();
		}
		
	}

	if (SniperEnemy->getExplosiveGrenadeAmount() > 0)
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bHasExplosive"), true);
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bHasExplosive"), false);
	}

}


void ABTSniperAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
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
