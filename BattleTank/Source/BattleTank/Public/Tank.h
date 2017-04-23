// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put new includes above

class UTankBarrel;
class UTankTurret;
class AProjectile;
UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:

	UFUNCTION(BluePrintCallable, Category= Firing)
		void Fire();
private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay()override;
	//local Barrel Reference for Spawning Projectiles
	UTankBarrel* Barrel = nullptr; //TODO remove


	//TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000; 

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;
		
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;


	double LastFireTime = 0;
};
