// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "JamGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GMTKJAM2023_API UJamGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void IncrementLevelIndex() { LevelIndex++; };
	
	UFUNCTION(BlueprintCallable)
	void ResetLevelIndex() { LevelIndex = 0; }

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	int32 LevelIndex = 0;
};
