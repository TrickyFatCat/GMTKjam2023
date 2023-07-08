// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupEffectType.h"
#include "GMTKjam2023/GMTKjam2023.h"
#include "LurePickupEffect.generated.h"

/**
 * 
 */
UCLASS()
class GMTKJAM2023_API ULurePickupEffect : public UPickupEffectType
{
	GENERATED_BODY()

public:
	virtual bool ActivateEffect_Implementation(AActor* OtherActor) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	ELureType LureType = ELureType::Gold;
};
