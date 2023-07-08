﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InteractionQueueComponent.h"
#include "TrickyGameModeLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GMTKjam2023/Components/HitPointsComponent.h"
#include "GMTKjam2023/Components/MimicHandlerComponent.h"


APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

	Lure = CreateDefaultSubobject<UStaticMeshComponent>("Lure");
	Lure->SetupAttachment(GetRootComponent());

	InteractionQueue = CreateDefaultSubobject<UInteractionQueueComponent>("InteractionQueue");
	InteractionQueue->SetFinishManually(true);
	HitPoints = CreateDefaultSubobject<UHitPointsComponent>("HitPoints");
	MimicHandler = CreateDefaultSubobject<UMimicHandlerComponent>("MimicHandler");
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}

	MimicHandler->OnMimicToggled.AddDynamic(this, &APlayerCharacter::HandleMimicing);
	InteractionQueue->OnInteractionFinishedSignature.AddDynamic(this, &APlayerCharacter::HandleInteractionFinish);
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Lure->AddLocalRotation(FRotator{0.f, LureRotationSpeed * DeltaTime, 0.f});
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);

		//Interacting
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &APlayerCharacter::Interact);

		//Mimic
		EnhancedInputComponent->BindAction(MimicAction,
		                                   ETriggerEvent::Started,
		                                   this,
		                                   &APlayerCharacter::ToggleMimicing);

		//Attack
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Attack);

		//Pause
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &APlayerCharacter::TogglePause);
	}
}

void APlayerCharacter::TogglePause()
{
	UTrickyGameModeLibrary::TogglePause(this);
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void APlayerCharacter::Interact()
{
	if (MimicHandler->GetIsMimicing())
	{
		return;
	}

	ToggleInput(false);
	InteractionQueue->StartInteraction();
}

void APlayerCharacter::ToggleMimicing()
{
	if (!MimicHandler->GetCanMimic())
	{
		return;
	}

	MimicHandler->GetIsMimicing() ? MimicHandler->DisableMimicing() : MimicHandler->EnableMimicing();
}

void APlayerCharacter::Attack()
{
}

void APlayerCharacter::HandleMimicing(USkeletalMesh* NewMesh, UStaticMesh* LureMesh)
{
	GetMesh()->SetSkeletalMesh(NewMesh, false);
	Lure->SetStaticMesh(LureMesh);

	if (MimicHandler->GetIsMimicing())
	{
		GetCharacterMovement()->DisableMovement();
	}
	else
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
}

void APlayerCharacter::HandleInteractionFinish(AActor* TargetActor)
{
	ToggleInput(true);
}

void APlayerCharacter::ToggleInput(const bool bIsEnabled)
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (PlayerController)
	{
		bIsEnabled ? EnableInput(PlayerController) : DisableInput(PlayerController);
	}
}
