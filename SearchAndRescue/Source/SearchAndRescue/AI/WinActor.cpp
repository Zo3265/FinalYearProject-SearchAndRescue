// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/AI/WinActor.h"

// Sets default values
AWinActor::AWinActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->BodyInstance.SetInstanceNotifyRBCollision(true);
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AWinActor::OnOverLapBegin);
	
}

// Called when the game starts or when spawned
void AWinActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWinActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWinActor::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AHostageChar* Hostage = Cast<AHostageChar>(OtherActor);
	//UE_LOG(LogTemp, Warning, TEXT("Overlapping."))
	if (Hostage)
	{
		PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC)
		{
			PC->SetPause(true);
		}
		
	}
}

