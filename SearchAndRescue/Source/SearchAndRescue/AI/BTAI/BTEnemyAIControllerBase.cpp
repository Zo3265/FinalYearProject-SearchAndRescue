// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/BTEnemyAIControllerBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"
#include "Kismet/GameplayStatics.h"

ABTEnemyAIControllerBase::ABTEnemyAIControllerBase()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));

	//Default values for the AI sight. Here in case I forget to set them in the child AI controllers.
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 1000;
	SightConfig->LoseSightRadius = 1200;
	SightConfig->PeripheralVisionAngleDegrees = 70.0f;
	SightConfig->PointOfViewBackwardOffset = 0.0f;
	SightConfig->SetMaxAge(30.0f);
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	AIPerception->ConfigureSense(*SightConfig);
	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());
}

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

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		PlayerPawn = PlayerController->GetPawn();
	}
}

void ABTEnemyAIControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AIBehavior != nullptr && Enemy->bDead == false)
	{
		//Default behaviour is to patrol
		GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), SphereStore);
		Enemy->setSpeed(Enemy->getDefaultSpeed());
	}

	else if(AIBehavior != nullptr)
	{
		this->GetBrainComponent()->StopLogic(TEXT("Death shutdown"));
	}

}

