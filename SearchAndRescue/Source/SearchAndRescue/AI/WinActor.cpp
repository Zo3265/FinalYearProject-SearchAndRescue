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
	PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (MenuWidgetClass)
	{
		MenuWidgetInstance = CreateWidget<UUserWidget>(PC, MenuWidgetClass);
	}
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
		
		if (PC)
		{
			PC->SetPause(true);
			if (MenuWidgetInstance)
			{
				// 3. Render the menu onto the player's screen
				MenuWidgetInstance->AddToViewport();

				// 4. Setup Input Mode to focus on UI elements
				FInputModeUIOnly InputModeData;
				InputModeData.SetWidgetToFocus(MenuWidgetInstance->TakeWidget());
				InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

				PC->SetInputMode(InputModeData);

				// 5. Explicitly display the hardware mouse cursor
				PC->bShowMouseCursor = true;
			}
		}
		
	}
}

