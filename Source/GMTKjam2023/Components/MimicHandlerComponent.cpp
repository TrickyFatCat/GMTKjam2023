﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MimicHandlerComponent.h"


UMimicHandlerComponent::UMimicHandlerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UMimicHandlerComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UMimicHandlerComponent::EnableMimicing()
{
	if (bIsMimicing || LureMeshes.Num() <= 0)
	{
		return false;
	}

	FHitResult HitResult;
	AActor* Actor = GetOwner();
	const FVector TraceStart = Actor->GetActorLocation();
	const FVector TraceEnd = TraceStart + Actor->GetActorForwardVector() * WallCheckDistance;

	GetWorld()->LineTraceSingleByChannel(HitResult,
	                                     TraceStart,
	                                     TraceEnd,
	                                     ECC_Visibility);

	if (HitResult.IsValidBlockingHit())
	{
		
		Actor->SetActorRotation(HitResult.ImpactNormal.Rotation());
	}

	bIsMimicing = true;
	OnMimicToggled.Broadcast(ChestMesh, LureMeshes[LureType]);
	return true;
}

bool UMimicHandlerComponent::DisableMimicing()
{
	if (!bIsMimicing)
	{
		return false;
	}

	bIsMimicing = false;
	OnMimicToggled.Broadcast(MimicMesh,nullptr);
	return true;
}

void UMimicHandlerComponent::SetLureType(ELureType Value)
{
	LureType = Value;
	OnLureChanged.Broadcast(LureType);
}
