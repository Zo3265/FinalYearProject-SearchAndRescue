// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/EnemyBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	//Get the first child actor attached to this.
	//Should be the splineMovementActor
	UChildActorComponent* ChildActor = this->GetComponentByClass<UChildActorComponent>();

	if (ChildActor)
	{
		//GLog->Log("Has Child Actors");
		SphereStore = ChildActor->GetChildActor();
		SphereStore->SetActorTransform(splineController->getSpline()->GetComponentTransform());

		StartTime = GetWorld()->GetTimeSeconds();
		Count = GetWorld()->GetTimeSeconds();
	}

	//Set the speed of the character proportional to the splines length. Except a little slower so we don't get jittery movement. 
	float Speed = splineController->getSpline()->GetSplineLength() / splineController->getTotalPathTimeController();
	//UE_LOG(LogTemp, Warning, TEXT("Speed is: %f"), GetCharacterMovement()->MaxWalkSpeed);
	fDefaultSpeed = Speed;
	GetCharacterMovement()->MaxWalkSpeed = fDefaultSpeed - 20.0f;
	AnimIsDead = Cast<UBoolAnimInstance>(GetMesh()->GetAnimInstance());

}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (fHealth <= 0.0f)
	{
		bDead = true;
		if (iDeathCount == 0)
		{
			PlayBTDeathMontage();
		}
		
	}

	if (SphereStore != nullptr && bDead == false)
	{
		//How long the current spline has been going for.
		float CurrentSplineTime = (Count - StartTime) / splineController->getTotalPathTimeController();
		//UE_LOG(LogTemp, Warning, TEXT("Spline Time is: %f"), CurrentSplineTime);
		//UE_LOG(LogTemp, Warning, TEXT("Count is: %f"), Count);

		//Need to reset count so that we keep following the loop.
		if (Count >= splineController->getTotalPathTimeController())
		{
			//GLog->Log("Spline is Ended");
			Count = StartTime;
		}

		//Find the distance we are along the spline.
		float Distance = splineController->getSpline()->GetSplineLength() * CurrentSplineTime;

		//Translate that distance into world space. Then move the sphere to it,
		FVector Position = splineController->getSpline()->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		SphereStore->SetActorLocation(Position);

		//Rotate the sphere in world space.
		FVector Direction = splineController->getSpline()->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
		SphereStore->SetActorRotation(Rotator);

		Count += 1.0f * DeltaTime;
	}
	
}

int AEnemyBase::getExplosiveGrenadeAmount()
{
	return iExplosiveGrenadeAmount;
}

int AEnemyBase::getFlashGrenadeAmount()
{
	return iFlashGrenadeAmount;
}

float AEnemyBase::getHealth()
{
	return fHealth;
}

void AEnemyBase::setSpeed(float fSpeedStore)
{
	GetCharacterMovement()->MaxWalkSpeed = fSpeedStore;
}

float AEnemyBase::getDefaultSpeed()
{
	return fDefaultSpeed;
}

void AEnemyBase::takeDamage(float fDamageStore)
{
	fHealth -= fDamageStore;
}


// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBase::PlayAttackAnim()
{

	if (AnimInstance != nullptr)
	{

		/*if (!AnimInstance->Montage_IsPlaying(FiringAnimation))
		{*/
		//GLog->Log("Playing Animation");
		AnimInstance->Montage_Play(FiringAnimation);
		//}

	}
}

void AEnemyBase::PlayReloadAnim()
{
	if (AnimInstance != nullptr)
	{
		AnimInstance->Montage_Play(ReloadAnimation);
	}
}

void AEnemyBase::PlayGrenadeThrowAnim()
{
	iExplosiveGrenadeAmount--;
	if (AnimInstance != nullptr)
	{
		this->SetActorHiddenInGame(true);
		AnimInstance->Montage_Play(GrenadeThrowAnimation);

		FVector SocketLocation = GetMesh()->GetSocketLocation(TEXT("GrenadeSocket"));
		FRotator SocketRotation = GetMesh()->GetSocketRotation(TEXT("GrenadeSocket"));

		FActorSpawnParameters GrenadeSpawnParameters;
		GrenadeSpawnParameters.Owner = this;
		GrenadeSpawnParameters.Instigator = GetInstigator();
		GrenadeSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		ExplosiveGrenade = GetWorld()->SpawnActor<AExplosiveGrenade>(ExplosiveGrenadeClass, SocketLocation,
			SocketRotation, GrenadeSpawnParameters);

		if (ExplosiveGrenade != nullptr)
		{
			ExplosiveGrenade->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("GrenadeSocket"));
			ExplosiveGrenade->SetOwner(this);
		}
	}
}

void AEnemyBase::PlayBTDeathMontage()
{
	if (AnimInstance != nullptr)
	{
		AnimIsDead->setIsDeadBool(true);
		this->SetActorEnableCollision(false);
		AnimInstance->Montage_Play(DeathAnimation);
		iDeathCount += 1;
	}
}

void AEnemyBase::DestroyActor()
{
	this->SetActorHiddenInGame(true);
	//this->SetActorEnableCollision(false);
	this->Destroy();
}

void AEnemyBase::OnGrenadeRelease()
{
	//GLog->Log("Released Grenade");

	APawn* PlayerPawn = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
	FVector LaunchVelocity = PlayerPawn->GetActorLocation();

	ExplosiveGrenade->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	ExplosiveGrenade->ProjectileMovement->SetUpdatedComponent(ExplosiveGrenade->GetRootComponent());
	ExplosiveGrenade->ProjectileMovement->Activate(true);
	ExplosiveGrenade->ProjectileMovement->Velocity = LaunchVelocity;


}

void AEnemyBase::OnGrenadeThrowFinished()
{
	this->SetActorHiddenInGame(false);
}

AWeaponBase* AEnemyBase::getWeaponBase()
{
	return Weapon;
}

bool AEnemyBase::getIsDead()
{
	return bDead;
}

