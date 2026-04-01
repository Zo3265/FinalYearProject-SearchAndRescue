// Fill out your copyright notice in the Description page of Project Settings.


#include "SniperRifle.h"

// Sets default values
ASniperRifle::ASniperRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	iCurrentMagCount = 6;
	iCurrentAmmoReserve = 36;
	iMaxMagCount = 6;
	iMaxAmmoReserve = 36;
}

// Called when the game starts or when spawned
void ASniperRifle::BeginPlay()
{
	Super::BeginPlay();
	
	Count = GetWorld()->GetTimeSeconds();
}

// Called every frame
void ASniperRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if (iCurrentMagCount != 0 && bCanFire == true)
	{
		Fire();
		iCurrentMagCount--;
	}

	else if (bCanFire == false)
	{
		Count += 1.0f * DeltaTime;

		if (Count >= 0.5f)
		{
			bCanFire = true;
		}
	}

	if(iCurrentMagCount <= 0 && bReloading == false)
	{
		GetWorldTimerManager().SetTimer(ReloadTimer, this, &ASniperRifle::Reload, 2.0f, false); //2 second reload.
		bReloading = true; //We are reloading
	}

}

void ASniperRifle::Reload()
{
	int iDiff = iMaxMagCount - iCurrentMagCount; //How much ammo we need.
	iCurrentMagCount += iDiff; //Refill the magazine.
	iCurrentAmmoReserve -= iDiff; //Take the refill away from our reserve ammo.
	bReloading = false; //We are no longer reloading.
}

