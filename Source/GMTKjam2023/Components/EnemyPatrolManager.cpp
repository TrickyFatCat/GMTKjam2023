// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPatrolManager.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"


UEnemyPatrolManager::UEnemyPatrolManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEnemyPatrolManager::BeginPlay()
{
	Super::BeginPlay();

	AAIController* Controller = Cast<AAIController>(GetOwner()->GetInstigatorController());

	if (Controller)
	{
		Controller->GetBlackboardComponent()->SetValueAsFloat(WaitKeyName, WaitDuration);
	}
}

bool UEnemyPatrolManager::GetPatrolLocation(FVector& Location)
{
	if (PatrolPoints.Num() < 1)
	{
		return false;
	}
	
	Location = PatrolPoints[CurrentIndex]->GetActorLocation();
	return true;
}

void UEnemyPatrolManager::CalculateNextPatrolPoint()
{if (PatrolPoints.Num() <= 1)
 	{
 		return;
 	}
 
 	int32 NextIndex = CurrentIndex + 1;
 
 	switch (PatrolType)
 	{
 	case EPatrolType::Loop:
 		if (NextIndex >= PatrolPoints.Num())
 		{
 			NextIndex = 0;
 		}
 		break;
 
 	case EPatrolType::PingPong:
 		NextIndex = CurrentIndex + 1 * PingPontDirection;
 		
 		if (NextIndex >= PatrolPoints.Num())
 		{
 			PingPontDirection = -1;
 		}
 		else if (NextIndex < 0)
 		{
 			PingPontDirection = 1;
 		}
 
 		NextIndex = CurrentIndex + 1 * PingPontDirection;
 		break;
 
 	case EPatrolType::Random:
 		do
 		{
 			NextIndex = UKismetMathLibrary::RandomInteger(PatrolPoints.Num());
 		}
 		while (NextIndex == CurrentIndex);
 		break;
 	}
 
 	CurrentIndex = NextIndex;
}