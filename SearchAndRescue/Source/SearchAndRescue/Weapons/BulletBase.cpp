// Fill out your copyright notice in the Description page of Project Settings.

#include "BulletBase.h"
#include "SearchAndRescue/AI/MLAI/Enemies/MLEnemyBase.h"
#include "SearchAndRescue/AI/BTAI/EnemyBase.h"
#include "Kismet/GameplayStatics.h"
#include "SearchAndRescue/MainCharacter/MainCharacter.h"

// Sets default values
ABulletBase::ABulletBase()
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

    Mesh->OnComponentBeginOverlap.AddDynamic(this, &ABulletBase::OnOverLapBegin);

    //Projectile Movement Component. Useful for bullets such as this.
    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->SetUpdatedComponent(Mesh); //This is telling the projectile movement to move the mesh specifically.

    ProjectileMovement->InitialSpeed = finitSpeed;
    ProjectileMovement->MaxSpeed = fMaxSpeed;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = false;
    ProjectileMovement->Bounciness = 0.0f;
    ProjectileMovement->ProjectileGravityScale = 0.0f; // Set this to 0 if you want the bullets to go completely straight.

    InitialLifeSpan = 8.0f;
}

// Called when the game starts or when spawned
void ABulletBase::BeginPlay()
{
	Super::BeginPlay();

    AMLEnemyBase* OwnerEnemy = Cast<AMLEnemyBase>(GetOwner());

    if (bTraining == true)
    {
        if (OwnerEnemy)
        {
            TargetActor = OwnerEnemy->getTrainingTarget();
        }
    }

    else
    {
        TargetActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    }
    PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    
}

// Called every frame
void ABulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ABulletBase::setTarget(AActor* ActorStore)
{
    TargetActor = ActorStore;
}


void ABulletBase::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Enemy bullets overlapping with the player.
    if ((TargetActor && OtherActor == TargetActor) && bPlayerBullet == false)
    {
        AMLEnemyBase* OwnerEnemy = Cast<AMLEnemyBase>(GetOwner());
        if (OwnerEnemy)
        {
            //UE_LOG(LogTemp, Warning, TEXT("MLEnemy Hit player"));
            OwnerEnemy->setHit(true);
            if (AMainCharacter* MC = Cast<AMainCharacter>(OtherActor))
            {
                MC->takeDamage(fDamage);
            }
            this->Destroy();
        }

        else
        {
            //UE_LOG(LogTemp, Warning, TEXT("Hit something"));
            if (AMainCharacter* MC = Cast<AMainCharacter>(OtherActor))
            {
                MC->takeDamage(fDamage);
            }
            this->Destroy();
        }
    }

    //Player bullets overlapping with the enemies
   else if (bPlayerBullet == true)
   {
        if (OtherActor == nullptr) { return; }
        if (!IsValid(OtherActor)) { return; }
        AMLEnemyBase* MLEnemy = Cast<AMLEnemyBase>(OtherActor);
        AEnemyBase* BTEnemy = Cast<AEnemyBase>(OtherActor);
        if (MLEnemy)
        {
            UE_LOG(LogTemp, Warning, TEXT("Hit MLEnemy"));
            MLEnemy->takeDamage(fDamage);
            this->Destroy();
        }

        else if (BTEnemy)
        {
            UE_LOG(LogTemp, Warning, TEXT("Hit BTEnemy"));
            BTEnemy->takeDamage(fDamage);
            this->Destroy();
        }
       
   }
    //UE_LOG(LogTemp, Warning, TEXT("Hit"));
    
}

