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
	//
	//ULearningAgentsManager* ManagerComp = this->FindComponentByClass<ULearningAgentsManager>();
	//if (!ManagerComp)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("LearningAgentsManager not found on this actor!"));
	//	return;
	//}

	//TArray<AActor*> EnemyActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMLEnemyBase::StaticClass(), EnemyActors);
	//for (AActor* Enemy : EnemyActors)
	//{
	//	if (Enemy)
	//	{
	//		this->AddTickPrerequisiteActor(Enemy);

	//		ManagerComp->AddAgent(Enemy);
	//		
	//		AMLEnemyBase* MLEnemyCast = Cast<AMLEnemyBase>(Enemy);
	//		//AgentToSplineMap.Add(MLEnemyCast->getAgentId(), MLEnemyCast->GetSplineController()->getSpline());

	//		if (MLEnemyCast && MLEnemyCast->GetSplineController())
	//		{
	//			// Now ManagerSpline has a physical reference before the Interactor asks for it!
	//			ManagerSpline = MLEnemyCast->GetSplineController()->getSpline();
	//		}
	//	}

	//}

	////Setting up interactor
	//EnemyInteractorRef = NewObject<UEnemyInteractor>(this);
	//ULearningAgentsInteractor* BaseInteractor = Cast<ULearningAgentsInteractor>(EnemyInteractorRef);
	//if (EnemyInteractorRef)
	//{
	//	EnemyInteractorRef->SetupInteractor(ManagerComp);
	//	//EnemyInteractorRef->MakeInteractor(ManagerComp, UEnemyInteractor::StaticClass());
	//	/*USplineComponent** temp = AgentToSplineMap.Find(EnemyInteractorRef->getInteractorAgentID());*/
	//	EnemyInteractorRef->setInteractorSplineComponent(ManagerSpline);
	//}
	//
	//EnemyPolicy = NewObject<ULearningAgentsPolicy>(this);
	//if (EnemyPolicy)
	//{
	//	EnemyPolicy->SetupPolicy(ManagerComp, BaseInteractor, EncoderNeuralNetworkAsset, PolicyNeuralNetworkAsset, DecoderNeuralNetworkAsset, true, true, true, PolicySettings, 1234);
	//	//EnemyPolicy->MakePolicy(ManagerComp, BaseInteractor, ULearningAgentsPolicy::StaticClass(), FName("EnemyPolicy"), EncoderNeuralNetworkAsset, PolicyNeuralNetworkAsset, DecoderNeuralNetworkAsset, false, false, false, PolicySettings);
	//}

	//EnemyCritic = NewObject<ULearningAgentsCritic>(this);
	//if (EnemyCritic)
	//{
	//	EnemyCritic->SetupCritic(ManagerComp, BaseInteractor, EnemyPolicy, CriticNetworkAsset, true, CriticSettings, 1234);
	//	//EnemyCritic->MakeCritic(ManagerComp, BaseInteractor, EnemyPolicy, ULearningAgentsCritic::StaticClass(), FName("EnemyCritic"), CriticNetworkAsset, false, CriticSettings);
	//}

	//EnemyTrainingEnvRef = NewObject<UEnemyTrainingEnvironment>(this);
	//ULearningAgentsTrainingEnvironment* BaseTrainingEnvironment = Cast<ULearningAgentsTrainingEnvironment>(EnemyTrainingEnvRef);
	//if (EnemyTrainingEnvRef)
	//{
	//	EnemyTrainingEnvRef->SetupTrainingEnvironment(ManagerComp);
	//	//EnemyTrainingEnvRef->MakeTrainingEnvironment(ManagerComp, UEnemyTrainingEnvironment::StaticClass());
	//	/*USplineComponent** temp = AgentToSplineMap.Find(EnemyTrainingEnvRef->getTrainingEnvAgentID());*/
	//	EnemyTrainingEnvRef->setTrainingEnvSplineComponent(ManagerSpline);
	//}

	//

	//GetWorldTimerManager().SetTimer(ReloadTimer, this, &AEnemyManager::DelayPPO, 10.0f, false);
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//if (PPOTrainer && PPOTrainer->IsSetup())
	//{
	//	if (PPOTrainer->HasTrainingFailed()) 
	//	{
	//		UE_LOG(LogTemp, Error, TEXT("PPO Trainer communication failed!"));
	//		return;
	//	}

	///*	if (!bHasFirstFrameProcessed)
	//	{
	//		bHasFirstFrameProcessed = true;
	//		return;
	//	}*/

	//	PPOTrainer->RunTraining(PPOTrainerTrainingSettings, TrainingGameSettings, true, true);
	//}


}

