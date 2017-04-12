// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto ControlledTank = Cast<ATank>(GetPawn());

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ensure(PlayerTank))
	{
		//Move Towards Player
		MoveToActor(PlayerTank, AcceptanceRadius);
		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//Fire if Ready
		ControlledTank->Fire();
	}
	//AimTowardsCrosshair
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	}



