// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/BTEnemyAIControllerBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"
#include "Kismet/GameplayStatics.h"

void ABTEnemyAIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//Get the pawn that the controller is attached to.
	//Cast it to the correct class.
	ControlledPawn = GetPawn();
	Enemy = Cast<AEnemyBase>(ControlledPawn);

	if (ControlledPawn != nullptr)
	{
		//Find the child actor component
		ChildActor = ControlledPawn->GetComponentByClass<UChildActorComponent>();

		if (ChildActor != nullptr)
		{
			//Get the actual child actor.
			SphereStore = ChildActor->GetChildActor();
		}
	}
}

void ABTEnemyAIControllerBase::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != NULL)
	{
		RunBehaviorTree(AIBehavior);

		PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	}
}

void ABTEnemyAIControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Default behaviour is to patrol
	GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), SphereStore);

}
