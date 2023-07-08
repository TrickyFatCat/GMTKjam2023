// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MimicHandlerComponent.generated.h"

class USkeletalMesh;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMimicToggledSignature, USkeletalMesh*, NewMesh, UStaticMesh*, LureMesh);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UMimicHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMimicHandlerComponent();

	UPROPERTY(BlueprintAssignable)
	FOnMimicToggledSignature OnMimicToggled;

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	bool EnableMimicing();

	UFUNCTION(BlueprintCallable)
	bool DisableMimicing();

	bool GetCanMimic() const { return bCanMimic; }
	
	UFUNCTION(BlueprintGetter)
	bool GetIsMimicing() const { return bIsMimicing; }

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess))
	bool bCanMimic = true;

	UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetIsMimicing)
	bool bIsMimicing = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess))
	TObjectPtr<USkeletalMesh> MimicMesh = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess))
	TObjectPtr<USkeletalMesh> ChestMesh = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, meta=(AllowPrivateAccess))
	float WallCheckDistance = 256.f;
};
