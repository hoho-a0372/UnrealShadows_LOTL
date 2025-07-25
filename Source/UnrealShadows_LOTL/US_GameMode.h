// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "US_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSHADOWS_LOTL_API AUS_GameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AUS_GameMode();
	
	UFUNCTION(BlueprintCallable, Category = "Minions")
	void AlertMinions(class AActor* AlertInstigator, const FVector& Location, const float Radius);

};
