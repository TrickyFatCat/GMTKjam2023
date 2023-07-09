// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GMTKjam2023/GMTKjam2023.h"
#include "EnemyDesireComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UEnemyDesireComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemyDesireComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ELureType DesiredLure = ELureType::Gold;
};
