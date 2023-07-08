// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

class UHitPointsComponent;
class UEnemyPatrolManager;
class UEnemyPlayerHandler;
class UAttackComponent;

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
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	TObjectPtr<UHitPointsComponent> HitPoints = nullptr;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	TObjectPtr<UEnemyPatrolManager> PatrolManager = nullptr;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	TObjectPtr<UEnemyPlayerHandler> PlayerHandler = nullptr;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Components")
	TObjectPtr<UAttackComponent> AttackComponent = nullptr;
};
