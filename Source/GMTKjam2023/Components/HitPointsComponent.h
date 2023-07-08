// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SimpleResourceComponent.h"
#include "HitPointsComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UHitPointsComponent : public USimpleResourceComponent
{
	GENERATED_BODY()

public:
	UHitPointsComponent();
};
