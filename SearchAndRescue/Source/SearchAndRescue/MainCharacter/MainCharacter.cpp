// Fill out your copyright notice in the Description page of Project Settings.


#include "SearchAndRescue/MainCharacter/MainCharacter.h"
#include "SearchAndRescue/AI/BTAI/HostageChar.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponAttachmentPoint = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponAttachmentPoint"));
	WeaponAttachmentPoint->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
			(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}

		if (MenuWidgetClass)
		{
			MenuWidgetInstance = CreateWidget<UUserWidget>(PlayerController, MenuWidgetClass);
		}
	}

	
	UCameraComponent* PlayerCamera = FindComponentByClass<UCameraComponent>();
	WeaponAttachmentPoint->AttachToComponent(PlayerCamera, FAttachmentTransformRules::KeepRelativeTransform);

	FActorSpawnParameters SpawnParamaters = FActorSpawnParameters();
	SpawnParamaters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SniperRifle = GetWorld()->SpawnActor<ASniperRifle>(SniperClass, FTransform(), SpawnParamaters);
	if (SniperRifle != nullptr)
	{
		SniperRifle->AttachToComponent(WeaponAttachmentPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
		SniperRifle->SetOwner(this);
		CurrentWeapon = SniperRifle;
		SniperRifle->SetActorHiddenInGame(true);
	}

	Shotgun = GetWorld()->SpawnActor<AShotgun>(ShotgunClass, FTransform(), SpawnParamaters);
	if (Shotgun != nullptr)
	{
		Shotgun->AttachToComponent(WeaponAttachmentPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
		Shotgun->SetOwner(this);
		Shotgun->SetActorLocation(FVector(Shotgun->GetActorLocation().X, Shotgun->GetActorLocation().Y, Shotgun->GetActorLocation().Z - 30));
		Shotgun->SetActorHiddenInGame(true);
		//CurrentWeapon = Shotgun;
	}

	AssaultRifle = GetWorld()->SpawnActor<AAssaultRifle>(AssaultClass, FTransform(), SpawnParamaters);
	if (AssaultRifle != nullptr)
	{
		AssaultRifle->AttachToComponent(WeaponAttachmentPoint, FAttachmentTransformRules::SnapToTargetIncludingScale);
		AssaultRifle->SetOwner(this);
		AssaultRifle->SetActorLocation(FVector(AssaultRifle->GetActorLocation().X, AssaultRifle->GetActorLocation().Y, AssaultRifle->GetActorLocation().Z));
		//AssaultRifle->SetActorHiddenInGame(true);
		CurrentWeapon = AssaultRifle;
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (fHealth <= 0.0f)
	{
		APlayerController* PlayerController = Cast<APlayerController>(Controller);

		if (PlayerController)
		{
			PlayerController->SetPause(true);
			if (MenuWidgetInstance)
			{
				// 3. Render the menu onto the player's screen
				MenuWidgetInstance->AddToViewport();

				// 4. Setup Input Mode to focus on UI elements
				FInputModeUIOnly InputModeData;
				InputModeData.SetWidgetToFocus(MenuWidgetInstance->TakeWidget());
				InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

				PlayerController->SetInputMode(InputModeData);

				// 5. Explicitly display the hardware mouse cursor
				PlayerController->bShowMouseCursor = true;
			}
		}
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMainCharacter::Jumping);
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainCharacter::Move);
		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMainCharacter::Look);
		//Shooting
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &AMainCharacter::Shoot);
		//Reloading
		EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Triggered, this, &AMainCharacter::Reload);
		//Swapping Weapons
		EnhancedInputComponent->BindAction(SwapAssault, ETriggerEvent::Triggered, this, &AMainCharacter::SwapWeapons, 0);
		EnhancedInputComponent->BindAction(SwapShotgun, ETriggerEvent::Triggered, this, &AMainCharacter::SwapWeapons, 1);
		EnhancedInputComponent->BindAction(SwapSniper, ETriggerEvent::Triggered, this, &AMainCharacter::SwapWeapons, 2);
		//Interacting with the hostage
		EnhancedInputComponent->BindAction(Interact, ETriggerEvent::Triggered, this, &AMainCharacter::Interaction);

	}
}

void AMainCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		// get right vector
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AMainCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AMainCharacter::Jumping()
{
	Jump();
}

void AMainCharacter::Shoot()
{
	if (Cast<ASniperRifle>(CurrentWeapon))
	{
		GLog->Log("Firing Sniper");
		SniperRifle->SniperFire();
	}

	else if (Cast<AShotgun>(CurrentWeapon))
	{
		GLog->Log("Shotgun Firing");
		Shotgun->ShotgunFire();
	}

	else if (Cast<AAssaultRifle>(CurrentWeapon))
	{
		GLog->Log("AssaultRifle Firing");
		AssaultRifle->AssualtFire();
	}
	
}

void AMainCharacter::Reload()
{
	if (Cast<ASniperRifle>(CurrentWeapon))
	{
		GLog->Log("Reloading Sniper");
		SniperRifle->Reload();
	}

	else if (Cast<AShotgun>(CurrentWeapon))
	{
		GLog->Log("Reloading Shotgun");
		Shotgun->Reload();
	}

	else if (Cast<AAssaultRifle>(CurrentWeapon))
	{
		GLog->Log("AssaultRifle Reloading");
		AssaultRifle->Reload();
	}
}

void AMainCharacter::SwapWeapons(int32 WeaponIndex)
{
	switch (WeaponIndex)
	{
	case(0):
		AssaultRifle->SetActorHiddenInGame(false);
		Shotgun->SetActorHiddenInGame(true);
		SniperRifle->SetActorHiddenInGame(true);
		CurrentWeapon = AssaultRifle;
		break;
	case(1):
		AssaultRifle->SetActorHiddenInGame(true);
		Shotgun->SetActorHiddenInGame(false);
		SniperRifle->SetActorHiddenInGame(false);
		CurrentWeapon = Shotgun;
		break;
	case(2):
		AssaultRifle->SetActorHiddenInGame(true);
		Shotgun->SetActorHiddenInGame(true);
		SniperRifle->SetActorHiddenInGame(false);
		CurrentWeapon = SniperRifle;
		break;
	}
}

void AMainCharacter::Interaction()
{
	AHostageChar* Hostage = Cast<AHostageChar>(UGameplayStatics::GetActorOfClass(GetWorld(), AHostageChar::StaticClass()));

	if (Hostage)
	{
		float Distance = FVector::Distance(Hostage->GetActorLocation(), UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation());
		//UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), Distance);

		if (Distance <= 90.0f)
		{
			//GLog->Log("Playing");
			Hostage->playActivationMontage();
		}
	}
	
}

void AMainCharacter::takeDamage(float fDamageStore)
{
	fHealth -= fDamageStore;
}

