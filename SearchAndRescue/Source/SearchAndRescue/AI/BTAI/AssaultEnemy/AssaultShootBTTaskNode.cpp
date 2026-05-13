// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/AssaultEnemy/AssaultShootBTTaskNode.h"
#include "SearchAndRescue/AI/BTAI/AssaultEnemy/BTAssaultAIController.h"
#include "SearchAndRescue/AI/BTAI/AssaultEnemy/AssaultEnemy.h"
#include "SearchAndRescue/Weapons/AssaultRifle.h"

EBTNodeResult::Type UAssaultShootBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
		AAssaultEnemy* Assault = Cast<AAssaultEnemy>(ControlledPawn);
		AAssaultRifle* Rifle = Assault->getAssaultRifle();;
		if ((Assault != nullptr && Rifle != nullptr) && Rifle->getCurrentMagCount() > 0 && Rifle->getReloading() != true)
		{
			Rifle->AssualtFire();
			Assault->PlayAttackAnim();
			return EBTNodeResult::Succeeded;
		}

		else if ((Assault != nullptr && Rifle != nullptr) && Rifle->getReloading() != true)
		{
			Assault->PlayReloadAnim();
			Rifle->setReloading(true);
			Rifle->Reload();
		}
	}

	return EBTNodeResult::Failed;
}
