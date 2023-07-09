// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyPlayerHandler.generated.h"

class APlayerCharacter;
class UMimicHandlerComponent;
class UBlackboardComponent;
class UEnemyCounterComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UEnemyPlayerHandler : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemyPlayerHandler();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	APlayerCharacter* GetPlayerCharacter() const { return PlayerCharacter; }

	UMimicHandlerComponent* GetMimicHandler() const { return MimicHandler; }

	UEnemyCounterComponent* GetEnemyCounter() const { return EnemyCounter; }	

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	APlayerCharacter* PlayerCharacter = nullptr;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	UMimicHandlerComponent* MimicHandler = nullptr;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	UEnemyCounterComponent* EnemyCounter = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName PlayerActorKeyName = "PlayerActor";

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName CanAttackKeyName = "CanAttack";
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float AttackDistance = 50.f;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	bool bIsInAttackRadius = false;

	UPROPERTY()
	UBlackboardComponent* BlackboardComponent = nullptr;

	UFUNCTION()
	void HandlePlayerDeath();
};
