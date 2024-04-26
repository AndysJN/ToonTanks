// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class AProjectile;
class UCapsuleComponent;

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();

	void HandleDestruction();

	UPROPERTY(EditAnywhere, Category=Combat)
	TSubclassOf<UCameraShakeBase> DeathCameraShakeClass;

protected:
	UFUNCTION()
	void RotateTurret (FVector &LookAtTarget);

	void Fire();

private:
	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<UCapsuleComponent> CapsuleComp;

	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<UStaticMeshComponent> BaseMesh;

	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<UStaticMeshComponent> TurretMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"));
	TObjectPtr<USceneComponent> ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category=Targeting)
	float TurretInterpRate = 25.f;
	
	UPROPERTY(EditDefaultsOnly, Category=Combat)
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category=Combat)
	TObjectPtr<UParticleSystem> DeathParticles;

	UPROPERTY(EditAnywhere, Category=Combat)
	TObjectPtr<USoundBase> DeathSound;
};
