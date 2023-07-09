// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GMTKjam2023/GMTKjam2023.h"
#include "EnemyDesireComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIndulgeFinishedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIndulgeStartedSignature);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UEnemyDesireComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEnemyDesireComponent();

	UPROPERTY(BlueprintReadOnly)
	FTimerHandle IndulgeTimer;

	UPROPERTY(BlueprintAssignable)
	FOnIndulgeFinishedSignature OnIndulgeFinished;

	UPROPERTY(BlueprintAssignable)
	FOnIndulgeStartedSignature OnIndulgeStarted;

	UFUNCTION()
	void StartIndulging();

	UFUNCTION()
	void FinishIndulging();

	UFUNCTION(BlueprintCallable)
	void StopIndulging();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	ELureType DesiredLure = ELureType::Gold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float IndulgeDuration = 5.f;
};
