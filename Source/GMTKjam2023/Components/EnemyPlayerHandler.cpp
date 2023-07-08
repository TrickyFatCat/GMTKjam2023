// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPlayerHandler.h"

#include "AIController.h"
#include "MimicHandlerComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GMTKjam2023/Player/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"


UEnemyPlayerHandler::UEnemyPlayerHandler()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UEnemyPlayerHandler::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

в	bIsInAttackRadius = GetOwner()->GetDistanceTo(PlayerCharacter) <= AttackDistance;

	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsBool(CanAttackKeyName, bIsInAttackRadius);
	}
}


void UEnemyPlayerHandler::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (PlayerCharacter)
	{
		MimicHandler = PlayerCharacter->FindComponentByClass<UMimicHandlerComponent>();
	}

	AAIController* Controller = Cast<AAIController>(GetOwner()->GetInstigatorController());
	
	if (Controller)
	{
		BlackboardComponent = Controller->GetBlackboardComponent();
		BlackboardComponent->SetValueAsObject(PlayerActorKeyName, PlayerCharacter);
	}
}
