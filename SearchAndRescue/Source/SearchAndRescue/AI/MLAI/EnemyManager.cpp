// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/EnemyManager.h"

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> EnemyActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMLEnemyBase::StaticClass(), EnemyActors);
	for (AActor* Enemy : EnemyActors)
	{
		if (Enemy)
		{
			this->AddTickPrerequisiteActor(Enemy);
			
			AMLEnemyBase* MLEnemyCast = Cast<AMLEnemyBase>(Enemy);
			AgentToSplineMap.Add(MLEnemyCast->getAgentId(), MLEnemyCast->GetSplineController()->getSpline());
		}

	}

	EnemyInteractorRef = NewObject<UEnemyInteractor>(this);
	
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

