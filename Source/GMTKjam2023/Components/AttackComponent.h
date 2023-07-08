// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"

class UAnimMontage;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAttackComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* AttackMontage = nullptr;

public:
	UFUNCTION(BlueprintCallable)
	float StartAttack();
};
