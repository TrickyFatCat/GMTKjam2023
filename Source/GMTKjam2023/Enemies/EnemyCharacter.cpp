// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "GMTKjam2023/Components/HitPointsComponent.h"


AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	HitPoints = CreateDefaultSubobject<UHitPointsComponent>("HitPoints");
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
