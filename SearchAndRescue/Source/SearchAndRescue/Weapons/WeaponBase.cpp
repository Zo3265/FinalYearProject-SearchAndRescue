// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Kismet/GameplayStatics.h"

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
    //Currently aims at the players feet. I will need to make it so that it targets the players torso but to that I need to target a socket on the players mesh. Which it currently doesn't have.
    FRotator FireRotation = (PlayerLocation - MuzzleLocation).Rotation();

    FActorSpawnParameters SpawnParameters;
    SpawnParameters.Owner = this;
    SpawnParameters.Instigator = GetInstigator();
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    Bullet = GetWorld()->SpawnActor<ABulletBase>(BulletClass, MuzzleLocation, FireRotation, SpawnParameters);
}

