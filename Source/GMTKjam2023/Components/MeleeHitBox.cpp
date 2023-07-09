// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeHitBox.h"

#include "HitPointsComponent.h"


UMeleeHitBox::UMeleeHitBox()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UMeleeHitBox::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UMeleeHitBox::HandleBeginOverlap);
}

void UMeleeHitBox::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent,
                                      AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp,
                                      int32 OtherBodyIndex,
                                      bool bFromSweep,
                                      const FHitResult& SweepResult)
{
	if (!IsValid(OtherActor))
	{
		return;
	}

	UHitPointsComponent* HitPoints = OtherActor->FindComponentByClass<UHitPointsComponent>();

	if (!HitPoints)
	{
		return;
	}

	HitPoints->DecreaseValue(Damage);
}

void UMeleeHitBox::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent,
                                    AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp,
                                    int32 OtherBodyIndex)
{
}
