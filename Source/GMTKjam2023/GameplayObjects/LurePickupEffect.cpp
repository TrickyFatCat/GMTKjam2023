// Fill out your copyright notice in the Description page of Project Settings.


#include "LurePickupEffect.h"

#include "GMTKjam2023/Components/MimicHandlerComponent.h"

bool ULurePickupEffect::ActivateEffect_Implementation(AActor* OtherActor)
{
	UMimicHandlerComponent* MimicHandler = OtherActor->FindComponentByClass<UMimicHandlerComponent>();

	if (!MimicHandler)
	{
		return false;
	}

	MimicHandler->SetLureType(LureType);
	return true;
}
