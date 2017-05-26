// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
//Depends on movement component via pathfinding system
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto ControlledTank = GetPawn();


	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank&& ControlledTank)) { return; }	
	//Move Towards Player
	MoveToActor(PlayerTank, AcceptanceRadius);
	//Aim towards the player
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
	//If Aim or locked
	if(AimingComponent->GetFiringState()== EFiringState::Locked)
	{
		AimingComponent->Fire();
	}
	
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent))
	{
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller can't find aiming component at Begin Play"))
	}
	}



