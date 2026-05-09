// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SearchAndRescue/Weapons/WeaponBase.h"
#include "GameFramework/Actor.h"
#include "AssaultRifle.generated.h"

UCLASS()
class SEARCHANDRESCUE_API AAssaultRifle : public AWeaponBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAssaultRifle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AssualtFire();
};
