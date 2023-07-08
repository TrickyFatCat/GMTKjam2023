// Fill out your copyright notice in the Description page of Project Settings.


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
	if (bIsMimicing)
	{
		return false;
	}

	bIsMimicing = true;
}

bool UMimicHandlerComponent::DisableMimicing()
{
	if (!bIsMimicing)
	{
		return false;
	}

	bIsMimicing = false;
}
