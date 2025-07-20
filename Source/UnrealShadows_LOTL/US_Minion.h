// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "US_Minion.generated.h"

UCLASS()
class UNREALSHADOWS_LOTL_API AUS_Minion : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Minion Perception", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPawnSensingComponent> PawnSense;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Minion Perception", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> Collision;

	// Default Location When this is not chasing characters
	UPROPERTY()
	FVector PatrolLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Minion AI", meta = (AllowPrivateAccess = "true"))
	float AlertRadius = 6000.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
	float Health = 5.f;

	// 미니언이 패배했을 때 스폰될 픽업 아이템 클래스
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AUS_BasePickup> SpawnedPickup;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Minion AI")
	float PatrolSpeed = 150.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Minion AI")
	float ChaseSpeed = 350.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Minion AI")
	float PatrolRadius = 50000.f;

	// Sets default values for this character's properties
	AUS_Minion();

protected:
	UFUNCTION()
	void OnHearingNoise(APawn* PawnInstigator, const FVector& Location, float Volume);

	UFUNCTION()
	void OnDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// called to find new location
	UFUNCTION(BlueprintCallable, Category = "Minion AI")
	void SetNextPatrolLocation();

	// called to chase player character
	UFUNCTION(BlueprintCallable, Category = "Minion AI")
	void Chase(APawn* Pawn);

	virtual void PostInitializeComponents() override;

	FORCEINLINE UPawnSensingComponent* GetPawnSense() const { return PawnSense; }
	FORCEINLINE USphereComponent* GetCollision() const { return Collision; }
	
	// 미니언의 감지 능력으로 폰을 발견했을 때
	UFUNCTION()
	void OnPawnDetected(APawn* Pawn);

	// 플레이어 캐릭터가 잡혔는지 확인할 때
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION(BlueprintCallable, Category = "Minion AI")
	void GoToLocation(const FVector& Location);
};
