// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

class UBehaviorTree;

UCLASS()
class GMTKJAM2023_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* BehaviorTree = nullptr;
};
