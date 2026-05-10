// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SearchAndRescue/Weapons/AssaultRifle.h"
#include "SearchAndRescue/Weapons/SniperRifle.h"
#include "SearchAndRescue/Weapons/Shotgun.h"
#include "MainCharacter.generated.h"

UCLASS()
class SEARCHANDRESCUE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASniperRifle> SniperClass;
	UPROPERTY()
	ASniperRifle* SniperRifle;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AAssaultRifle> AssaultClass;
	UPROPERTY()
	AAssaultRifle* AssaultRifle;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AShotgun> ShotgunClass;
	UPROPERTY()
	AShotgun* Shotgun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	class USceneComponent* WeaponAttachmentPoint;

	UPROPERTY();
	AWeaponBase* CurrentWeapon;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent*
		PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* ShootAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* ReloadAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* SwapAssault;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* SwapShotgun;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* SwapSniper;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Jumping();
	void Shoot();
	void Reload();
	void SwapWeapons(int32 WeaponIndex);
};
