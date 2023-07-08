// Fill out your copyright notice in the Description page of Project Settings.


#include "LurePickup.h"

#include "SphereInteractionComponent.h"


ALurePickup::ALurePickup()
{
}

void ALurePickup::DisablePickup()
{
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

