// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetPatrolLocation.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GMTKjam2023/Components/EnemyPatrolManager.h"

UBTTask_GetPatrolLocation::UBTTask_GetPatrolLocation()
{
}

EBTNodeResult::Type UBTTask_GetPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	AActor* Owner = Cast<AAIController>(OwnerComp.GetOwner())->GetPawn();
	
	if (!Blackboard || !Owner)
	{
		return EBTNodeResult::Failed;
	}

	UEnemyPatrolManager* PatrolManager = Owner->FindComponentByClass<UEnemyPatrolManager>();

	if (!PatrolManager)
	{
		return EBTNodeResult::Failed;
	}

	FVector TargetLocation {FVector::ZeroVector};

	if (!PatrolManager->GetPatrolLocation(TargetLocation))
	{
		return EBTNodeResult::Failed;
	}
	
	Blackboard->SetValueAsVector(TargetLocationKey.SelectedKeyName, TargetLocation);

	return EBTNodeResult::Succeeded;
}
