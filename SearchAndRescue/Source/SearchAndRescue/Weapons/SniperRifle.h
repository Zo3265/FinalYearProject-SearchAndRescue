// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.h"
#include "SniperRifle.generated.h"

UCLASS()
class SEARCHANDRESCUE_API ASniperRifle : public AWeaponBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASniperRifle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle ReloadTimer;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	void SniperFire();
	
private:
	
	//Variables for testing
	float Count;
	float StartTime;
	float DT;
};
