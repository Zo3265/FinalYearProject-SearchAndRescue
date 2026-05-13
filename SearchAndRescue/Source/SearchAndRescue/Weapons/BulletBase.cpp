// Fill out your copyright notice in the Description page of Project Settings.

#include "BulletBase.h"
#include "SearchAndRescue/AI/MLAI/Enemies/MLEnemyBase.h"

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
	//On overlap with anything we delete the bullet.
    if (TargetActor && OtherActor == TargetActor)
    {
        //UE_LOG(LogTemp, Warning, TEXT("Hit"));
        AMLEnemyBase* OwnerEnemy = Cast<AMLEnemyBase>(GetOwner());

        if (OwnerEnemy)
        {
            OwnerEnemy->setHit(true);
            this->Destroy();
        }
    }
    //UE_LOG(LogTemp, Warning, TEXT("Hit"));
    
}

