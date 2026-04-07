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
		/*if (AnimInstance->Montage_IsPlaying(FiringAnimation))
		{
			float AttackMontageTimeStore = AnimInstance->Montage_GetPosition(FiringAnimation);
			UE_LOG(LogTemp, Warning, TEXT("Current Montage Time: %f"), AttackMontageTimeStore);
			if (AttackMontageTimeStore >= 0.1f )
			{
				SniperRifle->SniperFire();
			}
		}*/

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
	if (AnimInstance != nullptr)
	{
		AnimInstance->Montage_Play(GrenadeThrowAnimation);
	}
}
