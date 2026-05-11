// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HostageChar.generated.h"

UCLASS()
class SEARCHANDRESCUE_API AHostageChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHostageChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Variables")
	float fHealth = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Variables")
	float fDefaultSpeed = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation Montages")
	UAnimMontage* ActivationMontage;

	UPROPERTY()
	UAnimInstance* AnimInstance;

	
	bool bActivated = false;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void playActivationMontage();

	void takeDamage(float fDamageStore);

	UFUNCTION(BlueprintCallable)
	void setActivated(bool bStore);
	UFUNCTION(BlueprintCallable)
	bool getActivated();
};
