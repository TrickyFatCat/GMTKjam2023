// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_GetPlayerLocation.h"

#include "BehaviorTree/BlackboardComponent.h"

void UBTService_GetPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	if (Blackboard)
	{
		AActor* TargetActor = Cast<AActor>(Blackboard->GetValueAsObject(PlayerActorKey.SelectedKeyName));

		if (TargetActor)
		{
			Blackboard->SetValueAsVector(TargetLocationKey.SelectedKeyName, TargetActor->GetActorLocation());
		}
	}
	
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
