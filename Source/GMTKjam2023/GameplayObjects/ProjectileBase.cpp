// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "GMTKjam2023/Components/MeleeHitBox.h"


AProjectileBase::AProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;

	HitBox = CreateDefaultSubobject<UMeleeHitBox>("HitBox");
	SetRootComponent(HitBox);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	HitBox->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBase::HandleProjectileBeginOverlap);
	InitialLocation = GetActorLocation();
}

void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if ((InitialLocation - GetActorLocation()).Size() > MaxDistance)
	{
		Destroy();
	}
}

void AProjectileBase::HandleProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                                   AActor* OtherActor,
                                                   UPrimitiveComponent* OtherComp,
                                                   int32 OtherBodyIndex,
                                                   bool bFromSweep,
                                                   const FHitResult& SweepResult)
{
	Destroy();
}
