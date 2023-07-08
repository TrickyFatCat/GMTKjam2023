// Fill out your copyright notice in the Description page of Project Settings.


#include "HitPointsComponent.h"


UHitPointsComponent::UHitPointsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	UActorComponent::SetComponentTickEnabled(false);
}