// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	
	virtual void Tick(float DeltaSeconds) override;

	void HandleDestruction();

protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<ATank> Tank;

	UPROPERTY(EditAnywhere, Category=Targeting)
	float FireRange = 500.f;

	UPROPERTY()
	FTimerHandle FireRateTimerHandle;

	UPROPERTY(EditAnywhere)
	float FireRate = 2.f;

	void CheckFireCondition();
	bool InFireRange() const;
};
