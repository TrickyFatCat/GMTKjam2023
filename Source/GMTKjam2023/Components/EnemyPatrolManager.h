﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyPatrolManager.generated.h"

UENUM()
enum class EPatrolType: uint8
{
	PingPong,
	Loop,
	Random
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UEnemyPatrolManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemyPatrolManager();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	TArray<AActor*> PatrolPoints;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	EPatrolType PatrolType = EPatrolType::PingPong;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName WaitKeyName = NAME_None;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	float WaitDuration = 3.f;

public:
	UFUNCTION(BlueprintCallable)
	bool GetPatrolLocation(FVector& Location);

	UFUNCTION(BlueprintCallable)
	void CalculateNextPatrolPoint();

private:
	int32 CurrentIndex = 0;

	int32 PingPontDirection = 1;
};
