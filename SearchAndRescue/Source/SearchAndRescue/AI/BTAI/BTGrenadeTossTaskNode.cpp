// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/BTGrenadeTossTaskNode.h"
#include "SearchAndRescue/AI/BTAI/BTSniperAIController.h"
#include "SearchAndRescue/AI/BTAI/SniperEnemy.h"

EBTNodeResult::Type UBTGrenadeTossTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		GLog->Log(FString::Printf(TEXT("Failed OwnerComp")));
		return EBTNodeResult::Failed;
	}

	AAIController* Controller = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = Controller->GetPawn();

	//Plays attack animation using the BT.
	if (ControlledPawn != nullptr)
	{
		ASniperEnemy* Sniper = Cast<ASniperEnemy>(ControlledPawn);
		if (Sniper != nullptr)
		{
			Sniper->PlayGrenadeThrowAnim();
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
