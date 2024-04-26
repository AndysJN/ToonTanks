// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category=Combat)
	TObjectPtr<UStaticMeshComponent> ProjectileMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category=Combat)
	TObjectPtr<UParticleSystem> HitParticles;

	UPROPERTY(VisibleAnywhere, Category=Combat)
	TObjectPtr<UParticleSystemComponent> ParticleSystemComponent;

	UPROPERTY(EditAnywhere, Category=Combat)
	TObjectPtr<USoundBase> LaunchSound;

	UPROPERTY(EditAnywhere, Category=Combat)
	TObjectPtr<USoundBase> HitSound;

	UPROPERTY(EditAnywhere, Category=Combat)
	TSubclassOf<UCameraShakeBase> HitCameraShakeClass;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	


};
