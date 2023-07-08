// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CalcNextPatrolPoint.h"

#include "GMTKjam2023/Components/EnemyPatrolManager.h"
#include "AIController.h"

EBTNodeResult::Type UBTTask_CalcNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AActor* Owner = Cast<AAIController>(OwnerComp.GetOwner())->GetPawn();

	if (!Owner)
	{
		return EBTNodeResult::Failed;
	}

	UEnemyPatrolManager* PatrolManager = Owner->FindComponentByClass<UEnemyPatrolManager>();

	if (!PatrolManager)
	{
		return EBTNodeResult::Failed;
	}

	PatrolManager->CalculateNextPatrolPoint();
	return EBTNodeResult::Succeeded;
}
