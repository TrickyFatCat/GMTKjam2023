// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Attack.generated.h"

/**
 * 
 */
UCLASS()
class GMTKJAM2023_API UBTTask_Attack : public UBTTaskNode
{
	GENERATED_BODY()
	
public:

	UBTTask_Attack();
	 
	UPROPERTY()
	UBehaviorTreeComponent* MyOwnerComp;

	FTimerDelegate TimerDelegate;
	FTimerHandle TimerHandle;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	void OnAnimationTimerDone();
};
