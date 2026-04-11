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
	if (AnimInstance != nullptr)
	{
		SniperRifle->SetActorHiddenInGame(true);
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

void ASniperEnemy::OnGrenadeRelease()
{
	//GLog->Log("Released Grenade");

	APawn* PlayerPawn = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
	FVector LaunchVelocity = PlayerPawn->GetActorLocation();
	
	ExplosiveGrenade->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	ExplosiveGrenade->ProjectileMovement->SetUpdatedComponent(ExplosiveGrenade->GetRootComponent());
	ExplosiveGrenade->ProjectileMovement->Activate(true);
	ExplosiveGrenade->ProjectileMovement->Velocity = LaunchVelocity;
	iCount++;
	
}

void ASniperEnemy::OnGrenadeThrowFinished()
{
	SniperRifle->SetActorHiddenInGame(false);
}
