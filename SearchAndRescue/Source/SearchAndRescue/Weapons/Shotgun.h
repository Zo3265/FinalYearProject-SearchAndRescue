// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SearchAndRescue/Weapons/WeaponBase.h"
#include "Shotgun.generated.h"

/**
 * 
 */
UCLASS()
class SEARCHANDRESCUE_API AShotgun : public AWeaponBase
{
	GENERATED_BODY()
public:
	AShotgun();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	void ShotgunFire();
};
