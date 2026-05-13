// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
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

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABulletBase> BulletClass;

	UPROPERTY()
	ABulletBase* Bullet;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Fire();
	void setCoolDown(float fStore);
	float getCoolDown();

	void setRange(float fStore);
	float getRange();

	UStaticMeshComponent* getMesh();
	int getCurrentMagCount();
	int getMaxMagCount();
	void setCurrentAmmoReserve(int iStore);
	int getCurrentAmmoReserve();

	float Cooldown = 1.0f;
	float Range = 3000.0f;
	int iCurrentMagCount; //Current Ammo in gun
	int iCurrentAmmoReserve; //Current Ammo Reserve
	int iMaxMagCount; //Maximum ammo allowed in magazine
	int iMaxAmmoReserve; //Maximum ammo allowed as reserve

	bool bReloading = false;
	bool bCanFire = true;
	void Reload();

	bool getCanFire();
	UFUNCTION(BlueprintCallable)
	void setReloading(bool bStore);
	bool getReloading();
	ABulletBase* getBullet();

};
