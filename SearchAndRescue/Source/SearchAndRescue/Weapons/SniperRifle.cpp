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

	Cooldown = 0.93f;
	Range = 5000.0f;
}

// Called when the game starts or when spawned
void ASniperRifle::BeginPlay()
{
	Super::BeginPlay();
	
	StartTime = GetWorld()->GetTimeSeconds();
	Count = StartTime;
}

// Called every frame
void ASniperRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DT = DeltaTime;

	//SniperFire(DeltaTime);
}

void ASniperRifle::SniperFire()
{
	if (iCurrentMagCount != 0) //&& bCanFire == true)
	{
		//GLog->Log("Firing");
		Fire();
		bCanFire = false;
		iCurrentMagCount--;
		Cooldown = 0.93f;
	}

	////This acts as a bolt timer for the sniper rifle.
	//else if (bCanFire == false)
	//{
	//	Count += 1.0f * DT;
	//	//UE_LOG(LogTemp, Warning, TEXT("Count is: %f"), Count);
	//	if (Count >= 0.93f)
	//	{
	//		bCanFire = true;
	//		Count = StartTime;
	//	}
	//}

	//if (iCurrentMagCount <= 0 && bReloading == false)
	//{
	//	GetWorldTimerManager().SetTimer(ReloadTimer, this, &AWeaponBase::Reload, 2.0f, false); //2 second reload.
	//	bReloading = true; //We are reloading
	//}
}







