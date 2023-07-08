// Fill out your copyright notice in the Description page of Project Settings.


#include "LurePickup.h"

#include "LurePickupEffect.h"
#include "PickupEffectsComponent.h"
#include "PickupEffectType.h"
#include "SphereInteractionComponent.h"


ALurePickup::ALurePickup()
{
	LureMesh = CreateDefaultSubobject<UStaticMeshComponent>("LureMesh");
	LureMesh->SetupAttachment(GetRootComponent());
}

void ALurePickup::DisablePickup()
{
}

void ALurePickup::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (PickupEffectsComponent->GetMainEffectType())
	{
		const ULurePickupEffect* PickupEffect = Cast<ULurePickupEffect>(
			PickupEffectsComponent->GetMainEffectType()->GetDefaultObject(false));
		if (PickupEffect && Meshes.Num() > 0)
		{
			LureMesh->SetStaticMesh(Meshes[PickupEffect->LureType]);
		}
	}
}

void ALurePickup::StartInteraction_Implementation(AActor* OtherActor)
{
	InteractionTriggerComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

bool ALurePickup::FinishInteraction_Implementation(AActor* OtherActor)
{
	InteractionTriggerComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	return Super::FinishInteraction_Implementation(OtherActor);
}
