// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "GMTKjam2023/Components/AttackComponent.h"
#include "GMTKjam2023/Components/EnemyPatrolManager.h"
#include "GMTKjam2023/Components/EnemyPlayerHandler.h"
#include "GMTKjam2023/Components/HitPointsComponent.h"
#include "ProceduralMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "GMTKjam2023/Components/EnemyDesireComponent.h"


AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	HitPoints = CreateDefaultSubobject<UHitPointsComponent>("HitPoints");
	PatrolManager = CreateDefaultSubobject<UEnemyPatrolManager>("PatrolManager");
	PlayerHandler = CreateDefaultSubobject<UEnemyPlayerHandler>("PlayerHandler");
	AttackComponent = CreateDefaultSubobject<UAttackComponent>("AttackComponent");
	EnemyDesireComponent = CreateDefaultSubobject<UEnemyDesireComponent>("DesireComponent");
	
	FieldOfViewMesh = CreateDefaultSubobject<UProceduralMeshComponent>("FOVMesh");
	FieldOfViewMesh->SetupAttachment(GetRootComponent());

	EnemyBubbleWidget = CreateDefaultSubobject<UWidgetComponent>("BubbleWidget");
	EnemyBubbleWidget->SetupAttachment(GetRootComponent());
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
