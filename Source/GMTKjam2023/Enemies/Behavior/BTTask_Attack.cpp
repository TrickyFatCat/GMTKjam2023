// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "GMTKjam2023/Components/AttackComponent.h"

UBTTask_Attack::UBTTask_Attack()
{
	bCreateNodeInstance = true;

	TimerDelegate = FTimerDelegate::CreateUObject(this, &UBTTask_Attack::OnAnimationTimerDone);
}


EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* const AIController = OwnerComp.GetAIOwner();

	// reset timer handle
	TimerHandle.Invalidate();
	MyOwnerComp = &OwnerComp;

	UAttackComponent* AttackComponent = AIController->GetPawn()->FindComponentByClass<UAttackComponent>();

	if (!AttackComponent)
	{
		return EBTNodeResult::Failed;
	}

	const float FinishDelay = AttackComponent->StartAttack();

	if (FinishDelay > 0)
	{
		AIController->GetWorld()->GetTimerManager().SetTimer(TimerHandle,
		                                                     TimerDelegate,
		                                                     FinishDelay,
		                                                     false);
		return EBTNodeResult::InProgress;
	}

	return EBTNodeResult::Succeeded;
}

EBTNodeResult::Type UBTTask_Attack::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* const MyController = OwnerComp.GetAIOwner();

	if (MyController && TimerHandle.IsValid()
	)
	{
		MyController->GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}

	TimerHandle.Invalidate();

	return EBTNodeResult::Aborted;
}

void UBTTask_Attack::OnAnimationTimerDone()
{
	if (MyOwnerComp)
	{
		FinishLatentTask(*MyOwnerComp, EBTNodeResult::Succeeded);
	}
}
