// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "Navigation/CrowdFollowingComponent.h"


AEnemyController::AEnemyController(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))

{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);
}
