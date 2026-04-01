// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletBase.h"
#include "WeaponBase.generated.h"

UCLASS()
class SEARCHANDRESCUE_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABulletBase> BulletClass;

	UPROPERTY()
	ABulletBase* Bullet;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Fire();
};
