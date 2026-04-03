// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/SniperShootBTTaskNode.h"
#include "SearchAndRescue/AI/BTAI/BTSniperAIController.h"
#include "SearchAndRescue/AI/BTAI/SniperEnemy.h"
#include "SearchAndRescue/Weapons/SniperRifle.h"

EBTNodeResult::Type USniperShootBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
		ASniperRifle* Rifle = Sniper->getRifle();;
		if (Sniper != nullptr && Rifle != nullptr)
		{

			Rifle->SniperFire();
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}

