// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupInteractive.h"
#include "LurePickup.generated.h"

UCLASS()
class GMTKJAM2023_API ALurePickup : public APickupInteractive
{
	GENERATED_BODY()

public:
	ALurePickup();

protected:
	virtual void DisablePickup() override;

private:
	virtual void StartInteraction_Implementation(AActor* OtherActor) override;

	virtual bool FinishInteraction_Implementation(AActor* OtherActor) override;
};

