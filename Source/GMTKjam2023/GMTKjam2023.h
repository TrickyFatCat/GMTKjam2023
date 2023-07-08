// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ELureType : uint8
{
	Gold,
	Food,
	Potion,
	Weapon,
	Book,
	None
};