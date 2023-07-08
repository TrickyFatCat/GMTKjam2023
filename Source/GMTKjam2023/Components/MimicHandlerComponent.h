// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GMTKjam2023/GMTKjam2023.h"
#include "MimicHandlerComponent.generated.h"

class USkeletalMesh;
class UStaticMesh;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMimicToggledSignature, USkeletalMesh*, NewMesh, UStaticMesh*, LureMesh);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLureChangedSignature, ELureType, LureType);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTKJAM2023_API UMimicHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMimicHandlerComponent();

	UPROPERTY(BlueprintAssignable)
	FOnMimicToggledSignature OnMimicToggled;
	
	UPROPERTY(BlueprintAssignable)
	FOnLureChangedSignature OnLureChanged;

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

	void SetLureType(ELureType Value);

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess))
	bool bCanMimic = true;

	UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetIsMimicing)
	bool bIsMimicing = false;

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess))
	ELureType LureType = ELureType::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess))
	TObjectPtr<USkeletalMesh> MimicMesh = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess))
	TObjectPtr<USkeletalMesh> ChestMesh = nullptr;

	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess))
	TMap<ELureType, UStaticMesh*> LureMeshes;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, meta=(AllowPrivateAccess))
	float WallCheckDistance = 256.f;
};
