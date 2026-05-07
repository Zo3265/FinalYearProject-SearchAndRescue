// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BulletBase.generated.h"

class AMLEnemyBase;

UCLASS()
class SEARCHANDRESCUE_API ABulletBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	UStaticMeshComponent* Mesh;

	UFUNCTION()
	void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY()
	AActor* TargetActor;

	bool bTraining = true;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "Bullet Variables")
	float fDamage = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Bullet Variables")
	float finitSpeed = 50000.0f;

	UPROPERTY(EditAnywhere, Category = "Bullet Variables")
	float fMaxSpeed = 50000.0f;	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bullet Variables")
	float iAmount;

	void setTarget(AActor* ActorStore);
};
