// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_SpawnProjectile.h"

#include "GMTKjam2023/GameplayObjects/ProjectileBase.h"

void UAnimNotify_SpawnProjectile::Notify(USkeletalMeshComponent* MeshComp,
                                         UAnimSequenceBase* Animation,
                                         const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp->GetWorld() || !MeshComp->GetOwner())
	{
		return;
	}
	if (!ProjectileClass)
	{
		return;
	}

	FTransform SpawnTransform;
	SpawnTransform.SetLocation(MeshComp->GetSocketLocation(SpawnSocketName));
	SpawnTransform.SetRotation(FQuat(MeshComp->GetOwner()->GetActorForwardVector().Rotation()));
	MeshComp->GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, SpawnTransform);
	Super::Notify(MeshComp, Animation, EventReference);
}
