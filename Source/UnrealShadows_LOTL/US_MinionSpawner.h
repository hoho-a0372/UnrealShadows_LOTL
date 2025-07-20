// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "US_MinionSpawner.generated.h"

UCLASS()
class UNREALSHADOWS_LOTL_API AUS_MinionSpawner : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn System", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UBoxComponent> SpawnArea;

	UPROPERTY()
	FTimerHandle SpawnTimerHandler;

public:	
	// included All Spawnable minion type
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn System")
	TArray<TSubclassOf<class AUS_Minion>> SpawnableMinions;

	// minion spawning timing
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn System")
	float SpawnDelay = 10.f;

	// number of minion at start
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn System")
	int32 NumMinionAtStart = 5;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn System")
	int32 NumMaxMinion = 20;
	int32 NumMinionOnLevel;

	// Sets default values for this actor's properties
	AUS_MinionSpawner();

protected:
	UFUNCTION()
	void Spawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
