﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPatrolManager.h"

#include "Kismet/KismetMathLibrary.h"


UEnemyPatrolManager::UEnemyPatrolManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEnemyPatrolManager::BeginPlay()
{
	Super::BeginPlay();
}

void UEnemyPatrolManager::GetNextPointLocation(FVector& Location)
{
	if (PatrolPoints.Num() <= 1)
	{
		return;
	}

	int32 NextIndex = CurrentIndex + 1;

	switch (PatrolType)
	{
	case EPatrolType::Loop:
		if (NextIndex >= PatrolPoints.Num())
		{
			NextIndex = 0;
		}
		break;

	case EPatrolType::PingPong:
		if (NextIndex >= PatrolPoints.Num())
		{
			NextIndex = CurrentIndex - 1;
		}
		else if (NextIndex < 0)
		{
			NextIndex = CurrentIndex + 1;
		}
		break;

	case EPatrolType::Random:
		do
		{
			NextIndex = UKismetMathLibrary::RandomInteger(PatrolPoints.Num());
		}
		while (NextIndex == CurrentIndex);
		break;
	}

	CurrentIndex = NextIndex;
	Location = PatrolPoints[CurrentIndex]->GetActorLocation();
}
