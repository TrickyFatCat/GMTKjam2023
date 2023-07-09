// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyDesireComponent.h"


UEnemyDesireComponent::UEnemyDesireComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEnemyDesireComponent::StartIndulging()
{
	if (GetWorld()->GetTimerManager().IsTimerActive(IndulgeTimer))
	{
		return;
	}

	GetWorld()->GetTimerManager().SetTimer(IndulgeTimer, this, &UEnemyDesireComponent::FinishIndulging, IndulgeDuration);
	OnIndulgeStarted.Broadcast();
}

void UEnemyDesireComponent::FinishIndulging()
{
	OnIndulgeFinished.Broadcast();
}

void UEnemyDesireComponent::StopIndulging()
{
	if (!GetWorld()->GetTimerManager().IsTimerActive(IndulgeTimer))
	{
		return;
	}

	GetWorld()->GetTimerManager().ClearTimer(IndulgeTimer);
}


void UEnemyDesireComponent::BeginPlay()
{
	Super::BeginPlay();
}
