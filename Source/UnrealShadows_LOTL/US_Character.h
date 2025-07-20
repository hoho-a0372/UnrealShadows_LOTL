// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "US_Character.generated.h"

UCLASS()
class UNREALSHADOWS_LOTL_API AUS_Character : public ACharacter
{
	GENERATED_BODY()

	// Added Camera Component, Spring Arm Component
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category="Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

	// Added Input Mapping Context Pointer, Input Action Pointer
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> SprintAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Data", meta = (AllowPrivateAccess = "true"))
	class UDataTable* CharacterDataTable;

	struct FUS_CharacterStats* CharacterStats;

	UPROPERTY()
	AActor* InteractableActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stealth", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPawnNoiseEmitterComponent> NoiseEmitter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UUS_WeaponProjectileComponent> Weapon;

public:
	// Sets default values for this character's properties
	AUS_Character();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called by each input actions
	void Move(const struct FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void SprintStart(const FInputActionValue& Value);
	void SprintEnd(const FInputActionValue& Value);
	void Interact(const FInputActionValue& Value);

	UFUNCTION(Server, Reliable)
	void SprintStart_Server();
	UFUNCTION(Server, Reliable)
	void SprintEnd_Server();
	UFUNCTION(Server, Reliable)
	void Interact_Server();

	UFUNCTION(NetMulticast, Reliable)
	void SprintStart_Client();
	UFUNCTION(NetMulticast, Reliable)
	void SprintEnd_Client();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() { return FollowCamera; }

	void UpdateCharacterStats(int32 CharacterLevel);

	FORCEINLINE FUS_CharacterStats* GetCharacterStats() const { return CharacterStats; }

	FORCEINLINE UUS_WeaponProjectileComponent* GetWeapon() const { return Weapon; }
};