void AEnemyManager::DelayPPO()
{
	//ULearningAgentsManager* ManagerComp = this->FindComponentByClass<ULearningAgentsManager>();
	//ULearningAgentsInteractor* BaseInteractor = Cast<ULearningAgentsInteractor>(EnemyInteractorRef);
	//ULearningAgentsTrainingEnvironment* BaseTrainingEnvironment = Cast<ULearningAgentsTrainingEnvironment>(EnemyTrainingEnvRef);

	//UE_LOG(LogTemp, Warning, TEXT("[TRAINER SETUP] Step 1: Initiating Trainer Setup Logic."));

	//FLearningAgentsTrainerProcessSettings TrainerProcessSettings;
	//TrainerProcessSettings.TrainerFileName = TEXT("train_ppo.py");
	//TrainerProcessSettings.NonEditorEngineRelativePath = TEXT("../../../../../../Engine/Plugins/Experimental/LearningAgents/Content/Python/");
	//FLearningAgentsSharedMemoryCommunicatorSettings SharedMemorySettings;
	//SharedMemorySettings.Timeout = 60.0f;
	//FLearningAgentsTrainerProcess TrainerProcess;

	//// STEP 2: Verify objects are valid before calling plugin functions
	//if (!ManagerComp || !BaseInteractor || !BaseTrainingEnvironment || !EnemyPolicy || !EnemyCritic)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("[TRAINER SETUP] CRITICAL: One or more required objects are NULLPTR!"));
	//	return;
	//}

	////UE_LOG(LogTemp, Warning, TEXT("[TRAINER SETUP] Step 2: Spawning Shared Memory Process..."));
	////TrainerProcess = ULearningAgentsCommunicatorLibrary::SpawnSharedMemoryTrainingProcess(TrainerProcessSettings, SharedMemorySettings);

	//UE_LOG(LogTemp, Warning, TEXT("[TRAINER SETUP] Step 3: Creating Communicator..."));
	//FLearningAgentsCommunicator SharedMemoryCommunicator;
	////SharedMemoryCommunicator = ULearningAgentsCommunicatorLibrary::MakeSharedMemoryCommunicator(TrainerProcess, SharedMemorySettings);
	//SharedMemoryCommunicator = ULearningAgentsCommunicatorLibrary::MakeSharedMemoryCommunicator(TrainerProcess, SharedMemorySettings);
	//

	//PPOTrainer = NewObject<ULearningAgentsPPOTrainer>(this);
	//if (PPOTrainer)
	//{
	//	FLearningAgentsPPOTrainerSettings PPOTrainerSettings;
	//	UE_LOG(LogTemp, Warning, TEXT("[TRAINER SETUP] Step 4: Calling SetupPPOTrainer. Handshake will occur now..."));
	//	PPOTrainer->SetupPPOTrainer(ManagerComp, BaseInteractor, BaseTrainingEnvironment, EnemyPolicy, EnemyCritic, SharedMemoryCommunicator, PPOTrainerSettings);

	//	UE_LOG(LogTemp, Warning, TEXT("[TRAINER SETUP] Step 5: SetupPPOTrainer completed successfully!"));

	//	//PPOTrainer->MakePPOTrainer(ManagerComp, BaseInteractor, BaseTrainingEnvironment, EnemyPolicy, EnemyCritic, SharedMemoryCommunicator, ULearningAgentsPPOTrainer::StaticClass());
	//}

	//else
	//{
	//	UE_LOG(LogTemp, Error, TEXT("[TRAINER SETUP] Failed to allocate NewObject for PPOTrainer!"));
	//}

}

