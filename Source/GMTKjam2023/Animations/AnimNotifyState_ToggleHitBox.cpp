// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_ToggleHitBox.h"

#include "GMTKjam2023/Components/MeleeHitBox.h"

void UAnimNotifyState_ToggleHitBox::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                                float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	HitBox = MeshComp->GetOwner()->FindComponentByClass<UMeleeHitBox>();

	if (HitBox)
	{
		HitBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		HitBox->SetHiddenInGame(false);
	}
	
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
}

void UAnimNotifyState_ToggleHitBox::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	if (HitBox)
	{
		HitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		HitBox->SetHiddenInGame(true);
	}
	Super::NotifyEnd(MeshComp, Animation, EventReference);
}
