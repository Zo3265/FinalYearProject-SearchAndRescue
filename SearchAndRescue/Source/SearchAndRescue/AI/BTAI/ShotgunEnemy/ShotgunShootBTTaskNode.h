// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ShotgunShootBTTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API UShotgunShootBTTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
public:

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
};
