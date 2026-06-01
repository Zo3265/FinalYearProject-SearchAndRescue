// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/HostageAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

AHostageAIController::AHostageAIController()
{
}

void AHostageAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	Hostage = Cast<AHostageChar>(GetPawn());
}

void AHostageAIController::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
	}
}

void AHostageAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Once the hostage is activated they always follow the player.
	GetBlackboardComponent()->SetValueAsObject(FName("PlayerActor"), PlayerPawn);
	GetBlackboardComponent()->SetValueAsBool(FName("bActivated"), Hostage->getActivated());
}
