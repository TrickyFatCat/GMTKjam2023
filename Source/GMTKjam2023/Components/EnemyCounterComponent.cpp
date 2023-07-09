// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCounterComponent.h"


UEnemyCounterComponent::UEnemyCounterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UEnemyCounterComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UEnemyCounterComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

