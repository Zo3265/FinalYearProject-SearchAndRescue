// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SearchAndRescue/AI/BTAI/HostageChar.h"
#include "HostageAIController.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API AHostageAIController : public AAIController
{
	GENERATED_BODY()
public:
	AHostageAIController();
protected:
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY()
	AHostageChar* Hostage;

	UPROPERTY()
	APawn* PlayerPawn;
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
