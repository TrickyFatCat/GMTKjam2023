// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_GetPatrolLocation.generated.h"

/**
 * 
 */
UCLASS()
class GMTKJAM2023_API UBTTask_GetPatrolLocation : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_GetPatrolLocation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node")
	FBlackboardKeySelector TargetLocationKey;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
