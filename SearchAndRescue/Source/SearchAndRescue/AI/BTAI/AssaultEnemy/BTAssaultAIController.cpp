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
		//UE_LOG(LogTemp, Warning, TEXT("Storing the players location as we see them:"));
		lastPlayerLocation = PlayerPawn->GetActorLocation();
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), lastPlayerLocation);
	}

	if ((GetBlackboardComponent()->GetValueAsBool(TEXT("bHavePlayer")) == true && GetBlackboardComponent()->GetValueAsBool(TEXT("bSeePlayer")) == false))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Lost the player so are chasing:"));
		float distance = FVector::Distance(lastPlayerLocation, ControlledPawn->GetActorLocation());
		//UE_LOG(LogTemp, Warning, TEXT("Distance is: %f"), distance);
		AssaultEnemy->setSpeed(400.0f);
		if (distance <= 70.0f)
		{
			UE_LOG(LogTemp, Warning, TEXT("Have player set to false:"));
			GetBlackboardComponent()->SetValueAsBool(TEXT("bHavePlayer"), false);
			GetAIPerceptionComponent()->ForgetAll();
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
	if (!Actor || Actor != GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		return;
	}
	if (Stimulus.WasSuccessfullySensed() && Actor->ActorHasTag(TEXT("Player")))
	{
		//UE_LOG(LogTemp, Warning, TEXT("See the player:"));
		//GLog->Log("See player");
		GetBlackboardComponent()->SetValueAsBool(TEXT("bSeePlayer"), true);
		this->SetFocus(PlayerPawn);
		lastPlayerLocation = PlayerPawn->GetActorLocation();
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), lastPlayerLocation);
	}

	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Lost the player:"));
		//GLog->Log("Lost");
		lastPlayerLocation = PlayerPawn->GetActorLocation();
		GetBlackboardComponent()->SetValueAsBool(TEXT("bSeePlayer"), false);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bHavePlayer"), true);
		this->ClearFocus(EAIFocusPriority::Gameplay);
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), lastPlayerLocation);
	}
}


