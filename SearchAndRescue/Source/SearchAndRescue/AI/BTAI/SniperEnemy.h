// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SearchAndRescue/AI/BTAI/EnemyBase.h"
#include "SearchAndRescue/Weapons/SniperRifle.h"
#include "SniperEnemy.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API ASniperEnemy : public AEnemyBase
{
	GENERATED_BODY()
public:
	ASniperEnemy();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASniperRifle> SniperClass;

	UPROPERTY()
	ASniperRifle* SniperRifle;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
};
