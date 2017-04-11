// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;
/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);
private:	
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//Start the tank moving the barrel so that a shot woud hit where the crosshair intersects the world
	void AimTowardsCrosshair();


	//Return an OUT Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float CrossHairYLocation = 0.33333;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float LineTraceRange = 1000000.0;
};
