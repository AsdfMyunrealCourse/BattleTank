// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//Move the barrelt the right amount this frame
	//given a max elevation and the frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel_Elevate() called at speed %f"), DegreesPerSecond)
}


