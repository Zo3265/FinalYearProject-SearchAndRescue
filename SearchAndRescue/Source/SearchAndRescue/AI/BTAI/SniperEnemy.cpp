// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/BTAI/SniperEnemy.h"

ASniperEnemy::ASniperEnemy()
{

}

void ASniperEnemy::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters SpawnParamaters = FActorSpawnParameters();
	SpawnParamaters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SniperRifle = GetWorld()->SpawnActor<ASniperRifle>(SniperClass, FTransform(), SpawnParamaters);

	if (SniperRifle != nullptr)
	{
		SniperRifle->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("GunPoint"));
		SniperRifle->SetOwner(this);
	}

	AnimInstance = GetMesh()->GetAnimInstance();

}

void ASniperEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AnimInstance != nullptr)
	{
		if (AnimInstance->Montage_IsPlaying(GrenadeThrowAnimation))
		{
			float GrenadeMontageTimeStore = AnimInstance->Montage_GetPosition(GrenadeThrowAnimation);
			APawn* PlayerPawn = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
			FVector LaunchVelocity = PlayerPawn->GetActorLocation();
			//UE_LOG(LogTemp, Warning, TEXT("Current Montage Time: %f"), GrenadeMontageTimeStore);
			if (GrenadeMontageTimeStore >= 1.83f && iCount == 0)
			{
				ExplosiveGrenade->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				ExplosiveGrenade->ProjectileMovement->SetUpdatedComponent(ExplosiveGrenade->GetRootComponent());
				ExplosiveGrenade->ProjectileMovement->Activate(true);
				//FVector LaunchDirection = GetControlRotation().Vector();

				//UE_LOG(LogTemp, Warning, TEXT("Launch Velocity: %s"), *LaunchVelocity.ToString());
				//UE_LOG(LogTemp, Warning, TEXT("Launch Velocity: %s"), *LaunchVelocity.ToString());
				ExplosiveGrenade->ProjectileMovement->Velocity = LaunchVelocity;
				iCount++;
			}
		}

	}
}

ASniperRifle* ASniperEnemy::getRifle()
{
	return SniperRifle;
}

void ASniperEnemy::PlayAttackAnim()
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

void ASniperEnemy::PlayGrenadeThrowAnim()
{
	if (AnimInstance != nullptr && iCount == 0)
	{
		//SniperRifle->SetActorHiddenInGame(true);
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
