// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackComponent.h"

#include "GameFramework/Character.h"


UAttackComponent::UAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();
}

float UAttackComponent::StartAttack()
{
	if (!AttackMontage)
	{
		return 0.f;
	}

	ACharacter* Character = Cast<ACharacter>(GetOwner());

	if (!Character)
	{
		return 0.f;
	}

	return Character->PlayAnimMontage(AttackMontage);
}