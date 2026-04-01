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

	void Reload();
	void SniperFire(float DeltaTime);
	bool bReloading = false;
	bool bCanFire = true;
private:
	int iCurrentMagCount; //Current Ammo in gun
	int iCurrentAmmoReserve; //Current Ammo Reserve
	int iMaxMagCount; //Maximum ammo allowed in magazine
	int iMaxAmmoReserve; //Maximum ammo allowed as reserve
	float Count;
	float StartTime;
};
