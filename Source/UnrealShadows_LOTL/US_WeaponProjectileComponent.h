// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "US_WeaponProjectileComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALSHADOWS_LOTL_API UUS_WeaponProjectileComponent : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AUS_BaseWeaponProjectile> ProjectileClass;

	// 캐릭터에 종속성을 추가하지 않고도 기능을 추가할 수 있는 Mapping Context 사용
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* WeaponMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* ThrowAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* ThrowAnimation;

public:	
	// Sets default values for this component's properties
	UUS_WeaponProjectileComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Throw();
	UFUNCTION(Server, Reliable)
	void Throw_Server();
	UFUNCTION(NetMulticast, UnReliable) // 모든 클라이언트에 RPC multicasting
	void Throw_Client();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SetProjectileClass(TSubclassOf<class AUS_BaseWeaponProjectile> NewProjectileClass);
};
