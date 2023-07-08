// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MimicHandlerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UMimicHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMimicHandlerComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	bool EnableMimicing();

	UFUNCTION()
	bool DisableMimicing();

	bool GetCanMimic() const { return bCanMimic; }
	
	UFUNCTION(BlueprintGetter)
	bool GetIsMimicing() const { return bIsMimicing; }

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess))
	bool bCanMimic = true;

	UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetIsMimicing)
	bool bIsMimicing = false;
};
