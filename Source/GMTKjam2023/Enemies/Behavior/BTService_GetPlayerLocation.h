// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_GetPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class GMTKJAM2023_API UBTService_GetPlayerLocation : public UBTService
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node")
	FBlackboardKeySelector PlayerActorKey;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node")
	FBlackboardKeySelector TargetLocationKey;
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
