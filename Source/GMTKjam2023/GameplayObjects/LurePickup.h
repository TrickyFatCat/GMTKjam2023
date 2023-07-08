// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupInteractive.h"
#include "GMTKjam2023/GMTKjam2023.h"
#include "LurePickup.generated.h"

class UStaticMesh;

UCLASS()
class GMTKJAM2023_API ALurePickup : public APickupInteractive
{
	GENERATED_BODY()

public:
	ALurePickup();

protected:
	virtual void DisablePickup() override;

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(VisibleDefaultsOnly, Category="Components", BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> LureMesh = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<ELureType, UStaticMesh*> Meshes;

private:
	virtual void StartInteraction_Implementation(AActor* OtherActor) override;

	virtual bool FinishInteraction_Implementation(AActor* OtherActor) override;


};

