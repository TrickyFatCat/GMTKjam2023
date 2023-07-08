// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyPlayerHandler.generated.h"

class APlayerCharacter;
class UMimicHandlerComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UEnemyPlayerHandler : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemyPlayerHandler();

	APlayerCharacter* GetPlayerCharacter() const { return PlayerCharacter; }

	UMimicHandlerComponent* GetMimicHandler() const { return MimicHandler; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	APlayerCharacter* PlayerCharacter = nullptr;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	UMimicHandlerComponent* MimicHandler = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName PlayerActorKeyName = "PlayerActor";
};
