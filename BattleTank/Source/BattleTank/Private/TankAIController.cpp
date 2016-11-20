// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT ("AI Controller not posessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller posessing : %s"), *ControlledTank->GetName())
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not finding Player"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Found Player Tank : %s"), *PlayerTank->GetName())
	}
}
ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn= GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
			return nullptr;
	}
	return Cast<ATank>(PlayerPawn);

}
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

