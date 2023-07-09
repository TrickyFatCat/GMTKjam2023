// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_StartIndulging.h"

#include "AIController.h"
#include "GMTKjam2023/Components/EnemyDesireComponent.h"

UBTTask_StartIndulging::UBTTask_StartIndulging()
{
	bCreateNodeInstance = true;

	TimerDelegate = FTimerDelegate::CreateUObject(this, &UBTTask_StartIndulging::OnAnimationTimerDone);
}

EBTNodeResult::Type UBTTask_StartIndulging::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* const AIController = OwnerComp.GetAIOwner();

	UEnemyDesireComponent* DesireComponent = AIController->GetPawn()->FindComponentByClass<UEnemyDesireComponent>();

	if (!DesireComponent)
	{
		return EBTNodeResult::Failed;
	}

	if (DesireComponent->IndulgeDuration > 0)
	{
		if (!DesireComponent->OnIndulgeFinished.IsAlreadyBound(this, &UBTTask_StartIndulging::OnAnimationTimerDone))
		{
			DesireComponent->OnIndulgeFinished.AddDynamic(this, &UBTTask_StartIndulging::OnAnimationTimerDone);
		}
		
		DesireComponent->StartIndulging();
		return EBTNodeResult::InProgress;
	}

	return EBTNodeResult::Succeeded;
}

EBTNodeResult::Type UBTTask_StartIndulging::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* const AIController = OwnerComp.GetAIOwner();

	UEnemyDesireComponent* DesireComponent = AIController->GetPawn()->FindComponentByClass<UEnemyDesireComponent>();

	if (!DesireComponent)
	{
		return EBTNodeResult::Failed;
	}
	
	DesireComponent->StopIndulging();
	return EBTNodeResult::Aborted;
}

void UBTTask_StartIndulging::OnAnimationTimerDone()
{
	if (MyOwnerComp)
	{
		FinishLatentTask(*MyOwnerComp, EBTNodeResult::Succeeded);
	}
}
