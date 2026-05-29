// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/MLAI/Enemies/MLEnemyBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMLEnemyBase::AMLEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

// Called when the game starts or when spawned
void AMLEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters SpawnParamaters = FActorSpawnParameters();
	SpawnParamaters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (SniperClass != nullptr)
	{
		SniperRifle = GetWorld()->SpawnActor<ASniperRifle>(SniperClass, FTransform(), SpawnParamaters);

		if (SniperRifle != nullptr)
		{
			SniperRifle->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("GunPoint"));
			SniperRifle->SetOwner(this);
		}
	}
	
	else if (ShotgunClass != nullptr)
	{
		Shotgun = GetWorld()->SpawnActor<AShotgun>(ShotgunClass, FTransform(), SpawnParamaters);

		if (Shotgun != nullptr)
		{
			Shotgun->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("ShotgunSocket"));
			Shotgun->SetOwner(this);
		}
	}

	else if (AssaultRifleClass != nullptr)
	{
		AssaultRifle = GetWorld()->SpawnActor<AAssaultRifle>(AssaultRifleClass, FTransform(), SpawnParamaters);

		if (AssaultRifle != nullptr)
		{
			AssaultRifle->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("AssaultRifleSocket"));
			AssaultRifle->SetOwner(this);
		}
	}


	AnimInstance = GetMesh()->GetAnimInstance();
	
	TArray<AActor*> FoundActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("LearningAgentsManager"), FoundActor);

	for(AActor* temp : FoundActor)
	{
		ULearningAgentsManager* tempManager = temp->FindComponentByClass<ULearningAgentsManager>();

		if(tempManager != nullptr)
		{
			tempManager->AddAgent(this);
			AgentId = tempManager->GetAgentId(this);
			bFoundManager = true;
		}
	}

	if (bFoundManager == false)
	{
		GLog->Log("Could not find manager");
	}
}

// Called every frame
void AMLEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (fHealth <= 0.0f)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Enemy is dead"));
		bDead = true;
		
		if (iDeathCount == 0)
		{
			PlayDeathMontage();
			this->SetActorEnableCollision(false);
		}
	}
}

int AMLEnemyBase::getExplosiveGrenadeAmount()
{
	return iExplosiveGrenadeAmount;
}

int AMLEnemyBase::getFlashGrenadeAmount()
{
	return iFlashGrenadeAmount;
}

float AMLEnemyBase::getHealth()
{
	return fHealth;
}

void AMLEnemyBase::setSpeed(float fSpeedStore)
{
	GetCharacterMovement()->MaxWalkSpeed = fSpeedStore;
}

float AMLEnemyBase::getDefaultSpeed()
{
	return fDefaultSpeed;
}

void AMLEnemyBase::takeDamage(float fDamageStore)
{
	//UE_LOG(LogTemp, Warning, TEXT("Damaging enemy for: %f"), fDamageStore);
	fHealth -= fDamageStore;

	if (EnemyHitSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), EnemyHitSound, GetActorLocation());
	}
	
}

//To improve training for the patrolling behaviour. We need to reset the enemies to a random point on the spline.
void AMLEnemyBase::ResetToRandomPointOnSpline()
{
	if (EnemySpline != nullptr)
	{
		//Modified version of the code from the learning agents tutorial.
		//Get the total spline length and a random distance along that spline.
		float SplineLength = EnemySpline->getSpline()->GetSplineLength();
		float RandomDistance = FMath::FRandRange(0.0f, SplineLength);

		//Create a new vector and rotator for the location and rotation of the enemy.
		FVector NewLocation = EnemySpline->getSpline()->GetLocationAtDistanceAlongSpline(RandomDistance, ESplineCoordinateSpace::World);
		FRotator NewRotation = EnemySpline->getSpline()->GetRotationAtDistanceAlongSpline(RandomDistance, ESplineCoordinateSpace::World);

		//Teleport enemy to said location with an offset of 50.0f on the Z. Idk why this is but the tutorial has it.
		TeleportTo(NewLocation + FVector(0, 0, 50.f), NewRotation, false, true);

		//Remove all momentum from the character so as to not have any momentum carry over.
		//Rotate the character to face the correct direction
		this->GetCharacterMovement()->StopMovementImmediately();
		this->Controller->SetControlRotation(NewRotation);
	}
}

int32 AMLEnemyBase::getAgentId()
{
	return AgentId;
}

ASplineController* AMLEnemyBase::GetSplineController()
{
	return EnemySpline;
}

void AMLEnemyBase::setSeePlayer(bool bStore)
{
	bSeePlayer = bStore;
}

bool AMLEnemyBase::getSeePlayer()
{
	return bSeePlayer;
}

void AMLEnemyBase::setSawPlayer(bool bStore)
{
	bSawPlayer = bStore;
}

bool AMLEnemyBase::getSawPlayer()
{
	return bSawPlayer;
}

void AMLEnemyBase::setSuccessTimer(float fStore)
{
	SuccessTimer = fStore;
}

float AMLEnemyBase::getTimer()
{
	return SuccessTimer;
}

AMyActor* AMLEnemyBase::getTrainingTarget()
{
	return TrainingTarget;
}

void AMLEnemyBase::setIsAimed(bool bStore)
{
	bIsAimed = bStore;
}

bool AMLEnemyBase::getIsAimed()
{
	return bIsAimed;
}

void AMLEnemyBase::setEnemyShootValue(float fStore)
{
	EnemyShootValue = fStore;
}

float AMLEnemyBase::getEnemyShootValue()
{
	return EnemyShootValue;
}

void AMLEnemyBase::setEnemyReloadValue(float fStore)
{
	EnemyReloadValue = fStore;
}

float AMLEnemyBase::getEnemyReloadValue()
{
	return EnemyReloadValue;
}

void AMLEnemyBase::setAmmoPercent(float fStore)
{
	AmmoPercent = fStore;
}

float AMLEnemyBase::getAmmoPercent()
{
	return AmmoPercent;
}

void AMLEnemyBase::setTurnValue(float fStore)
{
	TurnValue = fStore;
}

float AMLEnemyBase::getTurnValue()
{
	return TurnValue;
}

void AMLEnemyBase::setHit(bool bStore)
{
	bHit = bStore;
}

bool AMLEnemyBase::getHit()
{
	return bHit;
}

void AMLEnemyBase::setIdleTimer(float fStore)
{
	IdleTimer = fStore;
}

float AMLEnemyBase::getIdleTimer()
{
	return IdleTimer;
}

void AMLEnemyBase::setCurrentState(EAgentState StateStore)
{
	CurrentState = StateStore;
}

EAgentState AMLEnemyBase::getCurrentState()
{
	return CurrentState;
}

void AMLEnemyBase::PlayDeathMontage()
{
	if (AnimInstance != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Playing animation"));
		if (EnemyDeathSound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), EnemyDeathSound, GetActorLocation());
		}
		
		AnimInstance->Montage_Play(DeathAnimation);
		iDeathCount += 1;
	}
}

AWeaponBase* AMLEnemyBase::getWeapon()
{
	if (SniperRifle)
	{
		return SniperRifle;
	}

	else if (Shotgun)
	{
		return Shotgun;
	}

	else if (AssaultRifle)
	{
		return AssaultRifle;
	}

	return nullptr;
}

void AMLEnemyBase::DestroyActor()
{
	this->SetActorHiddenInGame(true);
	//this->SetActorEnableCollision(false);
	this->Destroy();
	
}

// Called to bind functionality to input
void AMLEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

