// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_FinishInteraction.h"

#include "InteractionQueueComponent.h"

void UAnimNotify_FinishInteraction::Notify(USkeletalMeshComponent* MeshComp,
                                           UAnimSequenceBase* Animation,
                                           const FAnimNotifyEventReference& EventReference)
{
	UInteractionQueueComponent* InteractionQueueComponent = MeshComp->GetOwner()->FindComponentByClass<UInteractionQueueComponent>();

	if (!InteractionQueueComponent)
	{
		return;
	}

	InteractionQueueComponent->FinishInteraction();
	Super::Notify(MeshComp, Animation, EventReference);
}
