// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GrenadeBase.generated.h"

UCLASS()
class SEARCHANDRESCUE_API AGrenadeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrenadeBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	UStaticMeshComponent* Mesh;

	virtual void Explode();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "Grenade Variables")
	float fDamage = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Grenade Variables")
	float finitSpeed = 1000.0f;

	UPROPERTY(EditAnywhere, Category = "Grenade Variables")
	float fFuseTime = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Grenade Variables")
	bool bDummy = false;

	
};
