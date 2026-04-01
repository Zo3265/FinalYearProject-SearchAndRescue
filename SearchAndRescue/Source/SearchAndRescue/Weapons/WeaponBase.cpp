// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"


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
    Fire();
}

void AWeaponBase::Fire()
{
    FActorSpawnParameters SpawnParamaters = FActorSpawnParameters();
    SpawnParamaters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    SniperBullet = GetWorld()->SpawnActor<ABulletBase>(BulletClass, FTransform(), SpawnParamaters);
    
    if (SniperBullet != nullptr)
    {
        SniperBullet->AttachToComponent(Mesh, FAttachmentTransformRules::KeepRelativeTransform, TEXT("BulletSpawn"));
        SniperBullet->SetOwner(this);
    }
}

