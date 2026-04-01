// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/Weapons/SniperRifle.h"

// Sets default values
ASniperRifle::ASniperRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASniperRifle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASniperRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

