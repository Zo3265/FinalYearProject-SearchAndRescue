// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SearchAndRescue/Weapons/GrenadeBase.h"
#include "ExplosiveGrenade.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API AExplosiveGrenade : public AGrenadeBase
{
	GENERATED_BODY()
	
public:
	AExplosiveGrenade();
protected:
	virtual void BeginPlay() override;

	virtual void Explode() override;
public:
	virtual void Tick(float DeltaTime) override;
private:
};
