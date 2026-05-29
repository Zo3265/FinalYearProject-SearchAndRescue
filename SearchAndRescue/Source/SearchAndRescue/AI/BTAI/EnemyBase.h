// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SearchAndRescue/AI/SplineController.h"
#include "SearchAndRescue/Weapons/ExplosiveGrenade.h"
#include "SearchAndRescue/Weapons/WeaponBase.h"
#include "SearchAndRescue/AI/BoolAnimInstance.h"
#include "Components/AudioComponent.h"
#include "EnemyBase.generated.h"

UCLASS()
class SEARCHANDRESCUE_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Spline that we set for a specific enemy to follow.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	ASplineController* splineController;

	UPROPERTY()
	AActor* SphereStore; //Stores the sphere of the enemey.

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

	UPROPERTY()
	UAnimInstance* AnimInstance;

	UPROPERTY()
	AWeaponBase* Weapon;

	int iDeathCount = 0;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Time variables used to determine how far along the spline we are.
	float StartTime;
	float Count;
	float resetTime;

	int getExplosiveGrenadeAmount();
	int getFlashGrenadeAmount();
	float getHealth();

	void setSpeed(float fSpeedStore);
	float getDefaultSpeed();

	void takeDamage(float fDamageStore);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void PlayAttackAnim();
	void PlayReloadAnim();
	void PlayGrenadeThrowAnim();
	void PlayBTDeathMontage();

	UFUNCTION(BlueprintCallable)
	void OnGrenadeRelease();

	UFUNCTION(BlueprintCallable)
	void OnGrenadeThrowFinished();

	UFUNCTION(BlueprintCallable)
	AWeaponBase* getWeaponBase();

	UFUNCTION(BlueprintCallable)
	bool getIsDead();

	UFUNCTION(BlueprintCallable)
	void DestroyActor();

	bool bDead = false;
	UBoolAnimInstance* AnimIsDead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* EnemyHitSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* EnemyDeathSound;
};
