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
	ULearningAgentsInteractor* BaseInteractor = Cast<ULearningAgentsInteractor>(EnemyInteractorRef);
	ULearningAgentsManager* ManagerComp = this->FindComponentByClass<ULearningAgentsManager>();
	if (EnemyInteractorRef)
	{
		//EnemyInteractorRef->SetupInteractor(ManagerComp);
		EnemyInteractorRef->MakeInteractor(ManagerComp, UEnemyInteractor::StaticClass());
		USplineComponent** temp = AgentToSplineMap.Find(EnemyInteractorRef->getInteractorAgentID());
		EnemyInteractorRef->setInteractorSplineComponent(*temp);
	}
	
	EnemyPolicy = NewObject<ULearningAgentsPolicy>(this);
	if (EnemyPolicy)
	{
		//EnemyPolicy->SetupPolicy(ManagerComp, BaseInteractor);
		EnemyPolicy->MakePolicy(ManagerComp, BaseInteractor, ULearningAgentsPolicy::StaticClass(), FName("EnemyPolicy"), EncoderNeuralNetworkAsset, PolicyNeuralNetworkAsset, DecoderNeuralNetworkAsset, false, false, false, PolicySettings);
	}

	EnemyCritic = NewObject<ULearningAgentsCritic>(this);
	if (EnemyCritic)
	{
		//EnemyCritic->SetupCritic(ManagerComp, BaseInteractor, EnemyPolicy, CriticNetworkAsset, false);
		EnemyCritic->MakeCritic(ManagerComp, BaseInteractor, EnemyPolicy, ULearningAgentsCritic::StaticClass(), FName("EnemyCritic"), CriticNetworkAsset, false, CriticSettings);
	}

	EnemyTrainingEnvRef = NewObject<UEnemyTrainingEnvironment>(this);
	ULearningAgentsTrainingEnvironment* BaseTrainingEnvironment = Cast<ULearningAgentsTrainingEnvironment>(EnemyTrainingEnvRef);
	if (EnemyTrainingEnvRef)
	{
		//EnemyTrainingEnvRef->SetupTrainingEnvironment(ManagerComp);
		EnemyTrainingEnvRef->MakeTrainingEnvironment(ManagerComp, UEnemyTrainingEnvironment::StaticClass());
		USplineComponent** temp = AgentToSplineMap.Find(EnemyTrainingEnvRef->getTrainingEnvAgentID());
		EnemyTrainingEnvRef->setTrainingEnvSplineComponent(*temp);
	}

	FLearningAgentsTrainerProcessSettings TrainerProcessSettings;
	FLearningAgentsSharedMemoryCommunicatorSettings SharedMemorySettings;
	ULearningAgentsCommunicatorLibrary::SpawnSharedMemoryTrainingProcess(TrainerProcessSettings, SharedMemorySettings);

	FLearningAgentsTrainerProcess TrainerProcess;
	FLearningAgentsCommunicator SharedMemoryCommunicator;
	SharedMemoryCommunicator = ULearningAgentsCommunicatorLibrary::MakeSharedMemoryCommunicator(TrainerProcess, SharedMemorySettings);

	PPOTrainer = NewObject<ULearningAgentsPPOTrainer>(this);
	if (PPOTrainer)
	{
		FLearningAgentsPPOTrainerSettings PPOTrainerSettings;
		PPOTrainer->MakePPOTrainer(ManagerComp, BaseInteractor, BaseTrainingEnvironment, EnemyPolicy, EnemyCritic, SharedMemoryCommunicator, ULearningAgentsPPOTrainer::StaticClass());
	}
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PPOTrainer->RunTraining();
}

