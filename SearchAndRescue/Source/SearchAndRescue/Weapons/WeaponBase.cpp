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

    //Deafult values for the guns. In case I forget to set them.
    iCurrentMagCount = 30;
    iCurrentAmmoReserve = 180;
    iMaxMagCount = 30;
    iMaxAmmoReserve = 180;

    Cooldown = 0.05f;
    Range = 5000.0f;
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

    if (Cooldown > 0.0f)
    {
        Cooldown -= DeltaTime;
    }
}

void AWeaponBase::Fire()
{
    if (this)
    {
        ACharacter* EnemyChar = Cast<ACharacter>(GetOwner());
        USkeletalMeshComponent* EnemyMesh = EnemyChar->GetMesh();

        FVector FaceLocation = EnemyMesh->GetSocketLocation(TEXT("FaceShoot"));
        FVector AimDirection = EnemyChar->GetControlRotation().Vector();
        FVector TargetAimPoint = FaceLocation + (AimDirection * 10000.0f);

        //Get the location of the bullets spawn point
        FVector MuzzleLocation = Mesh->GetSocketLocation(TEXT("BulletSpawn"));
        FRotator BulletRotation = (TargetAimPoint - MuzzleLocation).Rotation();

        FActorSpawnParameters SpawnParameters;
        SpawnParameters.Owner = GetOwner();
        SpawnParameters.Instigator = GetInstigator();
        SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        Bullet = GetWorld()->SpawnActor<ABulletBase>(BulletClass, MuzzleLocation, BulletRotation, SpawnParameters);
        if (ShootSound)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), ShootSound, this->GetActorLocation());
        }
    }
    
}

void AWeaponBase::Reload()
{
    if (this)
    {
        int iDiff = iMaxMagCount - iCurrentMagCount; //How much ammo we need.
        iCurrentMagCount += iDiff; //Refill the magazine.
        iCurrentAmmoReserve -= iDiff; //Take the refill away from our reserve ammo.
        //bReloading = false; //We are no longer reloading.
        if (ReloadSound)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), ReloadSound, this->GetActorLocation());
        }
    }
    
}

bool AWeaponBase::getCanFire()
{
    if (this)
    {
        return bCanFire;
    }
    
    return false;
}

void AWeaponBase::setReloading(bool bStore)
{
    if (this)
    {
        bReloading = bStore;
    }
    
}

bool AWeaponBase::getReloading()
{
    if (this)
    {
        return bReloading;
    }
    return false;
}

ABulletBase* AWeaponBase::getBullet()
{
    return Bullet;
}

void AWeaponBase::setCoolDown(float fStore)
{
    if (this)
    {
        Cooldown = fStore;
    }
    
}

float AWeaponBase::getCoolDown()
{
    if (this)
    {
        return Cooldown;
    }
    return 0;
}

void AWeaponBase::setRange(float fStore)
{
    if (this)
    {
        Range = fStore;
    }
   
}

float AWeaponBase::getRange()
{
    if (this)
    {
        return Range;
    }
    return 0;
}

UStaticMeshComponent* AWeaponBase::getMesh()
{
    if (this && Mesh)
    {
        return Mesh;
    }
    return nullptr;
}

int AWeaponBase::getCurrentMagCount()
{
    if (this)
    {
        return iCurrentMagCount;
    }
    return 0;
} 

int AWeaponBase::getMaxMagCount()
{
    if (this)
    {
        return iMaxMagCount;
    }
    return 0;
}

void AWeaponBase::setCurrentAmmoReserve(int iStore)
{
    if (this)
    {
        iCurrentAmmoReserve = iStore;
    }
    
}

int AWeaponBase::getCurrentAmmoReserve()
{
    if (this)
    {
        return iCurrentAmmoReserve;
    }
    return 0;
}

