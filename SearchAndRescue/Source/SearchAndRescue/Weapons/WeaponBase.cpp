// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Root Component
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(Root);

    //Mesh Component
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->BodyInstance.SetInstanceNotifyRBCollision(true);
    Mesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeaponBase::Fire()
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();

    //Get the location of the bullets spawn point
    FVector MuzzleLocation = Mesh->GetSocketLocation(TEXT("BulletSpawn"));

    //Get the player location
    FVector PlayerLocation = PlayerPawn->GetActorLocation();

    //Rotate the bullet to go to the players location.
    //FVector TargetLocation = PlayerPawn->GetActorLocation() + FVector(0, 0, 90);
    FRotator FireRotation = Mesh->GetSocketRotation(TEXT("BulletSpawn"));

    FActorSpawnParameters SpawnParameters;
    SpawnParameters.Owner = this;
    SpawnParameters.Instigator = GetInstigator();
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    Bullet = GetWorld()->SpawnActor<ABulletBase>(BulletClass, MuzzleLocation, FireRotation, SpawnParameters);
}

void AWeaponBase::Reload()
{
    int iDiff = iMaxMagCount - iCurrentMagCount; //How much ammo we need.
    iCurrentMagCount += iDiff; //Refill the magazine.
    iCurrentAmmoReserve -= iDiff; //Take the refill away from our reserve ammo.
    bReloading = false; //We are no longer reloading.
}

bool AWeaponBase::getCanFire()
{
    return bCanFire;
}

bool AWeaponBase::getReloading()
{
    return bReloading;
}

void AWeaponBase::setCoolDown(float fStore)
{
    Cooldown = fStore;
}

float AWeaponBase::getCoolDown()
{
    return Cooldown;
}

void AWeaponBase::setRange(float fStore)
{
    Range = fStore;
}

float AWeaponBase::getRange()
{
    return Range;
}

UStaticMeshComponent* AWeaponBase::getMesh()
{
    if (Mesh)
    {
        return Mesh;
    }
    return nullptr;
}

int AWeaponBase::getCurrentMagCount()
{
    return iCurrentMagCount;
}

int AWeaponBase::getMaxMagCount()
{
    return iMaxMagCount;
}

