// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

class UHitPointsComponent;
class UEnemyPatrolManager;

UCLASS()
class GMTKJAM2023_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	TObjectPtr<UHitPointsComponent> HitPoints = nullptr;
	
	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	TObjectPtr<UEnemyPatrolManager> PatrolManager = nullptr;
};
