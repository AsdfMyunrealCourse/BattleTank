// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class UTankTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:


private:
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;
	
	virtual void SetPawn(APawn* InPawn) override;
	
	UFUNCTION()
	void OnPossessedTankDeath();
protected:
	//How close can the ai tank get
	UPROPERTY(EditAnywhere, Category = "Setup") //consider EditDefaultsOnly
	float AcceptanceRadius = 8000;
};
