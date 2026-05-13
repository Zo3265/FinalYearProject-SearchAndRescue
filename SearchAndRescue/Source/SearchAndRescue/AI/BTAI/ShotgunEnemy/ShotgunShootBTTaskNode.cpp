// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/ShotgunEnemy/ShotgunShootBTTaskNode.h"
#include "SearchAndRescue/AI/BTAI/ShotgunEnemy/BTShotgunAIController.h"
#include "SearchAndRescue/AI/BTAI/ShotgunEnemy/ShotgunEnemy.h"
#include "SearchAndRescue/Weapons/Shotgun.h"

EBTNodeResult::Type UShotgunShootBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
		AShotgunEnemy* ShotgunEnemy = Cast<AShotgunEnemy>(ControlledPawn);
		AShotgun* Shotgun = ShotgunEnemy->getShotgun();;
		if ((ShotgunEnemy != nullptr && Shotgun != nullptr) && Shotgun->getCurrentMagCount() > 0 && Shotgun->getReloading() != true)
		{
			Shotgun->ShotgunFire();
			ShotgunEnemy->PlayAttackAnim();
			return EBTNodeResult::Succeeded;
		}

		else if ((ShotgunEnemy != nullptr && Shotgun != nullptr) && Shotgun->getReloading() != true)
		{
			Shotgun->Reload();
			Shotgun->setReloading(true);
			ShotgunEnemy->PlayReloadAnim();
		}
	}

	return EBTNodeResult::Failed;
}
