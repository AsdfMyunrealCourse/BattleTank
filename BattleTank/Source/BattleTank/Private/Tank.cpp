// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Donkey: %s constructed in c++"), *TankName)
	//no need to protect pointers as added at construction
}

void ATank::BeginPlay()
{
	Super::BeginPlay(); //Needed for BP BeginPlay() !!
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Donkey: %s BeginPlay in c++"), *TankName)
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }

	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (IsReloaded)
	{
		//Spawn Projectile at socket location
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
