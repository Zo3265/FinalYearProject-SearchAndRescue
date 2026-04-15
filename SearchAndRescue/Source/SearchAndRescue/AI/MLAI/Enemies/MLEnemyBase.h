// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "LearningAgentsManager.h"
#include "SearchAndRescue/Weapons/ExplosiveGrenade.h"
#include "MLEnemyBase.generated.h"

UCLASS()
class SEARCHANDRESCUE_API AMLEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMLEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Variables")
	float fHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Variables")
	float fDefaultSpeed = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation Montages")
	UAnimMontage* FiringAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation Montages")
	UAnimMontage* ReloadAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation Montages")
	UAnimMontage* DeathAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation Montages")
	UAnimMontage* GrenadeThrowAnimation;

	UPROPERTY(EditDefaultsOnly, Category = "Grenades")
	TSubclassOf<AExplosiveGrenade> ExplosiveGrenadeClass;

	UPROPERTY()
	AExplosiveGrenade* ExplosiveGrenade;

	UPROPERTY(EditDefaultsOnly, Category = "Grenades")
	int iExplosiveGrenadeAmount = 1;

	UPROPERTY(EditDefaultsOnly, Category = "Grenades")
	int iFlashGrenadeAmount = 1;

	bool bFoundManager = false;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int getExplosiveGrenadeAmount();
	int getFlashGrenadeAmount();
	float getHealth();

	void setSpeed(float fSpeedStore);
	float getDefaultSpeed();

	void takeDamage(float fDamageStore);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
